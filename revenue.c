//
// Created by Samir Buch on 1/25/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printCloser();

int main() {

    float itemPrice;
    float itemQuantity;

    double _throwaway;

    printf("Welcome to \"Temple\" store\n\n");

    printf("\tEnter item price: ");
    scanf("%f", &itemPrice);

    if(itemPrice <= 0) {
        printf("\n\tThis is not a valid item price.\n\tPlease run the program again\n");
        printCloser();
        exit(1);
    }

    printf("\tEnter quantity: ");
    scanf("%f", &itemQuantity);

    if(itemQuantity <= 0) {
        printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again\n");
        printCloser();
        exit(1);
    }

    double itemQuantityFP = modf(itemQuantity, &_throwaway);
    if(itemQuantityFP != 0) {
        printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again\n");
        printCloser();
        exit(1);
    }

    float subtotal = itemPrice * itemQuantity;

    printf("\n");
    printf("\tThe item price is: $%.2f\n", itemPrice);
    printf("\tThe order is: %.0f item(s)\n", itemQuantity);
    printf("\tThe cost is: $%.2f\n", subtotal);

    float discountRate;

    if(itemQuantity >= 150) {
        discountRate = 0.25;
    } else if (itemQuantity <= 149 && itemQuantity >= 100) {
        discountRate = 0.15;
    } else if (itemQuantity <= 99 && itemQuantity >= 50) {
        discountRate = 0.1;
    } else if (itemQuantity <= 49 && itemQuantity >= 1) {
        discountRate = 0;
    } else {
        printf("\tSomething has gone horribly wrong.\n\tYou should never see this error.\n\tPlease run the program again\n");
        printCloser();
        exit(1);
    }

    printf("\tThe discount is: %.1f%%\n", discountRate * 100);

    float discountAmount = subtotal * discountRate;
    printf("\tThe discount amount is: $%.2f\n", discountAmount);

    float total = subtotal - discountAmount;
    printf("\tThe total is: $%.2f\n", total);

    printCloser();

    return 0;
}

void printCloser() {
    printf("\nThank You for using \"Temple\" store\n");
}