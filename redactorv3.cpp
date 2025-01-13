#include <stdio.h>
#include <string.h>

//the files to be redacted need to be placed in the same place as the other c files
//uses putchar to display the redacted and non-redacted characters to the terminal
void dataRedact(FILE *input, char redactChar) {
    int c;
    
    while ((c = fgetc(input)) != EOF) {
        if (c >= '0' && c <= '9') { //redacts digits
            putchar(redactChar);
        }
        else if (strchr("aeiouAEIOU", c) != NULL) { //returns a pointer to first occurence of a letter or something
            putchar(redactChar);
        }
        else { //otherwise just leave it alone cuz why not
            putchar(c);
        }
    }
}

int main() {
    char fileName[1000]; //store input namee
    int symchoice, i = 1; //store usr symbol symchoice
    unsigned int redactSymbols[] = {178, 165, 157, 146, 219}; //the actual symboles used to redact le txt file
    FILE *input = NULL;
    
    printf("This program is a REDACT program for redacting DIGITS and vowel characters ");
    printf("(a, e, i, o, u, A, E, I, O, U) in a TEXT file.\n");
    printf("The program will be TERMINATED, once '*' (asterisk) is entered.\n\n");
    
    while (i == 1) { //we want infinite loop cuz what if theres many files to redact???
        printf("Please enter REDACT text filename : ");
        scanf("%s", fileName);
        
        if (strcmp(fileName, "*") == 0) { // if user choses *, the program skips file reading and creating
        } else {
            input = fopen(fileName, "r"); // open file to read
            if (input == NULL) { // error handling if file cannot be opened
                printf("Error opening input file!\n");
                continue;
            }
        }
        
        printf("Choose one of these symbols:\n");
        printf("1. %c (ASCII Code 178 decimal)\n", 178);
		printf("2. %c (ASCII COde 165 decimal)\n", 165);
		printf("3. %c (ASCII COde 157 decimal)\n", 157);
		printf("4. %c (ASCII COde 146 decimal)\n", 146);
		printf("5. %c (ASCII Code 219 decimal)\n", 219);
        
    
        printf("Please enter the number for the chosen REDACT character : ");
        scanf("%d", &symchoice);
        
        if (symchoice == 0) { //if user choses 0, the program ends
            printf("Program terminated. BYEBYE\n");
            if (input != NULL) {
            	fclose(input);
			}
            break;
        }
        
        if (symchoice < 1 || symchoice > 5) {
            printf("WROOOONG CHOICE!\n");
            fclose(input);
            continue;
        }
        
        dataRedact(input, redactSymbols[symchoice - 1]);
        
        fclose(input); // close files to not waste resources
        
        printf("\nFile has been redacted successfully! SEEYA\n\n");
    }
    
    return 0;
}