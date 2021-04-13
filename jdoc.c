//Programming Fundamentals coursework using C.
//The following program needs a file as an input(preferably .java). It reads the whole file, it outputs all the functions/methods name, the authors name and also the 
//the params and returns of the current method.

// @author G_Lefterov

#include <stdio.h>
#include <string.h>
int main(int argc, char** argv) {

int isBlank = 0;
int lineCounter =0;
int blankNumber = 0;
int nonBlankNumber = 0;
int commentsNumber =0;
int currentlyComment =0;
int afterComment =0;
int printNextLine =0;
int counterCurrentFuncName=0;
int indexingParam =0;
int indexingReturn =0;
int arrayParamReturn[50];
int indexingArrayChoose=0;
char lineWithFuncNames[100][500];
char lineMethodDesc[100][50];
char lineMethodDescWordByWord[100][500];
char lineFuncWordByWord[100][500];
char allFuncNames[100][500];
char lineAuthor[500];
char authorName[50][500];
char wholeFile[25000];
char currentComment[1000];
FILE *inputFile = fopen(argv[2], "r");
FILE* outputFile = fopen(argv[4], "w");

if(outputFile == NULL){
    printf("Error occurred while opening the output file! Check the directory!");
}


if (inputFile != NULL)
{
    char currentLine[1000]; // declaring an array of chars(string) with maximum line size of 1000 
    while (fgets(currentLine, sizeof currentLine, inputFile) != NULL) // read a line 
    {
        lineCounter++; //incrementing lineCounter by one(used to count the lines of the file)
        for(int i=0; i<strlen(currentLine); i++){ //for loop with counter i, that's going to iteract for every single char of the length of currentLine
        if(currentLine[i] == '/' && currentLine[i+1] == '*' && currentLine[i+2]== '*'){ //if statement that checks if there is a comment that begins this line
            commentsNumber++; //incrementing the number of comments by 1

        }

        if(currentLine[i] != 0 && currentLine[i] != ' ' && currentLine[i] != '\n' && currentLine[i] != '\t'){ // if statement that checks if the line is blank
                nonBlankNumber++; //incrementing the non-blank lines number by 1
                break; // break the for-loop
            }


        }

        if(afterComment == 1){ //if statement used to print the next line after a comment ends( e.g. public void getMatric(){ )
                        fprintf(outputFile, "     */ \n"); //printf used to print the end of the comment and a new line
                        fprintf(outputFile, "%s \n", currentLine );//print of the next line after the comment
                        strcpy(lineWithFuncNames,currentLine); //copy the currentline string to an variable string used to get the names of the function later in the code
                afterComment=0; //assign a 0 to the after comment variable
        }
         
char *token = strtok(lineWithFuncNames, " "); //tokenising the first element of the string with delimiter a space 
int counterWhile=1; //declaring and initialisng a counter used as a counter in the while loop
while(token != NULL){ //while loop used to finish the tokenisation of the current string
        counterWhile++; //incrementing the counterWhile by 1
strcpy(lineFuncWordByWord[counterWhile], token); //copy the current token into the array lineFuncWordByWord in counterWhile position
    token = strtok(NULL, " "); //resume the tokenisation


}
if(strcmp(lineWithFuncNames[counterCurrentFuncName], lineFuncWordByWord[4])){ //if statement that checks if the two strings are equal (if the current method name is already in the array)
   counterCurrentFuncName++; //increment the counter by 1 so the next method name will be at a new index 
}
strcpy(lineWithFuncNames[counterCurrentFuncName], lineFuncWordByWord[4]); //copy the method name in the indexed array




        for(int i=1; i<strlen(currentLine); i++){ //for-loop used to check if there are params, returns, authors or an end of a comment

        if(currentLine[i] == '@' && currentLine[i+1] == 'p' && currentLine[i+2] == 'a' && currentLine[i+3] == 'r' &&currentLine[i+4] == 'a' && currentLine[i+5] == 'm'){ //if statement that checks if there is a @param
        strcpy(lineMethodDesc[indexingArrayChoose+1], currentLine); //copy the current line into an array full of lines with params or returns
        arrayParamReturn[indexingArrayChoose] = 1; //that's used to know if it's param or return 1 means param
        indexingArrayChoose++;
        }
        if(currentLine[i] == '@' && currentLine[i+1] == 'r' && currentLine[i+2] == 'e' && currentLine[i+3] == 't' &&currentLine[i+4] == 'u' && currentLine[i+5] == 'r' && currentLine[i+6] == 'n'){//if statement that checks if there is a @return
        strcpy(lineMethodDesc[indexingArrayChoose+1], currentLine);//copy the current line into an array full of lines with params or returns
        arrayParamReturn[indexingArrayChoose] = 2; //that's used to know if it's param or return 2 means return
        indexingArrayChoose++;
        }
                    if(currentLine[i] == '@' && currentLine[i+1] == 'a' && currentLine[i+2] == 'u'){ //if statement that checks if there's an @author tag in the line
                strcat(lineAuthor, currentLine); //concatenate string lineAuthor and currentLine
                break; //end of the for-loop
            }
        if(currentLine[i-1] == '/' && currentLine[i] == '*' && currentLine[i+1]== '*'){ //if statement that checks if there is a comment beginning in the current line
currentlyComment=1; //variable used to indicate if there's a comment that's currently being printed 
}


    if(currentLine[i-1] == '*' && currentLine[i] == '/'){ //if statement that checks if there is a comment ending in the current line
afterComment = 1; //variable used to print the line after the comment ends
currentlyComment = 0; //variable used to indicate if there's a comment that's currently being printed 
    }

        }

        if(currentlyComment == 1){ //if statement that checks if currentlyComment is true and if so, prints into the file
                        fprintf(outputFile, "%s ", currentLine );
        }




}
    fclose(inputFile); //close the inputFile
    fclose(outputFile); //close the outputFile
}
else
{
    printf("Error occurred while opening the input file! Check the directory!");//file doesn't exist
}

char *token = strtok(lineAuthor, " ");//tokenising the first element of the string with delimiter a space 
int counterWhile=1; //initialisng a counter used as a counter in the while loop
while(token != NULL){ //while loop used to finish the tokenisation of the current string
        counterWhile++;//incrementing the counterWhile by 1
strcpy(authorName[counterWhile], token); //copy the current token into the array authorName at index counterWhile's value
    token = strtok(NULL, " "); //resume the tokenisation


}


printf("Class: %s \n", lineWithFuncNames[1]); //print the class name
printf("Author: %s %s", authorName[4],authorName[5]); //print the author name
printf("\n"); //print a new line



for(int i=0; i<strlen(lineWithFuncNames)-3; i++){ //for loop used to print information into the files
printf("Method: %s \n", lineWithFuncNames[i+2]); //print the method name
if(arrayParamReturn[i]==1){ //if statement that checks if the current function params or returns
printf("Parameter: ");//prints the string into the command line
counterWhile =0; //initialisng a counter used as a counter in the while loop
        token = strtok(lineMethodDesc[i+1], " "); //resume the tokenisation at the 2 dimensional array
while(token != NULL ) { //while loop used to finish the tokenisation of the current string
        if(counterWhile > 1){ //if statement that checks if counterWhile is bigger than one (so it wont output *)
      printf( " %s", token );
      }
          token = strtok(NULL, " "); //resume the tokenisation
      counterWhile++; //increment counterWhile by 1
   }
   printf("\n"); //print a new line
}else if(arrayParamReturn[i]==2){
printf("Returns: "); //prints the string into the command line
counterWhile =0;//initialisng a counter used as a counter in the while loop
        token = strtok(lineMethodDesc[i+1], " "); //resume the tokenisation at the 2 dimensional array
while(token != NULL ) { //while loop used to finish the tokenisation of the current string
        if(counterWhile > 1){ //if statement that checks if counterWhile is bigger than one (so it wont output *)
      printf( " %s", token ); 
      }

          token = strtok(NULL, " "); //resume the tokenisation
      counterWhile++; //increment counterWhile by 1
   }
}
printf("\n"); //print a new line
}






blankNumber = lineCounter - nonBlankNumber; //calculation to get the number of blank lines
printf("Total number of lines = %d", lineCounter); //output of the information about the number of the lines
printf("\n");
printf("Blank Lines = %d", blankNumber);//output of the information about the number of the blank lines
printf("\n");
printf("nonBlankLines = %d", nonBlankNumber); //output of the information about the number of the non-blank lines
printf("\n");
printf("commentsNumber = %d", commentsNumber); //output the number of the comment blocks 

return 0;

};


