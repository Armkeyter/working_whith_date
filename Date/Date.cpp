#include "Date.h"
int Date::count = 0;
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
	count++;
	
}


Date::Date(int day, int month, int year)
{
	this->year = year;
	this->month = month;
	this->day = day;
	count++;
}

Date::Date(int day, int month) :day(0), month(0), year(0) { count++; };


Date::Date(const Date& date) {//конструктор копирования
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
	count++;
};

Date::~Date()
{
}

void Date::Set(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::GetYear() {
	return this->year;
}

int Date::GetMonth() {
	return this->month;
}

int Date::GetDay() {
	return this->day;
}

int Date::GetCounter()
{
	return count;
}

void Date::Deduction(Date& date1, Date& dateRight) {
	int sum = 0;
	if (date1.month > dateRight.month) {
		Date temp;
		temp.month = date1.month;
		date1.month = dateRight.month;
		dateRight.month = temp.month;
		temp.day = date1.day;
		date1.day = dateRight.day;
		dateRight.day = temp.day;
	}

	for (int i = date1.month; i < dateRight.month; i++) {
		if (i == 1 || i == 3 || i == 4 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			sum += 31;
		}
		else if (i == 6 || i == 9 || i == 11) {
			sum += 30;
		}
		else
			if (date1.year % 4 == 0)
				sum += 29;
			else
				sum += 28;
	}
	sum = sum - date1.day + dateRight.day;
	cout << "Количество дней: " << sum << endl;
}

void Date::Neighbours(Date& date) {
	Date dateRight(date);
	Date dateLeft(date);
	if (dateLeft.day == 1) {
		if (dateLeft.month != 1) {
			dateLeft.month -= 1;
			if (dateLeft.month == 1 || dateLeft.month == 3 || dateLeft.month == 4 || dateLeft.month == 5 || dateLeft.month == 7 || dateLeft.month == 8 || dateLeft.month == 10 || dateLeft.month == 12) {
				dateLeft.day = 31;
			}
			else if (dateLeft.month == 6 || dateLeft.month == 9 || dateLeft.month == 11) {
				dateLeft.day = 30;
			}
			else
				if (dateLeft.year % 4 == 0)
					dateLeft.day = 29;
				else
					dateLeft.day = 28;
		}
		else {
			dateLeft.month = 12;
			dateLeft.year -= 1;
			dateLeft.day = 31;
		}
	}
	else
		dateLeft.day -= 1;
	cout << "Дата левее: " << dateLeft.day << '.' << dateLeft.month << '.' << dateLeft.year << endl;
	if (dateRight.month != 12) {
		if ((dateRight.month == 1 || dateRight.month == 3 || dateRight.month == 4 || dateRight.month == 5 || dateRight.month == 7 || dateRight.month == 8 || dateRight.month == 10) && dateRight.day == 31) {
			dateRight.day = 1;
			dateRight.month += 1;
		}
		else if ((dateRight.month == 6 || dateRight.month == 9 || dateRight.month == 11) && date.day == 30) {
			dateRight.day = 1;
			dateRight.month += 1;
		}
		else if ((dateRight.year % 4 == 0 && dateRight.day == 29) || dateRight.day == 28) {
			dateRight.day = 1;
			dateRight.month += 1;
		}
		else {
			dateRight.day += 1;
		}
	}
	else {
		if (dateRight.day == 31) {
			dateRight.day = 1;
			dateRight.month = 1;
			dateRight.year += 1;
		}
	}

	cout << "Дата правее: " << dateRight.day << '.' << dateRight.month << '.' << dateRight.year << endl;
}

void Date::NeighbourSome(Date& date, int n) {
		Date dateRight(date);
		Date dateLeft(date);
		if (dateLeft.day <= n) {
			if (dateLeft.month != 1) {
				dateLeft.month -= 1;
				if (dateLeft.month == 1 || dateLeft.month == 3 || dateLeft.month == 4 || dateLeft.month == 5 || dateLeft.month == 7 || dateLeft.month == 8 || dateLeft.month == 10 || dateLeft.month == 12) {
					dateLeft.day = 31 + dateLeft.day - n;
				}
				else if (dateLeft.month == 6 || dateLeft.month == 9 || dateLeft.month == 11) {
					dateLeft.day = 31 + dateLeft.day - n;
				}
				else
					if (dateLeft.year % 4 == 0)
						dateLeft.day = 30 + dateLeft.day - n;
					else
						dateLeft.day = 29 + dateLeft.day - n;
			}
			else {
				dateLeft.month = 12;
				dateLeft.year -= 1;
				dateLeft.day = 32 + dateLeft.day - n;
			}
		}
		else
			dateLeft.day -= n;
		cout << "Дата левее: " << dateLeft.day << '.' << dateLeft.month << '.' << dateLeft.year << endl;
		if (dateRight.month != 12) {
			if ((dateRight.month == 1 || dateRight.month == 3 || dateRight.month == 4 || dateRight.month == 5 || dateRight.month == 7 || dateRight.month == 8 || dateRight.month == 10) && dateRight.day == 31) {
				dateRight.day = n;
				dateRight.month += 1;
			}
			else if ((dateRight.month == 6 || dateRight.month == 9 || dateRight.month == 11) && date.day == 30) {
				dateRight.day = n;
				dateRight.month += 1;
			}
			else if ((dateRight.year % 4 == 0 && dateRight.day == 29) || dateRight.day == 28) {
				dateRight.day = n;
				dateRight.month += 1;
			}
			else {
				dateRight.day += n;
			}
		}
		else {
			if (dateRight.day == 31) {
				dateRight.day = n;
				dateRight.month = 1;
				dateRight.year += 1;
			}
		}
		cout << "Дата правее: " << dateRight.day << '.' << dateRight.month << '.' << dateRight.year << endl;
	}

void Date::Compare(Date& date1, Date& dateRight) {
	if (

		date1.year == dateRight.year && date1.month == dateRight.month && date1.day == dateRight.day)
		cout << "Даты равны!" << endl;
	else if (date1.year > dateRight.year)
		cout << "Первая дата больше второй" << endl;
	else  if (dateRight.year > date1.year)
		cout << "Вторая дата больше первой" << endl;
	else if (dateRight.year == date1.year) {
		if (date1.month > dateRight.month)
			cout << "Первая дата больше второй" << endl;
		else if (date1.month < dateRight.month)
			cout << "Вторая дата больше первой" << endl;
		else
			if (date1.day > dateRight.day)
				cout << "Первая дата больше второй" << endl;
			else
				cout << "Вторая дата больше первой" << endl;
	}
}

void Date::operator=(Date& other)//Оператор присваивания
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

Date& Date::operator++()
{
	this->year++;
	return *this;
}

Date& Date::operator++(int value)
{
	Date temp(*this);
	this->year++;
	return temp;
}

ostream& operator<<(ostream& out, Date&other)
{
	out << other.day << '.' << other.month << '.' << other.year;
	return out;
}

istream& operator>>(istream& in, Date&other)
{
	in >> other.day >> other.month >> other.year;
	return in;
}
