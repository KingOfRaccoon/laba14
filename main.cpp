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
    cout << "�������� ������:" << endl;
    printList(first);
    processing(&first);
    cout << "��������� �������:\n";
    printList(first);
    deleteList(&first, &end);
    return 0;
}