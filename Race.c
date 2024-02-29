//CIS2017 Lab7: Race
//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator();

void tortMove(int *tPtr);

void hareMove(int *hPtr);

void printRace(int hPos, int tPos);

int main() {
    srand((unsigned) time(NULL));

    int hPos = 1;                        // hare start position is 1, cannot slip past 1
    int tPos = 1;                        // tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");    // the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");    // the spacing is modeled after the sample

    while (hPos < 70 && tPos < 70) {
//        sleep(1);                        // slows down the race
        hareMove(&hPos);
        tortMove(&tPos);

        // Accounting for slips at start
        if (hPos < 1) hPos = 1;
        if (tPos < 1) tPos = 1;

        // If they happen to jump past the finish line
        if (tPos > 70) tPos = 70;
        if (hPos > 70) hPos = 70;

        printRace(hPos, tPos);
        puts("");
    }

    if (hPos == 70 && tPos == 70) {
        printf("It's a tie!\n");
    } else if (hPos == 70) {
        printf("Yuch. Hare wins.\n");
    } else if (tPos == 70) {
        printf("TORTOISE WINS!!! YAY!!!\n");
    } else {
        printf("Error: illegal condition. hPos: %d & tPos: %d\n", hPos, tPos);
    }


}

//Prints the position of the H and T
void printRace(int hPos, int tPos) {
    if (hPos == tPos) {
        for (int i = 0; i < hPos; i++) printf(" ");
        printf("OUCH!!!");
    } else {
        for (int i = 0; i < 70; i++) {
            printf(" ");
            if (i == hPos) printf("H");
            if (i == tPos) printf("T");
        }
    }
    printf("\n");
}

//Controls the tortoise movement
void tortMove(int *tPtr) {
    int randomNumber = randomNumberGenerator();
    if (randomNumber >= 5) *tPtr += 3; // fast plod
    else if (randomNumber >= 3) *tPtr += 1;  // slow plod
    else *tPtr -= 6; // slip
}

//Controls the hare movement
void hareMove(int *hPtr) {
    int randomNumber = randomNumberGenerator();
    if (randomNumber >= 3) *hPtr += 1; // small hop
    else if (randomNumber >= 2) {
        int randomOfThree = rand() % 3;
        if (randomOfThree == 0) *hPtr += 0; // sleep
        else if (randomOfThree == 1) *hPtr += 9; // big hop
        else *hPtr -= 2; // small slip
    } else if (randomNumber >= 1) *hPtr -= 12; // big slip
}

//Generates random number from 1-10
int randomNumberGenerator() {
    return rand() % 10;
}
