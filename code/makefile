# Compiler
CC = gcc

# Compiler flags
# -g: adds debugging information to the executable file
# -Wall: turns on most, but not all, compiler warnings
CFLAGS = -g -Wall -std=c99

# The target executable
TARGET = social_platform

# The source files
SRCS = main.c platform.c post.c comment.c reply.c

# The object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build directory
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
