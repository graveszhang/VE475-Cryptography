//
// Created by Graves Zhang on 2020/6/1.
//

#ifndef H3_AES_H
#define H3_AES_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <memory.h>

void printext(uint8_t text[0x10]); // print out the matrix as text

uint8_t *encryption(const uint8_t *text, const uint8_t *key); // aes main structure

uint8_t **gen_roundkey(const uint8_t key[0x10]); // generate the round key

uint8_t *transpose(const uint8_t text[0x10]); // Transpose the matrix for convenience of going through column

void add_roundkey(uint8_t text[0x10], uint8_t key[0x10]);

void sub_bytes(uint8_t text[0x10]);

void shift_rows(uint8_t text[0x10]);

void mix_columns(uint8_t text[0x10]);

#endif //H3_AES_H
