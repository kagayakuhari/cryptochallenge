#include "hex2base64.h"
#include <stdlib.h>
#include <strings.h>

static const char encode_table[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

char *hex2base64(char *hex_data, size_t in_len) {

  char *encoded_data, byte1, byte2, byte3;
  size_t out_len, padding;
  int i, j;

  // Output length must be multiple of four.
  // Blocks of 3 bytes must become 4-byte blocks.
  out_len = ((in_len + 2) / 3) * 4;

  // Check for overflow
  if (out_len < in_len)
    return NULL;

  // Allocate memory for output
  // REMEMBER TO ALLOCATE NULL BYTE AS WELL
  if (!(encoded_data = (char *)malloc(out_len + 1)))
    // Allocation failed
    return NULL;

  while (i < in_len) {
    // We get THREE BYTES from input
    byte1 = hex_data[i++];
    byte2 = (i < in_len) ? hex_data[i++] : 0;
    byte3 = (i < in_len) ? hex_data[i++] : 0;

    // Start encoding
    // We need to take 24 bits into x4 6-bits
    encoded_data[j++] =
        encode_table[byte1 >> 2]; // Shifted 2 bits, we end up with 6 bits
    encoded_data[j++] =
        encode_table[((byte1 & 0x03) << 4) |
                     (byte2 >> 4)]; // OR remaining 2 bits with 4 bits = 6 bits
    encoded_data[j++] =
        encode_table[((byte2 & 0x0F) << 2) | (byte3 >> 6)]; // Idem
    encoded_data[j++] = encode_table[byte3 & 0x3F];
  }

  // Check if we need padding
  for (padding = in_len % 3; padding > 0; padding--) {
    encoded_data[out_len - padding] = '=';
  }

  // Return encoded data
  encoded_data[out_len] = '\0';
  return encoded_data;
}
