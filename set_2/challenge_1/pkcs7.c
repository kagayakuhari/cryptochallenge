#include "pkcs7.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BLOCK_SIZE 20
#define PADDING 0x04

// Returns number of bytes padded
int do_pad(char *data, size_t data_length, int pad_len) {

  int count;

  for (count = 0; count < pad_len; count++) {
    data[data_length + count] = PADDING;
  }

  return count;
}

// Allocates and copies to new memory.
// Returns output pointer.
char *allocate_and_copy(const char *data, size_t data_length, int alloc_size) {

  char *result;

  result = (char *)calloc(alloc_size, sizeof(char)); // Calloc adds NULLBYTE
  memcpy(result, data, data_length);

  return result;
}

// Calculates how much pad to add.
char *pkcs7(const char *data, size_t data_length) {

  int mod, pad_len, output_len;
  char *output;

  mod = data_length % BLOCK_SIZE;
  if (mod != 0) {
    pad_len = BLOCK_SIZE - mod;
    output_len = data_length + pad_len;
    output = allocate_and_copy(data, data_length, output_len + 1);
    do_pad(output, data_length, pad_len);
  } else {
    output = allocate_and_copy(data, data_length, data_length + BLOCK_SIZE + 1);
    do_pad(output, data_length, BLOCK_SIZE);
  }

  return output;
}
