#include <iostream>
#include <iomanip>//for setw()
#include <conio.h>//for getche()

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "Введите номер задания лабораторной работы: ";
	cin >> a;
	switch (a) {
	case 1: {
		/*Номер телефона, например (212) 767—8900, можно условно разделить на три части: 
		код города (212), номер телефонной станции (767) и номер абонента (8900). 
		Напишите программу с использованием структуры, позволяющую раздельно хранить 
		эти три части телефонного номера. Назовите структуру phone. Создайте две структурные переменные типа phone. 
		Инициализацию одной из них произведите сами, а значения для другой запросите с клавиатуры. 
		Затем выведите содержимое обеих переменных на экран. 
		Результат работы программы должен выглядеть приблизительно так:
Введите код города, номер станции и номер абонента:
415 555 1212
Мой номер (212) 767-8900
Ваш номер (415) 555-1212
*/

// uses structure to store phone number

struct phone
   {
   int area;         //area code (3 digits)
   int exchange;     //exchange (3 digits)
   int number;       //number (4 digits)
   };

   phone ph1 = { 212, 767, 8900 };  //initialize phone number
   phone ph2;                       //define phone number
                                    // get phone no from user
   cout << "\nEnter your area code, exchange, and number";
   cout << "\n(Don't use leading zeros): ";
   cin >> ph2.area >> ph2.exchange >> ph2.number;

   cout << "\nMy number is "        //display numbers
	<< '(' << ph1.area << ") "
	<< ph1.exchange << '-' << ph1.number;

   cout << "\nYour number is "
	<< '(' << ph2.area << ") "
	<< ph2.exchange << '-' << ph2.number << endl;

	} break;
	case 2: {
		/*Расположение точки на плоскости можно задать с помощью двух координат: х и у. 
		Например, если точка имеет координаты (4, 5), то это значит, что она отстоит на 4 единицы 
		справа от вертикальной оси и на 5 единиц вверх от горизонтальной оси. 
		Сумма двух точек определяется как точка, имеющая координаты, равные сумме соответствующих координат слагаемых.
Напишите программу, использующую для интерпретации точки на плоскости структуру с названием point. 
Определите три переменные типа point, и две из них инициализируйте с помощью значений, вводимых с клавиатуры. 
Затем присвойте третьей переменной значение суммы первых двух переменных и выведите результат на экран. 
Результат работы программы может выглядеть следующим образом:
Введите координаты точки p1: 3 4 
Введите координаты точки р2: 5 7 
Координаты точки p1+p2 равны 8.11*/

		struct point {
			int po1,po2, sum;
		};

		point x, y;
		cout << "Введите координаты точки p1 (x y): ";
		cin >> x.po1 >> y.po1;
		cout << "Введите координаты точки р2 (x y): ";
		cin >> x.po2 >> y.po2;
		x.sum = x.po1 + x.po2;
		y.sum = y.po1 + y.po2;
		cout << "Координаты точки p1+p2 равны " << x.sum << " " << y.sum << endl;

	} break;
	case 3: {
		/*Создайте структуру с именем Volume, содержащую три поля типа Distance из примера englstrc, 
		для хранения трех измерений помещения. Определите переменную типа Volume, инициализируйте ее, 
		вычислите объем, занимаемый помещением, и выведите результат на экран. 
		Для подсчета объема переведите каждое из значений типа Distance в значение типа float, 
		равное соответствующей длине в футах и хранимое в отдельной переменной. 
		Затем для вычисления объема следует перемножить три полученные вещественные переменные.*/

		struct Distance {
			int feet;
			float inches;
		};

		struct Volume {
			Distance length;
			Distance width;
			Distance height;
		};

		float l, w, h;
		Volume room1 = { { 16, 3.5 }, { 12, 6.25 }, { 8, 1.75 } };

		l = room1.length.feet + room1.length.inches / 12.0;
		w = room1.width.feet + room1.width.inches / 12.0;
		h = room1.height.feet + room1.height.inches / 12.0;

		cout << "Volume = " << l * w * h << " cubic feet\n";

	} break;
	case 4: {
		/*4.Создайте структуру с именем employee, содержащую два поля: 
		номер сотрудника типа int и величину его пособия в долларах типа float. 
		Запросите с клавиатуры данные о трех сотрудниках, сохраните их в трех структурных 
		переменных типа employee и выведите информацию о каждом из сотрудников на экран.*/

		struct employee {
			int number;
			float posDollar;
		};

		employee w1, w2, w3;
		cout << "Введите номер работника и размер его пособия в долларах: ";
		cin >> w1.number >> w1.posDollar;
		cout << "Введите номер работника и размер его пособия в долларах: ";
		cin >> w2.number >> w2.posDollar;
		cout << "Введите номер работника и размер его пособия в долларах: ";
		cin >> w3.number >> w3.posDollar;
		cout << endl << "Информация о сотрудниках\n";
		cout << "Первый сотрудник:\nНомер " << w1.number << "\nРазмер пособия " << w1.posDollar << " долларов" << endl;
		cout << "\nВторой сотрудник:\nНомер " << w2.number << "\nРазмер пособия " << w2.posDollar << " долларов" << endl;
		cout << "\nТретий сотрудник:\nНомер " << w3.number << "\nРазмер пособия " << w3.posDollar << " долларов" << endl;

	} break;
	case 5: {
		/*Создайте структуру типа date, содержащую три поля типа int: месяц, день и год. 
		Попросите пользователя ввести день, месяц и год в формате 31/12/2002, сохраните введенное значение 
		в структурной переменной, а затем извлеките данные из этой переменной и выведите их на экран в том же 
		формате, в каком они вводились.*/

		struct date {
			int mounth, day, year;
		};

		char F;
		date d, m, y;
		cout << "Введите дату в формате 12/03/2013: ";
		cin >> m.mounth >> F >> d.day >> F >> y.year;
		if (m.mounth < 10)cout << "0" << m.mounth << " ";
		if (d.day < 10)cout << "0" << d.day << " ";
		else cout << d.day << " ";
		cout << y.year << endl;

	} break;
	case 6: {
		/*6.Как мы говорили, стандартные средства ввода/вывода C++ вместо значений перечисляемых типов 
		данных выводят их внутреннее представление в виде целых чисел. Для того чтобы преодолеть это 
		ограничение, вы можете использовать конструкцию switch, с помощью которой устанавливается 
		соответствие между значением переменной перечисляемого типа и ее внутренним представлением. 
		Пусть, например, в программе определен перечисляемый тип данных etype, отражающий должность сотрудника:
enum etype { laborer, secretary, manager, accountant, executive, researcher };

Напишите программу, которая сначала по первой букве должности, введенной пользователем, 
определяет соответствующее значение переменной, помещает это значение в переменную типа etype, 
а затем выводит полностью название должности, первую букву которой ввел пользователь. 
Взаимодействие программы с пользователем может выглядеть следующим образом:
Введите первую букву должности
(laborer, secretary, manager, accountant, executive, researcher): a
Полное название должности; accountant
Возможно, вам понадобится два ветвления switch: одно — для ввода значения, другое — для вывода.*/

		enum etype { laborer, secretary, manager, accountant, executive, researcher };
		char name;

		cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher) : ";
		cin >> name;
		switch (name) {
		case 'l': { 
			string etype[]{ "laborer" }; 
			cout << "Полное название должности: " << etype[0];
		}break;
		case 's': {
			string etype[]{ "secretary" };
			cout << "Полное название должности: " << etype[0];
		}break;
		case 'm': {
			string etype[]{ "manager" };
			cout << "Полное название должности: " << etype[0];
		}break;
		case 'a': {
			string etype[]{ "accountant" };
			cout << "Полное название должности: " << etype[0];
		}break;
		case 'e': {
			string etype[]{ "executive" };
			cout << "Полное название должности: " << etype[0];
		}break;
		case 'r': {
			string etype[]{ "researcher" };
			cout << "Полное название должности: " << etype[0];
		}break;
		}

	} break;
	case 7: {
		/*Добавьте поля типа enum etype (см. упражнение 6) и struct date (см. упражнение 5) в структуру employee
		из упражнения 4. Организуйте программу таким образом, чтобы пользователь вводил 4 пункта данных о
		каждом из трех сотрудников: 
		
		его номер, величину зарплаты, его должность и дату принятия на работу.
		Программа должна хранить введенные значения в трех переменных типа employee и выводить их содержимое на экран.*/

		struct employee {
			int number;
			float posDollar;
			enum etype { laborer, secretary, manager, accountant, executive, researcher };
			struct {
				int day, mounth, year;
			} dt;
		};


		employee w1, w2, w3;
		char F;
		char dol1, dol2, dol3;

		cout << "Введите  номер, величину зарплаты,  должность и дату принятия на работу работника: ";
		cin >> w1.number >> w1.posDollar >> dol1 >> w1.dt.mounth >> F >> w1.dt.day >> F >> w1.dt.year;
		cout << "Введите  номер, величину зарплаты,  должность и дату принятия на работу работника: ";
		cin >> w2.number >> w2.posDollar >> dol2 >> w2.dt.mounth >> F >> w2.dt.day >> F >> w2.dt.year;
		cout << "Введите  номер, величину зарплаты,  должность и дату принятия на работу работника: ";
		cin >> w3.number >> w3.posDollar >> dol3 >> w3.dt.mounth >> F >> w3.dt.day >> F >> w3.dt.year;

		cout << endl << "Информация о сотрудниках\n";
		cout << "Первый сотрудник:\nНомер " << w1.number << "\nРазмер зарплаты " << w1.posDollar << " в долларах" << endl;
		//должность
		switch (dol1) {
		case 'l': {
			string etype[]{ "laborer" };
			cout << "Название должности: " << etype[0];
		}break;
		case 's': {
			string etype[]{ "secretary" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'm': {
			string etype[]{ "manager" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'a': {
			string etype[]{ "accountant" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'e': {
			string etype[]{ "executive" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'r': {
			string etype[]{ "researcher" };
			cout << "Название должности: " << etype[0];
		}break;
		}
		cout << endl << "Дата принятия на работу: ";
		if (w1.dt.mounth < 10)cout << "0" << w1.dt.mounth << " ";
		if (w1.dt.day < 10)cout << "0" << w1.dt.day << " ";
		else cout << w1.dt.day << " ";
		cout << w1.dt.year << endl;
		
		cout << "\nВторой сотрудник:\nНомер " << w2.number << "\nРазмер зарплаты " << w2.posDollar << " в долларах" << endl;
		//должность
		switch (dol2) {
		case 'l': {
			string etype[]{ "laborer" };
			cout << "Название должности: " << etype[0];
		}break;
		case 's': {
			string etype[]{ "secretary" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'm': {
			string etype[]{ "manager" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'a': {
			string etype[]{ "accountant" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'e': {
			string etype[]{ "executive" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'r': {
			string etype[]{ "researcher" };
			cout << "Название должности: " << etype[0];
		}break;
		} 
		cout << endl << "Дата принятия на работу: ";
		if (w2.dt.mounth < 10)cout << "0" << w2.dt.mounth << " ";
		if (w2.dt.day < 10)cout << "0" << w2.dt.day << " ";
		else cout << w2.dt.day << " ";
		cout << w2.dt.year << endl;

		cout << "\nТретий сотрудник:\nНомер " << w3.number << "\nРазмер зарплаты " << w3.posDollar << " в долларах" << endl;
		//должность
		switch (dol3) {
		case 'l': {
			string etype[]{ "laborer" };
			cout << "Название должности: " << etype[0];
		}break;
		case 's': {
			string etype[]{ "secretary" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'm': {
			string etype[]{ "manager" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'a': {
			string etype[]{ "accountant" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'e': {
			string etype[]{ "executive" };
			cout << "Название должности: " << etype[0];
		}break;
		case 'r': {
			string etype[]{ "researcher" };
			cout << "Название должности: " << etype[0];
		}break;
		}
		cout << endl << "Дата принятия на работу: ";
		if (w3.dt.mounth < 10)cout << "0" << w3.dt.mounth << " ";
		if (w3.dt.day < 10)cout << "0" << w3.dt.day << " ";
		else cout << w3.dt.day << " ";
		cout << w3.dt.year << endl;

	} break;
	case 8: {
		/*8.Вернитесь к упражнению 9 комплекта заданий 2. В этом упражнении требуется написать программу, 
		которая хранит значения двух дробей в виде числителя и знаменателя, а затем складывает эти дроби 
		согласно арифметическому правилу. Измените эту программу так, чтобы значения дробей хранились в 
		структуре fraction, состоящей из двух полей типа int. предназначенных для хранения числителя и знаменателя. 
		Все значения дробей должны храниться в переменных типа fraction.*/

		struct fraction {
			int n1, n2;
		};

		char oper, ch;
		fraction a, b;//c = a.n2 d = b.n2
		char slash = '/';

		do {
				cout << "Введите первую дробь: ";
				cin >> a.n1 >> slash >> b.n1;
				cout << "Введите вторую дробь: ";
				cin >> a.n2 >> slash >> b.n2;
				if ((a.n1 * b.n2 + b.n1 * a.n2) == (b.n1 * b.n2))cout << "Сумма равна " << (a.n1 * b.n2 + b.n1 * a.n2) / (b.n1 * b.n2) << endl;
				else cout << "Сумма равна " << (a.n1 * b.n2 + b.n1 * a.n2) << slash << (b.n1 * b.n2) << endl;
						
			cout << "Вы хотете продолжить? (да = y, нет = n) ";
			cin >> ch;
		} while (ch != 'n');

	} break;
	case 9: {
		/*Создайте структуру с именем time. Три ее поля, имеющие тип int. будут называться hours, minutes и seconds. 
		Напишите программу, которая просит пользователя ввести время в формате часы, минуты, секунды. 
		Можно запрашивать на ввод как три значения сразу, так и выводить для каждой величины отдельное приглашение. 
		Программа должна хранить время в структурной переменной типа time и выводить количество секунд в введенном времени, 
		определяемое следующим образом:
long totalsecs = t1.hours*3600 + t1 minutes*60 + t1.seconds*/

		struct Time {
			int hours, minutes, seconds;
		};

		Time t;
		cout << "Введите время (часы минуты секунды) ";
		cin >> t.hours >> t.minutes >> t.seconds;
		long totalsecs = t.hours * 3600 + t.minutes * 60 + t.seconds;
		cout << "количество секунд в введенном времени: " << totalsecs << endl;

	} break;
	case 10: {
		/*Создайте структуру с именем sterling, хранящую денежные суммы в старой английской системе, описанной 
		в упражнениях 8 и 11 комплекса заданий 2. Поля структуры могут быть названы pounds, shillings и 
		pence и иметь тип int. Программа должна запрашивать у пользователя значение денежной суммы в новых десятичных фунтах 
		(значение должно храниться в переменной типа double), затем переводить эту сумму в старую систему, 
		сохранять переведенное значение в переменной типа sterling и выводить на экран полученную сумму в фунтах, 
		шиллингах и пенсах.*/

		struct sterling {
			int pound, shilling, penny;
		};

		sterling now; //now - nowoe
		char C = '.';
		double decpo, decshi;
		//1 фунт был равен 20 шиллингам, а 1 шиллинг — 12 пенсам
		cout << "Введите число десятичных фунтов(фунты.шиллинги): ";
		cin >> decpo;
		now.pound = static_cast<int>(decpo);//находим число фунтов
		decshi = decpo - now.pound;//число шиллингов
		now.shilling = static_cast<int>(decshi * 20);//находим шиллинги и пенни(до точки шиллинги после пенни)		
		now.penny = static_cast<int>(decshi * 240 - now.shilling * 12);
		cout << "Эквивалентная сумма в старой форме записи: ";
		cout << now.pound << C << now.shilling << C << now.penny << endl;

	} break;
	case 11: {
		/*Используя структуру time из упражнения 9, напишите программу, которая получает от пользователя 
		два значения времени в формате 12:59:59, сохраняет их в переменных типа struct time, 
		затем переводит оба значения в секунды, складывает их, переводит сумму в исходный формат, 
		сохраняет его в переменной типа time и выводит полученный результат на экран в формате 12:59:59.*/

		struct Time {
			int hours, minutes, seconds;
		};

		Time t1, t2;
		char F = ':';
		cout << "Введите время (часы:минуты:секунды) ";
		cin >> t1.hours >>F>> t1.minutes >>F>> t1.seconds;
		cout << "Введите время (часы:минуты:секунды) ";
		cin >> t2.hours >>F>> t2.minutes >>F>> t2.seconds;
		t1.seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
		t2.seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
		long totalsecs = t1.seconds + t2.seconds;
		t2.hours = totalsecs / 3600;
		totalsecs -= t2.hours * 3600;//остаются секунды + минуты
		t2.minutes = totalsecs / 60;
		t2.seconds = totalsecs - t2.minutes * 60;//находим число секунд

		cout << "Сумма: " << t2.hours << F << t2.minutes << F << t2.seconds << endl;

	} break;
	case 12: {
		/*Переработайте программу-калькулятор для дробей, описанную в упражнении 12 комплекта упражнений 3 так, 
		чтобы каждая из дробей хранилась как значение переменной типа struct fraction, по аналогии с упражнением 
		8 этого комплекса упражнений.*/
		struct fraction {
			int n1, n2;
		};

		char oper, ch;
		fraction a, b;//c = a.n2 d = b.n2
		char slash = '/';

		do {
			cout << "Введите оператор (+, -, *, /): ";
			cin >> oper;
			switch (oper)
			{
			case '+': {
				cout << "Введите первую дробь: ";
				cin >> a.n1 >> slash >> b.n1;
				cout << "Введите вторую дробь: ";
				cin >> a.n2 >> slash >> b.n2;
				if ((a.n1 * b.n2 + b.n1 * a.n2) == (b.n1 * b.n2))cout << "Сумма равна " << (a.n1 * b.n2 + b.n1 * a.n2) / (b.n1 * b.n2) << endl;
				else cout << "Сумма равна " << (a.n1 * b.n2 + b.n1 * a.n2) << slash << (b.n1 * b.n2) << endl;
			} break;
			case '-': {
				cout << "Введите первую дробь: ";
				cin >> a.n1 >> slash >> b.n1;
				cout << "Введите вторую дробь: ";
				cin >> a.n2 >> slash >> b.n2;
				if ((a.n1 * b.n2 - b.n1 * a.n2) == (b.n1 * b.n2))cout << "Разность равна " << (a.n1 * b.n2 - b.n1 * a.n2) / (b.n1 * b.n2) << endl;
				else cout << "Разность равна " << (a.n1 * b.n2 - b.n1 * a.n2) << slash << (b.n1 * b.n2) << endl;
			} break;
			case '*': {
				cout << "Введите первую дробь: ";
				cin >> a.n1 >> slash >> b.n1;
				cout << "Введите вторую дробь: ";
				cin >> a.n2 >> slash >> b.n2;
				if ((a.n1 * a.n2) == (b.n1 * b.n2)) cout << "Результат умножения равен " << (a.n1 * a.n2) / (b.n1 * b.n2) << endl;
				else cout << "Результат умножения равен " << (a.n1 * a.n2) << slash << (b.n1 * b.n2) << endl;
			} break;
			case '/': {
				cout << "Введите первую дробь: ";
				cin >> a.n1 >> slash >> b.n1;
				cout << "Введите вторую дробь: ";
				cin >> a.n2 >> slash >> b.n2;
				if ((a.n1 * b.n2) == (b.n1 * a.n1))cout << "Результат деления равен " << (a.n1 * b.n2) / (b.n1 * a.n1) << endl;
				else cout << "Результат деления равен " << (a.n1 * b.n2) << slash << (b.n1 * a.n1) << endl;
			} break;
			default: cout << "Введен неверный оператор";
			}
			cout << "Вы хотете продолжить? (да = y, нет = n) ";
			cin >> ch;
		} while (ch != 'n');
	} break;
	}

}