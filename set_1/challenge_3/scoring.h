#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

const char* hexToASCII(const char* hex);
char singleByteXORCipher(const char* input, size_t length, const char* output);

#ifdef __cplusplus
}
#endif
