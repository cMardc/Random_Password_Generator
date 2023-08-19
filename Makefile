# Makefile for Password Generator

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source file and output file
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OUT = $(BUILD_DIR)/password_generator

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	@rm -f $(OUT)

.PHONY: all clean

