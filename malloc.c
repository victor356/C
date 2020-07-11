#include <stdio.h>
void main(){
    int prova[]={2,3,4,5,6,7};

printf("size of int= %d\n",sizeof(int)); 
printf("size of array di 6 interi= %d\n",sizeof(prova));

    int *q={5,4,3,2,5,7};
    int *p=(int*)malloc(6*sizeof(int));
   
    if(*p==NULL)
        printf("P Error in allocating memory!!!\n");
   
    *p=12;
    *(p+3)=444;
    *(p+1)=22;
    for(int i=0;i<5;i++)
        printf("%d ",*(p+i));
  
    printf("\n");

    int *c=calloc(6,sizeof(int));
    if(*c==NULL)
        printf("C Error in allocating memory!!!\n");
    *c=99; 
    *(c+2)=23; 
 for(int i=0;i<5;i++){
        printf("%d ",*(c+i));
    }

}