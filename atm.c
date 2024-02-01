//
// Created by Samir Buch on 2/1/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void check_i(const int *i);

void handle_receipt(int *num_transactions);

/**
 * Displays the current balance
 * @param current_balance
 */
void display_balance(const double *current_balance);

/**
 * Withdraw an amount from the bank
 * @param current_balance Pointer to user's current balance
 * @param total_withdrawn Pointer to total amount withdrawn today
 * @return int: EXIT_SUCCESS or EXIT_FAILURE
 */
void withdraw_amount(double *current_balance, double *total_withdrawn);

/**
 *
 * @param current_balance Pointer to user's current balance
 * @param total_deposited Pointer to total amount deposited today
 */
void deposit_amount(double *current_balance, double *total_deposited);

int main(void) {
    puts("Welcome to TEMPLE ATM\n");

    int pin = 3014;

    for (int i = 0; i < 3; i++) {
        int checked_pin = 0;
        printf("Please enter your pin: ");
        scanf("%u", &checked_pin);

        if (checked_pin != pin) {
            printf("Incorrect pin. %i attempts remaining.\n", 2 - i);

            if (i == 2) {
                printf("Too many incorrect attempts. Exiting..\n");
                exit(EXIT_FAILURE);
            }

            continue;
        } else {
            break;
        }
    }

    puts(""); // Empty line

    // Starting sentinel value not equal to any of the following
    int sentinel = -1;
    double balance = 5000;
    double total_withdrawn = 0;
    double total_deposited = 0;

    int num_transactions = 0;

    puts("Welcome, Nana.");

    do {
        printf("Your current balance is: $%.2lf\n", balance);
        puts("Please enter a number from the following menu, then press enter:\n");

        // Withdraw vs Withdrawal?
        // https://www.yourdictionary.com/articles/withdraw-vs-withdrawal-clarity

        puts("\t1 - Check balance");
        puts("\t2 - Withdraw Amount");
        puts("\t3 - Deposit Amount");
        puts("\t0 - Exit");

        printf("\n>> ");
        scanf("%i", &sentinel);

        switch (sentinel) {
            // Display balance
            case 1: {
                display_balance(&balance);
                break;
            }
            // Withdraw an amount
            case 2: {
                withdraw_amount(&balance, &total_withdrawn);
                handle_receipt(&num_transactions);
                break;
            }
            // Deposit an amount
            case 3: {
                deposit_amount(&balance, &total_deposited);
                handle_receipt(&num_transactions);
                break;
            }
            // Exit
            case 0: {
                break; // Handled by end of while loop.
            }
            default: {
                puts("Invalid menu item. Please select from 1, 2, 3, or 0.\n");
                continue;
            }
        }

    } while (sentinel != 0);

    printf("Total transactions: %i\n", num_transactions);
    puts("\nThank you for using TEMPLE ATM services.");

    return EXIT_SUCCESS;

}

void check_i(const int *i) {
    printf("You have %i attempts remaining\n", 2 - *i);

    if(*i == 2) {
        puts("Too many incorrect attempts. Exiting...");
        exit(EXIT_FAILURE);
    }
}

void handle_receipt(int *num_transactions) {
    int receipt = -1;
    printf("Would you like a receipt? [1 = yes, 0 = no]\n");
    scanf("%i", &receipt);

    if (receipt == 1) {
        puts("Printing receipt...");
        *num_transactions += 1;
    } // Handle any other response as "no"
}

// did this HAVE to be a function?
void display_balance(const double *current_balance) {
    printf("Current balance: $%.2lf\n", *current_balance);
}

void withdraw_amount(double *current_balance, double *total_withdrawn) {
    for (int i = 0; i < 3; i++) {
        double amount_to_withdraw = 0;

        printf("Please enter an amount up to $1000 that you'd like to withdraw: ");
        scanf("%lf", &amount_to_withdraw);

        double integer_withdraw = 0;
        double fraction = modf(amount_to_withdraw, &integer_withdraw);
        if(fraction != 0) {
            puts("You may not withdraw an amount of cents.");
            check_i(&i);

            continue;
        }

        if((int) integer_withdraw % 20 != 0) {
            puts("You may only withdraw in multiples of 20.");
            check_i(&i);

            continue;
        }

        if (amount_to_withdraw + *total_withdrawn > 1000) {
            puts("You may not withdraw more than $1,000 per day.");
            check_i(&i);

            continue;
        }

        if(amount_to_withdraw < 0) {
            puts("You may not withdraw less than $0.");
            check_i(&i);

            continue;
        }

        if (amount_to_withdraw == 0) {
            puts("Aborting withdraw...");

            break;
        }

        // * = Dereference operator
        // Not to be confused with & = address of operator
        *current_balance -= amount_to_withdraw;
        *total_withdrawn += amount_to_withdraw;

        break;
    }

}

void deposit_amount(double *current_balance, double *total_deposited) {
    for(int i = 0; i < 3; i++) {
        double amount_to_deposit = 0;

        printf("Please input the amount up to $10000 you'd like to deposit: ");
        scanf("%lf", &amount_to_deposit);

        double integer_deposit = 0;
        double fraction = modf(amount_to_deposit, &integer_deposit);
        if(fraction != 0) {
            puts("You may not deposit an amount of cents.");
            check_i(&i);

            continue;
        }

        if(amount_to_deposit + *total_deposited > 10000) {
            puts("You may not deposit more than $10000 in a day.");
            check_i(&i);

            continue;
        }

        if(amount_to_deposit < 0) {
            puts("You may not deposit less than $0.");
            check_i(&i);

            continue;
        }

        if(amount_to_deposit == 0) {
            puts("Aborting deposit...");

            break;
        }

        *current_balance += amount_to_deposit;
        *total_deposited += amount_to_deposit;

        break;
    }
}

// This whole program would be a lot cleaner if I could pass
// functions as arguments. Imagine:
/*
 * void failure_loop(int func) {
 *  for(int i = 0; i < 3; i++) {
 *    if(i == 2) {
 *      puts("Too many failed attempts.");
 *      exit(EXIT_FAILURE);
 *    }
 *
 *    // THIS CALLS THE WHOLE FUNCTION OVER AGAIN!
 *    int result = func();
 *    if(result == EXIT_FAILURE) {
 *      puts("Invalid input");
 *    } else {
 *      break;
 *    }
 *  }
 * }
*/