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

PersonList* createList(PersonList *list) {
    list->next = NULL;
}

PersonList* insert(Person *p, PersonList *list) {
    list->person = p;
    list->next = list;
    return list;
}

