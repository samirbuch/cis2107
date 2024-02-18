//
// Created by Samir Buch on 2/18/24.
//

#include <stdio.h>
#include <stdbool.h>

size_t max(size_t rows, size_t columns, const int array[rows][columns]);

size_t rowSum(size_t rowLength, const int array[rowLength]);

size_t columnSum(size_t columnToSum, size_t rows, size_t columns, const int array[rows][columns]);

bool isSquare(size_t rows, size_t columns);

void displayOutputs(size_t rows, size_t columns, const int array[rows][columns]);

int main(void) {
    puts("Let's create a 2-dimensional array!");

    int rows = 0;
    int columns = 0;

    printf("How many rows? ");
    scanf("%d", &rows);
    printf("How many columns? ");
    scanf("%d", &columns);

    int array[rows][columns]; // Cannot initialize. Oh well

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("enter array[%i][%i]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    puts("");

    puts("Here is your 2-dimensional array:");
    displayOutputs(rows, columns, array);

    puts("");

    for (int row = 0; row < rows; row++) {
        printf("Sum of row %i: ", row + 1);
        int sumOfRow = rowSum(columns, array[row]); // Columns = length of row
        printf("%d\n", sumOfRow);
    }

    puts("");

    for (int col = 0; col < columns; col++) {
        printf("Sum of column %i: ", col + 1);
        int sumOfCol = columnSum(col, rows, columns, array);
        printf("%d\n", sumOfCol);
    }

    puts("");

    bool isSquareArray = isSquare(rows, columns);
    if (isSquareArray == true) puts("This is a square array.");
    else puts("This is not a square array.");

    puts("");

    printf("Maximum number in the entire array: %zu\n",
           max(rows, columns, array)
    );

    return 0;
}

void displayOutputs(size_t rows, size_t columns, const int array[rows][columns]) {
    for (int i = 0; i < rows; ++i) {
        printf("[");
        for (int j = 0; j < columns; ++j) {
            if (j + 1 == columns) printf("%d", array[i][j]);
            else printf("%d, ", array[i][j]);
        }
        printf("]\n");
    }
}

size_t rowSum(size_t rowLength, const int array[rowLength]) {
    size_t acc = 0;
    for (int i = 0; i < rowLength; i++) {
        acc += array[i];
    }
    return acc;
}

// hmm. how do i get rid of the `columns` parameter?
size_t columnSum(size_t columnToSum, size_t rows, size_t columns, const int array[rows][columns]) {
    size_t acc = 0;
    for (int j = 0; j < rows; j++) {
        acc += array[j][columnToSum];
    }
    return acc;
}

bool isSquare(size_t rows, size_t columns) {
    return rows == columns; // ?????? way too easy
}

// The way we're filling the array, I could just keep track of the
// numbers the user puts in and update the biggest one each time.
// But, here it is in function form.
size_t max(size_t rows, size_t columns, const int array[rows][columns]) {
    int acc = array[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (array[i][j] > acc) acc = array[i][j];
        }
    }

    return acc;
}

