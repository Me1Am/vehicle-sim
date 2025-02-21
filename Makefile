# Pre-compiler and Compiler flags
C_FLAGS := -Wall -Wextra -std=c11 -ggdb
PRE_FLAGS := 

# Project directory structure
BIN := bin
SRC := src
LIB := lib
INC := include

# Build directories and output
TARGET := $(BIN)/main
BUILD := build

# Library search directories and flags
EXT_LIB := "C:\\Users\\JTK6759\\Documents\\apps\\msys64\\mingw64\\lib"
LD_FLAGS := -l raylib
LDPATHS := $(addprefix -L,$(LIB) $(EXT_LIB))

# Include directories
INC_DIRS := $(INC) $(shell find $(SRC) -type d) 
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Construct build output and dependency filenames
SRCS := $(wildcard $(SRC)/*.c)
OBJS := $(subst $(SRC)/,$(BUILD)/,$(addsuffix .o,$(basename $(SRCS))))
DEPS := $(OBJS:.o=.d)

# Run task
run: build
	@echo "Executing..."
	./$(TARGET) $(ARGS)

# Build task
build: clean all

# Main task
all: $(TARGET)

# Task producing target from built files
$(TARGET): $(OBJS)
	@echo "Building..."
	mkdir -p $(dir $@)
	$(CC) $(OBJS) -o $@ $(LDPATHS) $(LD_FLAGS)

# Compile all c files
$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LD_FLAGS)

# Clean task
.PHONY: clean
clean:
	@echo "Clearing..."
	rm -rf build

# Include all dependencies
-include $(DEPS)