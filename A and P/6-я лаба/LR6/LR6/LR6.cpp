// LR6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma warning(disable : 4996) 
#include <Windows.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

int** in_matrix(int** matrix, int a,int  b);
int** in_matrix_random(int** matrix, int a, int b);
void sum_stolbs(int** matrix, int a, int b);
void sedlovie(int** matrix, int a, int b);
void vivod_matrix(int** matrix, int a, int b);
int kol_noli(int** matrix, int a, int b);

 main()
{
     int** matrix = NULL;
    
     int a, b;   int result;
     SetConsoleCP(1251); // Задаем таблицу символов для консоли.
     SetConsoleOutputCP(1251);
     while (1) {
         printf("Выберить способ ввода матрицы, 1 - С клавиатуры, 2 - Рандом ---> ");
       scanf("%d", &result);
         if ((result == 1) || (result == 2)) break;
     }
     printf("\nВведите количество строк --> "); scanf("%d", &a);
     printf("\nВведите количество столбцов --> "); scanf("%d", &b);
     printf("\nЗадается матрица размером %d x %d", a, b);
     if (result == 1) 
     {
         matrix = in_matrix(matrix, a, b);
     }
     else 
     {
         matrix = in_matrix_random(matrix, a, b);
     }
     vivod_matrix(matrix, a, b);
     sum_stolbs(matrix, a, b);
     sedlovie(matrix, a, b);
     printf("\n\nКооличесво столбцов не имеющих 0-вого элемента --->%d", kol_noli(matrix, a, b));
   //  for (int i = 0; i < a; i++)  // цикл по строкам
     //    free(matrix[i]);   // освобождение памяти под строку
     //free(matrix);
}



 int** in_matrix(int** matrix, int a, int  b) 
 {
     matrix = (int**)malloc(a * sizeof(int*));
     for (int i = 0; i < a; i++) 
        {
         matrix[i] = (int*)malloc(b * sizeof(int));
         for (int j = 0; j < b; j++)
         {
             printf("\nВведите элемент matrix[%d,%d] -->", i, j); scanf("%d", &matrix[i][j]);
             //printf("\nВведите элемент matrix[%d,%d] -->%d", i, j, matrix[i, j]);
         }
        }
     return matrix;
 }

 int** in_matrix_random(int** matrix, int a, int b) 
 {
     srand(time(0)); //задает постоянное рандомное значение 
     matrix = (int**)malloc(a * sizeof(int*));
     for (int i = 0; i < a; i++) 
       {
         matrix[i] = (int*)malloc(b * sizeof(int));
         for (int j = 0; j < b; j++)
         {
             matrix[i][j] = rand() % 200 - 100;
         }
       }
     return matrix;
 }

 void vivod_matrix(int** matrix, int a, int b)
 {
     printf("\n\n\n"); printf("\n Полученная матрица \n");
     for (int i = 0; i < a; i++) 
     { 
         for (int j = 0; j < b; j++)
         {
             printf("%6d\t", matrix[i][j]);
         }
         printf("\n");
     }
 }

 void sum_stolbs(int** matrix, int a, int b)
 {
     int chet, nechet;
     for (int i = 0; i < b; i++) 
     {
         chet = 0; nechet = 0;
         for (int j = 0; j < a; j++) 
         {
             int temp = matrix[j][i];
             //if ((matrix[j,i]*(int*)) % 2) nechet++; else chet++;
             if (temp % 2) nechet++; else chet++;
         }
         if (chet > nechet) 
         {
             int sum = 0;
             for (int j = 0; j < a; j++)
             {
                 int temp = matrix[j][i];
                 sum += temp;
             }
             printf("\n Строка  %3d, колличество четных %3d , колличество нечетных %3d , сумма  = %7d", i,chet,nechet, sum);
         }
     }
 }


 void sedlovie(int** matrix, int a, int b) 
 {
     int tempj=0;
     for (int i = 0; i < a; i++)
     {
         int max_i = 0, min_j = 0;
         for (int j = 0; j < b; j++)
         {
             if (max_i < matrix[i][j]) { max_i = matrix[i][j]; tempj = j; }
         }
         min_j = max_i;
         for (int L = 0; L < a; L++)
         {
             if (min_j > matrix[L][tempj]) 
             {
                 min_j = matrix[L][tempj];
                 break; 
             }
         }
         if (min_j == max_i) 
         {
             printf("\nСедловая точка sedl[%d,%d] = %d", i, tempj, matrix[i][tempj]);
         }
     }
 }

 int kol_noli(int** matrix, int a, int b) 
 {
     int col = 0;
     for (int j = 0; j < b; j++) 
     {
         int schet = 0;
         for (int i = 0; i < a; i++) 
         {
             if (matrix[i][j] == 0) schet++;
         }
         if (schet == 0) col++;
     }
     return col;
 }