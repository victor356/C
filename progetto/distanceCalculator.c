#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int shouldAdd(int a, int b){


}
int shouldDel();
int shouldSet();


 int add(char* str,unsigned int n, int b){
        str[n]+=b;
    }

 int del(char* str, int n){
     str[n]=NULL;
 }
 int set(char* str, unsigned int n, int b){
     str[n]=b;
 }

int minimum(int a, int b, int c) {

/* funzione che calcola il minimo di 3 valori */
    
    int min = a;

    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

int max(int a,int b){
    int max;
    if (a>b)
    max=a;
    else
    {
        max=b;
    }
    return max;
    
}

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
                int k = minimum(
                    d[i][j - 1],
                    d[i - 1][j],
                    d[i - 1][j - 1]
                );
                d[i][j] = k + 1;
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

int main(){
     FILE* fptr;
//read f1
 char input1[100000];
    fptr = fopen("C:\\Users\\vitto\\Documents\\GitHub\\C\\progetto\\input1.txt","r");
   fscanf(fptr,"%[^\n]s",input1);
    printf("1st read= %s\n", input1);
    fclose(fptr); 

//read f2
 char input2[100000];
    fptr = fopen("C:\\Users\\vitto\\Documents\\GitHub\\C\\progetto\\input2.txt","r");
   fscanf(fptr,"%[^\n]s",input2);
    printf("2nd read= %s\n", input2);
    fclose(fptr); 
    

    clock_t t; 
    t = clock(); 
  
 //calculate number of operations and time needed
    int result=Levenshtein_distance(input1,input2);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("la distanza tra le due stringhe: %d\n",result);
    printf("To calculate the distance between those 2 strings took %f seconds\n", time_taken); 
//write result
   fptr = fopen("C:\\Users\\vitto\\Documents\\GitHub\\C\\progetto\\output.txt","w"); 
   printf("Written string: %d\n",result);
   
    fprintf(fptr,"%d",result);
    fclose(fptr);





// //trasformare da f1 a f2
// int difference[100000];
// for(int i=0; i<max(strlen(input1),strlen(input2)); i++){
   
// difference[i]=input1[i]-input2[i];

//    }
//     //scrivere il risultato generatore
// fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\progetto\\modifiche.txt","w"); 
//    printf("Procedure to follow: %d\n",difference);
//    for(int i=0;i<(sizeof(difference)/sizeof(difference[0]));i++){
//     fprintf(fptr,"%d",difference[i]);
//    }
//     fclose(fptr);






/*

int l1;
int l2;

printf("Enter the lenght of 1st string\n");
scanf("%d", &l1);

char x[l1]; 
printf("Enter the 1st string\n");
scanf("%s", &x);
   
printf("Enter the lenght of 2st string\n");
scanf("%d", &l2);
char y[l2];
  
printf("Enter the 2st string\n");
scanf("%s", &y);


printf("la distanza tra le due stringhe: %d\n",Levenshtein_distance(x,y));
*/
return 0;
}