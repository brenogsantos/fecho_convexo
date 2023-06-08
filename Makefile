

CC = g++
CFLAGS = -g -Wall
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
EXECUTABLE = $(BIN_DIR)/main

# List of source files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
# List of object files (generated from the corresponding source files)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
# List of header files
HDRS = $(wildcard $(INC_DIR)/*.h)

# Rule to link object files and generate the executable
$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile individual source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@

# Rule to clean up object files and the executable
clean:
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)

# Default target (build the executable)
all: $(EXECUTABLE)

# Run the executable
run: $(EXECUTABLE)
	$(EXECUTABLE)
