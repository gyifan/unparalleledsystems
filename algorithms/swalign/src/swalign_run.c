#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "swalign.h"

#define FILE_INPUT 	"input.dat"
#define FILE_OUTPUT 	"../data/output.dat"
#define BUF_SIZE 	80
#define SAMPLES		600

int main(int argc,char* argv[]){

/*
	int size = strlen(argv[1])+strlen(argv[2]);
	char result[size];
	if(argc != 3){
		printf("Usage: swalign [StringA] [StringB]");
		exit(-1);
	} else {
		swalign(argv[1], argv[2], result);
	}
	printf("%s\n", result);
	fflush(stdout);
	
	return 0;
*/
	
	FILE *fdout;
	FILE *fdin;
	char buf_0[BUF_SIZE*SAMPLES];
	char* buf[2*SAMPLES];
	char* result[SAMPLES];
	int i=0; // counter

	if(NULL==(fdin=fopen(FILE_INPUT,"r"))){
		fprintf(stderr, "Open input file failed\n");
		return -1;
	}

	if(NULL==(fdout=fopen(FILE_OUTPUT,"w"))){
		fprintf(stderr, "Open output file failed\n");
		return -1;
	}
	

	// Read from input file
	if(NULL==fgets(buf_0, BUF_SIZE*SAMPLES, fdin)){
		fprintf(stderr, "Read from input file failed. \n");
		return -1;
	}
	fclose(fdin);
	
	// Tokenize the string
	buf[0] = malloc(BUF_SIZE);
	buf[0] = strtok(buf_0, " ");
	for (i=1; i<2*SAMPLES; i++){
#ifdef DEBUG
		printf("%s	%d\n", buf[i-1], i-1);
#endif /*DEBUG*/
		buf[i] = strtok(NULL, " ");
	}
	
	// Align the strings
	for (i=0; i<SAMPLES; i++){
		result[i] = malloc(BUF_SIZE);
		if(-1==swalign(buf[2*i], buf[2*i+1], result[i])){
			fprintf(stderr, "swalign error\n");
			return -1;
		}

#ifdef DEBUG
		printf("%s	%d\n", result[i], i);
		printf("%d %s %s %s\n", i, buf[2*i], buf[2*i+1],result[i]);
#endif /*DEBUG*/
	
		fprintf(fdout, "%d %s %s %s\n", i, buf[2*i], buf[2*i+1],result[i]);
	}
	fclose(fdout);

// free the heap
	for (i=0; i<SAMPLES; i++){
		free(result[i]);
	}
	
	return 0;
}
