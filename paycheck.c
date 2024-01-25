//
// Created by Samir Buch on 1/25/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printCloser();

int main() {
    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");

    float employeeNum;
    float hourlySalary;
    float weeklyTime;

    // Junk variable used to store junk values lol
    double _throwaway;

    printf("\tEnter Employee Number: ");
    // TODO: clang-tidy mentions using strtol()
    // cert-err34-c
    scanf("%f", &employeeNum);

    if(employeeNum <= 0) {
        printf("\tThis is not a valid Employee Number. \n\tPlease run the program again\n");
        printCloser();
        exit(1);
    }

    double employeeNumFP = modf(employeeNum, &_throwaway);
    if(employeeNumFP != 0) {
        printf("\t\nThis is not a valid Employee Number.\n\tPlease run the program again\n");
        printCloser();
        exit(1);
    }

    printf("\tEnter Hourly Salary: ");
    scanf("%f", &hourlySalary);

    if(hourlySalary <= 0) {
        printf("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n");
        printCloser();
        exit(1);
    }

    printf("\tEnter Weekly Time: ");
    scanf("%f", &weeklyTime);

    float regularHours;
    float overtimeHours = 0;
    if(weeklyTime > 40) {
        regularHours = 40;
        overtimeHours = weeklyTime - 40;
    } else {
        regularHours = weeklyTime;
    }

    if(weeklyTime <= 0) {
        printf("\t\nThis is not a weekly time.\n\tPlease run the program again\n");
        printCloser();
        exit(1);
    }

    printf("==============================\n");

    printf("\tEmployee #: %d\n", (int) employeeNum);
    printf("\tHourly Salary: $%.2f\n", hourlySalary);
    printf("\tWeekly Time: %.1f hours\n", weeklyTime);

    float regularPay = hourlySalary * (float) regularHours;
    printf("\tRegular Pay: $%.2f\n", regularPay);

    float overtimePay = 0;

    if(weeklyTime > 40) {
        overtimeHours = weeklyTime - 40.0;
        overtimePay = overtimeHours * (hourlySalary * 1.5);
    }
    printf("\tOvertime Pay: $%.2f\n", overtimePay);

    float netPay = regularPay + overtimePay;
    printf("\tNet Pay: $%.2f\n", netPay);

    printf("==============================\n");

    printCloser();
    return 0;
}

void printCloser() {
    printf("\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
}