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

int main(){

	//variables
	char in_filename[1024];
	char out_filename[1024];
	char encrypt_key[1024];
	char operation = ' ';

	//while the user does not want to quit
	while(operation != 'Q'){

		//read in user values
		printf("Enter the input file name: \n");
		scanf("%s", in_filename);

		printf("Enter the output file name: \n");
 		scanf("%s", out_filename);

		printf("Enter key: \n");
		getchar();
		fgets(encrypt_key, 1024, stdin);

		int i = 0;

		while(encrypt_key[i] != '\n'){

			printf("key value at %d: %c\n", i, encrypt_key[i]);
			i++;
		}

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

				//call encryption function
				if(encrypt_file(in_filename, out_filename, encrypt_key) == 1)
					return 1;

				//reset operation
				operation = ' ';
			}

			else if(operation == 'D'){

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
