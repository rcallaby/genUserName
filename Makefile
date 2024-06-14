# Define the compiler
CC = gcc

# Define the flags for the compiler
CFLAGS = -Wall -Wextra -O2

# Define the target executable
TARGET = genUserName

# Define the source files
SRCS = src/main.c src/fileOps.c src/userNameGen.c

# Define the object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the build
clean:
	rm -f $(OBJS) $(TARGET)

# Rule to run the program
run: $(TARGET)
	./$(TARGET) input.txt

.PHONY: all clean run
