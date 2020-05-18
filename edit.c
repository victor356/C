#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Levenshtein_distance(char *x, char *y) {
    int m = strlen(x);
    int n = strlen(y);

    register int i, j;

    int distance;

    int **d = (int**) malloc((m + 1) * sizeof(int*));

    for(i = 0; i <= m; i++)
        d[i] = (int*) malloc((n + 1) * sizeof(int));

    for(i = 0; i <= m; i++)
        d[i][0] = i;

    for(j = 1; j <= n; j++)
        d[0][j] = j;

    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(x[i - 1] != y[j - 1]) {
               /* int k = minimum(
                    d[i][j - 1],
                    d[i - 1][j],
                    d[i - 1][j - 1]
                );
                d[i][j] = k + 1;*/
            } else {
                d[i][j] = d[i - 1][j - 1];
            }
        }
    }

    distance = d[m][n];

    for(i = 0; i <= m; i++)
        free(d[i]);

    free(d);
    return distance;
}

int minimum(int a, int b, int c) {

/* funzione che calcola il minimo di 3 valori */

    int min = a;

    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

void main(void){
char* x[100];
char* y[100];


printf("inserire seconda stringa\n");
scanf("%c\n",y);

printf("inserire prima stringa\n");
scanf("%c\n",x);

printf("hey");
}