#include "repeatingXOR.h"
#include <iomanip>
#include <iostream>
#include <string>

const char *test1 = "Burning 'em, if you ain't quick and nimble \
                     I go crazy when I hear a cymbal";

int main(void) {

  std::string output;

  output = repeating_XOR(test1);

  for (char c : output)
    std::cout << std::hex << std::setw(2) << std::setfill('0')
              << (int)(unsigned char)c;

  std::cout << std::dec << std::endl;
}
