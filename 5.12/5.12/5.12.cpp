#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class fraction {
private:
	int n1, n2;//n1 - chis, n2 - znam
public:
	fraction() : n1(0), n2(0)
	{}
	fraction(int c, int z) : n1(c), n2(z)
	{}
	char a;
	void getFrac() {
		cout << "Введите числитель/знаменатель дроби: ";
		cin >> n1 >> a >> n2;
	}
	void putFrac() {
		cout << "Вывод дроби " << n1 << a << n2 << endl;
	}
	void fAdd(fraction, fraction);//сумма
	void fSub(fraction, fraction);//разность
	void fMul(fraction, fraction);//умножение
	void fDiv(fraction, fraction);//деление
	void lowterms();//сокращение дроби
	void showGrid() {//вывод
		cout << setiosflags(ios::left) << setw(1) << n1 << '/' << n2 << " ";
	}
	void setZnam() {//ввод наименьшего знаменателя
		fraction t1, t2, t_res;
		cout << "Введите знаменатель: ";
		cin >> t1.n2;

		for (int i = 1; i < t1.n2; i++) {//вывод дроби сверху
			t1.n1 = i;
			t1.showGrid();
			t2.n2 = t1.n2;
		}
		cout << endl;

		for (int i = 1; i < t1.n2; i++) {//вывод дроби вниз
			t1.n1 = i;
			t1.showGrid();
			t2.n2 = t1.n2;
			for (int j = 1; j < t2.n2; j++) {//вывод умножения
				t2.n1 = j;
				t_res.fMul(t1, t2);
				t_res.lowterms();
				t_res.showGrid();
			}
			cout << endl;
		}
	}
};
void fraction::fAdd(fraction a, fraction b) {
	n1 = a.n1 * b.n2 + b.n1 * a.n2;//числитель
	n2 = (a.n2 * b.n2);//знаменатель
}
void fraction::fSub(fraction a, fraction b) {
	n1 = (a.n1 * b.n2 - b.n1 * a.n2);
	n2 = (a.n2 * b.n2);
}
void fraction::fMul(fraction a, fraction b) {
	n1 = (a.n1 * b.n1);
	n2 = (a.n2 * b.n2);
}
void fraction::fDiv(fraction a, fraction b) {
	n1 = (a.n1 * b.n2);
	n2 = (a.n2 * b.n1);
}
void fraction::lowterms() //Сокращение дроби
{
	long tchis, tznam, temp, nod;
	tchis = labs(n1); // Используем неотрицательные значения | labs - вычисляет абсолютную величину значения, 
	//передаваемого в качестве аргумента через параметр n.
	tznam = labs(n2); // Нужен cmath
	if (tznam == 0) { // Проверка знаменателя 
		cout << "Недопустимый знаменатель"; exit(1); // exit - завершает работу программы
	}
	else if (tchis == 0) {
		n1 = 0;
		n2 = 1;
		return;
	}
	// Нахождение наибольшего общего делителя 
	while (tchis != 0) {
		if (tchis < tznam) { // Если числитель больше знаменателя, меняем их местами.
			temp = tchis;
			tchis = tznam;
			tznam = temp;
		}
		tchis = tchis - tznam;
	}
	nod = tznam;// Делим числитель и знаменатель на НОД.
	n1 = n1 / nod;
	n2 = n2 / nod;
}

	int main() {
		setlocale(LC_ALL, "Russian");
		fraction frac;
		frac.setZnam();
		return 0;
	}