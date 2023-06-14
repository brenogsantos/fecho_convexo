

CC = g++
CFLAGS = -g -Wall
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
EXECUTABLE = $(BIN_DIR)/fecho
PROJECT_ROOT = .

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
HDRS = $(wildcard $(INC_DIR)/*.h)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	ln -sf $(EXECUTABLE) $(PROJECT_ROOT)/fecho

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE) $(PROJECT_ROOT)/fecho

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	$(EXECUTABLE) $(filename)
