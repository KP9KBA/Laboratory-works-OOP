﻿#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a;
    cout << "Введите номер задания лабораторной работы: ";
    cin >> a;
    switch (a) {
    case 1: {
        /*1) Считая, что кубический фут равен 7,481 галлона, написать программу,
    запрашивающую у пользователя число галлонов и выводящую на экран
    эквивалентный объем в кубических футах.*/

    // converts gallons to cubic feet
        float gallons, cufeet;

        cout << "\nВведите число галлонов: ";
        cin >> gallons;
        cufeet = gallons / 7.481;
        cout << "Эквивалентный объем галлонов в кубических футах " << cufeet << endl;

    }break;
    case 2: {
        /*Напишите программу, выводящую следующую таблицу :
        1990           135
            1991          7290
            1992        11300
            1993        16200
            В программе использовать только один оператор с cout.*/
            // generates table

            cout << 1990 << setw(8) << 135 << endl
                << 1991 << setw(8) << 7290 << endl
                << 1992 << setw(8) << 11300 << endl
                << 1993 << setw(8) << 16200 << endl;
    }break;
    case 3: {
        /*Напишите программу, генерирующую следующий вывод :
        10
            20
            19
            Используйте представление числа 10 в виде целой константы.
            Для вывода числа 20 воспользуйтесь одной из арифметических 
            операций с присваиванием, а для вывода числа 19 — операцией декремента.*/

            // exercises arithmetic assignment and decrement
            int var = 10;

            cout << var << endl;      // var = 10
            var *= 2;                 // var стало = 20
            cout << var-- << endl;    // выводим var, затем декрементируем
            cout << var << endl;      // var = 19
    }break;
    case 4: {
        /*4.Напишите программу, выводящую па экран ваше любимое стихотворение. 
        Для разбиения на строчки используйте подходящую управляющую последовательность.*/
        /*Ночь, улица, фонарь, аптека...
            Ночь, улица, фонарь, аптека,
            Бессмысленный и тусклый свет.
            Живи еще хоть четверть века -
            Все будет так.Исхода нет.
            Умрешь - начнешь опять сначала
            И повторится все, как встарь :
        Ночь, ледяная рябь канала,
            Аптека, улица, фонарь.*/
        cout << "Мое любимое стихотворение " << endl;
        cout << "Ночь, улица, фонарь, аптека..." << endl
            << "Ночь, улица, фонарь, аптека," << endl
            << "Бессмысленный и тусклый свет." << endl
            << "Живи еще хоть четверть века -" << endl
            << "Все будет так.Исхода нет." << endl
            << "Умрешь - начнешь опять сначала" << endl
            << "И повторится все, как встарь :" << endl
            << "Ночь, ледяная рябь канала," << endl
            << "Аптека, улица, фонарь." << endl;
    }break;
    case 5: {
        /*Библиотечная функция islower() принимает в качестве аргумента один символ (букву)
        и возвращает ненулевое целое значение в том случае, если буква является строчной, 
        и нулевое, если буква является заглавной. Описание функции хранится в файле CTYPE.H. 
        Напишите программу, которая принимает букву от пользователя, а затем выводит нулевое 
        или ненулевое значение в зависимости от того, является ли буква строчной или нет.*/
        char a;
        cout << "Введите букву: ";
        cin >> a;
        if (islower(a) != 0) cout << 1;
        else cout << 0;
    }break;
    case 6: {
        /*На биржевых торгах за 1 фунт стерлингов давали $1.487, за франк — $0.172. 
        за немецкую марку — $0.584, а за японскую йену — $0.00955. Напишите программу, 
        которая запрашивает денежную сумму в долларах, а затем выводит эквивалентные 
        суммы в других валютах.*/
        float dollar;
        cout << "Введите денежную сумму в долларах: ";
        cin >> dollar;
        cout << "Суммы эквивалентные доллару в других валютах: Фунт - " << dollar / 1.487 << ";" << endl << " Немецкая марка - "
            << dollar / 0.584 << ";" << endl << " Японская йена - " << dollar / 0.00955 << ";" << endl << " Франк - " << dollar / 0.172
            << endl;
    }break;
    case 7: {
        /*Температуру, измеренную в градусах по Цельсию, можно перевести в градусы по Фаренгейту путем 
        умножения на 9/5 и сложения с числом 32. Напишите программу, запрашивающую температуру в 
        градусах по Цельсию и отображающую ее эквивалент по Фаренгейту.*/

        int C;//C-Celsius 
        cout << "Введите градусы по Цельсию: ";
        cin >> C;
        cout << "Градусы по Цельсию эквивалентно по Фаренгейту: " << (C * (9 / 5) + 32) << endl;
    }break;
    case 8: {
        /*8.Когда размер величины, выводимой на экран с помощью манипулятора setw(), оказывается 
        меньше размера зарезервированного поля, по умолчанию незаполненные поля заполняются пробелами. 
        Манипулятор setfill() принимает в качестве аргумента один символ, который замещает все 
        пробелы на незаполненных позициях поля. Модифицируйте пример 2 так, чтобы символы, 
        разделяющие пары значений из столбцов, были не пробелами, а точками, например
        Москва..........8425785*/
        cout << 1990 <<setfill('.')<< setw(8) << 135 << endl
            << 1991 << setw(8) << 7290 << endl
            << 1992 << setw(8) << 11300 << endl
            << 1993 << setw(8) << 16200 << endl;
    }break;
    case 9: {
        /*Две дроби а/b и c/d можно сложить следующим образом:
        a/b + c/d = (a*d + b*c)/(b*d)
        Например, 1/4 + 2/3 = (1*3 + 4*2)/4*3 = 11/12
        Напишите программу, запрашивающую у пользователя значения двух дробей, а затем 
        выводящую результат, также записанный в форме дроби. Взаимодействие программы с 
        пользователем может выглядеть, например, следующим образом:
        Введите первую дробь: 1/2 Введите вторую дробь: 2/5 Сумма равна 9/10
        Вы можете использовать тот факт, что операция извлечения >> может считывать более одного значения за раз:
        cin >> а >> dummychar >> b;*/
        int a, b, c, d, sum;
        char ch = '/';
        cout << " Введите первую дробь: ";
        cin >> a >> ch >> b;
        cout << "Введите вторую дробь: ";
        cin>> c >> ch >> d;
        if ((a * d + b * c) == (b * d))cout << "Сумма равна " << (a * d + b * c) / (b * d) << endl;
        else cout << "Сумма равна " << (a * d + b * c) <<ch<< (b * d);
    }break;
    case 10: {
        /*Устаревшая денежная система Великобритании состояла из фунтов, шиллингов и пенсов. 
        1 фунт был равен 20 шиллингам, а 1 шиллинг — 12 пенсам. Для записи использовалась система, 
        состоящая из знака £ и трех десятичных значений, разделенных точками. Например, запись £5.2.8 
        обозначала 5 фунтов, 2 шиллинга и 8 пенсов (пенс — множественное число отпенни). 
        Современная денежная система, принятая в 50-е годы XX века, состоит только из фунтов и пенсов, 
        причем один фунт равен 100 пенсам. Такой фунт называют десятичным. Таким образом, в новой денежной
        системе указанная сумма будет обозначаться как £5.13 (если быть точнее, £5.1333333). 
        Напишите программу, которая будет преобразовывать сумму, записанную в старом формате 
        (фунты, шиллинги, пенсы), в новый формат (фунты, пенсы). Форматом взаимодействия программы с 
        пользователем может являться следующий:
        Введите количество фунтов: 7 
        Введите количество шиллингов: 17 
        Введите количество пенсов: 9 
        Десятичных фунтов:  £7.89
        В большинстве компиляторов для представления знака £ используется десятичный код 156. 
        Некоторые компиляторы позволяют скопировать знак фунта прямо из таблицы символов Windows.*/
        int pound, shilling, penny;
        cout << "Введите количество фунтов: ";
        cin >> pound;
        cout << "Введите количество шиллингов: ";
        cin >> shilling;
        cout << "Введите количество пенсов: ";
        cin >> penny;
        penny = shilling * 12 + penny;
        shilling = penny / 12;
        //cout << "Десятичных фунтов: "<<(char)0x(U+00A3) << pound << "." << shilling;
    }break;
    case 11: {
        /*По умолчанию форматирование вывода производится по правому краю
поля. Можно изменить форматирование текста на левостороннее путем
использования манипулятора setiosflags(ios::left) (не беспокойтесь о смысле
новой формы записи, встретившейся в манипуляторе). Используйте этот
манипулятор вместе с setw() для того, чтобы произвести следующий вывод:
Фамилия     Имя	Адрес	Город
Петров      Василий         Кленовая 16	Санкт-Петербург
Иванов      Сергей           Осиновая 3	Находка
Сидоров     Иван	Березовая 21	Калининград*/


    }break;
    case 12: {
        /*Напишите программу, выполняющую действия, обратные тем, которые
описаны в упражнении 10, то есть запрашивающую у пользователя сум
му, указанную в десятичных фунтах, и переводящую ее в старую систему

фунтов, шиллингов и пенсов. Пример взаимодействия программы с пользователем может выглядеть так:
Введите число десятичных фунтов: 3.51 
Эквивалентная сумма в старой форме записи: £3.10.2
Обратите внимание на то, что если вам придется присваивать вещественное значение 
(например, 12,34) переменной целого типа, то его дробная часть (0,34) будет потеряна,
а целая переменная получит значение 12. Чтобы избежать предупреждения со стороны компилятора, 
используйте явное преобразование типов. Можно использовать операторы, подобные приведенным ниже:
float decpounds:	// сумма в десятичных фунтах
int pounds:	// сумма в старых фунтах
float decfrac:	// десятичная дробная часть
pounds = static_cast<int>(decpounds): //отбрасывание
//дробной части
decfrac = decpounds - pounds;	//прибавление дробной части
Чтобы получить число шиллингов, следует умножить на 20 значение переменной decfrac. 
Аналогичным образом можно получить число пен*/

    }break;
    }
	
	return 0;
}