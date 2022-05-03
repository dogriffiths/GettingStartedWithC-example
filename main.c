#include <stdio.h>

int main() {

    puts("Please tell me your name");

    char name[100];
    fgets(name, 100, stdin);

    printf("Welcome, %s!\n", name);

    return 0;
}