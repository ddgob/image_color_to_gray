CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/pixelRGB.o $(OBJ)/imagem.o $(OBJ)/imagemPGM.o $(OBJ)/imagemPPM.o $(OBJ)/memlog.o
HDRS = $(INC)/pixelRGB.hpp $(INC)/imagem.hpp $(INC)/imagemPGM.hpp $(INC)/imagemPPM.hpp $(INC)/memlog.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/programa

all: $(EXE)

$(BIN)/programa: $(OBJS)
	$(CC) -o $(BIN)/programa $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp -g

$(OBJ)/pixelRGB.o: $(HDRS) $(SRC)/pixelRGB.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pixelRGB.o $(SRC)/pixelRGB.cpp -g

$(OBJ)/imagem.o: $(HDRS) $(SRC)/imagem.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/imagem.o $(SRC)/imagem.cpp -g

$(OBJ)/imagemPGM.o: $(HDRS) $(SRC)/imagemPGM.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/imagemPGM.o $(SRC)/imagemPGM.cpp -g

$(OBJ)/imagemPPM.o: $(HDRS) $(SRC)/imagemPPM.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/imagemPPM.o $(SRC)/imagemPPM.cpp -g

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp -g

clean:
	rm -f $(EXE) $(OBJS) *.pgm *.out