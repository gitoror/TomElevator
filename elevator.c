#include "elevator.h"

#include <stdlib.h>
#include <stdio.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons) {
    Elevator *elevator = malloc(sizeof(Elevator));
    elevator->capacity = capacity;
    elevator->currentFloor = currentFloor;
    elevator->persons = persons;
    return elevator;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists) {
    Building *building = malloc(sizeof(Building));
    building->nbFloor = nbFloor;
    building->elevator = elevator;
    building->waitingLists = waitingLists;
    return building;
}

PersonList* exitElevator(Elevator *e) {
    // This functions returns the list of persons who quit the elevator
    // and actualize the persons who stay inside.
    PersonList *exitList = NULL; //ppl who leave the elevator
    PersonList *newList = NULL; // people who remain in the elevator
    PersonList *persons = e->persons; // for the while
    Person *p;
    while (persons != NULL) {
        p = persons->person;
        if (p->dest  == e->currentFloor) {
            exitList = insert(p,exitList);
        }
        else {
            newList = insert(p,newList);
        }
        persons = persons->next;
    }
    e->persons = newList; // people remaining in the elevator
    return exitList; 
}

PersonList* enterElevator(Elevator *e, PersonList *waitingList) {
    // This function returns the new list of people who are waiting at the 
    // floor where the elevator is. It also actualize the persons inside the 
    // elevator because of entrance.

    // Count the number of persons in the elevator to compare with capacity.  
    int numberPersons = 0;
    PersonList *countList = e->persons; // for the while
    while  (countList != NULL) {
        numberPersons++;
        countList = countList->next;
    }

    
    PersonList *newList = NULL; // people who remain in the elevator
    PersonList *newWaitingList = NULL; // people who stay outside the elevator

    PersonList *_waitingList = waitingList; // for the while
    while (_waitingList != NULL) {
        Person *p = _waitingList->person;
        if (p->src == e->currentFloor & numberPersons < e->capacity) {
            newList = insert(p, newList);
            numberPersons++;
        }
        else {
            newWaitingList = insert(p, newWaitingList); 
            // We could reverse this list to keep the same order in the waiting list.
        }
        _waitingList = _waitingList->next;
    }
    e->persons = newList;
    return newWaitingList;
}

void stepElevator(Building *b) {
    Elevator *e = b->elevator;
    if (e->currentFloor != e->targetFloor) {
        e->currentFloor = e->targetFloor; // an input changed targetFloor
        // Actualize people in the elevator and waiting, useful to print new people. 
        PersonList *exitList = exitElevator(e);  
        b->waitingLists[e->currentFloor] = enterElevator(e,b->waitingLists[e->currentFloor]);  
    }
}
