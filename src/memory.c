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
 * @file memory.c
 * @brief Memory manipulation functions implementation
 *
 * This implementation file contains various functions that provide an abstraction
 * over memory manipulation, including setting, moving, and copying memory blocks.
 *
 * @author Alex Fosdick
 * @date April 1, 2017
 *
 */

#include "memory.h"
#include <stdint.h>
#include <stdlib.h>

/***********************************************************
 Function Definitions
***********************************************************/

/* Function to set a value of a data array */
void set_value(char * ptr, unsigned int index, char value){
    ptr[index] = value;
}

/* Function to clear a value of a data array */
void clear_value(char * ptr, unsigned int index){
    set_value(ptr, index, 0);
}

/* Function to return a value of a data array */
char get_value(char * ptr, unsigned int index){
    return ptr[index];
}

/* Function to set data array elements to a value */
void set_all(char * ptr, char value, unsigned int size){
    for(unsigned int i = 0; i < size; i++) {
        set_value(ptr, i, value);
    }
}

/* Function to clear elements in a data array */
void clear_all(char * ptr, unsigned int size){
    set_all(ptr, 0, size);
}

/* Implementation of my_memmove function */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
    if (src < dst && (src + length) > dst) {
        // Overlap case, move from the end
        src += length;
        dst += length;
        while (length--) {
            *(--dst) = *(--src);
        }
    } else {
        // No overlap case, move from the beginning
        while (length--) {
            *dst++ = *src++;
        }
    }
    return dst;
}

/* Implementation of my_memcopy function */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
    while (length--) {
        *dst++ = *src++;
    }
    return dst;
}

/* Implementation of my_memset function */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
    uint8_t * start = src;
    while (length--) {
        *src++ = value;
    }
    return start;
}

/* Implementation of my_memzero function */
uint8_t * my_memzero(uint8_t * src, size_t length) {
    return my_memset(src, length, 0);
}

/* Implementation of my_reverse function */
uint8_t * my_reverse(uint8_t * src, size_t length) {
    uint8_t * start = src;
    uint8_t * end = src + length - 1;
    uint8_t temp;

    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    return src;
}

/* Implementation of reserve_words function */
int32_t * reserve_words(size_t length) {
    return (int32_t *)malloc(length * sizeof(int32_t));
}

/* Implementation of free_words function */
void free_words(uint32_t * src) {
    free(src);
}

