#include "hamming.h"
#include <iostream>
#include <string>

#if __cplusplus >= 202002LL
#include <bitset>
#define POPCOUNT 1
#else
#define POPCOUNT 0
#endif

#if POPCOUNT
// https://en.cppreference.com/w/cpp/numeric/popcount
int hamming_distance_bit_x86(unsigned char a, unsigned char b) {

  return __builtin_popcount(a ^ b);
}
#endif

int count_bits(unsigned char a, unsigned char b) {
  int dist = 0, i = 0;

  i = a ^ b;
  while (i) {
    dist += i & 1;
    i >>= 1;
  }
  return dist;
}

int hamming_distance(std::string str1, std::string str2) {
  int i, dist = 0;

  if (str1.length() != str2.length())
    return -1;
  for (i = 0; i < str1.length(); i++) {

#if POPCOUNT
    dist += hamming_distance_bit_x86(str1[i], str2[i]);
#else
    dist += count_bits(str1[i], str2[i]);
#endif
  }

  return dist;
}
