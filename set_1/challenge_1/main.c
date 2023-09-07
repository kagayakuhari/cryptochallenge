#include "hex2base64.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main(void) {
  char *data, *output_data;
  size_t data_length;

  // Allocate memory for input and output data
  data = (char *)calloc(MAX_LEN, sizeof(char));
  if (!data) {
    fprintf(stderr, "%s\n", "Allocation of memory for input data failed.");
    return -1;
  }

  output_data = (char *)calloc(MAX_LEN, sizeof(char));
  if (!output_data) {
    fprintf(stderr, "%s\n", "Allocation of memory for output data failed.");
    return -1;
  }

  // Get input data
  printf("%s\n", "Input your string: ");
  if (!(fgets(data, MAX_LEN, stdin))) {
    fprintf(stderr, "%s\n", "Error getting input data.");
    free(data);
    free(output_data);
    return -1;
  }

  // Make 'data' into a proper string just in case we want to work with it in
  // the future
  data_length = strlen(data);
  if (data_length > 0 && data[data_length - 1] != '\0')
    data[data_length - 1] = '\0';

  // Encode into base64
  // Don't encode last character (null character)
  if (!(output_data = hex2base64(data, data_length - 1))) {
    fprintf(stderr, "%s\n", "Encode error.");
    free(data);
    free(output_data);
    return -1;
  }

  // Print output
  printf("%s\n", output_data);

  // Cleanup
  free(data);
  free(output_data);
  return 0;
}
