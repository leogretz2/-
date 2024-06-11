/* swap.c
 * ------
 * Implementing a generic swap function.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_str(char **a, char **b)
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

/* gswap
 * --------
 * Generic swap. Takes two pointers and swaps the values they point to, which should be sz bytes.
 * 
 * Questions:
 * Q1: How do we allocate space for "tmp" variable?
 * A1: Array of characters
 * Q2: How do we copy sz bytes from one location to another?
 * A2: memcpy(void *dst, void *src, size_t elemsz)
 */
void gswap(void *a, void *b, size_t sz)
{
    char tmp[sz];
    memcpy(tmp, a, sz);
    // This doesn't work because it swaps the pointers (but want i to print j and j to print i after)
    // a = b;
    // b = tmp;
    memcpy(a, b, sz);
    memcpy(b, tmp, sz);
}

int main(int argc, char *argv[])
{
    int i = 107, j = 12345;
    printf("Before: i = %d, j %d.\n", i, j);
    // swap_int(&i, &j);
    gswap(&i, &j, sizeof(int));
    printf("After: i = %d, j %d.\n", i, j);
    printf("\n");

    char *s1 = strdup("Stanford University");
    char *s2 = strdup("Computer Science");
    printf("Before: s1 = \"%s\", s2 = \"%s\".\n", s1, s2);
    // swap_str(&s1, &s2);
    // gswap(&s1, &s2, sizeof(char *)); // (1) swaps values of pointed to variables
    gswap(s1, s2, sizeof(char *)); // (2) asking to swap characters so swaps size of (char *) (i.e. 8 bytes -> 8 chars)
    printf("After: s1 = \"%s\", s2 = \"%s\".\n", s1, s2);
    printf("\n");

    double d1 = 1.0, d2 = 2.0;
    printf("Before: d1 = %f, d2 = %f.\n", d1, d2);
    gswap(&d1, &d2, sizeof(double));
    printf("After: d1 = %f, d2 = %f.\n", d1, d2);
    printf("\n");

    return 0;
}
