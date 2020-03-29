CC=gcc
FLAGS=-Wall -g
LIBFLAGS=-Wall -g -shared

all: task1 task2 task3

task1: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) main1_1.o hello_Ariel.o -o task1

task2: main1_2.o lib
	$(CC) $(FLAGS) main1_2.o -L. -l Hello -o task2

task3: main1_3.o lib
	$(CC) $(FLAGS) main1_3.o -fPIC -ldl -o task3

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_1.c

main1_2.o: main1_2.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_2.c

main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_3.c

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c -fPIC hello_Ariel.c

lib: hello_Ariel.o
	$(CC) $(LIBFLAGS) hello_Ariel.o -o libHello.so

.PHONY: clean all

clean:
	rm -f task1 task2 task3 *.o *.so


