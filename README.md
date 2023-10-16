# weapon-shop

# Compiler and linker flags
CC := clang++
SRC_DIR := src
BIN_DIR := bin
BIN_EXE := $(BIN_DIR)/sfmlgame
OUTPUT := $(if $(findstring Windows_NT, $(OS)), $(BIN_EXE).exe, $(BIN_EXE))
OBJ_DIR := $(BIN_DIR)/obj
INC_DIRS := -I$(SRC_DIR)
LIB_DIRS := -L$(SFML_DIR)/lib
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
H_FILES := $(wildcard $(SRC_DIR)/*.h)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
CPP_FLAGS := -03 -std=c++20
LD_FLAGS := -03 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# MAKEFLAGS := -j8

# Compile the object files and place them in their own directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(H_FILES)
	$(CC) $(CPP_FLAGS) $(INC_DIRS) -c -o $@ $<

# Link the object files together to create the final executable
$(OUTPUT): $(OBJ_FILES) Makefile
	$(CC) $(LIB_DIRS) $(LD_FLAGS) $(OBJ_FILES) -o $(OUTPUT)

# When we type make, compile and link the executable
all: $(OUTPUT)

# If we type 'make run' it will build and then run the executable
run: $(OUTPUT)
	$(if $(findstring Windows_NT, $(OS)), cd bin && sfmlgame.exe && cd .., cd bin && ./sfmlgame && cd ..)

# If we type 'make clean' it will clean up all the object files and the executable
clean:
	$(if $(findstring Windows_NT, $(OS)), del bin\obj\*.o && del bin\sfmlgame.exe, rm $(OBJ_DIR)/*.o && rm $(OUTPUT))