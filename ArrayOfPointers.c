/*
Name:
Date:
Course: CSI2107
HW#: Lab 05: “Arrays of Pointers to Functions”

Objective: To design and implement array of function pointer.

The purpose of this program is to modify existing code related to exam selecting
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average.

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int students, int exams, int grades[students][exams]);

void minimum(int students, int exams, int grades[students][exams]);

void maximum(int students, int exams, int grades[students][exams]);

void average(int students, int exams, int grades[students][exams]);

int randomNumber(int lo, int hi);

int clamp(int d, int min, int max);

int main() {

    // seed random number generator
    srand(time(NULL));

    int students = 0;
    int exams = 0;

    printf("Enter the number of students: ");
    scanf("%u", &students);
    printf("Enter the number of exams: ");
    scanf("%u", &exams);

    puts("");

    int grades[students][exams];

//    puts("Seeding grade data...");

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            grades[i][j] = randomNumber(0, 100);
        }
    }

//    printArray(students, exams, grades);

    void (*functions[4])(int, int, int[students][exams]) = {
            printArray,
            minimum,
            maximum,
            average
    };

    puts("");

    int sentinel = -1;
    while (sentinel != 4) {
        puts("Enter a choice:");
        puts("\t0: Print the array of grades");
        puts("\t1: Find the minimum grade");
        puts("\t2: Find the maximum grade");
        puts("\t3: Print the average on all tests for each student");
        puts("\t4: End Program");
        puts("");

        scanf("%d", &sentinel);

        if (sentinel >= 0 && sentinel <= 3) {
            (*functions[sentinel])(students, exams, grades);
        }

        puts("");

    }

    puts("Thank you, goodbye.");

    return 0;
}

int clamp(int d, int min, int max) {
    const int t = d < min ? min : d;
    return t > max ? max : t;
}

int randomNumber(int lo, int hi) {
    int num = clamp(
            rand() % hi,
            lo,
            hi
    );
    return num;
}

void printArray(int students, int exams, int grades[students][exams]) {
    printf("     Exam: ");
    for (int i = 0; i < exams; i++) {
        printf("%4i", i + 1);
    }
    printf("\n");

    for (int student = 0; student < students; student++) {
        printf("Student %i: ", student + 1);
        for (int exam = 0; exam < exams; exam++) {
            printf("%4i", grades[student][exam]);
        }
        printf("\n");
    }
}

void minimum(int students, int exams, int grades[students][exams]) {
    int minimumScore = grades[0][0];
    for (int student = 0; student < students; student++) {
        for (int exam = 0; exam < exams; exam++) {
            int thisScore = grades[student][exam];
            if (thisScore < minimumScore) minimumScore = thisScore;
        }
    }

    printf("Minimum score attained: %i\n", minimumScore);
}

void maximum(int students, int exams, int grades[students][exams]) {
    int maximumScore = grades[0][0];
    for (int student = 0; student < students; student++) {
        for (int exam = 0; exam < exams; exam++) {
            int thisScore = grades[student][exam];
            if (thisScore > maximumScore) maximumScore = thisScore;
        }
    }

    printf("Maximum score attained: %i\n", maximumScore);
}

void average(int students, int exams, int grades[students][exams]) {
    for(int student = 0; student < students; student++) {
        float avg = 0;
        for(int exam = 0; exam < exams; exam++){
            avg += (float) grades[student][exam];
        }
        avg /= (float) exams;

        printf("Average exam score for student %i: %.2f\n", student + 1, avg);
    }
}
