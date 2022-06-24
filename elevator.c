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
    PersonList *newList;
    e->persons = createList(newList);
    return newList;
}

PersonList* enterElevator(Elevator *e, PersonList *list) {
    // list of new people
    Person* person = list->person;
    while (list->next != NULL) {
        person = (list->next)->person;
        insert(person, e->persons);
    }
    return e->persons;
}

void stepElevator(Building *b) {

}
