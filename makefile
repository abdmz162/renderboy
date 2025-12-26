###
CC = gcc

SRC = $(wildcard src/*.c) $(wildcard src/types/*.c)

OUT = build/game

# Include paths (adjust if raylib is elsewhere)
INCLUDE = -Iraylib-dist/include

# Linux raylib + X11 dependencies
LIB = -Lraylib-dist/lib -lraylib -lm -lpthread -ldl -lrt -lX11


all:
	$(CC) $(SRC) -o $(OUT) $(INCLUDE) $(LIB)

clean:
	rm -f $(OUT)

run:
	./$(OUT)
