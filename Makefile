all : prog

prog : main.o elevator.o person.o
	gcc -g -o prog main.o elevator.o person.o -lncurses

main.o : main.c
	gcc -g -c main.c

elevator.o : elevator.c
	gcc -g -c elevator.c

person.o : person.c
	gcc -g -c person.c

clean :
	rm -rf *.o prog

run : 
	./prog

CFLAGS  : -g
