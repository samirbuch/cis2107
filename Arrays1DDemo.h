//
// Created by Samir Buch on 2/8/24.
//

#ifndef CIS2107_ARRAYS1DEMO_H
#define CIS2107_ARRAYS1DEMO_H

#endif //CIS2107_ARRAYS1DEMO_H

/**
 * Clamp a number to between min & max
 * @param d The number to clamp
 * @param min Minimum number
 * @param max Maximum number
 * @return Integer between min and max
 */
int clamp(int d, int min, int max);

/**
 * Prints an integer array to stdout, formatted nicely.
 * @param n_elements Number of elements in array
 * @param array The array to print
 */
void pretty_print_array(unsigned int n_elements, const int* array);

/**
 * Fill an array with n_elements with random numbers between rand_min & rand_max inclusive
 * @param n_elements Number of elements in the array
 * @param array The array to fill
 * @param rand_min Minimum random number
 * @param rand_max Maximum random number
 */
void fill_array(unsigned int n_elements, int* array, int rand_min, int rand_max);

/**
 * Find the maximum number within a slice of the array
 * @param array The array to search
 * @param start_index Start index of the slice
 * @param end_index End index of the slice
 * @return Maximum integer between start_index and end_index
 */
int findWithRange(int* array, int start_index, int end_index);

/**
 * Reverses the elements of input_array, stored in revered_array
 * @param n_elements Number of elements in the array
 * @param input_array Input array
 * @param reversed_array Array with indices reversed
 */
void reverseArray(unsigned int n_elements, const int* input_array, int* reversed_array);

/**
 * Reverse the elements IN PLACE in the selected slice of the array
 * <h3>Warning: This function modifies the original array</h3>
 * @param array The array to select the slice from
 * @param start_index Start index from which to slice
 * @param end_index Ending index from which to slice
 */
void reverseSelectedRangeWithinArray(int* array, int start_index, int end_index);

/**
 * Finds the first index of a sequence of numbers in a given array
 * @param n_elements Length of the array
 * @param array The array
 * @param num_1 Number 1 in the sequence
 * @param num_2 Number 2 in the sequence
 * @return The integer index of the first instance of the sequence in the array
 */
int findSequence(unsigned int n_elements, const int* array, int num_1, int num_2);