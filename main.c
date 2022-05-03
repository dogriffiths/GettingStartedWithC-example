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
    struct Ranking *next;
} Ranking;

//Ranking high_scores[3];

Ranking* add_score(Ranking *high_scores, char name[], float score) {
    Ranking* newItem = malloc(sizeof(Ranking));
    strcpy(newItem->name, name);
    newItem->score = score;
    newItem->next = NULL;

    Ranking* result = high_scores;

    if (high_scores == NULL)
        result = newItem;
    else if (high_scores->score < newItem->score) {
        newItem->next = high_scores;
        result = newItem;
    } else {
        Ranking *before = high_scores;
        while(before->next != NULL) {
            Ranking *after = before->next;
            if (after->score < newItem->score) {
                newItem->next = after;
                break;
            }
            before = before->next;
        }
        before->next = newItem;
    }

    return result;
}

void display_high_scores(Ranking* high_scores) {
    puts("High scores:\n");

    Ranking* i = high_scores;
    int count = 1;

    while(i != NULL) {
        printf("%d: %s $%.2f\n", count++, i->name, i->score);
        i = i->next;
    }
}

int main() {
    srand(time(0));

    Ranking* high_scores = NULL;

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

        high_scores = add_score(high_scores, name, score);

        display_high_scores(high_scores);
    }

//    free(high_scores);

    Ranking *r = high_scores;
    while(r != NULL) {
        Ranking* next = r->next;
        free(r);
        r = next;
    }

    return 0;
}
