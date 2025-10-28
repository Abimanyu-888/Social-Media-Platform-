# Compiler

CC = gcc

# Compiler flags

CFLAGS = -Wall -Wextra -std=c99

# Directories

SRC_DIR = code
BIN_DIR = bin

# Executable names

TASK1 = $(BIN_DIR)/subTask1
TASK2 = $(BIN_DIR)/subTask2

# Source files

SRC1 = $(SRC_DIR)/subTask1.c
SRC2 = $(SRC_DIR)/subTask2.c

# Default target

all: $(TASK1) $(TASK2)

# Ensure bin directory exists

$(BIN_DIR):
mkdir -p $(BIN_DIR)

# Build Task 1

$(TASK1): $(SRC1) | $(BIN_DIR)
$(CC) $(CFLAGS) $(SRC1) -o $(TASK1)

# Build Task 2

$(TASK2): $(SRC2) | $(BIN_DIR)
$(CC) $(CFLAGS) $(SRC2) -o $(TASK2)

# Run Task 1

run1: $(TASK1)
./$(TASK1)

# Run Task 2

run2: $(TASK2)
./$(TASK2)

# Clean build files

clean:
rm -rf $(BIN_DIR)

.PHONY: all clean run1 run2
