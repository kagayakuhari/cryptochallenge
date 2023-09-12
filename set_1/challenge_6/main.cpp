#include "hamming.h"
#include <iostream>
#include <string>

const char *string1 = "this is a test";
const char *string2 = "wokka wokka!!!";

int main(void) {
#include<iostream>

  int hd;

  hd = hamming_distance(string1, string2);

  std::cout << hd << std::endl;

  return 0;
}
