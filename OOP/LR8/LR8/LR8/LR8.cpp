#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <regex>


using namespace std;
void Search(multimap<string, string> Slovar, string key) {
		auto iter = Slovar.find(key);
		string res = "Результат: ";
		for (; iter != Slovar.end(); iter++) {
			if (iter->first != key) { cout << res << endl; return; }
			else res += iter->second+", ";
		}
	}


multimap<string, string> RussDB;
multimap<string, string> EnglisDB;

std::vector<std::string> split(const string& input, const string& regex);
void LoadDB();

int main()
{
	system("chcp 1251");
	int item = 1; bool re = false;
	bool flag = false;
	while (true) {
		system("cls");
		cout << "1 - Загрузить данные из файла" <<endl;
		if (flag) {
			cout << "2 - Переключить режим перевода. Текущий режим :" << (re ? " англо-русский" : " русско-английский") << endl;
			cout << "3 - Перевести слово согласно режиму" << endl;
		}
		cout << "0 - Выход" << endl;
		cout << "Номер пункта -->";
		cin >> item;
		switch (item)
		{
		case 1:
			LoadDB();
			flag = true;
			break;
		case 2:
			re = !re;
			break;
		case 3:
			while (true) {
				system("cls");
				string word;
				cout << "Введите слово для перевода, 0 для выхода: "; cin >> word;
				if (word == "0") break;
				re ? Search(EnglisDB, word) : Search(RussDB, word);
				system("pause");
			}
		break;
		case 0:
			return 1;
			break;
		default:
			break;
		}
	}
}



void LoadDB() {
	ifstream fileE("English.txt"); ifstream fileR("Russian.txt");
	string line; 
	while (  getline(fileE, line)) {
		string key = ""; int KeySize = 0;
		for (; line[KeySize] != '-'; KeySize++) {
			key += line[KeySize];
		}
		string values = line.substr(KeySize + 1, line.size() - KeySize + 1);
		vector<string> valuess = split(values, ",\\s*");
		for (auto& str : valuess) {
			EnglisDB.insert(pair<string, string>{key, str});
		}
	}
	while (getline(fileR, line)) {
		string key = ""; int KeySize = 0;
		for (; line[KeySize] != '-'; KeySize++) {
			key += line[KeySize];
		}
		string values = line.substr(KeySize + 1, line.size() - KeySize + 1);
		vector<string> valuess = split(values, ",\\s*");
		for (auto& str : valuess) {
			RussDB.insert(pair<string, string>{key, str});
		}
	}
	fileE.close();
	fileR.close();
	cout << "Данные успешно загружены с базы данных" << endl;
	system("pause");
}



std::vector<std::string> split(const string& input, const string& regex) {
	std::regex re(regex);
	std::sregex_token_iterator
		first{ input.begin(), input.end(), re, -1 },
		last;
	return { first, last };
}