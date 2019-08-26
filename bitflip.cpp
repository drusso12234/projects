#include <iostream>
#include <cstdint>
#include <cmath>
//program to turn a decimal number into a binary number
int main() {
  std::cout << "Enter a number between 0 and 65535: ";
  uint16_t num;
  std::cin >> num;
  std::string biNum = "";
  std::string hexNum = "";
  uint16_t temp = 1;
  uint8_t tot = 0;
  char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  
  for (uint8_t i = 16; i > 0; --i) {
    //std::cout << (num & (1 << (i-1))) << std::endl;
    if ((num & (1 << (i-1))) != 0) {
      biNum += "1";
    }
    else {
      biNum += "0";
    }
  }

  for (uint8_t i = 16; i > 0; i-=4) {
    for (uint8_t k = i; k > (i - 4); --k) {
      if ((num & (1 << (k - 1))) != 0) {
     	for (uint8_t j = 3 - (i - k); j > 0; --j) {
	  temp *= 2;
	}
	tot += temp;
	temp = 1;
      }
    }
    hexNum += arr[tot];
    tot = 0;
  }
  std::cout << "binary: " << biNum << std::endl;
  std::cout << "hex: 0x" << hexNum << std::endl;
}
