#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class fraction
{
public:
	int upper, lower;

	fraction() : upper(0), lower(0) {}

	fraction(int up, int low) {
		upper = up;
		lower = low;
	}

	void lowterms() //Сокращение дроби
	{
		long tnum, tden, temp, gcd;
		tnum = labs(upper); // Используем неотрицательные значения
		tden = labs(lower); // Нужен cmath
		if (tden == 0) { // Проверка знаменателя 
			cout << "Impossible lower numer" << endl;
			exit(1);
		}
		else if (tnum == 0) {
			upper = 0;
			lower = 1;
			return;
		}
		// Нахождение наибольшего общего делителя 
		while (tnum != 0) {
			if (tnum < tden) { // Если числитель больше знаменателя, меняем их местами.
				temp = tnum;
				tnum = tden;
				tden = temp;
			}
			tnum = tnum - tden;
		}
		gcd = tden; // Делим числитель и знаменатель на НОД.
		upper = upper / gcd;
		lower = lower / gcd;

	}

	void output_stats() {
		lowterms();
		cout << upper << '/' << lower << endl;
	}

	void fadd(fraction f2) {
		fraction tmp;
		tmp.upper = (upper * f2.lower + lower * f2.upper);
		tmp.lower = lower * f2.lower;
		tmp.output_stats();
	}

	void fsub(fraction f2) {
		fraction tmp;
		tmp.upper = (upper * f2.lower - lower * f2.upper);
		tmp.lower = lower * f2.lower;
		tmp.output_stats();
	}

	void fmul(fraction f1, fraction f2) {
		upper = f1.upper * f2.upper;
		lower = f1.lower * f2.lower;
	}

	void fdiv(fraction f2) {
		fraction tmp;
		tmp.upper = upper * f2.lower;
		tmp.lower = lower * f2.upper;
		tmp.output_stats();
	}

	void show_grid() {
		cout << setiosflags(ios::left) << setw(1) << upper << '/' << lower << " ";
	}

	void set_znam() {
		fraction t1, t2, t_res;
		cout << "Input lower number: ";
		cin >> t1.lower;

		for (int i = 1; i < t1.lower; i++) {
			t1.upper = i;
			t1.show_grid();
			t2.lower = t1.lower;
		}
		cout << endl << endl;

		for (int i = 1; i < t1.lower; i++) {
			t1.upper = i;
			t1.show_grid();
			t2.lower = t1.lower;
			for (int j = 1; j < t2.lower; j++) {
				t2.upper = j;
				t_res.fmul(t1, t2);
				t_res.lowterms();
				t_res.show_grid();
			}
			cout << endl;
		}
	}#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

};

int main()
{
	fraction frac;
	frac.set_znam();
	return 0;
}