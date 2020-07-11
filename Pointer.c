#include <stdio.h>
#include <string.h>

int main(void){
int x=9999;
    printf("Valore x= %d\n",x);
    printf("Nome Indirizzo memoria di x= %d\n",&x);
    printf("Dimensione indirizzo memoria di x in bit= %d\n",sizeof(&x));
    printf("\n");

char c='A';
    printf("Character is %c \n", c);
    printf("Nome Indirizzo memoria c=%d\n",&c);
    printf("Dimensione indirizzo memoria di c in bit=%d\n",sizeof(&c));
    printf("\n");

char str[200]="Muccaaaa";
    printf("String is %s \n" , str);
    printf("Nome Indirizzo memoria str=%d\n",&str);
    printf("Dimensione indirizzo memoria di str in bit=%d\n",sizeof(&str));
    printf("\n");

float flt = 10.234;
double dbl = 20.123456;

   printf("Float value is %f \n", flt);
   printf("Double value is %lf \n", dbl);
   printf("\n");

char cha='m';
char *pc=&cha;   //pc refers to cha
*pc='B';       //cha has changed from 'm' to 'B'
printf("%c\n",cha);
printf("\n");

double num=2.45;
printf("%lf\n",num);
double *pointer1,*pointer2;
pointer1=&num;
pointer2=pointer1;      //both refers to d now
*pointer2=256.32;       //now d= 256.32
printf("%lf\n",num);

*pointer1=*pointer2 *100.0;   //now d=25632.0000
printf("%lf\n",num);
printf("\n");

char letters[26]="ciaone";
char *pc1=letters;
char *pc2=&letters;
char *pc3=letters[0];
printf("%c\n",*pc1);
printf("%c\n",*pc2);
printf("%c\n",pc3);
printf("\n");

int a1[10]={1,4,6,8,5,6};
int *pa=a1;     //il puntatore punta al primo blocco di memoria dell'array   --->1
printf("%d\n",*pa);
*pa++;          //il puntatore scorre all'elemento successivo  --->4
printf("%d\n",*pa);
*pa=*pa+1;      //il contenuto del puntatore viene incrementato di 1   ---->5
printf("%d\n",*pa);
printf("\n");

int a=5;
int b=2;
void cambia(int *px, int *py){  
     int temp=*px;  
        *px=*py;
    *py=temp;
//per cambiare valore non si può fare call by value ma call by reference, ovvero tramite puntatore
};

cambia(&a,&b);
printf("a=%d\n",a);
printf("b=%d\n",b);
printf("\n");

char string[]="provaaaaaaaaa";
printf("Lunghezza stringa= %d\n", strlen(string));
printf("\n");

int intero[]={2,3,5,6,7,8};
printf("numero elementi= %d\n", (int)( sizeof(intero) / sizeof(intero[0])));
} 