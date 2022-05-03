#include <stdio.h>
#include <string.h>
#include <stdlib.h>

short get_shorty() {
    char s[4];

    fflush(stdin);
    fgets(s, 4, stdin);
    return (short) strtol(s, 0, 0);
}

void get_string(char name[], int len) {
    fgets(name, 100, stdin);

    size_t pos = strcspn(name, "\n");

    name[pos] = '\0';
}
