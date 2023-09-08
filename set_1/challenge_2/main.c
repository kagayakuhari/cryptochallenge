#include "fixedxor.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024

int main(void) {

  char *xor1, *xor2 = NULL;
  unsigned char *output_data;
  size_t xor1_len, xor2_len;

  // Allocate memory for both inputs
  xor1 = (char *)calloc(MAX_LEN, sizeof(char));
  if (!xor1) {
    fprintf(stderr, "%s\n", "Allocation of memory for input data 1 failed.");
    goto cleanup;
  }
  xor2 = (char *)calloc(MAX_LEN, sizeof(char));
  if (!xor2) {
    fprintf(stderr, "%s\n", "Allocation of memory for input data 2 failed.");
    goto cleanup;
  }

  // Get data
  printf("%s\n", "Input your first string: ");
  if (!(fgets(xor1, MAX_LEN, stdin))) {
    fprintf(stderr, "%s\n", "Error getting input data.");
    goto cleanup;
  }
  printf("%s\n", "Input your second string: ");
  if (!(fgets(xor2, MAX_LEN, stdin))) {
    fprintf(stderr, "%s\n", "Error getting input data.");
    goto cleanup;
  }

  // Compare sizes and remove '\n'
  xor1_len = strlen(xor1);
  xor2_len = strlen(xor2);
  if (xor1_len != xor2_len) {
    fprintf(stderr, "%s\n", "Inputs must be of equal length.");
    goto cleanup;
  }
  if (xor1_len > 0 && xor1[xor1_len - 1] != '\0') {
    xor1[xor1_len - 1] = '\0';
    xor2[xor2_len - 1] = '\0';
  }

  if (!(output_data = fixedxor(xor1, xor2, xor1_len))) {
    fprintf(stderr, "%s\n", "Error in XOR function.");
    free(output_data);
    goto cleanup;
  }

  // Show result in hex because string is most defintely broken
  for (int i = 0; i < xor1_len; i++)
    printf("%02x", output_data[i]);
  printf("\n");
  free(output_data);
  return 0;

cleanup:
  free(xor1);
  free(xor2);
  return -1;
}
