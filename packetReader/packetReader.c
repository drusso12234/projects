/*
 * (c) Copyright 2017, Mantis Networks, Inc.  All rights reserved.
 */

 //export NO_NUMA=true if on one cpu system to make

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <pcap/pcap.h>
#include "shm_spsc.h"
#ifdef __APPLE__
#define FMT "ll"
#else /* __APPLE__ */
#define FMT "l"
#endif /* __APPLE__ */
#define kCOUNT 256


static volatile uint8_t gRunning = 1;


/* Signal Handler */
static void Handler_SIGINT(int __attribute__((__unused__)) p_signal)
{

        /* Shut us down */
    gRunning = 0;
} /* Handler_SIGINT */


int main(int argc,
         char *argv[])
{
    SHM_SPSC_RING_BUFFER *ring_buffer;
    SHM_ERROR_CODE        err;
    uint8_t              *ptr;
    uint32_t              len;
    uint8_t              *tmp;
    uint64_t              sec;
    uint64_t              nsec;
    uint32_t              bin_size;
    uint32_t              count;
    uint64_t              empty = 0;
    uint64_t              pending = 0;
    uint64_t              success = 0;
    time_t                last_time = time(NULL);
    uint32_t              time_count = 0;

    uint32_t              i;
    uint32_t              j; /* __DEBUG */

struct pcap_pkthdr packet_header;
struct timeval ts;

        /* Sanity check inputs */
    if (argc != 5)
    {
        fprintf(stderr, "error: harness_vector {instance} {ring_buffer_name} {PCAP_file_name} {packet_capture}\n");
        return(-1);
    }

        /* Install signal handler */
    signal(SIGINT, Handler_SIGINT);

    pcap_t *pd;
    pcap_dumper_t *pdumper;
    pd = pcap_open_dead(DLT_RAW, 65535);

    pdumper = pcap_dump_open(pd, argv[3]);

    int AofPacket = atoi(argv[4]);


        /* Keep trying to attach until we are successful or interrupt */
    do
    {
        switch (err = SHM_SPSC_Ring_Buffer_Attach(argv[2], atoi(argv[1]), &ring_buffer, &bin_size))
        {
        case SHM_FAILED_TO_OPEN_RING:
            printf("Waiting for ring '%s', instance %u to be created...\n", argv[2], atoi(argv[1]));
            sleep(1);
            break;

        case SHM_FAILED_TO_MMAP_RING:
            printf("Failed to map ring '%s', instance %u into process...\n", argv[2], atoi(argv[1]));
            sleep(1);
            break;

        case SHM_NOT_READY:
            printf("Ring '%s', instance %u not ready yet...\n", argv[2], atoi(argv[1]));
            sleep(1);
            break;

        case SHM_SUCCESS:
            printf("Ring '%s', instance %u finally ready...\n", argv[2], atoi(argv[1]));
            break;

        case SHM_ACTIVE_RING_RECEIVER:
            printf("Ring '%s', instance %u has an active receiver, resetting...\n", argv[2], atoi(argv[1]));
            SHM_SPSC_Ring_Buffer_Reset(argv[2], atoi(argv[1]));
            break;

        default:
                /* Ignore */
            break;
        }

    } while ((err != SHM_SUCCESS) && gRunning);

        /* Did we prematurely shut down? */
    if (err != SHM_SUCCESS)
    {
        goto bail;
    }

        /* Consume packets until termination */
    while (gRunning)
    {
        if (++time_count > 2500000)
        {
            time_count = 0;
            if (last_time != time(NULL))
            {
                last_time = time(NULL);
                fprintf(stdout, "empty: %15" FMT "u, pending: %15" FMT "u, success: %15" FMT "u\n", empty, pending, success);
            }
        }
        switch (SHM_SPSC_Dequeue_Block(ring_buffer, &count, &ptr))
        {
        case SHM_RING_EMPTY:
            empty++;
            break;

        case SHM_MORE_PENDING:
            pending++;
            for (i=0; i<count; i++)
            {
                printf("did it even get here? \n");
                tmp = ptr;
                ts.tv_sec = *((uint64_t *)tmp);
                tmp += sizeof(uint64_t);
                ts.tv_usec = *((uint64_t *)tmp)/1000;
                tmp += sizeof(uint64_t);
                len = *((uint32_t *)tmp);
                tmp += sizeof(uint32_t);

                packet_header.ts = ts;
                packet_header.caplen = len;
                packet_header.len = len;

                if (atoi(argv[4]) == 0) {
                //  while (gRunning) {
                    printf("It doesnt work \n");
                    //for (j=0; j < len; j++){
                      pcap_dump(pdumper, &packet_header, tmp);
                    //}

                  //}
                }
                //while (atoi(argv[4]) >= 1) {
                if (atoi(argv[4]) >= 1){
                 printf("it works \n");
                  //for (j = 0; j < len; j ++){
                    pcap_dump(pdumper, &packet_header, tmp);
                  //}
                  AofPacket--;
                  if (AofPacket == 0){
                    gRunning = 0;
                    break;
                  }
                }
            }
            SHM_SPSC_Free_Vector(ring_buffer, count);
            break;

        case SHM_SUCCESS:
            success++;
            printf("recieved %d \n", count);
            for (i=0; i<count; i++)
            {
                printf("did it even get here? \n");
                tmp = ptr;
                ts.tv_sec = *((uint64_t *)tmp);
                tmp += sizeof(uint64_t);
                ts.tv_usec = *((uint64_t *)tmp)/1000;
                tmp += sizeof(uint64_t);
                len = *((uint32_t *)tmp);
                tmp += sizeof(uint32_t);

                packet_header.ts = ts;
                packet_header.caplen = len;
                packet_header.len = len;

                if (atoi(argv[4]) == 0) {
                //  while (gRunning) {
                    printf("It doesnt work \n");
                    //for (j=0; j < len; j++){
                      pcap_dump(pdumper, &packet_header, tmp);
                    //}

                  //}
                }
                //while (atoi(argv[4]) >= 1) {
                if (atoi(argv[4]) >= 1){
                 printf("it works \n");
                  //for (j = 0; j < len; j ++){
                    pcap_dump(pdumper, &packet_header, tmp);
                  //}
                  AofPacket--;
                  if (AofPacket == 0){
                    gRunning = 0;
                    break;
                  }
                }
            }
            SHM_SPSC_Free_Vector(ring_buffer, count);
            break;
/*#if __DEBUG
for (i=0; i<count; i++)
{
    tmp = ptr;
    sec = *((uint64_t *)tmp);
    tmp += sizeof(uint64_t);
    nsec = *((uint64_t *)tmp);
    tmp += sizeof(uint64_t);
    len = *((uint32_t *)tmp);
    tmp += sizeof(uint32_t);

    packet_header.ts = ts;
    packet_header.caplen = len;
    packet_header.len = len;

    if (atoi(argv[4]) == 0) {
    //  while (gRunning) {
        for (j=0; j < len; j++){
          pcap_dump(pdumper, &packet_header, tmp[j]);
        }

      //}
    }
    //while (atoi(argv[4]) >= 1) {
    if (atoi(argv[4]) >= 1){
      for (j = 0; j < len; j ++){
        pcap_dump(pdumper, &packet_header, tmp[j]);
      }
      AofPacket--;
      if (AofPacket == 0){
        gRunning = 0;
        break;
      }
    }
}
#endif /* __DEBUG */
            SHM_SPSC_Free_Vector(ring_buffer, count);
            break;

        case SHM_PRODUCER_QUIT:
            gRunning = 0;
            break;

        default:
                /* Ignore */
            break;
        }
    }

        /* Clean up */
    SHM_SPSC_Ring_Buffer_Detach(ring_buffer);
    pcap_close(pd);
    pcap_dump_close(pdumper);
  bail:
    fprintf(stdout, "\nShutting down...\n");

    return(0);
} /* main() */
