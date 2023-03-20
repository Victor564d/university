#include <string>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>


using namespace std;

char** strings;
char** ReadFiles(char** Strings, ifstream& fin); // Считывание файла из потока
void displayText(int n); //отображение информации на экране
int CountEquels(char** Strings, int n); //подсчет количества одинаковых строк 
void Test();
int Count = 0;

	int main()
	{
		SetConsoleCP(1251); // Задаем таблицу символов для консоли.
		SetConsoleOutputCP(1251);

		ifstream fin("Tets.txt", ios::in);
		if (!fin)
		{
			cout << " Не возможно открыть входной файл \n";
			return 1;
		}

		strings = ReadFiles(strings, fin);

		if (Count > 0)
			displayText(Count);
		cout << std::endl << "Количество совпадений строк --> " << CountEquels(strings, Count);
		Test();
		return 0;
	}

	
	char** ReadFiles(char** Strings, ifstream & fin)
	{
		char temp[256];
		int n = 0;

		for (; fin.getline(temp, 256); n++);

		cout << "Количество строк -->" << n << std::endl;
		fin.clear();
		fin.seekg(0);
		Strings = new char* [n];
		for (int i = 0; i < n; i++) {
			Strings[i] = new char[256];
			fin.getline(Strings[i], 256);
		}
		fin.close();
		Count = n;
		return Strings;
	}

	void displayText(int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Строка " << i << " --> " << strings[i] << endl;
		}
	}

	int CountEquels(char** Strings, int n)
	{
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n - 1; j++)
			{
				if (!strcmp(Strings[i], Strings[j]))//UwU
				{
					count++;
				}
			}
		}
		return count;
	}

	void Test() {
		int m, x, n;
		char s[80];
		ifstream fin("test1.txt", ios::in);
		if (!fin)
		{
			cout << " Не возможно открыть входной файл \n";
			return ;
		}
		ofstream fout("test2.txt", ios::out);
		if (!fout)
		{
			cout << " Не возможно открыть входной файл \n";
			return;
		}
		x = 0; n = 80;
		while (fin.getline(s,n)) {
			x++; m = 0;
			for (int i = 1; i < n; i++)
				if (((s[i] == ' ') && (s[i - 1] != ' ')) || ((s[i] != ' ') && (i == 79)))
					m++;
			fout << (std::to_string(x) + "\t" + std::to_string(m) + "\n");

		}
		return ;
	}