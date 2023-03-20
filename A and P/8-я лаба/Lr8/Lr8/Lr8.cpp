#pragma warning(disable : 4996) ;
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
int Count=0;
FILE* FileIN;
FILE* FileOUT;
void DeletePointe();
void CountInFile();
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
	 printf("\nКоличество одинаковых строк --> %d", CountEquels(strings, Count));
	 FileIN = fopen("3.txt", "r");
	 FileOUT = fopen("2.txt", "w");
	 DeletePointe();
	 CountInFile();
	 Test();
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
		 Strings[i] = (char*)malloc(255 * sizeof(char));
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

 void DeletePointe()
 {
	 char pointer = '.';
	 char Replacment = ' ';
	 int flag = 0; char temp; 
	 while ((temp = fgetc(FileIN)) != EOF) {
		 if ((temp == pointer) && (!flag)) 
		 {
			 flag = 1; fputc(Replacment, FileOUT);
		 }
		 if (flag) {
			 while (((temp = fgetc(FileIN)) != EOF)&& (temp == pointer)){}
		 }
		 if (temp == EOF) return;
		 //printf("\n%c", temp);
		 flag = 0;
		 fputc(temp, FileOUT);
	 }
	 fclose(FileIN);
	 fclose(FileOUT);
 }

 void CountInFile()
 {
	 char pointers[] = { ' ',',','.','\n','\0' }; int pointerRazm = 5;
	 char* s; s = (char*)malloc(256*sizeof(char));
	 FileIN = fopen("test1.txt", "r");
	 FileOUT = fopen("test2.txt", "w");
	 while (fgets(s, 256, FileIN) != NULL)
	 {
		 int count = 0; int flag = 0;
		 for (int i = 0; i < 256; i++) 
		{
			 for (int j = 0; j < pointerRazm; j++) 
			 {
				 if (s[i] == pointers[j]) {
					 flag = 1; count++;  break;
				 }
			 }
			 while (flag) 
			 {
				 int flag2 = 0;
				 for (int j = 0; j < pointerRazm; j++) 
				 {
					 if (s[i+1] == pointers[j]) flag2 = 1;
				 }
				 if (flag2) { i++; flag2 = 0; }
				 else {
					 flag = 0; break;
				       }
			 }
			
		}
		 printf("\n%d", count);
		 fprintf(FileOUT, "%d\n",count);
	 }
	 fclose(FileIN);
	 fclose(FileOUT);
	 return;
 }


 void Test() {
	 int m, x, n;
	 char s[80];
	 FILE* in, * out; // описание указателей на файлы

	 if ((in = fopen("test1.txt", "rt")) == NULL) {
		 fprintf(stderr, " Не могу открыть входной файл \n");
		 return 1;
	 }

	 if ((out = fopen("new.txt", "wt")) == NULL) {
		 fprintf(stderr, "Не могу открыть выходной файл \n");
		 return 1;
	 }
	 x = 0; n = 80;

	 while (fgets(s, n, in) != NULL) {
		 x++; m = 0;
		 for (int i = 1; i < n; i++)
			 if (((s[i] == ' ') && (s[i - 1] != ' ')) || ((s[i] != ' ') && (i == 79)))
				 m++;
		 fprintf(out, "%d\t%d\n", x, m);
	 }
	 fclose(in); //закрытие файлов
	 fclose(out);
	 return 0;
 }

