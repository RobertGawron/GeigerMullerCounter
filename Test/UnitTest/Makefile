CC = gcc
CFLAGS = -Wall -I./UTestLib -I../../Software/NUCLEO-F091RC/Inc
DUT_SRC_PATH = ../../Software/NUCLEO-F091RC/Src/

default: all

all:  main.o gm_circular_buffer.o 
	$(CC) $(CFLAGS) -o count main.o gm_circular_buffer.o

main.o:  main.c
	$(CC) $(CFLAGS) -c main.c

gm_circular_buffer.o:  $(DUT_SRC_PATH)/gm_circular_buffer.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_circular_buffer.c

clean: 
	$(RM) count *.o *~
