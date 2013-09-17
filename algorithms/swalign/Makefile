CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
BIN = ./bin
OUT = ./output

vpath %.h ./include
vpath %.c ./src

EXECS = swalign_run swalign_test

all: $(EXECS)

$(OBJ)/swalign.o: swalign.c
	$(CC) -c $(CFLAGS) $(SRC)/swalign.c -o $(OBJ)/swalign.o

$(OBJ)/swalign_hls.o: swalign_hls.c
	$(CC) -c $(CFLAGS) $(SRC)/swalign_hls.c -o $(OBJ)/swalign_hls.o

swalign_run: $(SRC)/swalign_run.c $(OBJ)/swalign.o
	$(CC) $(CFLAGS) -o $(BIN)/swalign_run $(OBJ)/swalign.o $(SRC)/swalign_run.c

swalign_test: $(SRC)/swalign_test.c $(OBJ)/swalign_hls.o
	$(CC) $(CFLAGS) -o $(BIN)/swalign_test $(OBJ)/swalign_hls.o $(SRC)/swalign_test.c


.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* $(OUT)/* core* *~
