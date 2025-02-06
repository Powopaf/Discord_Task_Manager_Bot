CC=gcc
CFLAGS=-Wall -g

TARGET=main.out

SRC=main.c \
	Date/date.c \
	Task/task.c \

OBJ=$(SRC:.c=.o)

INC=-IDate -ITasks

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)