#include "aes.h"

int main() {
    uint8_t plaintext[16] = {
            0x00, 0x11, 0x22, 0x33,
            0x44, 0x55, 0x66, 0x77,
            0x88, 0x99, 0xaa, 0xbb,
            0xcc, 0xdd, 0xee, 0xff
    };
    printf("Plaintext message:\n");
    printext(plaintext);

    uint8_t key[16] = {
            0x2e, 0x46, 0x0d, 0x11,
            0x01, 0xa9, 0x85, 0xb2,
            0x29, 0x30, 0xaf, 0x76,
            0xa2, 0xe1, 0x7d, 0xa8
    };
    printf("Key used:\n");
    printext(key);

    uint8_t *ciphertext = encryption(plaintext, key);
    printf("Ciphertext message:\n");
    printext(ciphertext);
    free(ciphertext);

    return 0;
}