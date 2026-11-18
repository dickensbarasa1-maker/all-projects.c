#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* read a number safely; repeat until valid */
double readNum(void) {
    double v;
    int r;
    while ((r = scanf("%lf", &v)) != 1) {
        if (r == EOF) exit(0);
        printf("Invalid input, try again: ");
        while (getchar() != '\n');
    }
    return v;
}

void forLoop(void) {
    for (int i = 100; i >= 50; i--)
        printf("%d\n", i);
}

void atm(void) {
    double balance, amount;
    do {
        printf("Enter balance (> 0): ");
        balance = readNum();
    } while (balance <= 0);

    while (balance > 0) {
        printf("Withdraw amount: ");
        amount = readNum();
        if (amount <= 0) {
            printf("Amount must be greater than 0.\n");
            continue;
        }
        balance -= amount;
        printf("Balance: %.2f\n", balance);
    }
}

void guessGame(void) {
    int secret = rand() % 20 + 1, guess = 0, attempts = 0;
    while (guess != secret) {
        printf("Guess (1-20): ");
        guess = (int)readNum();
        if (guess < 1 || guess > 20) {
            printf("Enter a number from 1 to 20.\n");
            guess = 0;
            continue;
        }
        attempts++;
        if (guess > secret) printf("Too high!\n");
        else if (guess < secret) printf("Too low!\n");
        else printf("Congratulations!\n");
    }
    printf("Attempts: %d\n", attempts);
}

void password(void) {
    char pw[50];
    do {
        printf("Enter password: ");
        if (scanf("%49s", pw) != 1) exit(0);
    } while (strcmp(pw, "1234") != 0);
    printf("Access Granted\n");
}

int main(void) {
    srand((unsigned)time(NULL));
    printf("1.For 2.ATM 3.Guess 4.Password: ");
    int c = (int)readNum();
    if (c == 1) forLoop();
    else if (c == 2) atm();
    else if (c == 3) guessGame();
    else if (c == 4) password();
    else printf("Invalid choice.\n");
    return 0;
}
