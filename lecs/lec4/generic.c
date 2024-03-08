#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* count_???
 * ----------
 * Count the number of occurrences in key ins arr, which has n elements
 *
 * One version of this function for each type.
 * It sure would be nice if we could unify them. */
int count_int(int key, int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == key) count++;
    return count;
}

int count_float(float key, float *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == key) count++;
    return count;
}

int count_char(char key, char *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == key) count++;
    return count;
}

int count_str(char *key, char *arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == key) count++;
    return count;
}

/*
 * -----------
 * Generic version of count, using void *. */
int gcount(void *key, void *arr, int n, size_t elemsz){
    int count = 0;
    return count;
}

int main(int argc, char *argv[])
{
    int scores[] = {88, 94, 70,92,83,92,1,92};
    int nscores = sizeof(scores)/sizeof(scores[0]);
    int score_key = 92;
    float prices[] = {3.99,195,181.50};
    int nprices = sizeof(prices)/sizeof(prices[0]);
    float price_key = 3.5;
    char *letters = "CS107 rocks my world";
    int nletters = strlen(letters);
    int letter_key = 'o';

    printf("Count of %d = %d\n", score_key, gcount(&score_key, scores, nscores,sizeof(scores[0])));
    printf("Count of %g = %d\n", price_key, count_float(price_key, prices, nprices));
    printf("Count of %c = %d\n", letter_key, count_char(letter_key, letters,nletters));

    if (argc > 1)
    {
        char **words = argv + 1; /* Skip argv[0] */
        int nwords = argc - 1;
        char *word_key = words[0];
        printf("Count of %s = %d\n", word_key, gcount(&word_key,words, nwords, sizeof(words[0])));
    }

}