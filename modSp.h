typedef char telem;
struct list {
    telem data;
    list *link;
};

void initList(list **, list **);

void addItemInList(telem, list **, list **);

void processing(list **);

void printList(list *);

void deleteList(list **, list **);