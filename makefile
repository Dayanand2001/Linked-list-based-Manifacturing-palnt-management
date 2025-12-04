# Compiler and flags
CC = gcc
CFLAGS = -Wall -I./inc -I../../functions/assignment/library/buildlib/inc

# Directories
SRC = src
BIN = bin
lib_path= ../../functions/assignment/library/buildlib/libra/
libname= validation
# Collect all .c files and convert to .o
SRC_FILES = $(wildcard $(SRC)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

# Final target
TARGET = $(BIN)/main

# Default rule
all: $(TARGET)

# Link object files
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -L$(lib_path) -l$(libname) -o $(TARGET)

# Rule for compiling .c to .o
$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(SRC)/*.o $(TARGET)
