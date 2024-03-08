#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int musl_atoi(const char *s)
{
    while (isspace(*s)) {
        s++;
    }

    bool negative = false;
    switch (*s) {
        case '-':
            negative = true;
        case '+':
            s++;
    }

    /* Compute as a negative number to avoid overflow on INT_MIN */
    int number = 0;
    while (isdigit(*s)) {
        number = 10 * number - (*(s++) - '0');
    }

    return negative ? number : -number;
}

int main(int argc, char *argv[])
{
    printf("%d,%d,%d\n", argc, **argv, **(argv+1));
    printf("%d\n",atoi("3.14 binky"));
}