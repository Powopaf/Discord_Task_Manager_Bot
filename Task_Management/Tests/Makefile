CC=gcc
CFLAGS=-Wall -g

TARGET=test.out

SRC=testsDate.c \
 ../Unity/unity.c \
 ../Date/date.c \
 Utils/Date/utilsDate.c

OBJ=$(SRC:.c=.o)

INC=-I../Unity -I../Date -IUtils

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ)