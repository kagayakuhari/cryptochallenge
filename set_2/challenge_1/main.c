#include "pkcs7.h"
#include <stdio.h>

const char* test_string = "YELLOW SUBMARINE";

int main(void){

        const char* padded_data;

        padded_data = pkcs7(test_string, strlen(test_string));

        for(int i = 0; i < strlen(padded_data); i++){
                printf("%02x", padded_data[i]);
        }
        printf("\n");
        printf("%s\n", padded_data);
}
