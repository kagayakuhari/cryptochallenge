#include "scoring.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024

const char str1[] = "This is an English string.";
const char str2[] = "Esta es una cadena en Español.";
const char str3[] = "kkdssdajkdqw12522";
const char str4[] = "";
const char test[] =
    "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

int main(void) {
  // double s1, s2, s3, s4;

  // s1 = score(str1, strlen(str1));
  // s2 = score(str2, strlen(str2));
  // s3 = score(str3, strlen(str3));
  // s4 = score(str4, strlen(str4));

  // printf("%s\n", "The scores are:");
  // printf("%f, %f, %f, %f\n", s1, s2, s3, s4);

  // return 0;

  char c;
  char *output = NULL;
  const char *ascii_string = NULL;

  output = (char *)calloc(MAX_LEN, sizeof(char));
  if (!output) {
    fprintf(stderr, "%s\n",
            "Allocation of memory for input output data failed.");
    goto cleanup;
  }
  ascii_string = (char *)calloc(MAX_LEN, sizeof(char));
  if (!output) {
    fprintf(stderr, "%s\n",
            "Allocation of memory for input hex_to_ascci string failed.");
    goto cleanup;
  }

  // Convert HEX to ASCII
  ascii_string = hexToASCII(test);

  // Proceed to decrypt TEST string
  c = singleByteXORCipher(ascii_string, strlen(ascii_string), output);
  printf("Decrypted string: %s\n", output);
  printf("Key is: %c\n", c);

  free(output);
  return 0;

cleanup:
  free(output);
  free((void*)ascii_string);
  return -1;
}
