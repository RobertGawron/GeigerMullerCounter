CC=gcc
CFLAGS=-I./UTestLib
DEPS = utest.h
OBJ = main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

UnitTest: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)