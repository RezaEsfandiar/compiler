# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Project structure
INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objects
BIN_DIR = $(BUILD_DIR)/bin

# Source files (excluding token.cpp)
SOURCES = $(filter-out $(SRC_DIR)/token.cpp, $(wildcard $(SRC_DIR)/*.cpp))
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Target executable
TARGET = $(BIN_DIR)/LexicalAnalyzer

# Default target
all: build_dirs $(TARGET)

# Build the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Create build directories if not exist
build_dirs:
	mkdir -p $(BUILD_DIR) $(OBJ_DIR) $(BIN_DIR)

# Clean the build files
clean:
	rm -rf $(BUILD_DIR)

# Run the program
run: all
	$(TARGET)
