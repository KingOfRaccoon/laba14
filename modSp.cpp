#include <iostream>
#include "modSp.h"

using namespace std;

void processing(list **first) {
    list *tec;
    list *vr;
    list *last;

    while ((*first)->link && (*first)->link->data == (*first)->data) {
        *first = (*first)->link;
    }

    tec = (*first)->link;
    vr = (*first);
    printList(*first);
    while (tec) {
        if (tec->link == nullptr) {
            last = vr->link;
            vr->link = tec;
            delete last;
            break;
        }

        if (tec->data != tec->link->data && vr->link != tec) {
            last = vr;
            vr = tec;
            delete last;
            vr = vr->link;
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