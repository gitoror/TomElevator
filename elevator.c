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
    PersonList *exitList = NULL;
    PersonList *newList = NULL;
    Person *p = (e->persons)->person;
    while (e->persons->next != NULL) {
        if (p->dest != e->currentFloor) {
            insert(p,exitList);
        }
        else {
            insert(p,newList);
        }
        p = e->persons->next->person;
    }
    e->persons = newList;
    return exitList;
}

PersonList* enterElevator(Elevator *e, PersonList *waitingList) {  
    int numberPersons = 0;
    while (e->persons->next != NULL) {
        numberPersons++;
        e->persons = e->persons->next;
    }

    Person *newPerson = list->person;
    while(list->next != NULL) {
        if (numberPersons < e->capacity) {

        }
    }
}

void stepElevator(Building *b) {

}
