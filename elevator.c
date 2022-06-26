#include "elevator.h"

#include <stdlib.h>
#include <stdio.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons) {
    // Create an elevator
    Elevator *elevator = malloc(sizeof(Elevator));
    elevator->capacity = capacity;
    elevator->currentFloor = currentFloor;
    elevator->persons = persons;
    return elevator;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists) {
    // Create a building
    Building *building = malloc(sizeof(Building));
    building->nbFloor = nbFloor;
    building->elevator = elevator;
    building->waitingLists = waitingLists;
    return building;
}

PersonList *exitElevator(Elevator *e) {
    // This functions returns the list of persons who quit the elevator
    // and actualize the persons who stay inside.

    PersonList *exitList = NULL; // People who leave the elevator
    PersonList *personsInElevator = NULL; // Used to recreate the list of persons in the elevator after exit
    Person *p;
    PersonList *personsCheckDest = e->persons; // Used to see the destination of each person
    while (personsCheckDest != NULL) {
        p = personsCheckDest->person;
        if (p->dest == e->currentFloor) { // The persons quits the elevator
            exitList = insert(p, exitList); // Add the person to the exit list 
        }
        else { // The person stays in the elevator
            personsInElevator = insert(p,personsInElevator);
        }
        personsCheckDest = personsCheckDest->next; // Person checked.
    }

    // Reverse the list of people in the elevator to display it
    // in the same order as the precedent moment.
    PersonList *reverseList = NULL;
    while (personsInElevator != NULL) {
        Person *p = personsInElevator->person;
        reverseList = insert(p,reverseList);
        personsInElevator = personsInElevator->next;
    }
    
    e->persons = reverseList;
    return exitList;
}

PersonList *enterElevator(Elevator *e, PersonList *waitingList) {
    // This function returns the new list of people who are waiting at the
    // floor where the elevator is. It also actualize the persons inside the
    // elevator because of entrance.

    // Count the number of persons in the elevator to compare with capacity.
    int numberPersons = 0;
    PersonList *countList = e->persons; // for the while
    while (countList != NULL){
        numberPersons++;
        countList = countList->next;
    }

    while (waitingList != NULL & numberPersons < e->capacity) {
        Person *p = waitingList->person;
        e->persons = insert(p, e->persons); // The person enter in the elevator
        numberPersons++;
        waitingList = waitingList->next; // The persons quits the list
    }
    return waitingList;
}

void stepElevator(Building *b) {
    // This function actualize the elevator in the building if it changed floor.
    Elevator *e = b->elevator;
    if (e->currentFloor == e->targetFloor) {
        // Actualize people in the elevator and waiting, useful to print new people.
        PersonList *exitList = exitElevator(e);
        b->waitingLists[e->currentFloor] = enterElevator(e,b->waitingLists[e->currentFloor]);
    }
    
    if (e->currentFloor < e->targetFloor) {
        e->currentFloor++;
    }
    if (e->currentFloor > e->targetFloor) {
        e->currentFloor--;
    }
    
}
