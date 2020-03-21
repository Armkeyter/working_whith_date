#include <iostream>
using namespace std;
#pragma once
class Date

{
public:
	
	Date();
	Date(int day , int month , int year );
	
	Date(int , int );
	Date( const Date& );
	~Date();
	void Set(int , int , int );
	
	int GetYear();
	int GetMonth();
	
	int GetDay();
	static int GetCounter();
	void Deduction(Date& , Date& );
	void Neighbours(Date&);
	void NeighbourSome(Date& , int );
	void Compare(Date& , Date& );
	void operator =(Date&);
	Date& operator++();
	Date& operator++(int);
	friend ostream&  operator<<(ostream&,Date&);
	friend istream& operator>>(istream&, Date&);
	
private:
	int day, month, year;
	static int count;
};

