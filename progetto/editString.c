#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int shouldAdd(int a, int b){}
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

int main(){
     FILE* fptr;
//da f1 ottenere f2 tramite il generatore
//read f1
 char input1[100000];
    fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\progetto\\input1.txt","r");
   fscanf(fptr,"%[^\n]s",input1);
    printf("1st read= %s\n", input1);
    fclose(fptr); 

//read modifiche
 int input2[100000];
    fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\progetto\\modifiche.txt","r");
   fscanf(fptr,"%[^\n]d",input2);
   printf("modifiche read= %d\n", input2);
    fclose(fptr); 


//generate f2
    char output[100000];
    fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\progetto\\generatedResult.txt","w");
    for (int i = 0; i < (sizeof(output)/sizeof(output[0])); i++)
    {
     output[i]=input1[i]+input2[i];
     fputc(output[i],fptr);
     }

    fclose(fptr);
     printf("2nd string= %s\n", output);
      

}
