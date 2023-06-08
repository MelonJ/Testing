#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define ASCII_OFFSET 32
#define ASCII_LIMIT 95

int encrypt_file(char *in_filename, char *out_filename, char *key){

	//variables
	FILE *input_file;
	FILE *output_file;
	unsigned char ch;
	unsigned char ch_o;
	unsigned char key_offset;
	int key_index; //index to keep track of location in key.

	//open input file
	input_file = fopen(in_filename, "r");

	//check if it successfully opened
	if(input_file == NULL){
		perror("Error opening input file");
		return 1;
	}

	//open output file
	output_file = fopen(out_filename, "w");

	//check if it successfully opened
	if(output_file == NULL){
		perror("CANNOT OPEN OUTPUT FILE");
		return 1;
	}

	ch = fgetc(input_file);
	key_index = 0;

	//until the end of the file
	while(!feof(input_file)){

		//if the character is not a terminating character
		if(ch != '\n'){
			//subtract offsets
			ch -= ASCII_OFFSET;
			key_offset = key[key_index] - ASCII_OFFSET;
			//add offset values
			ch_o = (ch + key_offset);

			//if the sum is grater than limit
			if(ch_o > (ASCII_LIMIT)){
				ch_o = ch_o%ASCII_LIMIT + ASCII_OFFSET;
			}

			//add offset
			else
				ch_o += ASCII_OFFSET;

			//write to output file
			fprintf(output_file,"%c", ch_o);

			key_index++;

			//if we've reached the end of the key arr then reset index
			if(key[key_index] == '\n')
				key_index = 0;
		}

		else
			fprintf(output_file,"%c", '\n');

		//pull new character
		ch = fgetc(input_file);
	}

	//close files
	fclose(input_file);
	fclose(output_file);
	printf("Done Encrypting!\n\n");

	return 0;
}

int decrypt_file(char *in_filename, char *out_filename, char *key){


	//variables
	FILE *input_file;
	FILE *output_file;
	unsigned char ch;
	unsigned char ch_o;
 	unsigned char key_offset;
	int key_index; //index to keep track of location in key.

	//open input file
	input_file = fopen(in_filename, "r");

	//check if it successfully opened
	if(input_file == NULL){
		perror("Error opening input file");
		return 1;
	}

	//open output file
	output_file = fopen(out_filename, "w");

	//check if it successfully opened
	if(output_file == NULL){
		perror("CANNOT OPEN OUTPUT FILE");
		return 1;
	}

	ch = fgetc(input_file);
	key_index = 0;

	while(!feof(input_file)){

		if(ch != '\n'){
			//subtract offset from key
			key_offset = key[key_index] - ASCII_OFFSET;

			//ADD SOMETHING SMART HERE
			ch_o = ((ch - ASCII_OFFSET - key_offset + ASCII_LIMIT)%ASCII_LIMIT) + ASCII_OFFSET;

			//write to output file
			fprintf(output_file,"%c", ch_o);

			key_index++;

			//if we've reached the end of the key arr then reset
			if(key[key_index] == '\n')
				key_index = 0;
		}

		else
			fprintf(output_file, "%c", '\n');

		//pull new character
		ch = fgetc(input_file);
	}

	fclose(input_file);
	fclose(output_file);
	printf("Done Decrypting!\n\n");
	return 0;
}
