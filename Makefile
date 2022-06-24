all : prog

prog : main.o elevator.o person.o
	gcc -o prog main.o elevator.o person.o -lncurses

main.o : main.c
	gcc -c main.c

elevator.o : elevator.c
	gcc -c elevator.c

person.o : person.c
	gcc -c person.c

clean :
	rm -rf *.c prog

run : 
	./prog

