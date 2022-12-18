#include <iostream>
#include "modSp.h"

using namespace std;

void processing(list *first) {
    list *tec = first;
    list *vr;
    list *prev;
    while (tec && tec->link->link) {
        if (tec->data == tec->link->data) {
            vr = tec->link;
            tec->link = tec->link->link;
            delete vr;
        } else {
            prev = tec;
            tec = tec->link;
        }
    }

    if (tec->data == tec->link->data) {
        vr = prev->link;
        prev->link = tec->link;
        delete vr;
    }
}

void printList(list *tec) {
    do {
        std::cout << tec->data;
        tec = tec->link;
    } while (tec);
}

void addItemInList(telem ch, list **first, list **end) {
    list *nov = new list;
    nov->data = ch;
    nov->link = nullptr;
    if (*first)
        (*end)->link = nov;
    else
        *first = nov;
    *end = nov;
}

void initList(list **first, list **end) {
    *first = *end = nullptr;
}

void deleteList(list **first, list **end) {
    list *tec;
    while (*first) {
        tec = *first;
        *first = (*first)->link;
        delete tec;
    }
    *end = nullptr;
}