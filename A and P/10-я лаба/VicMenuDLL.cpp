#include "pch.h"
#include "VicMenuDLL.h"
#pragma warning(disable : 4996) ;
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define clear() system("cls");
int x, y;

int* GetCurentSelector(char  c // Символ клавиатуры
    , int* position // Массив в котором хранятся x и y
    , int MaxY // Максимальный количество строк 
    , int Colums  // Количество столбцов, по умолчанию - 1
)
{
    int x = position[0]; int y = position[1];
    switch (c)
    {
    case 72://вверх
        if (y > 1) y--;
        break;
    case 80://вниз
        if (y < MaxY) y++;
        break;
    case 75://лево
        if (x > 1) x--;
        break;
    case 77://право
        if (x < Colums) x++;
        break;
    }
    position[0] = x;
    position[1] = y;
    return position;
}

int PrintMenu(char** Menu //Массив меню 
    , int* position //Массив текущей позиции x и y
    , int MenuSize  //Колличество элементов меню
    , int Colums)  //Количество столбцов 
{

    int Rows = MenuSize; int Override = 0;  int Console_Width = 180;
    if (Colums > 3) Colums = 3;
    if (Colums > 1) { Rows = MenuSize / Colums; Override = MenuSize % Colums; if (Override > 0) Rows++; }
    while (1)
    {
        int flag = 0;
        for (int i = 0; i < Console_Width; i++)
        {
            printf("-");
        }
        printf("\n");
        if (Colums == 1)
        {
            for (int i = 0; i < MenuSize; i++)
            {
                if (position[1] - 1 == i)
                    printf("| --> %-172s |\n", Menu[i]);
                else printf("| %-176s |\n", Menu[i]);
            }
        }
        else
            if (Colums == 2)
            {
                int PosOut = 0;
                for (int i = 0; i < Rows; i++) {
                    for (int j = 0; j < Colums; j++)
                    {
                        printf("|");
                        if (i == Rows - 1)
                        {
                            if (Override) {
                                if ((position[0] - 1 == j) && (position[1] - 1 == i)) printf(" --> %-84s", Menu[PosOut++]);
                                else printf(" %-87s ", Menu[PosOut++]);
                                printf("|"); for (int l = 1; l < 89; l++) printf(" "); printf("|");
                                flag = 1;
                                break;
                            }
                            else {
                                if ((position[0] - 1 == j) && (position[1] - 1 == i)) printf(" --> %-84s", Menu[PosOut++]);
                                else printf(" %-87s ", Menu[PosOut++]);
                            }
                        }
                        else
                        {
                            if ((position[0] - 1 == j) && (position[1] - 1 == i)) printf(" --> %-84s", Menu[PosOut++]);
                            else printf(" %-87s ", Menu[PosOut++]);
                        }
                    }
                    if (!flag)
                        printf("|\n"); else printf("\n");
                }
            }
            else
            {
                int PosOut = 0;
                for (int i = 0; i < Rows; i++) {
                    for (int j = 0; j < Colums; j++)
                    {
                        printf("|");
                        if (i == Rows - 1)
                        {
                            if (Override == 1) {
                                if ((position[0] - 1 == j) && (position[1] - 1 == i)) printf(" --> %-54s", Menu[PosOut++]);
                                else printf(" %-57s ", Menu[PosOut++]);
                                printf("|"); for (int l = 1; l < 60; l++) printf(" "); printf("|");
                                for (int l = 1; l < 60; l++) printf(" "); printf("|");
                                flag = 1;
                                break;
                            }
                            else if (Override) {
                                if ((position[0] - 1 == j) && (position[1] - 1 == i)) printf(" --> %-54s", Menu[PosOut++]);
                                else printf(" %-57s ", Menu[PosOut++]);  printf("|"); j++; i++;
                                if ((position[0] - 1 == j) && (position[1] - 1 == i)) printf(" --> %-54s", Menu[PosOut++]);
                                else printf(" %-57s ", Menu[PosOut++]);
                                printf("|");
                                for (int l = 1; l < 60; l++) printf(" "); printf("|");
                                flag = 1;
                                break;
                            }
                            else {
                                if ((position[0] - 1 == j) && (position[1] - 1 == i)) printf(" --> %-54s", Menu[PosOut++]);
                                else printf(" %-57s ", Menu[PosOut++]);
                            }
                        }
                        else
                        {
                            if ((position[0] - 1 == j) && (position[1] - 1 == i)) printf(" --> %-54s", Menu[PosOut++]);
                            else printf(" %-57s ", Menu[PosOut++]);
                        }
                    }
                    if (!flag)
                        printf("|\n"); else printf("\n");
                }
            }

        for (int i = 0; i < Console_Width; i++) {
            printf("-");
        }

        char c = getch();
        if (c == 13) {
            if (Colums == 1) return position[1]; else if (Colums == 2)
                return position[0] + (position[1] - 1) * 2; else return position[0] + (position[1] - 1) * 3;
        }
        int MaxY = MenuSize / Colums; if (Override) MaxY++;
        position = GetCurentSelector(c, position, MaxY, Colums);
        clear();
    }
}

