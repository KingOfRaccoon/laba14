#include <iostream>
#include "modSp.h"

using namespace std;

void processing(list **first) {
    list *tec;
    list *prev;
    list *temp;

    while ((*first)->link && (*first)->link->data == (*first)->data) {
        temp = *first;
        *first = (*first)->link;
        delete temp;
    }

    if ((*first)->link) {
        tec = (*first)->link;
        prev = (*first);
        while (tec->link) {
            if (tec->data != tec->link->data) {
                if (prev->link != tec) {
                    temp = prev->link;
                    prev->link = tec;
                    delete temp;
                }

                prev = prev->link;
                tec = tec->link;
            } else {
                temp = tec;
                tec = tec->link;
                delete temp;
                prev->link = tec;
            }
        }
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