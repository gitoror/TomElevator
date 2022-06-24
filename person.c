#include "person.h"

#include <stdlib.h>
#include <stdio.h>


Person* createPerson(int src, int dest) {
    Person *person = malloc(sizeof(Person));
    (*person).src = src;
    // ou person->src = src;
    (*person).dest = dest;
    return person;
}


PersonList* insert(Person *p, PersonList *list) {
    PersonList *newList = malloc(sizeof(PersonList));
    newList->person = p;
    newList->next = list;
    return newList;
}

