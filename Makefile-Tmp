CC = gcc -I ./include
CFLAGS = -std=gnu99 -Wall -g #-DDEBUG

INC = ./include
SRC = ./src
OBJ = ./obj
DOC = ./doc
BIN = ./bin

vpath %.h ./include
vpath %.c ./src

EXECS = 

all: $(EXECS)

$(OBJ)/file.o:filename
	$(CC) -c $(CFLAGS) $(SRC)/file.c -o $(OBJ)/file.o

file: $(OBJ)/file.o
	$(CC) $(CFLAGS) -o $(BIN)/file $(OBJ)/file.o

.PHONY: clean
clean:
	/bin/rm -rf $(BIN)/* $(OBJ)/* core* *~
