//==============================================================================
//
// Title:       Smith-Waterman.h
//
// Purpose:     Includes the function interface for the Smith-Waterman module.
//
// Copyright:   Unparalleled Systems LLC. All Rights Reserved.
//
//==============================================================================

#ifndef __SmithWaterman_H__
#define __SmithWaterman_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Constants

// parent tokens
#define EMPTY 0
#define MATCH 1
#define DELETE 2
#define INSERT 3

// scoring parameters
#define MATCH_SCORE 2
#define MISMATCH_SCORE -1
#define DELETE_SCORE -1
#define INSERT_SCORE -1

//==============================================================================
// Types

typedef struct SCORE_CELL {
	int value;
	int parent;
} SCORE_CELL;

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions



int swalign(char* stringA, char* stringB, char* result);

//==============================================================================

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __SmithWaterman_H__ */
