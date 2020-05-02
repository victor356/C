#include <stdio.h>
int y=0;
int increment(void){
   extern int y;
   return y++;
}


int main(void){

printf("Il valore di y dovrebbe essere 0--> %d\n",y);
increment();
//oppure
printf("Il valore di y dovrebbe essere 1--> %d\n",increment());
printf("Il valore di y dovrebbe essere 2--> %d\n",increment());
printf("Il valore di y dovrebbe essere 3--> %d\n",y); 
//lo prende dal precedente metodo


  
  
  }