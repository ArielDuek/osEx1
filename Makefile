CC=gcc
FLAGS=-Wall -g
LIBFLAGS=-Wall -g -shared

all: task1.1 task1.2 task1.3 task2.1 task2.2 task2.3 task2.4

task1.1: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) main1_1.o hello_Ariel.o -o task1.1

task1.2: main1_2.o lib
	$(CC) $(FLAGS) main1_2.o -L. -l Hello -o task1.2

task1.3: main1_3.o lib
	$(CC) $(FLAGS) main1_3.o -fPIC -ldl -o task1.3

task2.1:main2_1.o
	$(CC) $(FLAGS) main2_1.o -o task2.1

task2.2:main2_2.o
	$(CC) $(FLAGS) main2_2.o -o task2.2

task2.3:main2_3.o
	$(CC) $(FLAGS) main2_3.o -o task2.3

task2.4:main2_4.o
	$(CC) $(FLAGS) main2_4.o -o task2.4

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_1.c

main1_2.o: main1_2.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_2.c

main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_3.c

main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_3.c

main2_1.o: main2_1.c
	$(CC) $(FLAGS) -c main2_1.c

main2_2.o: main2_2.c
	$(CC) $(FLAGS) -c main2_2.c

main2_3.o: main2_3.c
	$(CC) $(FLAGS) -c main2_3.c

main2_4.o: main2_4.c
	$(CC) $(FLAGS) -c main2_4.c

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c -fPIC hello_Ariel.c

lib: hello_Ariel.o
	$(CC) $(LIBFLAGS) hello_Ariel.o -o libHello.so

.PHONY: clean all

clean:
	rm -f task1.1 task1.2 task1.3 *.o *.so./main task2.1 task2.2 task2.3 task2.4


