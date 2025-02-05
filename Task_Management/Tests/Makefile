CC=gcc
CFLAGS=
TARGET=test.out
SRC=testsDate.c \
	../Unity/unity.c \
	../Date/date.c
INC=-I../Unity -I../Date
OBJ=$(SRC:.c=.o)
test_Date: $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(TARGET) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
clean:
	rm -f $(TARGET) $(OBJ)