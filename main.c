#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    puts("Please tell me your name");

    char name[100];
    fgets(name, 100, stdin);

    int pos = strcspn(name, "\n");

    name[pos] = '\0';

    printf("Welcome, %s!\n", name);

    int secret = rand();

    printf("The secret is %d\n", secret);

    return 0;
}