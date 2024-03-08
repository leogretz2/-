/* cstr.c
* -------
* Fun with C-strings, pointers, and memory leaks. */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* lowercase1
* ------------
* Converts str's chars to lowercase. No copy, no memory allocation
* chars are modified in the given string. Returns the same pointer passed as param.
*
* Works for many situations. But what if the string is read-only? */
char *lowercase1(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
    return str; /* Unnecessary to return since changing the value of the pointer in place */
}

/* lowercase2
* -----------
* Attempts to create and return a new string. But no memory is allocated -- instead 
* we write to an uninitialized pointer. What will happen?
*
* Note that str is marked "const", indicating that the chars within will not be modified. */
char *lowercase2(const char *str)
{
    char *copy; /* BUG: pointer not initialized, garbage address */
    for (int i = 0; i<=strlen(str); i++) /* i<=strlen(str) to account for \0 at end of strings */
        copy[i] = tolower(str[i]);
    return copy;
}

/* lowercase3
* -----------
* Creates new string, and allocates memory for it ... on the stack.
* What happens to that memory after the function returns? How will this show
* up when running the program? */
char *lowercase3(const char *str)
{
    char copy[strlen(str)+1]; /* array on the stack, correct size */
    for (int i = 0; i<=strlen(str); i++)
        copy[i] = tolower(str[i]);
    return copy; /* BUG: returns addr of stack var */
}

/* lowercase4
* -----------
* Allocates memory on the heap, but size is off-by one: no space for the null
* terminator (\0). How will this show up when running the program? */
char *lowercase4(const char *str)
{
    char *copy = malloc(strlen(str)); /* BUG: size 1 too small */
    for (int i = 0; i<=strlen(str); i++)
        copy[i] = tolower(str[i]);
    return copy;
}

/* lowercase5
* -----------
* Allocates correct amount of memory on the heap.
* This almost works (returns good pointer to lowercase string), but it also
* tries to update str to point to the new copy. Since strings are passed
* by value in C, this won't have an effect. */
char *lowercase5(const char *str)
{
    char *copy = malloc(strlen(str) + 1);
    for (int i = 0; i<=strlen(str); i++)
        copy[i] = tolower(str[i]);
    str = copy; /* BUG: attempt assign parameter to copy (?)*/
    return copy;
}

/* lowercase6
* -----------
* Takes a pointer by reference (char **)
* This almost works (returns good pointer to lowercase string), but it also
* tries to update str to point to the new copy. Since strings are passed
* by value in C, this won't have an effect. */
char *lowercase6(char **strp)
{
    char *copy = malloc(strlen(*strp) + 1);
    for (int i = 0; i<=strlen(*strp); i++)
        copy[i] = tolower((*strp)[i]);
    *strp = copy;
    return copy;
}

int main(int argc, char *argv[])
{
    char stack[16];
    char *heap = malloc(16);
    char *constant;

    strcpy(stack, "LeLaNd");
    strcpy(heap, "sTaNfOrD");
    constant = "junIOR";

    printf("\n After initialization: stack: \"%s\", heap: \"%s\", constant: \"%s\"\n\n", stack, heap, constant);

    char *result1, *result2, *result3;

    printf("Call lowercase6:\n\n");
    result1 = lowercase6(stack);
    result2 = lowercase6(&heap);
    result3 = lowercase6(constant);

    printf("stack=\"%s\",result1=\"%s\"\n",stack, result1);
    printf("heap=\"%s\",result2=\"%s\"\n",heap, result2);
    printf("constant=\"%s\",result3=\"%s\"\n",constant, result3);
    
    free(heap);
    return 0;
}