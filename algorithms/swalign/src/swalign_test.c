/*
 * swalign testbench
 * swalign_test.c
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "swalign_hls.h"

#define FILE_INPUT 	"../data/input.dat"
#define FILE_OUTPUT 	"../output/out.dat"
#define STRING_SIZE 	5
#define SAMPLES		600

int main(int argc,char* argv[]){
	
	FILE *fdout;
	FILE *fdin;
	char buf_1[STRING_SIZE];
	char buf_2[STRING_SIZE];
	char result[STRING_SIZE];
	int i; // counter
	int j; // counter

	if(NULL==(fdin=fopen(FILE_INPUT,"r"))){
		fprintf(stderr, "Open input file failed\n");
		return -1;
	}

	if(NULL==(fdout=fopen(FILE_OUTPUT,"w"))){
		fprintf(stderr, "Open output file failed\n");
		return -1;
	}
	

	// Read from input file by char. It reads first STRING_SIZE char into
	// buf_1, and then reads the next STRING_SIZE char into buf_2. Then, 
	// align buf_1 and buf_2, print the output in the output file.
	
	for(i=0; i<SAMPLES; i++){
		for(j=0; j<STRING_SIZE; j++)
			buf_1[j]=fgetc(fdin);
		fgetc(fdin); //discard the space
		for(j=0; j<STRING_SIZE; j++)
			buf_2[j]=fgetc(fdin);
		fgetc(fdin); //discard the space
		if(-1==swalign_hls((char *)&buf_1, (char *)&buf_2, (char *)&result)){
			fprintf(stderr, "swalign error\n");
			return -1;
		}

		fprintf(fdout, "%d %s %s %s\n", i, (char *)&buf_1, (char *)&buf_2, (char *)&result);
	}

	// close the files
	fclose(fdin);
	fclose(fdout);

	return 0;
}
