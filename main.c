#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "io.h"

int main() {
    srand(time(0));

    puts("Please tell me your name");

    char name[100];

    get_string(name, 100);

    printf("Welcome, %s!\n", name);

    short secret = rand() % 10 + 1;

    printf("The secret is %d\n", secret);

    puts("I am thinking of a number from 1 to 10. Can you guess what it is?");

    short guess;
    short attempts = 0;

    do {
        guess = get_shorty();

        printf("Your guess was %d\n", guess);

        if (guess > secret)
            puts("Too high!");
        else if (guess < secret)
            puts("Too low!");

        attempts++;
    } while(guess != secret);

    puts("You win!");

    float score = 2.0f / (float)attempts;

    printf("You won $%.2f\n", score);

    return 0;
}
