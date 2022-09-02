CC = g++
CFLAGS = -Wall -g

main: main.o device.o task.o routine.o
	$(CC) $(CFLAGS) -o main main.o device.o task.o routine.o

main.o: main.cpp source\headers\Device.hpp source\headers\Task.hpp source\headers\Routine.hpp source\headers\List.hpp
	$(CC) $(CFLAGS) -c main.cpp

device.o: source\headers\Device.hpp
	$(CC) $(CFLAGS) -c source\Device.cpp

task.o: source\headers\Task.hpp
	$(CC) $(CFLAGS) -c source\Task.cpp

routine.o: source\headers\Routine.hpp
	$(CC) $(CFLAGS) -c source\Routine.cpp

#list.o: source\headers\List.hpp
#	$(CC) $(CFLAGS) -c source\List.cpp