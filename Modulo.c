#include <stdio.h>

void main(void){
int x=0;
printf("inserire numero\n");
scanf("%d", &x);

if(x<0){
int y=-x;
printf("%d\n",y);
}

}