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
 * @file stats.h
 * @brief Header file for statistical analysis functions.
 *
 * This header file provides the declarations of functions that
 * perform various statistical analyses on a data set, such as
 * finding the mean, median, maximum, and minimum values.
 *
 * @author Cole Eastlund
 * @date 8/30/2024
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * Given an array of unsigned char data items, this function prints
 * the minimum, maximum, mean, and median of the data set.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return void
 */
void print_statistics(unsigned char array[], unsigned int size);

/**
 * @brief Prints an array of data.
 *
 * Given an array of unsigned char data items, this function prints
 * the array to the screen.
 *
 * @param array The array of data to print.
 * @param size The number of elements in the array.
 *
 * @return void
 */
void print_array(unsigned char array[], unsigned int size);

/**
 * @brief Finds the median of the data set.
 *
 * Given an array of unsigned char data items, this function returns
 * the median value.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return unsigned char The median of the data set.
 */
unsigned char find_median(unsigned char array[], unsigned int size);

/**
 * @brief Finds the mean of the data set.
 *
 * Given an array of unsigned char data items, this function returns
 * the mean value.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return unsigned char The mean of the data set.
 */
unsigned char find_mean(unsigned char array[], unsigned int size);

/**
 * @brief Finds the maximum of the data set.
 *
 * Given an array of unsigned char data items, this function returns
 * the maximum value.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return unsigned char The maximum of the data set.
 */
unsigned char find_maximum(unsigned char array[], unsigned int size);

/**
 * @brief Finds the minimum of the data set.
 *
 * Given an array of unsigned char data items, this function returns
 * the minimum value.
 *
 * @param array The array of data to analyze.
 * @param size The number of elements in the array.
 *
 * @return unsigned char The minimum of the data set.
 */
unsigned char find_minimum(unsigned char array[], unsigned int size);

/**
 * @brief Sorts the array from largest to smallest.
 *
 * Given an array of unsigned char data items, this function sorts
 * the array in descending order.
 *
 * @param array The array of data to sort.
 * @param size The number of elements in the array.
 *
 * @return void
 */
void sort_array(unsigned char array[], unsigned int size);

#endif /* __STATS_H__ */
