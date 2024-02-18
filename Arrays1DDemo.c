//
// Created by Samir Buch on 2/8/24.
// CIS 2107 / 003
// Lab number 4
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// All these function declarations are getting annoying.
#include "Arrays1DDemo.h"
// Consider thee banishéd

int main(void) {

    // Seed the random number generator
    srand(time(NULL)); // grr seeding with a predictable value
    // i would have loved to seed from /dev/urandom, but I don't know how.

    unsigned int num_elements = 0;
    printf("%s", "Enter the number of elements you would like: ");
    scanf("%d", &num_elements);

    int rand_min, rand_max = 0;
    printf("%s", "Enter the lower and upper bounds: ");
    scanf("%d %d", &rand_min, &rand_max);

    int array[num_elements];

    fill_array(num_elements, array, rand_min, rand_max);

    pretty_print_array(num_elements, array);
    puts("");

    int start_index = 0;
    int end_index = 0;
    printf("%s", "Enter the lower and upper indices to search for a maximum number: ");
    scanf("%d %d", &start_index, &end_index);

    if(start_index < 0 || end_index > num_elements - 1) {
        fprintf(stderr, "%s", "Invalid starting or ending indices.\n");
        exit(EXIT_FAILURE);
    }

    findWithRange(array, start_index, end_index);
    puts("");

    puts("Original:");
    pretty_print_array(num_elements, array);
    puts("");

    puts("Reversed:");
    int reversed_array[num_elements];
    reverseArray(num_elements, array, reversed_array);
    pretty_print_array(num_elements, reversed_array);
    puts("");

    int start_reversed_index = 0;
    int end_reversed_index = 0;
    printf("%s", "Enter the lower and upper indices from which to slice the array and reverse the slice: ");
    scanf("%d %d", &start_reversed_index, &end_reversed_index);

    reverseSelectedRangeWithinArray(array, start_reversed_index, end_reversed_index);
    pretty_print_array(num_elements, array);

    puts("");

    int num_1 = 0;
    int num_2 = 0;
    printf("Enter two numbers to find in sequence in the array: ");
    scanf("%d %d", &num_1, &num_2);

    int foundInSequence = findSequence(num_elements, array, num_1, num_2);
    if(foundInSequence == -1) {
        puts("Sequence not found in the array.");
    } else {
        printf("Sequence first found at index %d\n", foundInSequence);
    }

    return 0;
}

int clamp(int d, int min, int max) {
    const int t = d < min ? min : d;
    return t > max ? max : t;
}

void pretty_print_array(unsigned int n_elements, const int* array) {
    for(int i = 0; i < n_elements; i++) {
        printf("%4d", array[i]);
        if((i + 1) % 10 == 0) puts("");
    }
}

void fill_array(unsigned int n_elements, int* array, int rand_min, int rand_max) {
    for(int i = 0; i < n_elements; i++) {
        int num = clamp(
                rand() % rand_max,
                rand_min,
                rand_max
                );
        array[i] = num;
    }
}

int findWithRange(int* array, int start_index, int end_index) {
    if(start_index > end_index) {
        fprintf(stderr, "Error: starting index is greater than ending index.\n");
        exit(EXIT_FAILURE);
    }

    int max = array[start_index];
    for(int i = start_index; i <= end_index; i++) {
        printf("%4d", array[i]);
        if(array[i] > max) max = array[i];
    }
    puts("");

    printf("Max = %d\n", max);

    return max;
}

void reverseArray(unsigned int n_elements, const int* input_array, int* reversed_array) {
    for(unsigned int i = n_elements; i > 0; i--) {
        reversed_array[n_elements - i] = input_array[i - 1];
    }
}

void reverseSelectedRangeWithinArray(int* array, int start_index, int end_index) {
    int reversedRange[end_index - start_index];

    for(int i = end_index; i > start_index; i--) {
        reversedRange[end_index - i] = array[i - 1];
    }
    for(int i = start_index; i < end_index; i++) {
        array[i] = reversedRange[i];
    }

    // This is O(2n). not sure how i feel about that.
    // I could make it O(n/2)
}

int findSequence(unsigned int n_elements, const int* array, int num_1, int num_2) {
    for(int i = 0; i < n_elements - 1; i++) {
        if(array[i] == num_1 && array[i + 1] == num_2) return i;
    }
    return -1;
}
