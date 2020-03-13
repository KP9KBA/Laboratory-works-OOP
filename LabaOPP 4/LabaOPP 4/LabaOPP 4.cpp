#include <iostream>
#include <iomanip>//for setw()
#include <conio.h>//for getche()
using namespace std;

//структура 4 задания
struct Distance //јнглийские расстояния
{
	int feet;
	float inches;
};
void engldisp(Distance);
//структура 6 задания
struct Time {
	int hours, minutes, seconds;
};
//2 вариант 10 задания
int func_schet2(int);
int j = 1;
//структура 12 задания
struct sterling {
	int pound, shilling, penny;
};
//13 number
struct fraction {
	int n1, n2;
};

int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "Введите номер задания лабораторной работы: ";
	cin >> a;
	switch (a) {
	case 1: {
		/*Напишите функцию с именем circarea(), которая вычисляет площадь круга.
		Функция должна принимать один аргумент типа float и возвращать значение типа float.
		Напишите функцию main(), которая просит пользователя ввести значение радиуса,
		вызывает функцию circarea(), а затем отображает результат вычисления на экране.*/

		//функция находит площадь окружности
		float circarea(float radius);

		double rad;
		cout << "\nВведите радиус окружности: ";
		cin >> rad;
		cout << "Площадь равна " << circarea(rad) << endl;

	}break;
	case 2: {
		/*Возведение числа n в степень р — это умножение числа n на себя р раз. 
		Напишите функцию с именем power(), которая в качестве аргументов принимает 
		значение типа double для n и значение типа int для р и возвращает значение типа double. 
		Для аргумента, соответствующего степени числа, задайте значение по умолчанию, равное 2, 
		чтобы при отсутствии показателя степени при вызове функции число n возводилось в квадрат. 
		Напишите функцию main(), которая запрашивает у пользователя ввод аргументов для функции power(), 
		и отобразите на экране результаты ее работы.*/

		//power()
		//возвращает число n, возведенное в степень p
		double power(double n, int p = 2);//p has default value 2
		
			double number, answer;
			int pow;
			char yeserno;
			cout << "\nВведите число: ";//get number
			cin >> number;
			cout << "Будете вводить степень (y/n)?";
			cin >> yeserno;
			if (yeserno == 'y') {//пользователю нужен не квадрат числа?
				cout << "Введите степень:";
				cin >> pow;
				answer = power(number, pow);//возвести число в степень
			}
			else {
				answer = power(number);//квадрат числа
			}
			cout << "Ответ " << answer << endl;
		
		
	}break;
	case 3: {
		/*Напишите функцию с именем zeroSmaller(), в которую передаются с помощью ссылок 
		два аргумента типа int, присваивающую меньшему из аргументов нулевое значение. 
		Напишите программу для проверки работы функции.*/
		//zeroSmaller()
		//устанавливает наименьшее из двух чисел в ноль

		void zeroSmaller(int&, int&);
		int а = 4, б = 7, в = 11, г = 9;
		cout << "\nНачальные значения\na=" << а << " б==" << б
			<< " в==" << в << " г==" << г;
		zeroSmaller(а, б);
		zeroSmaller(в, г);
		cout << "\nКонечные значения\na=" << а << " б==" << б
			<< " в==" << в << " г==" << г;

	}break;
	case 4: {
		/*Напишите функцию, принимающую в качестве аргументов два значения типа Distance 
		и возвращающую значение наибольшего из аргументов.*/

		//bigengl()
		//сравнивает две структуры типа Distance, возвращает 
		//наибольшую
		//engldisp()
		//выводит структуру типа Distance в футах и дюймах

		Distance bigengl(Distance, Distance);//объявления
		Distance d1, d2, d3;  //определение трех расстояний
					  //получить рассто€ние d1 от пользователя
		cout << "\nВведите число футов:"; cin >> d1.feet;
		cout << "Введите число дюймов:"; cin >> d1.inches;
		//получить рассто€ние d2 от пользователя
		cout << "\nВведите число футов:"; cin >> d2.feet;
		cout << "Введите число дюймов:"; cin >> d2.inches;
		d3 = bigengl(d1, d2); //d3 больше, чем d1 и d2
							//вывести все значения
		cout << "\nd1="; engldisp(d1);
		cout << "\nd2="; engldisp(d2);
		cout << "\nнаибольшее Ч "; engldisp(d3); cout << endl;
	}break;
	case 5: {
		/*Напишите функцию с именем hms_to_secs(), имеющую три аргумента типа int: часы, минуты и секунды. 
		Функция должна возвращать эквивалент переданного ей временного значения в секундах (типа long). 
		Создайте программу, которая будет циклически запрашивать у пользователя ввод значения часов, минут 
		и секунд и выводить результат работы функции на экран.*/

		long hms_to_sec(int H, int M, int S);
		char answer = 'n';
		do {
			int h, m, s;
			cout << "Введите количество часов, минут, секунд: ";
			cin >> h >> m >> s;
			cout << "Эквивалент переданного временного значения в секундах " << hms_to_sec(h, m, s) << endl;
			cout << "Хотите продолжить? ";
			cin >> answer;
		} while (answer == 'y');
	}break;
	case 6: {
		/*Модифицируйте программу, описанную в упражнении 11 предыдущей лабораторной работы «Структуры», 
		складывающую два структурных значения типа time. Теперь программа должна включать в себя две функции. 
		Первая, time_to_secs(), принимает в качестве аргумента значение типа time и возвращает эквивалентное 
		значение в секундах типа long. Вторая, secs_to_time(), в качестве аргумента принимает число секунд, 
		имеющее тип long, а возвращает эквивалентное значение типа time.*/
		
		Time t1, t2;
		char F = ':';
		long time_to_secs(Time t1, Time t2);
		void secs_to_time(long totalsecs);

		cout << "Введите время (часы:минуты:секунды) ";
		cin >> t1.hours >> F >> t1.minutes >> F >> t1.seconds;
		cout << "Введите время (часы:минуты:секунды) ";
		cin >> t2.hours >> F >> t2.minutes >> F >> t2.seconds;
		secs_to_time(time_to_secs(t1, t2));

	}break;
	case 7: {
		/*Взяв в качестве основы функцию power() из упражнения 2, работающую только со значением типа double, 
		создайте перегруженные функции с этим же именем, принимающими в качестве аргумента значения типа char, 
		int, long и float. Напишите программу, вызывающую функцию power() со всеми возможными типами аргументов.*/
		double power(double n, int p = 2);
		char power(char n, int p = 2);
		int power(int n, int p = 2);
		long power(long n, int p = 2);
		float power(float n, int p = 2);
		
		cout << "Результат:\n" << power(3.2, 2) << endl;
		cout << "" << power('a', 3) << endl;
		cout << "" << power(2, 2) << endl;
		cout << "" << power(4, 4) << endl;
		cout << "" << power(3.5F, 2) << endl;
	}break;
	case 8: {
		/*Напишите функцию с именем swap(), обменивающую значениями два своих аргумента 
		типа int (обратите внимание, что изменяться должны значения переменных из вызывающей 
		программы, а не локальных переменных функции). Выберите способ передачи аргументов. 
		Напишите вызывающую программу main(), использующую данную функцию.*/
		void swap1(int& a, int& b);
		int a, b;
		cout << "Введите два числа: ";
		cin >> a >> b;
		swap1(a, b);
		cout << "Результат перемены " << a << " " << b;
	}break;
	case 9: {
		/*Переработайте программу из упражнения 8 так, чтобы функция swap() 
		принимала в качестве аргументов значения типа time (см. упражнение 6).*/
		Time t1, t2;
		char F = ':';
		void swap2(Time& t1, Time& t2);
		
		cout << "Введите время (часы:минуты:секунды) ";
		cin >> t1.hours >> F >> t1.minutes >> F >> t1.seconds;
		cout << "Введите время (часы:минуты:секунды) ";
		cin >> t2.hours >> F >> t2.minutes >> F >> t2.seconds;
		swap(t1, t2);
		cout<<"Результат:\n"<< t1.hours << F << t1.minutes << F << t1.seconds << endl;
		cout << t2.hours << F << t2.minutes << F << t2.seconds << endl;
	}break;
	case 10: {
		/*Напишите функцию, которая при каждом вызове будет выводить на экран количество раз, 
		которое она вызывалась ранее. Напишите программу, которая будет вызывать данную функцию 
		не менее 10 раз. Попробуйте реализовать данную функцию двумя различными способами: 
		с использованием глобальной переменной и статической локальной переменной для хранения 
		числа вызовов функции. Какой из способов предпочтительней? Почему для решения задачи 
		нельзя использовать обычную локальную переменную?*/
		int func_schet1();
		for (int i = 0; i <= 9; i++)
		{
			cout << "Функция вызывалась " << func_schet1() << " раз." << endl;
		}
	}break;
	case 11: {// второй вариант 10 задания
		for (int i = 0; i <= 9; i++)
		{
			cout << "Функция вызывалась " << func_schet2(j) << "раз." << endl;
			j++;
		}
	}break;
	case 12: {
		/*Напишите программу, использующую структуру sterling, которая описана 
		в упражнении 10 лабораторной работы 3 «Структуры». Программа должна получать 
		от пользователя значения двух денежных сумм, выраженных в фунтах, шиллингах 
		и пенсах, складывать эти значения и выводить результат на экран в том же формате. 
		Необходимо разработать три функции. Первая из них должна получать от пользователя 
		число фунтов, шиллингов и пенсов и возвращать соответствующее значение типа sterling. 
		Вторая функция должна принимать в качестве аргументов два значения типа sterling, 
		складывать их и возвращать значение, также имеющее тип sterling. Третья функция должна 
		принимать аргумент типа sterling и выводить его значение на экран.*/
		sterling m1, m2, sum;
		sterling input();
		sterling total(sterling,sterling);
		void putOut(sterling);

		m1 = input();
		m2 = input();
		sum = total(m1, m2);
		putOut(sum);
	}break;
	case 13: {
		/*Модифицируйте калькулятор, созданный в упражнении 12 лабораторной работы 3 «Структуры», 
		так, чтобы каждая арифметическая операция выполнялась с помощью функции. Функции могут 
		называться fadd(), fsub(), fmul() и fdiv(). Каждая из функций должна принимать два структурных 
		аргумента типа fraction и возвращать значение того же типа.*/
		char oper, ch;
		fraction a, b;//c = a.n2 d = b.n2
		void fAdd();
		void fSub();
		void fMul();
		void fDiv();
		
		do {
			cout << "Введите оператор (+, -, *, /): ";
			cin >> oper;
			switch (oper)
			{
			case '+': {
				fAdd();
			} break;
			case '-': {
				fSub();
			} break;
			case '*': {
				fMul();
			} break;
			case '/': {
				fDiv();
			} break;
			default: cout << "Введен неверный оператор";
			}
			cout << "Вы хотете продолжить? (да = y, нет = n) ";
			cin >> ch;
		} while (ch != 'n');
	} break;
	}
}

