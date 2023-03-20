#pragma warning(disable : 4996);
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

char** strings;
FILE* F;
char** ReadFiles(char** Strings);
void displayText(int n);
int CountEquels(char** Strings, int n);
int TruProblems(char* stroka);


int Count=0;
FILE* FileIN;
FILE* FileOUT;
void Test();

 main()
{
	 SetConsoleCP(1251); // Задаем таблицу символов для консоли.
	 SetConsoleOutputCP(1251);
	 if ((F = fopen("Tets.txt", "r")) == NULL)
	 {
		 fprintf(stderr, " Не возможно открыть входной файл \n");
		 return 1;
	 }
	 strings = ReadFiles(strings);
	 if (Count>0)displayText(Count);
	 int colichestvo = 0;
	 for (int k = 0; k < Count; k++)
		 if (TruProblems(strings[k])) colichestvo++;
	 printf("\n Colichestvo --> %d", colichestvo);
	 
}

 char** ReadFiles(char** Strings)
{
	 char temp[256] = { ' ' };
	 int n = 0;
	 while (fgets(temp, 256, F) !=NULL)
	 {
		 n++;
	 }
	 printf("Количество строк - %d\n", n);
	 Strings = (char**) malloc(n*sizeof(char*));
	 for (int i = 0; i < n; i++) {
		 Strings[i] = (char*)calloc(1,255 * sizeof(char));
	 }
	 fclose(F); 
	 F = fopen("Tets.txt", "r"); n = 0;
	 while (fgets(Strings[n], 256, F) != NULL)
	 {
		 n++;
	 }
	 Count = n;
	return Strings;
}
		
 void displayText(int n)
 {
	 for (int i = 0; i < n; i++) 
	 {
		 printf("Строка №%d -->%s", i, strings[i]);
	 }
 }
	
 int CountEquels(char** Strings, int n) 
 {
	 int count = 0;
	 for (int i = 0; i < n; i++) {
		 for (int j = i + 1; j < n - 1; j++) 
		 {
			 if (!strcmp(Strings[i], Strings[j])) 
			 {
				 count++;
			 }
		 }
	 }
	 return count;
 }

 int TruProblems(char* stroka) {
	 int i = 0;
	 for (i = 0; stroka[i] != 0; i++);
	 if ((stroka[0] == ' ') && (stroka[i - 2] == ' '))
		 return 1; else return 0;
 }