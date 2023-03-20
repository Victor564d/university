// DZ7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma warning(disable : 4996) 
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>


int* in_mas(int* mas, int n); //ввод массива
int* pol_sq(int* mas,int n); // положительные возводит в квадрат
int proiz(int* mas, int n); // Поиск произведения чисел находящихся в интервале
int poisk_elems(int* mas, int n); //поиск кратных одному числу и не кратных другому 
int poisk_max(int* mas, int n); // поис максимума по модулю 
int* preobr_mas(int* mas, int n); // перенос кратных в начало , не кратных после кратных
void out_mas(int* mas, int n); //вывод 

main()
{
    SetConsoleCP(1251); // Задаем таблицу символов для консоли.
    SetConsoleOutputCP(1251);
    int selector = 1; int* mas; int n = 0; mas = 0; // селектор - выбор пункта, мас -сам массив, его над задавать как 0
    while (selector != 0) //цикл меню , выходит из него как ток будет 0
    {
        
        printf("\n\nВыберите необходимый пункт \n");
        printf("1 - Ввод массива с клавиатуры \n");
        if (n > 0) {
            printf("2 - Вывод элементов массива на экран \n");
            printf("3 - Замена положительных элементов на квадраты \n");
            printf("4 - Функция произведения элементов в интервале \n");
            printf("5 - Поис количества элементов кратных A и не кратных B \n");
            printf("6 - Поиск максимального по модулю элемента и его индекса \n");
            printf("7 - Преобразование массива так, сначала все четные потом нечетные \n");
                   }
        printf("\n0 - Выход\n\n");
        scanf("%d", &selector); //считали селектор
        switch (selector)  //вызов функции в зависимости от селектора
        {
        case 1: {printf("\n Введите размер массива --> "); scanf("%d", &n); mas = in_mas(&mas, n); break; };  //ввод
        case 2: {out_mas(mas, n); break;  }; //вывод
        case 3: {pol_sq(mas, n); break;  }; //положительные в квадрат
        case 4: {int prozv = proiz(mas, n); printf("\nНа заданном интервале произведение = %d", prozv); break; }; // произведение на интервале
        case 5: {int col = poisk_elems(mas, n); printf("Колличество элементов соответствующим введенным параметрам = %d", col); break; }; //поиск кратных и не кратных
        case 6: {printf("Индекс максимального по модулю значения и его значения --> mas[%d] = %d", poisk_max(mas, n), mas[poisk_max(mas, n)]); break; }; // максимальный по модулю 
        case 7: {mas = preobr_mas(mas, n); break; };// преобразование массива
        default:
            break;
        }
    }
    free(mas); //очистка памяти
    return 0;

}

int* in_mas(int* mas, int n)  
{

    mas = (int*)malloc(sizeof(int) * n); //выделяем память
    for (int i = 0; i < n; i++)  // цикл считывания значений
    {
        printf("\nВведите mas[%d] -->", i);
        scanf("%d", &mas[i]);
    }
    return mas; //возвращаем массив
}


void out_mas(int* mas, int n)  
{
    printf("\nМассив элементов\n ");
    for (int i = 0; i < n; i++) { //цикл вывода
        printf(" mas[%d] = %d ", i, mas[i]);
    }
    printf("\n");
}


int* pol_sq(int* mas, int n) 
{
    for (int i = 0; i < n; i++)  //цикл поиска
    {
        if (mas[i] > 0) mas[i] *= mas[i];// если положительное то вовзводим в квадрат
    }
    return mas; //возвращаем значение 
}

int proiz(int* mas, int n) 
{
    int max, min,proizv = 1;
    printf("\n Введите минимальное значение интервала -->"); scanf("%d", &min);
    printf("\n Введите максимальное значение интервала -->"); scanf("%d", &max);
    for (int i = 0; i < n; i++) 
    {
        if ((mas[i] >= min) && (mas[i] <= max)) proizv *= mas[i]; //если значение лежит в интервале , то произведение умножаем на него
    }
    return proizv; //возврат произведения
}

int poisk_elems(int* mas, int n)
{
    int A, B, col=0;
    printf("\n Введите A (Значение кратно этому числу)  -->"); scanf("%d", &A);
    printf("\n Введите B (Значение не кратно этому числу)  -->"); scanf("%d", &B);
    for (int i = 0; i < n; i++)
    {
        if ((mas[i] % A == 0) && (mas[i] % B != 0))  col++; //если число соответствует кратности и не кратности , то увеличиваем счётчик
    }
    return col; //возврат колличества элементов кратных одному и не кратных другому 
}

int poisk_max(int* mas, int n) 
{
    int max_index=0; //Индекс максимально , по умолчанию 0
    for (int i = 1; i < n; i++)  //Цикл поиска 
    {
        if (abs(mas[max_index]) < abs(mas[i])) max_index = i; //если по модулю макс меньше значения , то запоминаем новый индекс максимального
    }
    return max_index; // возвращаем максимальный индекс
}

int* preobr_mas(int* mas, int n)
{
    int counter = 0; //счётчик текущего положения
    int* temp = (int*)malloc(sizeof(int) * (n)); //выделяем память под копию массива
    memmove(temp, mas,sizeof(int)*n); //делаем копию массива для предотвращения утери данных
    for (int i = 0; i < n; i++)  //цикл поиска кратных двум
    {
            if (!(temp[i]%2)) //если нашли кртаное 
            {
                printf("Кратное %d\n",temp[i]);
                mas[counter] = temp[i]; //записываем кратное двум
                counter++;//увеличиваем позицю 
            }
    }
    for (int i = 0; i < n; i++) //второй цикл поиска не кратных
    {
        if (temp[i] % 2) //если нашли не кратный 
        {
            printf("Не кратное %d\n", temp[i]);
            mas[counter] = temp[i]; //записываем не кратное  двум
            counter++;//увеличиваем позицю 
        }
    }
    free(temp); //очищаем занимаемую массивом temp память
    return mas; // возвращаем значения
}
