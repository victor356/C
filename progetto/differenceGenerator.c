
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define buffSize 10000
#include "filedistance.h"

// typedef struct add
// {
//     unsigned int n;
//     unsigned int byte;
// } addNb;

// typedef struct edit
// {
//     unsigned int n;
//     unsigned int byte;
// } setNb;

// typedef struct del
// {
//     unsigned int n;
// } delN;

// void export(file *root)
// {
//     FILE *fptr;
//     fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\progetto\\modifiche.bin", "wb");
//     exportRecursive(fptr,root);
//     fclose(fptr);
// }
// void exportRecursive(FILE* fptr, file root)
// {
//     if(root!=NULL)
//     {
//         exportRecursive(root.)
//     }
// }

int main()
{
    FILE *fptr;
    //read f1
    char *input1 = malloc(buffSize);
    int i = 0;
    fptr = fopen("C:\\Users\\vitto\\Documents\\GitHub\\C\\progetto\\input1.txt", "r");
    if (fptr == 0)
    {
        fprintf(stderr, "Error while opening");
        exit(1);
    }
    fscanf(fptr, "%[^\t]s", input1);
    printf("1st read= %s\n", input1);
    fclose(fptr);

    //read f2
    char *input2 = malloc(buffSize);
    fptr = fopen("C:\\Users\\vitto\\Documents\\GitHub\\C\\progetto\\input2.txt", "r");
    if (fptr == 0)
    {
        fprintf(stderr, "Error while opening");
        exit(1);
    }
    fscanf(fptr, "%[^\t]s", input2);
    printf("2nd read= %s\n", input2);
    fclose(fptr);

    //trasformare da f1 a f2
    int size = max(strlen(input1), strlen(input2));
    file diff[size];
    for (int i = 0; i < size; i++) //scrittura delle differenze carattere per carattere
    {
        if (input1[i] == NULL && input2[i] != NULL)
        {
            diff[i].type = ADD;
            diff[i].n = i;
            diff[i].byte = input2[i];
        }
        else if (input2[i] == NULL && input1[i] != NULL)
        {
            diff[i].type = DEL;
            diff[i].n = i;
            diff[i].byte = NULL;
        }
        else if (input2[i] != input1[i])
        {
            diff[i].type = SET;
            diff[i].n = i;
            diff[i].byte = NULL;
        }
    }
    //scrivere il risultato generatore su file
    fptr = fopen("difference.bin", "wb");
    for (int i = size - 1; i >= 0; i--)
    {
        fwrite(&diff + i, sizeof(file) * size, 1, fptr);
        printf("ciao");
    }
    printf("\n 1");

    fclose(fptr);
}