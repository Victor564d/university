#pragma warning(disable : 4996) ;

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define DESCENDING_SORT (0)
#define ASCENDING_SORT  (1)

typedef
struct clerk
{
    int
        num, exp;

    char
        name[32],
        surname[32],
        position[32],
        division[32];
    double
        salary;
}
clerk_t;
/* Печать информации */
void print_clerkOne(const clerk_t* e);
/* Печать информации  о всех*/
void print_clerk(const clerk_t* e, int arr_len);
/* Ввод информации */
clerk_t* scan_clerk(int arr_len);
/* Сортировка по полю */
void sort_array(clerk_t* arr, int arr_len, int sort_order_flag);
/*
    Поиск Клерка с максимальным окладом.
    Вернуть индекс этого Клерка.
*/
static int search_element(clerk_t arr[], int arr_size, const char* division);



int main()
{
    clerk_t* mas;
    SetConsoleCP(1251); // Задаем таблицу символов для консоли.
    SetConsoleOutputCP(1251);
    int selector = 1;  int n = 0; mas = 0; // селектор - выбор пункта, мас -сам массив, его над задавать как 0
    while (selector != 0) //цикл меню , выходит из него как ток будет 0
    {
        system("cls");
        cout<<("\n\nВыберите необходимый пункт \n");
        cout << ("1 - Ввод клерков с клавиатуры \n");
        if (n > 0) {
            cout << ("2 - Вывод клерков на экран \n");
            cout << ("3 - Сортировка по полю \n");
            cout << ("4 - Поиск клерка с максимальным окладом \n");
        }
        cout << ("\n0 - Выход\n\n");
        cin >> selector; //считали селектор
        switch (selector)  //вызов функции в зависимости от селектора
        {
        case 1: {cout << ("\n Введите размер массива --> "); cin >> n; mas = scan_clerk(n); break; };  //ввод
        case 2: {print_clerk(mas, n); break;  }; //вывод
        case 3: {int flag; cout << ("Введите флаг сортировки, 0 - по убыванию, 1 - по возрастанию -->"); cin >> flag; sort_array(mas, n, flag); break;  }; //положительные в квадрат
        case 4: {  char divis[32]; cout << ("Введите подразделение в котором будет выполнен поиск --> "); cin >> divis;
            int max_ock = search_element(mas, n, divis);
            if (max_ock != -1) {
                cout << "\nКлерк с максимальным окладом(номер) -->  "<< max_ock<<endl;
                print_clerkOne(&mas[max_ock]);
            }
            else cout << ("\nНе правильно введена должность/нет подходящего клерка ");
            cout << ("\a");
            getch();
            break; }; // произведение на интервале
        default:
            break;
        }
    }
    delete []mas;
    return 0;
}

/* Печать информации */
void print_clerkOne(const clerk_t* e)
{
    cout << ("Клерк:\r\n");
    cout << " *  Порядковый номер: "<< e->num<< "\r"<<endl;
    cout << " *  Фамилия:         "<< e->surname << "\r"<<endl;
    cout << " *  Имя:             "<< e->name << "\r" << endl;
    cout << " *  Должность:       " <<e->position << "\r" << endl;
    cout << " *  Стаж:            " <<e->exp << "\r" << endl;
    cout << " *  Подразделение:   " <<e->division << "\r" << endl;
    cout << " *  Оклад:           "<< e->salary << "\r" << endl;
}

/* Печать информации  о всех */
void print_clerk(const clerk_t* e, int arr_len)
{
    for (int i = 0; i < arr_len; i++) { //цикл вывода 
        print_clerkOne(&e[i]);
    }
    cout << ("\a"); // звук окончания вывода 
    getch(); //ждем ввод чего либо
}

/* Ввод информации */
clerk_t* scan_clerk(int arr_len)
{
    clerk_t* e = new clerk_t[arr_len]; //выделение памяти
    for (int i = 0; i < arr_len; i++) { //цикл ввода
        cout << ("Добавление информации о Клерк:\r\n");
        cout << (" *  Введите Фамилию:       "); scanf("%s", &e[i].surname);
        cout << (" *  Введите Имя:           "); scanf("%s", e[i].name);
        cout << (" *  Введите Должность:     "); scanf("%s", e[i].position);
        cout << (" *  Введите Стаж(лет):     "); scanf("%d", &e[i].exp);
        cout << (" *  Введите Подразделение: "); scanf("%s", e[i].division);
        cout << (" *  Введите Оклад:         "); scanf("%lf", &e[i].salary);
        e[i].num = i; //личный идинтификатор = номеру при создании 
    }

    return e; //возвращаем указатель
}

/* Сортировка по полю */
void sort_array(clerk_t* arr, int arr_len, int sort_order_flag)
{
    clerk_t tmp = { 0 };

    for (int i = arr_len - 1; i > 0; i--) // сортировка методом пузырька 
        for (int j = 0; j < i; j++)
            if (
                (sort_order_flag) ?
                (((arr[j]).salary) > ((arr[j + 1]).salary)) :   // Если сортировка по возрастанию
                ((arr[j]).salary) < ((arr[j + 1]).salary))     // Если сортировка по убыванию

            {
                tmp = arr[j]; //временная переменная
                arr[j] = arr[j + 1];// замена местами 
                arr[j + 1] = tmp;
            }

    // Расстановка правильных порядковых номеров
    for (int i = 0; i < arr_len; i++)
        arr[i].num = i;
}

/*
    Поиск Клерка с максимальным окладом.
    Вернуть индекс этого Клерка.
*/
static int search_element(clerk_t arr[], int arr_size, const char* division)
{
    int max_salary_num = -1; //задаем начальный флаг как -1;

    for (int i = 0; i < arr_size; i++) //в цикле просматриваем весь массив записей
        if (!strcmp(arr[i].division, division) && //если совпадает должность
            (
                (max_salary_num != -1) ? //проверяем , если флаг не равен -1, то происходит сравнение максимального заработка с текущим заработком 
                (arr[i].salary > arr[max_salary_num].salary) :
                (1) //иначе выдадим 1, да бы запомнить индекс элемента с максимальным окладом  
                )
            )
            max_salary_num = i; //запоминаем индекс с максимальным окладом

    return max_salary_num; // возвращаем максимальный оклад 
}
