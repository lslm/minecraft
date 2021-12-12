CC = clang
CXX = clang++ -std=c++17
LDFLAGS = lib/glfw/src/libglfw3.a lib/glad/src/glad.o
LDFLAGS += -Ilib/glfw/include -Ilib/glad/include -Isrc
LDFLAGS += -framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa

SRC = $(wildcard src/**/*.cpp src/**/**/*.cpp)
OBJ = $(SRC:.c=.o)
BIN = bin

all: dirs libs game

debug: dirs libs game_debug

dirs:
	mkdir -p ./$(BIN)

libs:
	cd lib/glad && $(CC) -o src/glad.o -Iinclude -c src/glad.c
	cd lib/glfw && cmake . && make

game: $(OBJ)
	$(CXX) -o $(BIN)/minecraft $^ $(LDFLAGS)

game_debug: $(OBJ)
	$(CXX) -g  -o $(BIN)/minecraft.a $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $<

clean:
	rm -rf $(BIN) $(OBJ)