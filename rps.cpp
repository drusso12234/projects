#include <iostream>
#include <string>

int main() {
  size_t aiChoice[] = {0,1,0,2,2,1,0,1,2,0};
  std::string name[] = {"win", "lose", "tie"};
  std::string opt[] = {"rock", "paper", "scissors"};
  size_t choice;
  size_t winners[10] = {};
  std::cout << "0 = rock\n1 = paper\n2 = scissors\nMake your choice: " << std::endl;
  for (size_t i = 0; i < 10; ++i) {
    std::cin >> choice;
    if (choice == aiChoice[i]) {
      winners[i] = 2;
      std::cout << "You choose " << opt[choice] << " they choose " << opt[aiChoice[i]] << " - You " << name[winners[i]] << std::endl;
    }
    if (choice > aiChoice[i]) {
      winners[i] = 0;
      if (choice - aiChoice[i] == 2) {
	winners[i] = 1;
      }
      std::cout	<< "You choose " << opt[choice] << " they choose " << opt[aiChoice[i]] << " - You " << name[winners[i]] << "!" << std::endl;
    }
    if (aiChoice[i] > choice) {
      winners[i] = 1;
      if (aiChoice[i] - choice == 2) {
	winners[i] = 0;
      }
      std::cout	<< "You choose " << opt[choice] << " they choose " << opt[aiChoice[i]] << " - You " << name[winners[i]] << std::endl;
    }
  }
  for (size_t i = 0; i < 10; ++i) {
    std::cout << "Game " << (i+1) << ": " << name[winners[i]] << std::endl;
  }
}
