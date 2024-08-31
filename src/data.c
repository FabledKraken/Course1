/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief
 *
 *
 *
 * @author Cole Eastlund
 * @date 08/31/2024
 *
 */

#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t *start_ptr = ptr;
    uint8_t negative = 0;

    if (data < 0) {
        negative = 1;
        data = -data;
        *ptr++ = '-';
    }

    uint32_t temp = data;
    do {
        temp /= base;
        ptr++;
    } while (temp > 0);

    *ptr = '\0';

    do {
        *--ptr = "0123456789ABCDEF"[data % base];
        data /= base;
    } while (data > 0);

    return ptr - start_ptr + 1 + negative;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int32_t sign = 1;

    if (*ptr == '-') {
        sign = -1;
        ptr++;
        digits--;
    }

    for (uint8_t i = 0; i < digits; i++) {
        result = result * base + (*ptr - '0');
        ptr++;
    }

    return result * sign;
}
