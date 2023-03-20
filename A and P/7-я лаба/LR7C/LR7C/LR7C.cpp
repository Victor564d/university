#pragma warning(disable : 4996) ;

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>


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



 main()
{
     clerk_t* mas;
     SetConsoleCP(1251); // Задаем таблицу символов для консоли.
     SetConsoleOutputCP(1251);
     int selector = 1;  int n = 0; mas = 0; // селектор - выбор пункта, мас -сам массив, его над задавать как 0
     while (selector != 0) //цикл меню , выходит из него как ток будет 0
     {
         system("cls");
         printf("\n\nВыберите необходимый пункт \n");
         printf("1 - Ввод клерков с клавиатуры \n");
         if (n > 0) {
             printf("2 - Вывод клерков на экран \n");
             printf("3 - Сортировка по полю \n");
             printf("4 - Поиск клерка с максимальным окладом \n");
         }
         printf("\n0 - Выход\n\n");
         scanf("%d", &selector); //считали селектор
         switch (selector)  //вызов функции в зависимости от селектора
         {  
         case 1: {printf("\n Введите размер массива --> "); scanf("%d", &n); mas = scan_clerk(n); break; };  //ввод
         case 2: {print_clerk(mas, n); break;  }; //вывод
         case 3: {int flag; printf("Введите флаг сортировки, 0 - по убыванию, 1 - по возрастанию -->"); scanf("%d", &flag); sort_array(mas, n, flag); break;  }; //положительные в квадрат
         case 4: {  char divis[32]; printf("Введите подразделение в котором будет выполнен поиск --> "); scanf("%s", divis);
                    int max_ock = search_element(mas, n, divis); 
                    if (max_ock != -1) { printf("\nКлерк с максимальным окладом(номер) --> %d \n", max_ock); 
                    print_clerkOne(&mas[max_ock]);
                    }
                    else printf("\nНе правильно введена должность/нет подходящего клерка ");
                    printf("\a");
                    getch();
                    break; }; // произведение на интервале
         default:
             break;
         }
     }
     free(mas);
    return 0;
}

 /* Печать информации */
 void print_clerkOne(const clerk_t* e)
 {
         printf("Клерк:\r\n");
         printf(" *  Порядковый номер: %02d.\r\n", e->num);
         printf(" *  Фамилия:          <%s>.\r\n", e->surname);
         printf(" *  Имя:              <%s>.\r\n", e->name);
         printf(" *  Должность:        <%s>.\r\n", e->position);
         printf(" *  Стаж:             %d.\r\n", e->exp);
         printf(" *  Подразделение:    <%s>.\r\n", e->division);
         printf(" *  Оклад:            %.3f руб.\r\n", e->salary);
 }

 /* Печать информации  о всех */
 void print_clerk(const clerk_t* e, int arr_len)
 {
     for (int i = 0; i < arr_len; i++) { //цикл вывода 
         print_clerkOne(&e[i]);
     }
     printf("\a"); // звук окончания вывода 
     getch(); //ждем ввод чего либо
 }

 /* Ввод информации */
 clerk_t* scan_clerk(int arr_len)
 {
     clerk_t* e = (clerk_t*)malloc(sizeof(clerk_t) * arr_len); //выделение памяти
     for (int i = 0; i < arr_len; i++) { //цикл ввода
         printf("Добавление информации о Клерк:\r\n");
         printf(" *  Введите Фамилию:       "); scanf("%s", &e[i].surname); 
         printf(" *  Введите Имя:           "); scanf("%s", e[i].name);
         printf(" *  Введите Должность:     "); scanf("%s", e[i].position); 
         printf(" *  Введите Стаж(лет):     "); scanf("%d",&e[i].exp); 
         printf(" *  Введите Подразделение: "); scanf("%s", e[i].division); 
         printf(" *  Введите Оклад:         "); scanf("%lf", &e[i].salary);
         e[i].num = i; //личный идинтификатор = номеру при создании 
     }
 
     return e; //возвращаем указатель
 }

 /* Сортировка по полю */
 void sort_array(clerk_t* arr, int arr_len, int sort_order_flag)
 {
     clerk_t tmp = {0};

     for (int i = arr_len-1; i > 0; i--) // сортировка методом пузырька 
         for (int j = 0; j <i ; j++)
             if (
                 (sort_order_flag) ?
                 (((arr[j]).salary) > ((arr[j+1]).salary)) :   // Если сортировка по возрастанию
                 ((arr[j]).salary) < ((arr[j+1]).salary))     // Если сортировка по убыванию

             {
                 tmp = arr[j]; //временная переменная
                 arr[j] = arr[j+1];// замена местами 
                 arr[j+1] = tmp;
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
