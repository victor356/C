
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
//read f1
 char input1[100000];
    fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\progetto\\input1.txt","r");
   fscanf(fptr,"%[^\n]s",input1);
    printf("1st read= %s\n", input1);
    fclose(fptr); 

//read f2
 char input2[100000];
    fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\progetto\\input2.txt","r");
   fscanf(fptr,"%[^\n]s",input2);
    printf("2nd read= %s\n", input2);
    fclose(fptr); 

//trasformare da f1 a f2
int difference[100000];
for(int i=0; i<max(strlen(input1),strlen(input2)); i++){
   
difference[i]=input1[i]-input2[i];

   }
    //scrivere il risultato generatore
fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\progetto\\modifiche.txt","w"); 
   printf("Procedure to follow: %d\n",difference);
   for(int i=0;i<(sizeof(difference)/sizeof(difference[0]));i++){
    fprintf(fptr,"%d",difference[i]);
   }
    fclose(fptr);

}