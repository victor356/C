#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define buffSize 10000
#include "filedistance.h"

int minimum(int a, int b, int c)
{

    /* funzione che calcola il minimo di 3 valori */

    int min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;

    return min;
}

int max(int a, int b)
{
    int max;
    if (a > b)
        max = a;
    else
    {
        max = b;
    }
    return max;
}
typedef enum type
{
    ADD,
    DEL,
    SET
} type;
typedef struct
{
    int type;
    unsigned int n;
    char byte;

} file;

typedef struct fileInput fileInput;

typedef struct fileInput
{
    char c;
    fileInput *file;

} fileInput;

void main()
{

    FILE *fptr;
    //read f1
  // int i = 0;
    fptr = fopen("input1.txt", "r");
    if (fptr == 0)
    {
        fprintf(stderr, "Error while opening");
        exit(1);
    }
    long input1_size = ftell(fptr);
    char *input1 = malloc(input1_size);

    fscanf(fptr, "%[^\t]s", input1);
    printf("1st read= %s\n", input1);
    fclose(fptr);

    //read modifiche
    fptr = fopen("difference.bin", "rb");
    if (fptr == 0)
    {
        fprintf(stderr, "Error while 2nd opening");
        exit(1);
    }
    long input2_size = ftell(fptr);
    file diff[input2_size];

    for (int i = 0; !feof(fptr); i++)
    {
        fscanf(fptr, "%d %d %c", diff[i].type, diff[i].n, diff[i].byte);
    }
    fclose(fptr);

    printf("type %d %d %c", diff[2].type, diff[5].n, diff[7].byte);
}