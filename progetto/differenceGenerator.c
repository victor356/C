
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
    SET,
    NONE
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

int main()
{
    FILE *fptr;
    //read f1
    int i = 0;
    fptr = fopen("input1.txt", "r");
    if (fptr == 0)
    {
        fprintf(stderr, "Error while opening");
        exit(1);
    }
    long input1_size = ftell(fptr);
    char *input1 = malloc(input1_size) + 1;

    fscanf(fptr, "%[^\t]s", input1);
    printf("1st read= %s\n", input1);
    fclose(fptr);

    //read f2
    fptr = fopen("input2.txt", "r");
    if (fptr == 0)
    {
        fprintf(stderr, "Error while opening");
        exit(1);
    }
    long input2_size = ftell(fptr);
    char *input2 = malloc(input2_size);

    fscanf(fptr, "%[^\t]s", input2);
    printf("2nd read= %s\n", input2);
    fclose(fptr);

    //trasformare da f1 a f2
    int size = max(input2_size, input1_size);
    file diff[size];
    diff[0].type = 2;
    diff[0].n = 0;
    diff[0].byte = 'a';
    printf("type %d %d %c \n", diff[0].type, diff[0].n, diff[0].byte);

    for (int i = 0; i < size; i++) //scrittura delle differenze carattere per carattere
    {
        if (!input1[i] && input2[i])
        {
            diff[i].type = 0;
            diff[i].n = i;
            diff[i].byte = input2[i];
        }
        else if (!input2[i] && input1[i])
        {
            diff[i].type = 1;
            diff[i].n = i;
            diff[i].byte = 0;
        }
        else if (input2[i] != input1[i])
        {
            diff[i].type = 2;
            diff[i].n = i;
            diff[i].byte = input2[i];
        }
        diff[i].type = i;
        diff[i].n = 0;
        diff[i].byte = 'z';
    }
    //scrivere il risultato generatore su file
    fptr = fopen("difference.bin", "wb");
    for (int i = size - 1; i >= 0; i--)
    {
        fwrite(&diff[i], sizeof(file), 1, fptr);
        printf("ciao");
    }

    fclose(fptr);
    free(input1);
    free(input2);

    printf("type %d %d %c", diff[2].type, diff[2].n, diff[2].byte);
}
//come controllare che il file binario sia scritto correttamente