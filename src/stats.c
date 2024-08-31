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
 * @file stats.c
 * @brief Implementation of statistical analysis functions.
 *
 * This file contains the implementations of functions that perform
 * statistical analysis on an array of data, including functions to
 * calculate the mean, median, maximum, minimum, and to sort the array.
 *
 * @author Cole Eastlund
 * @date 8/30/2024
 */

#include "platform.h"
#include "stats.h"
#include <stdio.h>

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function prints the statistical results of an array of data,
 * including the minimum, maximum, mean, and median values.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return void
 */
void print_statistics(unsigned char array[], unsigned int size) {
    printf("Minimum: %u\n", find_minimum(array, size));
    printf("Maximum: %u\n", find_maximum(array, size));
    printf("Mean: %u\n", find_mean(array, size));
    printf("Median: %u\n", find_median(array, size));
}

/**
 * @brief Prints an array of data.
 *
 * This function prints each element of the given array.
 *
 * @param array The array of data to print.
 * @param size The number of elements in the array.
 *
 * @return void
 */
void print_array(unsigned char *array, unsigned int size) {
#ifdef VERBOSE
    for (unsigned int i = 0; i < size; i++) {
        PRINTF("%u ", array[i]);
    }
    PRINTF("\n");
#endif
}

/**
 * @brief Finds the median of the data set.
 *
 * This function calculates and returns the median value of the array.
 * The array is sorted before calculating the median.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return unsigned char The median of the data set.
 */
unsigned char find_median(unsigned char array[], unsigned int size) {
    sort_array(array, size);
    if (size % 2 == 0) {
        return (array[size / 2 - 1] + array[size / 2]) / 2;
    } else {
        return array[size / 2];
    }
}

/**
 * @brief Finds the mean of the data set.
 *
 * This function calculates and returns the mean value of the array.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return unsigned char The mean of the data set.
 */
unsigned char find_mean(unsigned char array[], unsigned int size) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

/**
 * @brief Finds the maximum of the data set.
 *
 * This function finds and returns the maximum value in the array.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return unsigned char The maximum of the data set.
 */
unsigned char find_maximum(unsigned char array[], unsigned int size) {
    unsigned char max = array[0];
    for (unsigned int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/**
 * @brief Finds the minimum of the data set.
 *
 * This function finds and returns the minimum value in the array.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return unsigned char The minimum of the data set.
 */
unsigned char find_minimum(unsigned char array[], unsigned int size) {
    unsigned char min = array[0];
    for (unsigned int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

/**
 * @brief Sorts the array from largest to smallest.
 *
 * This function sorts the given array in descending order.
 *
 * @param array The array of data to sort.
 * @param size The number of elements in the array.
 *
 * @return void
 */
void sort_array(unsigned char array[], unsigned int size) {
    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = i + 1; j < size; j++) {
            if (array[i] < array[j]) {
                unsigned char temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
