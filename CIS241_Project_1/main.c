/**********************************************************************************
*Author: Jaime Malone
*Class: CIS241-01
*Project: Project 1
*Date: 06/09/2023
*Description
*
*
***********************************************************************************/

//includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "encryption.h"

//defines
#define MAX_STRING 1024

int main(){

	//variables
	char in_filename[MAX_STRING];
	char out_filename[MAX_STRING];
	char encrypt_key[MAX_STRING];
	char operation = ' ';

	//while the user does not want to quit
	while(operation != 'Q'){

		operation = ' ';

		//read in operation
		while(operation != 'E' && operation != 'D' && operation != 'Q'){

			printf("What would you like to do?\n");
			printf("\tE: Encrypt\n");
			printf("\tD: Decrypt\n");
			printf("\tQ: Quit\n");
			scanf("%c", &operation);
			operation = toupper(operation); //change to upper case
			printf("input: %c\n", operation);

			if(operation != 'E' && operation != 'D' && operation != 'Q'){
				printf("Invalid operation! Please try again\n\n");
			}

			getchar(); //flush input buffer

			if(operation == 'E'){

				//read in user file names
				printf("Enter the input file name: \n");
				scanf("%s", in_filename);

				printf("Enter the output file name: \n");
				scanf("%s", out_filename);

				printf("Enter Encryption key: \n");
				getchar();
				fgets(encrypt_key, MAX_STRING, stdin);

				//call encryption function
				if(encrypt_file(in_filename, out_filename, encrypt_key) == 1)
					return 1;

				//reset operation
				operation = ' ';
			}

			else if(operation == 'D'){

				//read in user file names
				printf("Enter the input file name: \n");
				scanf("%s", in_filename);

				printf("Enter the output file name: \n");
				scanf("%s", out_filename);

				printf("Enter Encryption key: \n");
				getchar();
				fgets(encrypt_key, MAX_STRING, stdin);

				if(decrypt_file(in_filename, out_filename, encrypt_key) == 1)
					return 1;

				//reset operation
				operation = ' ';
			}
		}

	}

	printf("Thank you, come again!\n");
	return 0;
}
