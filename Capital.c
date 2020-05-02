#include <stdio.h>
int main(){
    char string[1000];
    printf("*****Insert input string*****\n");
    scanf("%s",string);
    
    printf("Upper case string: %s\n", strupr(string));
    return 0;
  
  
  }