#include <algorithm>
#include "scoring.h"
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

#define TOTAL_CHAR_NUM 127

// From Wikipedia: https://en.wikipedia.org/wiki/Letter_frequency
// In alphabetical order
const double frequency[26] = {
    8.2, 1.5, 2.8, 4.3,   12.7, 2.2, 2.0, 6.1, 7.0,  0.15, 0.77, 4.0, 2.4,
    6.7, 7.5, 1.9, 0.095, 6.0,  6.3, 9.1, 2.8, 0.98, 2.4,  0.15, 2.0, 0.074};

const char* hexToASCII(const char* c_hex) {
    std::string ascii, hex(c_hex);
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byte = hex.substr(i, 2);
        char chr = (char) strtol(byte.c_str(), nullptr, 16);
        ascii.push_back(chr);
    }

        // Allocate memory for C
        char* result = (char*) malloc(ascii.size() + 1); // For NULL byte
        strcpy(result, ascii.c_str());

    return result;
}

double score(std::string data) {
  double score = 0.0;
  int frequency_pos, i = 0;
  char lower_c;

  for (char c : data) {
    if (isalpha(c)) {
      lower_c = tolower(c);
      frequency_pos =
          lower_c - 'a'; // Get position of char in our frequency list
      score += frequency[frequency_pos]; // Save similarity
      i++; // Number of actual letters we worked with
    }
  }

  if (i==0) {
  return 0;
  }

  return score / i;
}

std::string xorDecryptSingleChar(std::string data, char key) {
  std::string output;
  for (char c : data) {
    output.push_back(c ^ key);
  }
  return output;
}

char singleByteXORCipher(const char *c_data, size_t data_length,
                         const char *c_candidate_str) {
  std::string data(c_data), decrypted, candidate_str;
  char c, candidate_c = 0;
  double current_score, highest_score = 100000;

  // Loop through all chars
  for (c = 0; c < TOTAL_CHAR_NUM; c++) {
    decrypted = xorDecryptSingleChar(data, c);
    current_score = score(decrypted);
    std::cout << "Result: " << decrypted << std::endl;
    std::cout << "Key: " << c << std::endl;
    std::cout << "Socore: " << current_score << std::endl;
    if (current_score < highest_score) {
      highest_score = current_score;
      candidate_c = c;
      candidate_str = decrypted;
      std::cout << "Result: " << candidate_str << std::endl;
      std::cout << "Key: " << candidate_c << std::endl;
      std::cout << "Score: " << highest_score << std::endl;
    }
  }
  // Mind C and C++ differences
  c_candidate_str = candidate_str.c_str();

  return c;
}
