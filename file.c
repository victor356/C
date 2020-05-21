#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //scrittura
   char output[100];
   FILE* fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\provafile.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   printf("Enter string: ");
   scanf("%[^\n]s", output);
  
   printf("Written string: %s\n",output);
   for(int i=0;i<strlen(output);i++){
    fputc(output[i],fptr);
   }
    fclose(fptr);

//lettura
    char input[100];
    fptr = fopen("C:\\Users\\Vittorio\\Documents\\GitHub\\C\\provafile.txt","r");
   fscanf(fptr,"%[^\n]s",input);
    printf("Value read= %s\n", input);
    fclose(fptr); 


   return 0;
}