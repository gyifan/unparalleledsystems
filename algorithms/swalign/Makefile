CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
BIN = ./bin

vpath %.h ./include
vpath %.c ./src

EXECS = swalign_run 

all: $(EXECS)

$(OBJ)/swalign.o: swalign.c
	$(CC) -c $(CFLAGS) $(SRC)/swalign.c -o $(OBJ)/swalign.o

swalign_run: $(SRC)/swalign_run.c $(OBJ)/swalign.o
	$(CC) $(CFLAGS) -o $(BIN)/swalign_run $(OBJ)/swalign.o $(SRC)/swalign_run.c

.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* core* *~
