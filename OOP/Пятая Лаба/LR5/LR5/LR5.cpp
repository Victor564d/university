// LR5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Coords
{
public:
	Coords();
	Coords(int x1, int x2, int y1, int y2);
	~Coords();
	bool operator !();
	friend Coords& operator ++(Coords& M);
	friend istream& operator >>(istream& in, Coords& M);
	friend ostream& operator <<(ostream& out, Coords& M);
	friend bool operator !=(const Coords& M1, const Coords& M2);
	
	Coords operator *(const int mn) {
		x1 *= mn;
		x2 *= mn;
		y1 *= mn;
		y2 *= mn;
		return *this;
	}
	
private:
	int x1, x2, y1, y2;
};

Coords::Coords()
{
	x1 = x2 = y1 = y2 = 0;
}

Coords::Coords(int x1,int x2,int y1,int y2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

Coords::~Coords()
{
}

bool Coords::operator!() {
	if (x1 == x2 && y1 == y2) return true;
	return false;
}


Coords& operator ++(Coords& M) {	 
	M.x1 += rand();
	M.y1 += rand();
	return M;
}

bool operator !=(const Coords& M1, const Coords& M2) {
	if (M1.x1 == M2.x1 && M1.x2 == M2.x2 && M1.y1 == M2.y1 && M1.y2 == M2.y2) return false;
	return true;
}


istream& operator >>(istream& in, Coords& M) {
	cout << "Введите x1: ";
	while (true) {
		if (in >> M.x1) {
			break;
		}
		else {
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error. Не число" << endl;
			cout << "Введите x1 ";
		}
	}
	cout << "Введите y1: ";
	while (true) {
		if (in >> M.y1) {
			break;
		}
		else {
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error. Не число" << endl;
			cout << "Введите y1 ";
		}
	}
	cout << "Введите x2: ";
	while (true) {
		if (in >> M.y1) {
			break;
		}
		else {
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error. Не число" << endl;
			cout << "Введите x2 ";
		}
	}
	cout << "Введите y2: ";
	while (true) {
		if (in >> M.y2) {
			break;
		}
		else {
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Error. Не число" << endl;
			cout << "Введите y2 ";
		}
	}
	return in;
}

ostream& operator <<(ostream& out, Coords& M) {
	out << "x1=" << M.x1 << " y1=" << M.y1 << " x2=" << M.x2 << " y2=" << M.y2 << std::endl;
	return out;
}





int main()
{
	system("chcp 1251");
	Coords c1 = Coords(1, 2, 4, 3);
	Coords c2 = Coords(2, 2, 2, 2);
	cout << "Введите первый объект: " << endl;
		cin >> c1;
		cout << "Введите второй объект: " << endl;
		cin >> c2;
	cout << "Первый класс содержит" << endl;
	cout << c1;
	cout << "Второй класс содержит" << endl;
	cout << c2;
	cout << "Результат унарной операции ! в первом классе" << endl;
	cout << !c1<<endl;
	cout << "Результат унарной операции ! в втором классе" << endl;
	cout << !c2 << endl;
	cout << "Результат унарной дружественной функции ++ в первом классе" << endl;
	++c1;
	cout << c1;
	cout << "Результат бинарного метода класса * в втором классе" << endl;
	c2* 10;
	cout << c2;
	cout << "Результат бинарной дружественной функции != двух объектов не равных друг другу" << endl;
	cout << (c1 != c2) << endl;
	cout << "Результат бинарной дружественной функции != двух объектов  равных друг другу" << endl;
	Coords c3 = Coords(1, 1, 4, 4); Coords c4 = Coords(1, 1, 4, 4);
	cout << (c3 != c4) << endl;
}
