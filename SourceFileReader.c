/*
 * File:   SourceFileReader.c
 * Authors: Adaias Bedoy, Michael Hill
 *
 * Created on October 12, 2015, 10:59 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <glob.h>
#include <string.h>
#include "symbolTable.h"
#define MAX 100
extern int yylex();
extern int yyparse();
extern FILE *yyin;

/*
 *
 */

//yyerror function
//Leo's errorHandler function
int MaxSeverity;
void yyerror(int sev, int lineNumber)

{

  char str[50];
  char buffer[20];

if (sev == 1)
    {
      if (MaxSeverity == 0)
	{ 
	  MaxSeverity = 1;
	}
      sprintf(str, "Warning: at line number %d\n", lineNumber);
      perror(str);
    }  

if (sev == 2)
  
    {
      if (MaxSeverity == 1)
	{
	  MaxSeverity = 2;
	}
      sprintf(str, "Error: at line number %d\n", lineNumber);
      perror(str);
      
    }

if (sev == 3)
     {
       if (MaxSeverity == 2)
	 {
	   MaxSeverity = 3;
	 }
       sprintf(str, "Fatal: at line number %d\n", lineNumber);
       perror(str);
				    
     }

}

/*Initialize the symbol table*/
int main(int argc, char** argv) {
    int i;
     for (i = 0; i < SIZE; i++)
    {
        symbolTable[i].lexeme = strdup("default");
        symbolTable[i].next   = 0; 
    }
    
    
  /*Function to open files, will need to be updated to just handle .c files*/
    FILE *fp;
    char name[MAX];


   // printf("Enter filename: \n");
    //scanf("%s");

    if((yyin = fopen(argv[1], "r")) == 0)
        printf("\nFile cannot be opened!\n");
    fclose(fp);
    
       symbolTableInitialization();
    //calls yyparse which calls yylex to check tokens until scanner jams or reaches end of file
    do {
		yyparse();
	} while (!feof(yyin));
        
    return 0;
    
    
 /*Object finder. Also lists them as a way for us to test*/
  FILE * oFile;
  oFile = fopen ("SourceFileReader.c", "r");
 if (oFile!=NULL)
  {
    printf("Looking for objects...\n"); //numbers and lists all object files in current directory
    //glob example using .c extension found on link below, modified to work with .o extensions instead
    //http://www.qnx.com/developers/docs/660/index.jsp?topic=%2Fcom.qnx.doc.neutrino.lib_ref%2Ftopic%2Fg%2Fglob.html
    glob_t paths;
    int retval;
   
    paths.gl_pathc = 0;
    paths.gl_pathv = NULL;
    paths.gl_offs = 0;

    retval = glob( "*.o", GLOB_NOCHECK | GLOB_NOSORT,
                   NULL, &paths );
    if( retval == 0 ) {
        int idx;
       
        for( idx = 0; idx < paths.gl_pathc; idx++ ) {
            printf( "Object(s) found\n:[%d]: %s\n", idx,
                    paths.gl_pathv[idx] );
        }
       
        globfree( &paths );
    } else {
        puts( "No objects found" );
    }
    fclose (oFile);
  }
  if (oFile==NULL)
  {
      printf("No Objects Found\n");
      fclose (oFile);
  }
  return 0;
    return (EXIT_SUCCESS);
    
    
}