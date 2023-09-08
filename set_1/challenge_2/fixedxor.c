#include "fixedxor.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

unsigned char *fixedxor(const char *data_1, const char *data_2,
                        const size_t in_len) {

  size_t i;
  unsigned char *output_data;

  // Account for null byte here
  if (!(output_data = (unsigned char *)calloc(in_len, sizeof(char))))
    return NULL;

  for (i = 0; i < in_len; i++) {
    output_data[i] = (data_1[i] ^ data_2[i]);
  }

  return output_data;
}
