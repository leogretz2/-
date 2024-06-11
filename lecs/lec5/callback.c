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
* A1: void *
* Q2: What should find_max return?
* A2: _A pointer to_ the maximum element
* Q3: How do we get the address of the ith element of an arr?
* A3: Add size_t elemsz * i (bytes) to (char *) cast of void *arr
* Q4: How do we compare an array element to the max we've seen so far?
* A4: Pass client-supplied callback function
*/
int find_max_non_generic(int *arr, size_t nelems) {
    int max = arr[0];
    for (int i = 0; i < nelems; i++){
        if (arr[i] > max) max = arr[i];
    }
}

void *find_max(void *arr, size_t nelems, size_t elemsz,
               int (*cmpfn)(const void *, const void *))
{
    void *max = arr; /* Points to 0th elem of arr */
    for (int i = 1; i < nelems; i++) {
        void *ith = (char *)arr + elemsz*i;
        if (cmpfn(ith, max) > 0) max = ith;
    }
    return max;
}

int cmp_int(const void *va, const void *vb)
{
    int a = *(int *)va, b = *(int *)vb;
    if (a < b) return -1;
    if (b < a) return 1;
    return 0;
}

void test_ints()
{
    int nums[] = {40,19,23,45,12,45,23,99,53,12,78};
    int count = sizeof(nums) / sizeof(nums[0]);

    printf("Array of numbers: ");
    for (int i = 0; i < count; i++)
        printf("%d ", nums[i]);

    int max = *(int *)find_max(nums, count, sizeof(nums[0]), cmp_int);
    printf("Max of numbers: %d\n", max);
}

int cmp_str(const void *va, const void *vb)
{
    char *a = *(char **)va, *b = *(char **)vb;
    return strcmp(a,b);
}

void test_strs()
{
    char *strs[] = {"apple", "pear","banana","mango"};
    int count = sizeof(strs)/sizeof(strs[0]);

    printf("Array of strings: ");
    for (int i = 0; i < count; i++)
        printf("%s ", strs[i]);
    printf("\n");
    
    char *max = *(char **)find_max(strs, count, sizeof(strs[0]), cmp_str);
    printf("Max of numbers: %s\n", max);
}

int main(int argc, char *argv[])
{
    // test_ints();
    test_strs();
}