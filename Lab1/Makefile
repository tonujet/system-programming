CC=g++
CFLAGS=-c -Wall
LDFLAGS=

SRC_FOLDER=./src/
OBJ_FOLDER=./obj/
SRC=$(wildcard $(SRC_FOLDER)*.cpp)
OBJ=$(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

EXEC=out

all: $(EXEC) $(SRC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(EXEC) $(OBJ)