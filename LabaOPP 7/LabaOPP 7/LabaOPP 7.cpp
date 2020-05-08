#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>       //for strcpy(), strlen()
#include <cstring>       //for strcpy(), strlen() number 2
#include <process.h>     //for exit() number 2
#include <string> // for  to_string
using namespace std;
//number 1
class Distance {                  //English Distance class
private:
	int feet;
	float inches;
public:                        //constructor (no args)
	Distance() : feet(0), inches(0.0)
	{  }                     //constructor (two args)
	Distance(int ft, float in) : feet(ft), inches(in)
	{  }
	void getdist() {             //get length from user
		cout << "\nEnter feet: ";  cin >> feet;
		cout << "Enter inches: ";  cin >> inches;
	}
	void showdist() {           //display distance	
		cout << feet << "\'-" << inches << '\"';
	}
	Distance Add(Distance d2) {
		int f = feet + d2.feet;        //add the feet
		float i = inches + d2.inches;  //add the inches
		if (i >= 12.0)                  //if total exceeds 12.0,
		{                           //then decrease inches
			i -= 12.0;                  //by 12.0 and
			f++;                        //increase feet by 1
		}                           //return a temporary Distance
		return Distance(f, i);          //initialized to sum
	};  //add two distances
	Distance Diff(Distance d2) {
		int f = feet - d2.feet;        //subtract the feet
		float i = inches - d2.inches;  //subtract the inches
		if (i < 0)                      //if inches less than 0,
		{                           //then increase inches
			i += 12.0;                  //by 12.0 and
			f--;                        //decrease feet by 1
		}                           //return a temporary Distance
		return Distance(f, i);          //initialized to difference
	};  //subtract two distances
};
//number 2
/*class String             //user-defined string type
{
private:
	enum { SZ = 80 };              //size of String objects
	char str[SZ];                  //holds a C-string
public:
	String() {                     //no-arg constructor
		cin.ignore();
		strcpy_s(str, "");
	}
	String(char s[]) {           //1-arg constructor	
		//strcpy(str, s);
	}
	void display()const {               //display the String	
		cout << str;
	}
	String operator += (String ss) {  //add a String to this one                     
		if (strlen(str) + strlen(ss.str) >= SZ) {//result stays in this one		
			cout << "\nString overflow"; exit(1);
		}
		//strcat(str, ss.str);        //add the argument string
		return String(str);         //return temp String
	}

};*/
//number 3
class time {
private:
	int hrs, mins, secs;
public:
	time() : hrs(0), mins(0), secs(0) //no-arg constructor
	{  }                           //3-arg constructor
	time(int h, int m, int s) : hrs(h), mins(m), secs(s)
	{  }
	void display() {                   //format 11:59:59
		cout << hrs << ":" << mins << ":" << secs;
	}
	time operator + (time t2) {        //add two times
		int s = secs + t2.secs;        //add seconds
		int m = mins + t2.mins;        //add minutes
		int h = hrs + t2.hrs;          //add hours
		if (s > 59) {                  //if secs overflow,
			s -= 60; m++;
		}           //   carry a minute
		if (m > 59) {                //if mins overflow,		
			m -= 60; h++;
		}           //   carry an hour
		return time(h, m, s);          //return temp value
	}
	time operator -(time t2) {//number 6
		long total = (hrs * 3600 + mins * 60 + secs) - (t2.hrs * 3600 + t2.mins * 60 + t2.secs);
		int h = total / (60 * 60);
		int m = total % (60 * 60) / 60;
		int s = total % (60 * 60) % 60;
		return time(h, m, s);
	}
	time operator *(time t2) {
		long total = (hrs * 3600 + mins * 60 + secs) * (t2.hrs * 3600 + t2.mins * 60 + t2.secs);
		int h = total / (60 * 60);
		int m = total % (60 * 60) / 60;
		int s = total % (60 * 60) % 60;
		return time(h, m, s);
	}
	time operator ++ () {//number 5
		return time(++hrs, ++mins, ++secs);
	}
	time operator --() {//number 5
		return time(--hrs, --mins, --secs);
	}
	time operator ++(int) {//number 5
		return time(hrs++, mins++, secs++);
	}
	time operator --(int) {//number 5
		return time(hrs--, mins--, secs--);
	}
};
//number 4
class Int {
private:
	int i;
public:
	Int() : i(0)                       //no-arg constructor
	{  }
	Int(int ii) : i(ii)                //1-arg constructor
	{  }                            //   (int to Int)
	void putInt() {                      //display Int	
		cout << i;
	}
	void getInt() {                    //read Int from kbd
		cin >> i;
	}
	operator int() {                    //conversion operator
		return i;
	}                   //   (Int to int)
	Int operator + (Int i2) {           //addition
		return checkit(long double(i) + long double(i2));
	}
	Int operator - (Int i2) {           //subtraction
		return checkit(long double(i) - long double(i2));
	}
	Int operator * (Int i2) {          //multiplication
		return checkit(long double(i) * long double(i2));
	}
	Int operator / (Int i2) {          //division
		return checkit(long double(i) / long double(i2));
	}
	Int checkit(long double answer) {          //check results
		if (answer > 2147483647.0L || answer < -2147483647.0L) {
			cout << "\nOverflow Error\n"; exit(1);
		}
		return Int(int(answer));
	}
};
//number 7
class fraction {
private:
	int num, den;//num - числитель den - знаменатель
public:
	char a = '/';
	fraction():num(0),den(0) {}
	fraction(int n, int d) { num = n; den = d; }
	void getFrac() {
		cout << "Введите числитель/знаменатель дроби: ";
		cin >> num >> a >> den;
		if ((num == 0 && den == 0) || (num == 0 && den == 1)||(num == 1 && den == 1)) {
			cout << "Ошибка!!!!!" << endl;
			exit(1);
		}
	}
	void putFrac() {
		cout << "Вывод дроби " << num << a << den << endl;
	}
	fraction operator +(fraction a) {
		int n = a.num * den + num * a.den;//числитель
		int d = (a.den * den);//знаменатель
		return fraction(n, d);
	};//сумма
	fraction operator -(fraction a) {
		int n = (a.num * den - num * a.den);
		int d = (a.den * den);
		return fraction(n, d);
	};//разность
	fraction operator *(fraction a) {
		int n = (a.num * num);
		int d = (a.den * den);
		return fraction(n, d);
	};//умножение
	fraction operator /(fraction a) {
		int n = (a.num * den);
		int d = (a.den * num);
		return fraction(n, d);
	};//деление
	void lowterms() { //Сокращение дроби
		long chis, znam, temp, nod;
		chis = labs(num); // Используем неотрицательные значения | labs - вычисляет абсолютную величину значения, 
		//передаваемого в качестве аргумента через параметр n.
		znam = labs(den); // Нужен cmath
		/*if (znam == 0) { // Проверка знаменателя 
			cout << "Недопустимый знаменатель"; exit(1); // exit - завершает работу программы
		}
		else if (chis == 0) {
			num = 0;
			den = 1;
			return;
		}*/
		// Нахождение наибольшего общего делителя 
		while (chis != 0) {
			if (chis < znam) { // Если числитель больше знаменателя, меняем их местами.
				temp = chis;
				chis = znam;
				znam = temp;
			}
			chis = chis - znam;
		}
		nod = znam;// Делим числитель и знаменатель на НОД.
		num = num / nod;
		den = den / nod;
	}
};
//number 8
class bMoney {
private:
	long double money;
	string ustring;
public:
	bMoney() {money = 0;};
	explicit bMoney(long double m) :money(m) {}//конструктор преобразования long double в bMoney	
	operator long double() {//преобразование bMoney в long double	
		return money;
	}
	bMoney operator +(bMoney m2)	{
		return bMoney(money + m2.money);
	}
	bMoney operator -(bMoney m2) {
		return bMoney(money - m2.money);
	}
	bMoney operator /(long double m2) {
		return bMoney(money / m2);
	}
	bMoney operator *(long double m2) {
		return bMoney(money * m2);
	}
	void getmoney() {
		cout << "Введите денежную сумму со знаком $: ";
		cin >> ustring;
			ustring.erase(ustring.begin());
			int n = ustring.size();
			for (int i = 0; i < n;) {
				if (ustring.at(i) == ',') ustring.erase(ustring.begin() + i,
					ustring.begin() + i + 1);
				else i++;
			}
			money = atof(ustring.c_str());
	}
	void putmoney() {
		cout << money;
	};
};
//number 9
const int LIMIT = 100;
class safearay {
private:
	int arr[LIMIT];
public:
	int& operator [](int n) {  //note: return by reference
		if (n < 0 || n >= LIMIT) {
			cout << "\nИнтервал чисел слишком большой!"; exit(1);
		}
		return arr[n];
	}
	void getLim() {
		int a, b;
		cout << "Введите верхнюю и нижнюю границу массива: ";
		cin >> a >> b;
		int lim = b - a;
		if (lim > LIMIT) { cout << "\nИнтервал чисел слишком большой!"; exit(1); }
		else {
			for (int j = 0; j < lim; j++) {
				arr[j] = j * 10;
			}
		}
		for (int j = 0; j < lim; j++)      //display elements
		{
			int temp = arr[j];       //*right* side of equal sign
			cout << "Элемент " << j << " = " << temp << endl;
		}
	}
};
//number 10
class Polar {
	int x, y;
	double radius, angle;
public:
	Polar() :x(0), y(0), radius(0), angle(0) {}
	Polar(int x, int y) : x(x), y(y), radius(sqrt(x* x + y * y)), angle(acos((double)x / (double)radius)) {}
	/*double operator +(Polar C) {
		/*double x = radius * cos(angle);
		double y = radius * sin(angle);
		double Cx = C.radius * cos(C.angle);
		double Cy = C.radius * sin(C.angle);
		x = x + Cx; y = y + Cy;
		/*если у нас вектора (x,a) и (y,b) заданы в полярных координатах ( x,y - длины; a,b - углы), то их сумма (z,c) будет
		double x = radius, y = C.radius;
		double a = angle, b = C.angle;
		double z, c;//Результат
		z = sqrt((pow(x, 2) + pow(y, 2) - 2 * x * y * cos(a + M_PI - b)));//  -- длина (по теореме косинусов)
		c = asin( sin(a+ M_PI -b) * y/z ) - a; // -- угол (по теореме синусов)

	}*/
	Polar operator + (Polar C) {
		int X = x + C.x;
		int Y = y + C.y;

		return Polar(X, Y);
	}
	void putInfo() {
		cout << "Новый радиус: " << radius << "\nНовый угол: " << angle;
	}
};
//number 11
class sterling {
private:
	long pound;
	int shilling, penny;
public:
	sterling() :pound(0), shilling(0), penny(0) {};
	sterling (double decPound) {
		pound = static_cast<long> (decPound);
		long deschast = decPound - pound;
		shilling = static_cast <int> (deschast * 20);
		penny = static_cast<int>((decPound - pound) * 240 - shilling * 12);
	};
	sterling (long po, int shi, int pe):pound(po), shilling(shi), penny(pe){}
	void getSter() {
		char c;
		cout << "Введите значения количества фунтов, шиллингов и пенсов в формате £ 9.19.11: ";
		cin >> pound >> c >> shilling >> c >> penny;
	}
	void putSter() {
		cout << "£" << pound << '.' << shilling << '.' << penny << endl;
	}
	sterling operator +(sterling s1) {
		sterling sum;
		sum.pound = s1.pound + pound;
		sum.shilling = s1.shilling + shilling;
		sum.penny = s1.penny + penny;
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
	sterling operator -(sterling s1) {
		sterling sum;
		sum.pound = s1.pound - pound;
		sum.shilling = s1.shilling - shilling;
		sum.penny = s1.penny - penny;
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
	sterling operator *(double s1) {
		int sumpenny = (pound * 20 * 12 + shilling * 12 + penny) * (s1);
		long po = sumpenny / (20 * 12);
		int s = sumpenny % (20 * 12) / 12;
		int pe = sumpenny % (20 * 12) % 12;
		return sterling(po, s, pe);
	}
	sterling operator /(double s1) {
		int sumpenny = (pound * 20 * 12 + shilling * 12 + penny) / (s1);
		long po = sumpenny / (20 * 12);
		int s = sumpenny % (20 * 12) / 12;
		int pe = sumpenny % (20 * 12) % 12;
		return sterling(po, s, pe);
	}
	sterling operator /(sterling s1) {
		sterling sum;
		sum.pound = s1.pound / pound;
		sum.shilling = s1.shilling / shilling;
		sum.penny = s1.penny / penny;
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
	operator double()
	{
		float sum = penny + shilling * 12 + (pound * 20) * 12;
		double des_funt = (sum / 2.4) / 100;
		return des_funt;
	}	
};


int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "Введите номер лабораторной работы 7: "; cin >> a;
	switch (a)
	{
	case 1: {
		/*Добавьте в класс Distance из программы ENGLPLUS перегруженную операцию -, которая вычисляет разность двух интервалов.
		Она должна позволять выполнение выражений типа dist3=distl-dist2;. Предполагаем, что эта операция никогда не будет
		использоваться для вычитания большего интервала из меньшего (так как отрицательного интервала быть не может).*/
		Distance dist1, dist3;         //define distances
		dist1.getdist();               //get dist1 from user
		Distance dist2(3, 6.25);       //define, initialize dist2
		dist3.Diff(dist1);        //subtract
									   //display all lengths
		cout << "\ndist1 = ";  dist1.showdist();
		cout << "\ndist2 = ";  dist2.showdist();
		cout << "\ndist3 = ";  dist3.showdist();
	}break;
	case 2: {
		/*Напишите программу, которая заменяет перегруженную операцию + на перегруженную операцию += в программе STRPLUS.
		Эта операция должна позволять записывать выражения типа: si += s2
		где s2 прибавляется (объединяется) к строке si, результат при этом остается в si.
		Операция должна также позволять использовать результат для других вычислений, например в выражениях типа: s3 = si += s2*/
		//String s1 = "Merry Christmas! ";      //uses 1-arg ctor
		//String s2 = "Happy new year! ";         //uses 1-arg ctor
		//String s3;                             //uses no-arg ctor
		//s3 = s1 += s2;         //add s2 to s1, assign to s3
		//cout << "\ns1="; s1.display();         //display s1
		//cout << "\ns2="; s2.display();         //display s2
		//cout << "\ns3="; s3.display();         //display s3
	}break;
	case 3: {
		/*Модифицируйте класс time из упражнения 3 лабораторной работы №4 так, чтобы вместо метода add_time() можно было
		использовать операцию + для складывания двух значений времени. Напишите программу для проверки класса.*/
		time time1(5, 59, 59);               //create and initialze
		time time2(4, 30, 30);               //   two times
		time time3;                          //create another time
		time3 = time1 + time2;               //add two times
		cout << "\ntime1 = "; time1.display();
		cout << "\ntime2 = "; time2.display();
		cout << "\ntime3 = "; time3.display(); //display result
	}break;
	case 4: {
		/*Создайте класс Int, основанный на упражнении 1 из лабораторной работы № 4.
		Перегрузите четыре целочисленных арифметических операции (+, -, * и /) так, чтобы их можно
		было использовать для операций с объектами класса Int. Если результат какой-либо из операций выходит за
		границы типа int (в 32- битной системе), имеющие значение от 2 14 7 483 648 до -2 147 483 648, то операция
		должна послать сообщение об ошибке и завершить программу. Такие тины данных полезны там, где ошибки могут
		быть вызваны арифметическим переполнением, которое недопустимо. Подсказка: для облегчения проверки
		переполнения выполняйте вычисления с использованием типа long double. Напишите программу для проверки этого класса.*/
		Int alpha = 20;
		Int beta = 7;
		Int delta, gamma;
		gamma = alpha + beta;                  //27
		cout << "\ngamma="; gamma.putInt();
		gamma = alpha - beta;                  //13
		cout << "\ngamma="; gamma.putInt();
		gamma = alpha * beta;                  //140
		cout << "\ngamma="; gamma.putInt();
		gamma = alpha / beta;                  //2
		cout << "\ngamma="; gamma.putInt();

		delta = 2147483647;
		gamma = delta + alpha;                 //overflow error
		delta = -2147483647;
		gamma = delta - alpha;                 //overflow error
	}break;
	case 5: {
		/*Пополните класс time, рассмотренный в упражнении 3, перегруженными операциями увеличения (++) и уменьшения (--),
		которые работают в обеих, префиксной и постфиксной, формах записи и возвращают значение. Дополните функцию main(),
		чтобы протестировать эти операции.*/
		time t(17, 47, 0);
		time t1(12, 34, 13);
		cout << "\nstar time 1 = "; t.display();
		cout << "\nstart time 2 = "; t1.display();
		t++;
		cout << "\nPrefix time 1 = "; t.display();
		t1--;
		cout << "\nPrefix time 2 = "; t1.display();
		t = t + t1;
		cout << "\nSum = "; t.display();
		--t;
		cout << "\nPrefix time sum = "; t.display();
		++t;
		cout << "\nPostfix time 2 = "; t.display();

	}break;
	case 6: {
		/*Добавьте в класс time из упражнения 5 возможность вычитать значения времени, используя перегруженную операцию -,
		и умножать эти значения, используя тип float и перегруженную операцию умножения */
		time t1(1, 2, 3), t2(4, 5, 6);
		cout << "\nstar time 1 = "; t1.display();
		cout << "\nstar time 2 = "; t2.display();
		t2 = t2 - t1;
		cout << "\nOperation (t2-t1) = "; t2.display();
		t2 = t2 * t1;
		cout << "\nOperation (t2*t1) = "; t2.display();
	}break;
	case 7: {
		/*Модифицируйте класс fraction в четырехфункциональном дробном калькуляторе из упражнения 11 лабораторной работы №4 так,
		чтобы он использовал перегруженные операции сложения, вычитания, умножения и деления. (Вспомните правила арифметики с
		дробями в упражнении 12 лабораторной работы №2 «Циклы и ветвления».) Также перегрузите операции сравнения == и != и
		используйте их для выхода из цикла, когда пользователь вводит 0/1, 0 и 1 значения двух частей дроби.
			Вы можете модифицировать
		и функцию lowterms() так, чтобы она возвращала значение ее аргумента, уменьшенное до несократимой дроби. Это будет полезным
		в арифметических функциях, которые могут быть выполнены сразу после получения ответа.*/
		char oper, ch = ' ';
		fraction d1, d2, d;
		do {
			d1.getFrac();
			d2.getFrac();
			cout << "Введите оператор (+, -, *, /): ";
			cin >> oper;
			switch (oper)
			{
			case '+': {
				d = d1 + d2;
			} break;
			case '-': {
				d = d1 - d2;
			} break;
			case '*': {
				d = d1 * d2;
			} break;
			case '/': {
				d = d1 / d2;
			} break;
			default: cout << "Введен неверный оператор";
			}
			d.lowterms();
			d.putFrac();
			cout << "Вы хотете продолжить? (да = y, нет = n) ";
			cin >> ch;
		} while (ch != 'n');

	}break;
	case 8: {
		/*Модифицируйте класс bМоnеу из упражнения 12 лабораторной работы №6 «Массивы и строки», включив арифметические операции,
		выполненные с помощью перегруженных операций:
			bМоnеу = bМоnеу + bМоnеу   +
			bМоnеу = bМоnеу - bМоnеу   +
			bМоnеу = bМоnеу * long double (цена за единицу времени, затраченного на изделие) +
			long double = bМоnеу / bМоnеу (общая цена, деленная на цену за изделие) +
			bМоnеу = bМоnеу / long double (общая цена, деленная на количество изделий)
		Заметим, что операция / перегружена дважды. Компилятор может различить оба варианта, так как их аргументы разные.
		Помним, что легче выполнять арифметические операции с объектами класса bМоnеу, выполняя те же операции с его long double данными.
		Убедитесь, что программа main() запросит ввод пользователем двух денежных строк и числа с плавающей точкой. Затем она выполнит
		все пять операций и выведет результаты. Это должно происходить в цикле, так, чтобы пользователь мог ввести еще числа, если это понадобится.
		Некоторые операции с деньгами не имеют смысла: bМоnеу*bМоnеу не представляет ничего реального, так как нет такой вещи, как денежный квадрат;
		вы не можете прибавить bМоnеу к long double (что же будет, если рубли сложить с изделиями?). Чтобы сделать это невозможным,
		скомпилируйте такие неправильные операции, не включая операции преобразования для bМоnеу в long double или long double в bМоnеу.
		Если вы это сделаете и запишете затем выражение типа:
		bmon2 = bmonl + widgets; //это не имеет смысла
		то компилятор будет автоматически преобразовывать widgets в ЬМопеу и выполнять сложение. Без них компилятор
		будет отмечать такие преобразования как ошибки, что позволит легче найти концептуальные ошибки.
		Также сделайте конструкторы преобразований явными.*/
		bMoney n1, n2, res;
		n1.getmoney();
		n2.getmoney();
		cout << "bМоnеу = bМоnеу + bМоnеу: ";
		res = n1 + n2;
		res.putmoney();
		cout << endl;
		cout << "bМоnеу = bМоnеу - bМоnеу: ";
		res = n1 - n2;
		res.putmoney();
		cout << endl;
		cout << "bМоnеу = bМоnеу * long double: ";
		long double num = n2;
		res = n1 * num;
		res.putmoney();
		cout << endl;
		cout << "bМоnеу = bМоnеу / long double: ";
		res = n1 / num;
		res.putmoney();
		cout << endl;

	}break;
	case 9: {
		/*Дополните класс safearray из программы ARR0VER3 так, чтобы пользователь мог определять и верхнюю, и нижнюю границы массива
		(например, индексы, начинающиеся с 100 и заканчивающиеся 200).
			Имеем перегруженную операцию доступа к членам массива, проверяющую индексы каждый раз, когда к массиву нужен доступ,
		для проверки того, что мы не вышли за пределы массива. Вам понадобится конструктор с двумя аргументами, который определяет
		верхнюю и нижнюю границы. Так как мы еще не изучили, как выделять память динамически, то данные класса все еще будут размещаться
		в массиве, состоящем из 100 элементов, но вообще вы можете преобразовывать индексы массива safearray в индексы реального массива
		целых чисел произвольным образом.
		Например, если пользователь определил диапазон от 100 до 175, то вы можете преобразовать его в диапазон от агг[0] до агг[75].
		if(b-a>100)exit(1);		*/
		safearay sa1;
		sa1.getLim();

	}break;
	case 10: {
		/*Создайте класс Polar, который предназначен для хранения полярных координат (радиуса и угла). Перегрузите операцию + для выполнения
		сложения для объектов класса Polar. Сложение двух объектов выполняется путем сложения координат X объектов, а затем координат Y.
		Результат будет координатами новой точки. Таким образом, вам нужно будет преобразовать полярные координаты к прямоугольным, сложить их,
		а затем обратно преобразовать прямоугольные координаты результата к полярным.*/
		Polar a(2, 3), b(2, 3), c;
		c = a + b;
		c.putInfo();
	}break;
	case 11: {
		/*Помните структуру sterling? Мы встречались с ней в упражнении 10 лабораторной работы №2 «Основы программирования на С++»,
		в упражнении 11 лабораторной работы №4 и в других местах. Преобразуйте ее в класс, имеющий переменные для фунтов (типа long),
		шиллингов (типа int) и пенсов (типа int). Создайте в классе следующие функции:
			конструктор без аргументов; +
			конструктор с одним аргументом типа double (для преобразования от десятичных фунтов);  +
			конструктор с тремя аргументами: фунтами, шиллингами и пенсами;  +
			метод getSterLing() для получения от пользователя значений количества фунтов, шиллингов и пенсов в формате £9.19.11;  +
			метод putSterling() для вывода значений количества фунтов, шиллингов и пенсов в формате £9.19.11;  +
			метод для сложения (sterling + sterling), используя перегруженную операцию +;  +
			метод вычитания (sterling - sterling), используя перегруженную операцию -;  +
			метод умножения (sterling * double), используя перегруженную операцию *;	+
			метод деления (sterling / sterling), используя перегруженную операцию /;	+
			метод деления (sterling / double), используя перегруженную операцию /;	+
			операцию double (для преобразования к типу double) +
		Выполнять вычисления вы можете, например, складывая отдельно данные объекта: сложить сначала пенсы, затем шиллинги и т. д.
		Однако легче использовать операцию преобразования для преобразования объекта класса sterling к типу double, выполнить вычисления
		с типами double, а затем преобразовать обратно к типу sterling.*/
		sterling s1, s2, s;
		s1.getSter();
		s2.getSter();
		s = s1 + s2; cout << "Сумма: "; s.putSter();
		s = s1 - s2; cout << "Разность: "; s.putSter();
		s = s1 / s2; cout << "Частное: "; s.putSter();
		double temp = s1;
		s = s1 * temp; cout << "Произведение( sterling * double): "; s.putSter();
		s = s2 / temp; cout << "Частное(sterling / double): "; s.putSter();
	}break;
	}
}