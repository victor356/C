#include <stdio.h>
#include <stdlib.h>
void main(){

int* i=(int*) malloc(3*sizeof(int*));

printf("%d\n",i[0]);

int prova[10]={2};

printf("%d\n",prova[0]);
}