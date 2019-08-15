#include <set>
#include <string>
#include <iostream>
#include <map>
#include "string.h"
//ice = 5 psy = 10 dark = 15

std::set<int> fairy(){
  std::set<int> returns;
  returns.insert(15);
  returns.insert(6);
  returns.insert(11);
  returns.insert(14);
  return returns;
}

std::set<int> steel(){
  std::set<int> returns;
  returns.insert(0);
  returns.insert(3);
  returns.insert(5);
  returns.insert(7);
  returns.insert(9);
  returns.insert(10);
  returns.insert(11);
  returns.insert(12);
  returns.insert(14);
  returns.insert(16);
  returns.insert(17);
  return returns;
}

std::set<int> dark(){
  std::set<int> returns;
  returns.insert(15);
  returns.insert(13);
  return returns;
}

std::set<int> dragon(){
  std::set<int> returns;
  returns.insert(4);
  returns.insert(3);
  returns.insert(2);
  returns.insert(1);
  return returns;
}

std::set<int> ghost(){
  std::set<int> returns;
  returns.insert(11);
  return returns;
}

std::set<int> rock(){
  std::set<int> returns;
  returns.insert(1);
  returns.insert(0);
  returns.insert(7);
  returns.insert(9);
  return returns;
}

std::set<int> bug(){
  std::set<int> returns;
  returns.insert(4);
  returns.insert(6);
  returns.insert(8);
  return returns;
}

std::set<int> psychic(){
  std::set<int> returns;
  returns.insert(10);
  returns.insert(6);
  return returns;
}

std::set<int> flying(){
  std::set<int> returns;
  returns.insert(4);
  returns.insert(6);
  returns.insert(11);
  return returns;
}

std::set<int> ground(){
  std::set<int> returns;
  returns.insert(3);
  returns.insert(7);
  returns.insert(12);
  return returns;
}

std::set<int> fire(){
  std::set<int> returns;
  returns.insert(1);
  returns.insert(4);
  returns.insert(5);
  returns.insert(11);
  returns.insert(16);
  returns.insert(17);
  return returns;
}

std::set<int> water(){
  std::set<int> returns;
  returns.insert(1);
  returns.insert(2);
  returns.insert(5);
  returns.insert(16);
  return returns;
}

std::set<int> electric(){
  std::set<int> returns;
  returns.insert(3);
  returns.insert(9);
  returns.insert(16);
  return returns;
}

std::set<int> grass(){
  std::set<int> returns;
  returns.insert(2);
  returns.insert(3);
  returns.insert(4);
  returns.insert(8);
  return returns;
}

std::set<int> ice(){
  std::set<int> returns;
  returns.insert(5);
  return returns;
}

std::set<int> fighting(){
  std::set<int> returns;
  returns.insert(12);
  returns.insert(11);
  returns.insert(15);
  return returns;
}

std::set<int> poison(){
  std::set<int> returns;
  returns.insert(4);
  returns.insert(6);
  returns.insert(7);
  returns.insert(11);
  returns.insert(17);
  return returns;
}

int main(int argc, char** argv){
  std::string types[18] = {"normal", "fire", "water", "electric", "grass", "ice",
  "fighting", "poison", "ground", "flying", "psychic", "bug", "rock", "ghost",
  "dragon", "dark", "steel", "fairy"};

  std::map<std::string, int> resists;
  std::set<int> temp;
  std::set<int>::iterator iter;

  long unsigned int j;
  std::cout << sizeof(j) << std::endl;
  for (size_t i = 0; i < 18; ++i){
    resists[types[i]];
  }

  for (size_t i = 1; i < argc; ++i){
    if (strcmp(argv[i], "fire") == 0){
      temp = fire();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "water") == 0){
      temp = water();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "electric") == 0){
      temp = electric();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "grass") == 0){
      temp = grass();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "ice") == 0){
      temp = ice();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "fighting") == 0){
      temp = fighting();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "poison") == 0){
      temp = poison();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "ground") == 0){
      temp = ground();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "flying") == 0){
      temp = flying();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "psychic") == 0){
      temp = psychic();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "bug") == 0){
      temp = bug();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "rock") == 0){
      temp = rock();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "ghost") == 0){
      temp = ghost();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "normal") == 0){

    }
    if (strcmp(argv[i], "dragon") == 0){
      temp = dragon();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "dark") == 0){
      temp = dark();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "steel") == 0){
      temp = steel();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
    if (strcmp(argv[i], "fairy") == 0){
      temp = fairy();
      for (iter = temp.begin(); iter != temp.end(); ++iter){
        resists[types[*iter]]++;
      }
    }
  }
  std::map<std::string, int>::iterator it;
  int counter = 0;
  for (it = resists.begin(); it != resists.end(); ++it){
    std::cout << it->first << " - " << it->second << std::endl;
    if (it->second < 3){
      counter += it->second;
    }
    else{
      counter += 2;
    }
  }
    std::cout << "total: " << counter << std::endl;
}
