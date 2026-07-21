CC = gcc

SRC = hello.c
TARGET = hello

CFLAGS = -I./raylib-dist/include
LDFLAGS = -L./raylib-dist/lib
LIBS = -lraylib -lm -lpthread -ldl -lrt -lX11

.PHONY: all clean run rebuild

all: rebuild

rebuild: clean $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS) $(LIBS)

run: rebuild
	./$(TARGET)

clean:
	rm -f $(TARGET)
