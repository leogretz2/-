/* callback.c
 * ----------
 * Using callback functions with qsort */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *va, const void *vb)
{
    int a = *(int *)va, b = *(int *)vb;
    if (a<b) return -1;
    if (a>b) return 1;
    return 0;
}

int main(int argc, char *argv[])
{
    int nums[] = {40,19,23,45,12,45,23};
    int count = sizeof(nums)/sizeof(nums[0]);

    qsort(nums, count, sizeof(nums[0]), cmp_int);
    printf("Array of numbers: ");
}