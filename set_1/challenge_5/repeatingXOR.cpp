#include "repeatingXOR.h"
#include <string>

std::string key = "ICE";

std::string single_character_xor(char c, char key) {
  std::string output;
  output.push_back(c ^ key);
  return output;
}

std::string repeating_XOR(std::string data) {
  int i = 0;
  std::string output;

  for (char c : data) {
    output += single_character_xor(c, key[i % key.length()]);
    i++;
  }

  return output;
}
