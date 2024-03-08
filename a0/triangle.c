/* File: triangle.c
 * ----------------
 * Outputs an ascii representation of the Sierpinski triangle.
 *
 * The pattern of stars is generated using a bitwise AND 
 * on the coordinates. This works due to the relationship
 * between the fractal and Pascal's triangle.
 * https://en.wikipedia.org/wiki/Sierpinski_triangle
 */

#include <error.h>
#include <stdio.h>
#include <stdlib.h>


void print_triangle(int nlevels)
{
    int size = 1 << nlevels;

    for (int row = size - 1; row >= 0; row--) {
        for (int col = 0; col < row; col++) {
            printf(" ");
        }
        for (int col = 0; col + row < size; col++) {
            printf("%c ", (col & row) ? ' ' : '*');
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int n_levels = 3;

    if (argc > 1) {
        // Unnecessary
        if (argc > 2) {
            error(1,7,"Too many arguments");
        }

        n_levels = atoi(argv[1]);
        if (n_levels > 8 || n_levels < 0) {
            error(1,5,"Number must be between 0 and 8, inclusive");
        }
    }
    print_triangle(n_levels);
    return 0;

    /////////////////////
    // DUDE'S SOLUTION //
    /////////////////////
    // int nlevels = 3;
    // if (argc > 1)
    //     nlevels = atoi(argv[1]);
    // if (nlevels > 8 || nlevels < 0){
    //     printf("next time enter an integer i. 0 <= i <= 8.\n");
    //     exit(1);
    // }
    // print_triangle(nlevels);
    // return 0;
}
