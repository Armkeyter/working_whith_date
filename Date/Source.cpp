#include <iostream>
#include "Date.h"
using namespace std;

// 31day 01,03,04,05,07,08,10,12
//30day 06,09,11
//28-29day 02

int main(void) {
	setlocale(0, "ru");
	Date date3(12, 04, 2017);// ����������� � ����������
	Date date4(date3);//����������� �����������
	int day, month, year, choice, number = 0;
	Date date1;//����������� �� ���������
	Date date2;
	cout << "������� ������ ���� ����� Enter ���� ����� � ���" << endl;
	cin >> day >> month >> year;
	date1.Set(day, month, year);
	cout << "������� ������ ���� ����� Enter ���� ����� � ���" << endl;
	cin >> date2;
	while (true) {
		cout << "����� �������� �� ������ ������� � ������" << '\n'
			<< "������� (1) ���� �� ������ ������ ������� ���� ����� ������ ������" << '\n'
			<< "������� (2) ���� �� ������ ������ �������� ����" << '\n'
			<< "������� (3) ���� �� ������ ������ �������� ���� ����� �����-�� ����� n" << '\n'
			<< "������� (4) ���� �� ������ �������� ����" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			date1.Deduction(date1, date2);
			break;
		case 2:
			cout << "����� ���� �� ������ ������������, ������ ��� ������?" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				date1.Neighbours(date1);
				break;
			case 2:
				date2.Neighbours(date2);
				break;
			default:
				cout << "�� ����� �� �� �����" << endl;

			}
			break;
		case 3:
			cout << "������� ���� ����� ���������" << endl;
			cin >> number;
			cout << "����� ���� �� ������ ������������, ������ ��� ������?" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				date1.NeighbourSome(date1, number);
				break;
			case 2:
				date2.NeighbourSome(date2, number);
				break;
			default:
				cout << "�� ����� �� �� �����" << endl;
			}
			break;
		case 4:
			date1.Compare(date1, date2);
			break;
		default:
			cout << "�� ����� �� �� �����" << endl;
		}
	}
	

}