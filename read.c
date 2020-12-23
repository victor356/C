#include <stdio.h>
#include <String.h>
#include <stdlib.h>
#include <conio.h>

char *main3(char *file)
{
	FILE *fin = fopen(file, "rb");
	if (fin == NULL)
	{
		perror("Could not open file");
		exit(1);
	}
					//apro il file e mi posiziono alla fine del file
	fseek(fin, 0L, SEEK_END);
					//salvo la lunghezza del file su sizeFin
	long sizeFin = ftell(fin);
					//mi riposiziono all'inizio del file
	rewind(fin);
					//creo un buffer grande sizefin
	char *str = calloc(1, sizeFin);
					//inserisco il contenuto del file in str
	if (str != NULL)
	{
		fread(str, sizeFin, 1, fin);
	}
	fclose(fin);
	printf("%ld\n",sizeFin);

	return str;
}

// char *main2(char *file)
// {

// ///	char *ch="s";
// //	char df;
// //char text;
// 	long unsigned int offset,i;
// 	offset = 2561;

// 	FILE *fileptr;
// 	char *buffer,*text;
// 	long filelen;
// 	int count;
// 	count=0;
// 	fileptr = fopen(file, "rb");  // Open the file in binary mode
// 	fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
// 	filelen = ftell(fileptr);             // Get the current byte offset in the file
// 	rewind(fileptr);                      // Jump back to the beginning of the file
// 	int sub=0;
// 	if (strstr(file, ".txt") == NULL)
// 	{
// 		sub=2560;						//doc file
// 	}
// 	filelen =filelen-sub;
// 	buffer = (char *)malloc((filelen+1)*sizeof(char)); // Enough memory for file + \0
// 	fseek(fileptr, sub+1, SEEK_CUR);	//since this point the doc file is worth
// 	fread(buffer, filelen, 1, fileptr); // Read in the entire file
// 	fclose(fileptr); // Close the file
// 	for ( i = 0; i < strlen(buffer); ++i)
// 	{
// 		if(buffer[i]>127)
// 		{
// 			break;
// 		}
// 		else
// 		{
// 			count++;
// 		}
// 	}
// 	text = (char *)malloc((count+1)*sizeof(char)); // Enough memory for file + \0
// 	for ( i = 0; i < count; ++i)
// 	{
// 		text[i]=buffer[i];
// 		/*****************************************************************************
// 	    *	This Printf printing text content of the doc in one charchter per line   *
// 		*****************************************************************************/
// 	//	printf("%c\n",text[i] );
// 	}
// 	//printf("%d\n",count);

// 	/*******************************************************************************************
// 	*	This Printf printing some text content of the doc not whole text content in one line   *
// 	********************************************************************************************/
// 	//printf("%d\n",strlen(text));
// 	//printf("%s",text );
	

// 	return text;
// }

char *main()
{
	char *file = "read1.doc";

	// if (strstr(file, ".txt") != NULL)
	// {
	// 	return (char*)printf("%s",main3(file));
	// }
	//else
	return (char*)printf("%s",main3(file));
}
