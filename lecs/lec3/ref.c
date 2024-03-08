/* ref.c
* -------
* Demonstrate pass-by-reference in C */
#include <stdio.h>

void change(int *p) // void change(int x)
{
    *p += 10; // x += 10;
    printf("In change: %d\n", *p); //printf("In change: %d \n", x);
}

int main(int argc, char *argv[])
{
    int num = 107;
    printf("Before: %d\n",num);
    change(&num); // change(num);
    printf("After: %d\n",num);

    return 0;
}