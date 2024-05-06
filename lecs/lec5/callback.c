/* callback.c
* ----------------
* Implementing generic functions that use callbacks
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* -----------------
* Return the maximum value in an array
* 
* Questions/Tasks to convert to generic:
* Q1: What type should arr be?
* A1:
* Q2: What should find_max return?
* A2:
* Q3: How do we get the address of the ith element of an arr?
* A3:
* Q4: How do we compare an array element to the max we've seen so far?
* A4:
*/
int find_max(int *arr, size_t elems)
{
    int max = arr[0];
    for (int i = 0; i < elems; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}