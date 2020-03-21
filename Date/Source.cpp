#include <iostream>
#include "Date.h"
using namespace std;

// 31day 01,03,04,05,07,08,10,12
//30day 06,09,11
//28-29day 02

int main(void) {
	setlocale(0, "ru");
	Date date3(12, 04, 2017);// конструктор с параметром
	Date date4(date3);//конструктор копирования
	int day, month, year, choice, number = 0;
	Date date1;//конструктор по умолчанию
	Date date2;
	cout << "Введите первую дату через Enter день месяц и год" << endl;
	cin >> day >> month >> year;
	date1.Set(day, month, year);
	cout << "Введите вторую дату через Enter день месяц и год" << endl;
	cin >> date2;
	while (true) {
		cout << "Какие операции вы хотите сделать с датами" << '\n'
			<< "Нажмите (1) если вы хотите узнать сколько дней между вашими датами" << '\n'
			<< "Нажмите (2) Если вы хотите узнать соседние даты" << '\n'
			<< "Нажмите (3) Если вы хотите узнать соседние даты через какое-то число n" << '\n'
			<< "Нажмите (4) если вы хотите сравнить даты" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			date1.Deduction(date1, date2);
			break;
		case 2:
			cout << "Какую дату вы хотите использовать, первую или вторую?" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				date1.Neighbours(date1);
				break;
			case 2:
				date2.Neighbours(date2);
				break;
			default:
				cout << "Вы ввели не то число" << endl;

			}
			break;
		case 3:
			cout << "Сколько дней будет интеравал" << endl;
			cin >> number;
			cout << "Какую дату вы хотите использовать, первую или вторую?" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				date1.NeighbourSome(date1, number);
				break;
			case 2:
				date2.NeighbourSome(date2, number);
				break;
			default:
				cout << "Вы ввели не то число" << endl;
			}
			break;
		case 4:
			date1.Compare(date1, date2);
			break;
		default:
			cout << "Вы ввели не то число" << endl;
		}
	}
	

}