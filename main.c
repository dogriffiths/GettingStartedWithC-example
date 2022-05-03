#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "io.h"

#ifdef FRENCH
#define ASK_FOR_NAME "Veuillez me dire votre nom"
#else
#define ASK_FOR_NAME "Please tell me your name"
#endif

#define SCORE(x) (2.0f / (float)(x))

typedef struct Ranking {
    char name[100];
    float score;
} Ranking;

Ranking high_scores[3];

void add_score(char name[], float score) {
    for (int i = 0; i < 3; i++) {
        if(high_scores[i].score < score) {
            for(int j = 2; j > i; j--) {
                high_scores[j] = high_scores[j - 1];
            }
            strcpy(high_scores[i].name, name);
            high_scores[i].score = score;
            break;
        }
    }
}

void display_high_scores() {
    puts("High scores:\n");

    for(int i = 0; i < 3; i++) {
        printf("%d: %s $%.2f\n", i + 1, high_scores[i].name, high_scores[i].score);
    }
}

int main() {
    srand(time(0));

    while(1) {
        puts(ASK_FOR_NAME);

        char name[100];

        get_string(name, 100);

        if (strlen(name) == 0)
            break;

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

        float score = SCORE(attempts);

        printf("You won $%.2f\n", score);

        add_score(name, score);

        display_high_scores();
    }


    return 0;
}
