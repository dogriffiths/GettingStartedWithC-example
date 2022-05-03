#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    puts("Please tell me your name");

    char name[100];
    fgets(name, 100, stdin);

    size_t pos = strcspn(name, "\n");

    name[pos] = '\0';

    printf("Welcome, %s!\n", name);

    short secret = rand() % 10 + 1;

    printf("The secret is %d\n", secret);

    char guessText[4];

    fgets(guessText, 4, stdin);
    short guess = (short)strtol(guessText, 0, 0);

    printf("Your guess was %d\n", guess);

    return 0;
}