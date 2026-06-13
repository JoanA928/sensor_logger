# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Wpedantic -std=c23

# Output executable name
TARGET = main

# Source files
SRC = main.c verification.c

# Header files
HEAD = verification.h

# Default rule
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC) $(HEAD)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Remove generated files
clean:
	rm -f $(TARGET)

# Rebuild from scratch
rebuild: clean all

# Run program
run: $(TARGET)
	./$(TARGET)
