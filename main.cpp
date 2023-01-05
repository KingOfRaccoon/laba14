#include <iostream>
#include "modSp.h"

using namespace std;

int main() {
    list *first, *end;
    telem ch;
    setlocale(LC_ALL, "Russian");
    initList(&first, &end);
    cout << "\nВ списке L из каждой группы подряд идущих элементов " << endl
         << "сравными значениями оставить только один." << endl;
    cout << "Введите элементы списка (символы) сплошной строкой;"
         << "в конце - точка:" << endl;
    cin >> ch;
    while (ch != '.') {
        addItemInList(ch, &first, &end);
        cin >> ch;
    }
    cout << "Исходный список:" << endl;
    printList(first);
    processing(&first);
    cout << "Результат получен:\n";
    printList(first);
    deleteList(&first, &end);
    return 0;
}