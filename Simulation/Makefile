CC = gcc
CFLAGS = -Wall -I../Software/NUCLEO-F091RC/Inc
DUT_SRC_PATH = ../Software/NUCLEO-F091RC/Src/
STUB_SRC_PATH = ./Stub
default: all

all:  main.o \
	gm_circular_buffer.o \
	gm_display_updater.o \
	gm_measurement_calculator.o \
	gm_logger.o \
	gm_display_sim.o \
	gm_logger_sim.o
	$(CC) $(CFLAGS) -o main main.o \
		gm_circular_buffer.o \
		gm_display_updater.o \
		gm_measurement_calculator.o \
		gm_logger.o \
		gm_display_sim.o \
		gm_logger_sim.o

main.o:  main.c
	$(CC) $(CFLAGS) -c main.c

gm_circular_buffer.o:  $(DUT_SRC_PATH)/gm_circular_buffer.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_circular_buffer.c

gm_display_updater.o:  $(DUT_SRC_PATH)/gm_display_updater.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_display_updater.c

gm_measurement_calculator.o:  $(DUT_SRC_PATH)/gm_measurement_calculator.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_measurement_calculator.c	

gm_logger.o:  $(DUT_SRC_PATH)/gm_logger.c
	$(CC) $(CFLAGS) -c $(DUT_SRC_PATH)/gm_logger.c	


gm_display_sim.o:  $(STUB_SRC_PATH)/gm_display_sim.c
	$(CC) $(CFLAGS) -c $(STUB_SRC_PATH)/gm_display_sim.c	

gm_logger_sim.o:  $(STUB_SRC_PATH)/gm_logger_sim.c
	$(CC) $(CFLAGS) -c $(STUB_SRC_PATH)/gm_logger_sim.c	


clean: 
	$(RM) main *.o *~
