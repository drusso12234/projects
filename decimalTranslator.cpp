#include <iostream>
#include <cstdint>
#include <cmath>
//program to turn a decimal number into a binary number

void hex(char arr[], uint16_t num) {
  uint8_t k = sizeof(num) * 2;
  char stor[k];
  uint8_t i = 0;
  std::cout << "hex: 0x";
  while (i < k) {
    stor[i] = arr[num & 15];
    num >>= 4;
    ++i;
  }
  while (k > 0) {
    --k;
    std::cout << stor[k];
  }
  std::cout << std::endl;
}

void binary(uint16_t num, std::string& biNum) {
  for (uint8_t i = (sizeof(num) * 8); i > 0; --i) {
    if ((num & (1 << (i-1))) != 0) {
      biNum += "1";
    }
    else {
      biNum += "0";
    }
  }
}

//slower hex solution
void hex(char arr[], uint16_t num, std::string& hexNum) {
  uint16_t temp = 1;
  uint8_t tot = 0;

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
}
int main() {
  std::cout << "Enter a number between 0 and 65535: ";
  uint16_t num;
  std::cin >> num;
  std::string biNum = "";
  std::string hexNum = "";
  char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  hex(arr, num);
  binary(num, biNum);
  std::cout << "binary: " << biNum << std::endl;
}
