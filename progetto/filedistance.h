#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "website.c"

char *loadFile(char *dir)
{
    FILE *fptr;
    fptr = fopen(dir, "r");
    if (fptr == 0)
    {
        fprintf(stderr, "Error while opening");
        exit(1);
    }
    long input1_size = ftell(fptr);
    char *input1 = malloc(input1_size) + 1;
    fscanf(fptr, "%[^\t]s", input1);
    fclose(fptr);

    return input1;
}


int levenshtein_distance(const char *str1, const char *str2)
{
    const long len1 = strlen(str1), len2 = strlen(str2);
    unsigned int i, distance;
    edit **mat;

    /* Initialise the matrix */
    mat = levenshtein_matrix_create(str1, len1, str2, len2);

    /* Main algorithm */
    distance = levenshtein_matrix_calculate(mat, str1, len1, str2, len2);

    /* Clean up */
    for (i = 0; i <= len1; i++)
    {
        free(mat[i]);
    }
    free(mat);

    return distance;
}


// int minimum(int a, int b, int c)
// {

//     /* funzione che calcola il minimo di 3 valori */

//     int min = a;

//     if (b < min)
//         min = b;
//     if (c < min)
//         min = c;

//     return min;
// }
// int Levenshtein_distance(char *x, char *y)
// {
//     int m = strlen(x);
//     int n = strlen(y);

//     register int i, j;

//     int distance;

//     int **d = (int **)malloc((m + 1) * sizeof(int *));

//     for (i = 0; i <= m; i++)
//         d[i] = (int *)malloc((n + 1) * sizeof(int));

//     for (i = 0; i <= m; i++)
//         d[i][0] = i;

//     for (j = 1; j <= n; j++)
//         d[0][j] = j;

//     for (i = 1; i <= m; i++)
//     {
//         for (j = 1; j <= n; j++)
//         {
//             if (x[i - 1] != y[j - 1])
//             {
//                 int k = minimum(
//                     d[i][j - 1],
//                     d[i - 1][j],
//                     d[i - 1][j - 1]);
//                 d[i][j] = k + 1;
//             }
//             else
//             {
//                 d[i][j] = d[i - 1][j - 1];
//             }
//         }
//     }

//     distance = d[m][n];

//     for (i = 0; i <= m; i++)
//         free(d[i]);

//     free(d);
//     return distance;
// }
