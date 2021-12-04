CC = clang
CXX = clang++ -std=c++17
LDFLAGS = lib/glfw/src/libglfw3.a lib/glad/src/glad.o
LDFLAGS += -Ilib/glfw/include -Ilib/glad/include
LDFLAGS += -framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.c=.o)
BIN = bin

all: dirs libs game

dirs:
	mkdir -p ./$(BIN)

libs:
	cd lib/glad && $(CC) -o src/glad.o -Iinclude -c src/glad.c
	cd lib/glfw && cmake . && make

game: $(OBJ)
	$(CXX) -o $(BIN)/minecraft $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $<

clean:
	rm -rf $(BIN) $(OBJ)