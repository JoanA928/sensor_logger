# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Wpedantic -pthread -I$(LIBRARY)
# Output executable name
TARGET = main

# Source files
SRC = main.c verification.c generate_data.c

# Personal library
LIBRARY = library/

# Header files
HEAD = verification.h generate_data.h $(LIBRARY)/info_logger_macro.h

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