//1 number
float circarea(float r) {
	const float PI = 3.14159F;
	return r * r * PI;
}
//2 number
double power(double n, int p){
	double result = 1.0;//начать с 1
	for (int j = 0; j < p; j++)//умножить на n
	result *= n;//p раз
	return result;
}
//3 number
void zeroSmaller(int& first, int& second)
{
	if (first < second)
		first = 0;
	else
		second = 0;
}
//4 number
Distance bigengl(Distance dd1, Distance dd2)
{
	if (dd1.feet > dd2.feet)    //если число футов различается,
		return dd1;             //вернуть то, которое больше
	if (dd1.feet < dd2.feet)
		return dd2;
	if (dd1.inches > dd2.inches)//если число дюймов
							  // различается,
		return dd1;             //вернуть наибольшее
	else       //дюймы или dd2, если равные значения
		return dd2;
}
void engldisp(Distance dd)
{
	cout << dd.feet << "\'-" << dd.inches << "\"";
}
//5 number
long hms_to_sec(int H, int M, int S) {
	S = H * 3600 + M * 60 + S;
	return S;
};
//6 number
long time_to_secs(Time t1, Time t2) {
	t1.seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
	t2.seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
	long totalsecs = t1.seconds + t2.seconds;
	return totalsecs;
}
void secs_to_time(long totalsecs) {
	Time t2;
	char F = ':';
	t2.hours = totalsecs / 3600;
	totalsecs -= t2.hours * 3600;//остаются секунды + минуты
	t2.minutes = totalsecs / 60;
	t2.seconds = totalsecs - t2.minutes * 60;//находим число секунд
	cout << "Сумма: " << t2.hours << F << t2.minutes << F << t2.seconds << endl;
}
//7 number
char power(char n, int p)
{
	char sum = n;
	for (int j = 1; j < p; j++)
		sum *= n;
	return sum;
}
int power(int n, int p)
{
	int sum = n;
	for (int j = 1; j < p; j++)
		sum *= n;
	return sum;
}
long power(long n, int p)
{
	long sum = n;
	for (int j = 1; j < p; j++)
		sum *= n;
	return sum;
}
float power(float n, int p)
{
	float sum = n;
	for (int j = 1; j < p; j++)
		sum *= n;
	return sum;
}
//8 number
void swap1(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//9 number
void swap2(Time& t1, Time& t2) {
	int temp;
	temp = t1.hours;
	t1.hours = t2.hours;
	t2.hours = temp;
	temp = t1.minutes;
	t1.minutes = t2.minutes;
	t2.minutes = temp;
	temp = t1.seconds;
	t1.seconds = t2.seconds;
	t2.seconds = temp;
}
//10 number
int func_schet1()
{
	static int j = 0;
	j++;
	return j;
}
int func_schet2(int j)
{
	int schet = j;
	j++;
	return schet;
}
//12 number
sterling input() {
	char F;
	sterling temp;
	cout << "Введите денежную сумму: ";
	cin >> temp.pound >> F >> temp.shilling >> F >> temp.penny;
	return temp;
}
sterling total(sterling s1, sterling s2) {
	sterling sum;
	sum.pound = s1.pound + s2.pound;
	sum.shilling = s1.shilling + s2.shilling;
	sum.penny = s1.penny + s2.penny;
	if (sum.penny % 12 >= 0) {
		sum.shilling += sum.penny / 12;
		sum.penny %= 12;
	}
	if (sum.shilling % 20 >= 0) {
		sum.pound += sum.shilling / 20;
		sum.shilling %= 20;
	}
	return sum;
}
void putOut(sterling sum) {
	char F = '.';
	cout << "Сумма: " << sum.pound << F << sum.shilling << F << sum.penny << endl;
}
//13 number
void fAdd() {
	fraction a, b;
	char slash;
	cout << "Введите первую дробь: ";
	cin >> a.n1 >> slash >> b.n1;
	cout << "Введите вторую дробь: ";
	cin >> a.n2 >> slash >> b.n2;
	if ((a.n1 * b.n2 + b.n1 * a.n2) == (b.n1 * b.n2))cout << "Сумма равна " << (a.n1 * b.n2 + b.n1 * a.n2) / (b.n1 * b.n2) << endl;
	else cout << "Сумма равна " << (a.n1 * b.n2 + b.n1 * a.n2) << slash << (b.n1 * b.n2) << endl;
}
void fSub() {
	fraction a, b;
	char slash;
	cout << "Введите первую дробь: ";
	cin >> a.n1 >> slash >> b.n1;
	cout << "Введите вторую дробь: ";
	cin >> a.n2 >> slash >> b.n2;
	if ((a.n1 * b.n2 - b.n1 * a.n2) == (b.n1 * b.n2))cout << "Разность равна " << (a.n1 * b.n2 - b.n1 * a.n2) / (b.n1 * b.n2) << endl;
	else cout << "Разность равна " << (a.n1 * b.n2 - b.n1 * a.n2) << slash << (b.n1 * b.n2) << endl;
}
void fMul() {
	fraction a, b;
	char slash;
	cout << "Введите первую дробь: ";
	cin >> a.n1 >> slash >> b.n1;
	cout << "Введите вторую дробь: ";
	cin >> a.n2 >> slash >> b.n2;
	if ((a.n1 * a.n2) == (b.n1 * b.n2)) cout << "Результат умножения равен " << (a.n1 * a.n2) / (b.n1 * b.n2) << endl;
	else cout << "Результат умножения равен " << (a.n1 * a.n2) << slash << (b.n1 * b.n2) << endl;
}
void fDiv() {
	fraction a, b;
	char slash;
	cout << "Введите первую дробь: ";
	cin >> a.n1 >> slash >> b.n1;
	cout << "Введите вторую дробь: ";
	cin >> a.n2 >> slash >> b.n2;
	if ((a.n1 * b.n2) == (b.n1 * a.n1))cout << "Результат деления равен " << (a.n1 * b.n2) / (b.n1 * a.n1) << endl;
	else cout << "Результат деления равен " << (a.n1 * b.n2) << slash << (b.n1 * a.n1) << endl;
}