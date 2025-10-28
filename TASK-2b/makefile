# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I.
LDFLAGS = -lm

# Directories
BIN_DIR = bin

# Source files
SRCS1 = code/subTask1.c
SRCS2 = code/subTask2.c

# Executable files
EXEC1 = $(BIN_DIR)/subTask1
EXEC2 = $(BIN_DIR)/subTask2

# Default target: Build all programs
all: $(EXEC1) $(EXEC2)

# Target to create the bin directory
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Target to build subTask1
$(EXEC1): $(SRCS1) | $(BIN_DIR)
	@echo "Building $@"
	@$(CC) $(CFLAGS) -o $@ $(SRCS1) $(LDFLAGS)

# Target to build subTask2
$(EXEC2): $(SRCS2) | $(BIN_DIR)
	@echo "Building $@"
	@$(CC) $(CFLAGS) -o $@ $(SRCS2) $(LDFLAGS)

# Target to run subTask1
run1: $(EXEC1)
	@echo "Running subTask1..."
	@./$(EXEC1)

# Target to run subTask2
run2: $(EXEC2)
	@echo "Running subTask2..."
	@./$(EXEC2)

# Target to clean executables
clean:
	@echo "Cleaning executables..."
	@rm -rf $(BIN_DIR)

# Phony targets
.PHONY: all run1 run2 clean