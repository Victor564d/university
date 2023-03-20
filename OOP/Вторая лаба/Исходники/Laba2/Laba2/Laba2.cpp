// Laba2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <string>
#include <iostream>

using namespace std;
class Base_search
{
public:
	virtual bool find_elem(const char) = 0;
};

class char_search : public Base_search {
	const char c;
public:
	 char_search(const char c) : c(c) {}
	 virtual bool find_elem(const char c) override {
		 return this->c == c;
	}
};

class string_search : public Base_search {
	 const string  s;
public:
	string_search(const string s) :s(s){}
	virtual bool find_elem(const char c) override {
		for (char e : s)
		{
			if (e == c) return true;
		}
		return false;
	}
};

class string_list_search : public Base_search {
	string* s;
	int s_count;
public:
	string_list_search(const string* s, int s_count) {
		this->s = new string[s_count];
		for (int i = 0; i < s_count; i++)
			this->s[i] = s[i];
		this->s_count = s_count;
	}
	virtual bool find_elem(const char c) override {
		
		for (int i = 0; i < s_count; i++) {
			for (char e : s[i])
			{
				if (e == c) return true;
			}
			return false;
		}
	}
};



int main()
{
	system("chcp 1251");
	char_search obj1('L');
	string_search obj2("This is testovay strocka");
	cout << "Введите колличестово строк в матрице ";
	int s_count;
	cin >> s_count;
	string* s = new string[s_count];
	for (int i = 0; i < s_count; i++) {
		cout << "Введите строку " << i << " -->";
		cin >> s[i];
	}
	string_list_search obj3(s, s_count); char serch_el;
	while (1) {
		cout << "Введите символ для поиска. 0 для выхода ";
		cin >> serch_el;
		if (serch_el == '0') break;
		if (obj1.find_elem(serch_el)) cout << "Данный символ есть в 1-ом класе"<<endl;
		if (obj2.find_elem(serch_el)) cout << "Данный символ есть в 2-ом класе" << endl;
		if (obj3.find_elem(serch_el)) cout << "Данный символ есть в 3-ом класе" << endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
