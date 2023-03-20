// LR5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma warning(disable : 4996) 
#include <Windows.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>



const char glas[] = "aeiouy";//массив гласных 
char* in_pos(char* pos, int n);// Ввод последовательности
void out_pos(char* pos, int n);// Вывод последовательности
char* del_pos(char* pos, int n);//деление гласных и согласных
char* sort_pos(char* pos);//Сортировка последовательности

 main()
{
    SetConsoleCP(1251); // Задаем таблицу символов для консоли.
    SetConsoleOutputCP(1251);
    printf("Введите размер последовательности -->");
    int n; scanf("%d", &n); // считываем колличество элементов в последовательности
    char* pos =  in_pos(&pos, n);
    printf("\nВведенная последовательность :");
    out_pos(pos, n); //вызов вывода последовательности
    pos = del_pos(pos, n); //вызов функции деления последовательности по заданному правилу 
    printf("\nПреобразованная последовательность  :");
    out_pos(pos,n); // вызов вывода последовательности
    pos = sort_pos(pos); //вызов сортировки 
    printf("\nОтсортированная пооследовательность  :");
    out_pos(pos, n);// вызов вывода последовательности
    free (pos);
    return 0;
}

char* in_pos(char* pos, int n) //функция ввода последовательности
{
    pos = (char*)malloc(sizeof(char) *  (n+1)); //чистим память под последовательность
    printf("Введите последовательность --> ");
    scanf("%s", pos);  //считываем последовательность в виде строки 
    return pos;
}

void out_pos(char* pos,int n)// Вывод последовательности
{
    for (int i = 0; i < n; i++) { //цикл вывода
        printf("%c", pos[i]); //вывод элемента
    }
}

char* del_pos(char* pos, int n) 
{
    int counter=0; //счётчик текущего положения
    char* temp = (char*)malloc(sizeof(char) * (n )); //выделяем память под копию строки
    memmove(temp, pos, n); //делаем копию строки для предотвращения утери данных
    for (int i = 0; i < n; i++)  //цикл поиска гласных
     {
        for (int j = 0; j < 6; j++) //проверка по гласным
        { 
            if (temp[i] == glas[j]) //если нашли гласную 
            {
                pos[counter] = temp[i]; //записываем гласную
                counter++;//увеличиваем позицю 
                break;//завершаем проверку 
            }
        }
     }
    for (int i = 0; i < n; i++) //второй цикл поиска не гласных
    {
        int tip = 0;//если тип = 0 , то это согласная буква , иначе гласная 
        for (int j = 0; j < 6; j++) //проверка , гласный ли текущий символ
        {
            if (temp[i] == glas[j])
            {
                tip = 1;
                break;
            }
        }
        if (!tip) { // если он не гласный , то записываем его 
            pos[counter] = temp[i];
            counter++; // переводим позицию
        }
    }
    free(temp); //очищаем занимаемую массивом temp память
    return pos; // возвращаем значения
}

char* sort_pos(char* pos) 
{
    printf("\nВведите начальный индекс сортировки -->");
    int p; scanf("%d", &p);
    printf("\nВведите конечный индекс сортировки -->");
    int q; scanf("%d", &q);
    char temp;
    for (int j = q; j > 1; j--) //сортировка левой части 
        for (int i = p; i < j ; i++)// сравнение двух соседних элементов
            if (pos[i] > pos[i + 1])
            {
                temp = pos[i]; // перестановка элементов
                pos[i] = pos[i + 1];
                pos[i + 1] = temp;
            }
    return pos;
}