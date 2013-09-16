//==============================================================================
//
// Title:       Smith-Waterman.c
//
// Purpose:     This module performs a Smith-Waterman local sequence alignment 
//				on two given strings using defined scoring parameters.
//
// Copyright:   Unparalleled Systems LLC. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "swalign.h"

/*
int strlength(char* string) {
	int i = 0;
	int isEnd = 0;

	while(isEnd != 0){
		string[i];

	}

	return 0;
}
*/

int swalign(char* stringA, char* stringB, char* result) {
	
	// calculate lengths and initialize score matrix
	int lengthA = strlen(stringA) + 1;
	int lengthB = strlen(stringB) + 1;
	//int size = 16*20*20;
	SCORE_CELL score[lengthA][lengthB];

	// fill initial row/column of score matrix
	for (int i=0; i<lengthA; i++) {
		score[i][0].value = 0;
		score[i][0].parent = EMPTY;
	}
	for (int j=0; j<lengthB; j++) {
		score[0][j].value = 0;
		score[0][j].parent = EMPTY;
	}
	
	// fill the rest of the matrix
	int empty = 0;
	int match = 0;
	int delete = 0;
	int insert = 0;
	
	int maxValue = 0;
	int maxI = 0;
	int maxJ = 0;
	
	for (int i=1; i<lengthA; i++) {
		for (int j=1; j<lengthB; j++) {
			// calculate potential scores
			empty = 0;
			match = (stringA[i-1] == stringB[j-1]) ? 
				(score[i-1][j-1].value + MATCH_SCORE) : 
				(score[i-1][j-1].value + MISMATCH_SCORE);
			delete = score[i-1][j].value + DELETE_SCORE;
			insert = score[i][j-1].value + INSERT_SCORE;
			// choose maximum
			if ( (empty >= match) && (empty >= delete) && (empty >= insert) ) {
				score[i][j].value = empty;
				score[i][j].parent = EMPTY;	
			}
			else if ( (match >= empty) && (match >= delete) && (match >= insert) ) {
				score[i][j].value = match;
				score[i][j].parent = MATCH;
			}
			else if ( (delete >= empty) && (delete >= match) && (delete >= insert) ) {
				score[i][j].value = delete;
				score[i][j].parent = DELETE;	
			}
			else {
				score[i][j].value = insert;
				score[i][j].parent = INSERT;
			}
			// update local maximum values
			if (score[i][j].value >= maxValue) {
				maxValue = score[i][j].value;
				maxI = i;
				maxJ = j;
			}
		}
	}
	
	// backtrack
	int ia = maxI;
	int jb = maxJ;
	int parent = MATCH;
	int count = 0;
	char aligned[lengthA+lengthB];
	
	while (parent != EMPTY) {
		parent = score[ia][jb].parent;
		switch (parent) {
			case MATCH:
				aligned[count] = stringA[ia-1]; 
				count++;
				ia--;
				jb--;
				break;
			case DELETE:
				//aligned[count] = stringA[ia-1]; 
				//count++;
				ia--;
				break;
			case INSERT:
				aligned[count] = ' ';
				count++;
				jb--;
				break;
		}
	}
	
	// reverse aligned string for result
	for (int i=0; i<count; i++)
		result[i] = aligned[count-1-i];
	result[count] = 0;
	return 0;
}
