#include <iostream>
#include "modSp.h"

using namespace std;

void processing(list **first) {
    list *tec;
    list *prev;
    list *temp;

    while ((*first)->link && (*first)->link->data == (*first)->data) {
        *first = (*first)->link;

    }

    tec = (*first)->link;
    prev = (*first);
    while (tec) {
        if (tec->link == nullptr) {
            temp = prev->link;
            prev->link = tec;
            delete temp;
            break;
        }

        if (tec->data != tec->link->data) {
            if (prev->link != tec) {
                temp = prev->link;
                prev->link = tec;
                delete temp;
            }

            prev = prev->link;
        }

        tec = tec->link;
    }
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

void printList(list *tec) {
    do {
        cout << tec->data;
        tec = tec->link;
    } while (tec);
    cout << endl;
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