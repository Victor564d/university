
#include <iostream>
template <typename t, typename t_key>
    int search(t t1, int size, t_key key)
    {
        for (int i = 0; i < size; i++) {
        if (t1[i] == key) return i;
    }
    return 0;
 }

using namespace std;

int main()
{
    system("chcp 1251");
    int m[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,28,30 };
    short s[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,28,30 };
    char c[] = { 'f','a', 's', 'd', 'e', 'n', '3', ';', 'l', '\'' };
    char vibor = 'x'; int key = -1; short keys = -1;
    while (key != 0) {
        cout << "Введите значение для поиска в массиве типа int, 0 для перехода на поиск в short --> "; cin >> key;
        int temp = search<int[], int>(m, 30, key);
        cout << (temp ? "Значение найдено " : "Значение не найдено ") <<"(индекс элемента ->" << temp<< ")" << endl;
    }
    while (keys != 0) {
        cout << "Введите значение для поиска в массиве типа short, 0 для перехода на поиск в char --> "; cin >> keys;
        int temp = search<short[], short>(s, 30, keys);
        cout << (temp ? "Значение найдено " : "Значение не найдено ") << "(индекс элемента ->" << temp << ")" << endl;
    }
    while (vibor != '0') {
        cout << "Введите значение для поиска в массиве типа char, 0 для выхода--> "; cin >> vibor;
        int temp = search<char[], char>(c, 30, key);
        cout << (temp ? "Значение найдено " : "Значение не найдено ") << "(индекс элемента ->" << temp << ")" << endl;
    }

}

