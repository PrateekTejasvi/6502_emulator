CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = emulator
SRC = main.c cpu.c memory.c instruction_set.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
