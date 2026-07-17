# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Wpedantic -std=c23 -D_DEFAULT_SOURCE -pthread -I$(LIBRARY)

# Debug flags
DEBUG_FLAGS = -g -O0

# Output executable name
TARGET = main

# Source files
SRC = main.c verification.c generate_data.c collect_commands.c logger.c stop_command.c check_queue.c

# Personal library
LIBRARY = library

# Header files
HEAD = verification.h generate_data.h $(LIBRARY)/info_logger_macro.h $(LIBRARY)/app_state.h collect_commands.h logger.h check_queue.h

.PHONY: all debug clean run gdb

# Default rule
all: $(TARGET)

# Debug rule
debug: $(SRC) $(HEAD)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TARGET) $(SRC)

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

# Run program in debug mode
gdb: debug
	gdb ./$(TARGET)
