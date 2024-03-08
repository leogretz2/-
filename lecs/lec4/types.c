/* types.c
 * -------
 * Exploration of sizeof and 
*/
#include <stdio.h>

void size_params(int arr[], int *ptr)
{
    printf("sizeof(arr) (as param) = %zu\n", sizeof(arr));
    printf("sizeof(ptr) (as param) = %zu\n", sizeof(ptr));
}

void test_sizeof()
{
    int i = 107;
    double d = 3.14159;
    int *ip = &i;
    char *str = "CS107";
    printf("sizeof(i) = %zu\n", sizeof(i));
    printf("sizeof(d) = %zu\n", sizeof(d));
    printf("sizeof(ip) = %zu\n", sizeof(ip));
    printf("sizeof(str) = %zu\n", sizeof(str));
    printf("\n");

    /* Shorthand for: int arr[3], and setting each index */
    int arr[] = {10,20,30};
    printf("sizeof(arr) = %zu\n",sizeof(arr));
    /* Only for stack arrays declared as local var in the current function */
    int count = sizeof(arr) / sizeof(arr[0]);
    printf("count = %d\n", count);
    size_params(arr,arr);
}

void cast_val()
{
    int i = 107;
    float f = 3.14159;
    printf("Cast value: (float)i = %f, (int)d = %d\n", (float)i, (int)f);
}

void cast_ptr()
{
    int i = 107;
    float f = 3.14159;
    printf("Cast pointer: *(float *)&i = %f, *(int *)&d = %d\n", *(float *)&i, *(int *)&f);
}

void cast_chars()
{
    int i = 107;
    float f = 3.14159;
    printf("Cast to char *: &i = \"%s\", &d = \"%s\"\n", (char *)&i, (char *)&f);
}

void test_typecasts()
{
    cast_val();
    cast_ptr();
    cast_chars();
}

int main()
{
    test_sizeof();
    test_typecasts();
    return 0;
}