CC = gcc
CFLAGS = -Wall -fpic -I./Inc
DUT_SRC_PATH = ./Src
STUB_SRC_PATH = ./DriversPCSimulation
default: all

all: simulation.o \
	gm_circular_buffer.o \
	gm_display_updater.o \
	gm_measurement_calculator.o \
	gm_logger.o \
	gm_display_sim.o \
	gm_logger_sim.o
	$(CC) $(CFLAGS) -shared -o simulation.so simulation.o \
		gm_circular_buffer.o \
		gm_display_updater.o \
		gm_measurement_calculator.o \
		gm_logger.o \
		gm_display_sim.o \
		gm_logger_sim.o

main.o:  simulation.c
	$(CC) $(CFLAGS) -c simulation.c

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
	$(RM) *.so *.o *~
