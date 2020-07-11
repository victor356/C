#include <stdio.h>
struct Point{
        int x;
        float y;
    };
     
   /*in questo modo per istanziare la struttura Point devo
   scrivere ogni volta 'struct Point' */

   typedef struct Pippo{
        int x;
        char aa;
    }Parrucchiere;

  Parrucchiere a1,a2;
    Parrucchiere a1={4,'a'};
  /*con typedef è come se nell'instanziamento di una struttura 
  sintetizzassi "struct Pippo" con "parrucchiere" (è + veloce)*/
    
    typedef struct lista Alias; //dichiarazione struct con alias

    struct lista{   //istanziazione postuma della lista con alias
        int z;
        Parrucchiere prova; //struct annidata= struct dentro una struct, prova ne è puntatore
    };
    Alias paperino, minni;
 
    struct Point difference(struct Point prima, struct Point seconda)
    {
        seconda.x-=prima.x;
        
        seconda.y-=prima.y;
        return seconda;
    }
  
void main(){

  
   paperino.prova.aa="f";
  
     minni.z=5;
    minni.prova.x=11;

     struct Point p1={3,5.0};
    struct Point p2={2,39.0};
    struct Point p3=difference(p1,p2);

    printf("differenza= %d %f\n",p3.x,p3.y);

    struct Point pt={50,50};
    struct Point *pp=&pt;
    (*pp).x=100;  //ora pt.x=100
    // (*pp).x   =========  pp->x

    //una struct non può avere un elemento di se stessa, ma può avere un puntatore di se stessa
   typedef struct Topolino ecco;
   struct Topolino{
       int x;
       ecco *pa; //== struct Topolino pa
       
   }ecco;
ecco ppp;
ecco ppp2;
(ppp).x=3;
*(ppp).pa=ppp2;   
//deve essere un puntatore, come se fosse in un albero, la foglia finale avrebbe questo valore NULL
   
   typedef union{
       int ival;
       float fval;
   }value;

   typedef struct{
       char top;
       value val;

   }number;

    number n1[50];
    n1[0].top='a';
    n1[0].val.ival=56;


   }