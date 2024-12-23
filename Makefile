TARGET = a.out
TEST = -g -DTEST
CFLAGS := -O2 -Wall
#CFLAGS := -O2 -Wall -DTEST

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $@ $^

test: main.c
	$(CC) $(TEST) -o $(TARGET).test $^

clean:
	rm $(TARGET) *.o

.PHONY: clean test
