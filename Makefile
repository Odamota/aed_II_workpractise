all: printy

printy: main.o functions.o
	ggcc -o testit main.c functions.c

main.o: main.c helloWorld.h
	gcc -o main.o main.c -c -W -Wall -ansi -pedantic

helloWorld.o: helloWorld.c helloWorld.h
	gcc -o helloWorld.o helloWorld.c -c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o *~ printy

queue_generica: main.o functions.o
	gcc -o test main.o functions.o

main.o: main.c queue.h
	gcc -c -Wall main.c

queue.o: queue.h queue.c
	gcc -c -Wall queue.c
