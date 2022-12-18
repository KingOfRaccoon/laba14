#include <iostream>
#include "modSp.h"

using namespace std;

int main() {
    list *first, *end;
    telem ch;
    setlocale(LC_ALL, "Russian");
    initList(&first, &end);
    cout << "\n� ������ L �� ������ ������ ������ ������ ��������� " << endl
         << "�������� ���������� �������� ������ ����." << endl;
    cout << "������� �������� ������ (�������) �������� �������;"
         << "� ����� - �����:" << endl;
    cin >> ch;
    while (ch != '.') {
        addItemInList(ch, &first, &end);
        cin >> ch;
    }
    if (first && first->link && first->link->link) {
        cout << "�������� ������:" << endl;
        printList(first);
        processing(first);
        cout << "\n��������� �������:\n";
        addItemInList('9', &first, &end);
        printList(first);
        deleteList(&first, &end);
    } else cout << "������ �� ������ ��� � ��� ������ 3-� ���������";
    return 0;
}