

#include <iostream>
#include <string>
using namespace std;

class paper
{
	string color, factur, manufacture;
public:
	paper(string col, string fact, string manufact) : color(col), factur(fact), manufacture(manufact) {}
	string toString() {
		return  "Информация о бумаге : Производство " + manufacture + " Фактура : " + factur + "Цвет :" + color+".";
	}
};

class date {
	int d, m, y;
public:
	date(int d,int m,int y) : d(d),m(m),y(y){}
	string toString() {
		return  to_string(d) + "." + to_string(m) + "." + to_string(y);
	}
}; 

class calendar : public paper, public date {
public:
	calendar(string col, string fact, string manufact, int d, int m, int y) : paper(col, fact, manufact), date(d, m, y) {}
	calendar(paper obj1, date obj2) :paper(obj1), date(obj2) {}
	string toString() {
		return paper::toString() +"\t"+ date::toString();
	}
};



int main()
{
	system("chcp 1251");
	paper лист("Красный", "Глянец", "Крым бумага производство");
	date дата(3, 9, 2001);
	calendar календарь(лист, дата);
	cout << лист.toString() << endl;
	cout << дата.toString() << endl;
	cout << календарь.toString() << endl;
}

