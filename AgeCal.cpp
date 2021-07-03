#include "AgeCal.h"

#include<iostream>
using namespace std;

AgeCal::AgeCal()
{
	day = 0;
	month = 0;
	year = 0;
	name[20] = { 0 };
	rollno [20] = { 0 };
}
AgeCal::AgeCal(int d, int m, int y, char name[], char rollno[])
{
	setname(name);
	setrollno(rollno);
	setday(d);
	setmonth(m);
	setyear(y);
}
void AgeCal::setname(char n[])
{
	int i = 0;
	for (; n[i] != '\0'; i++)
	{
		name[i] = n[i];
	}
	name[i] = '\0';
}
void AgeCal::setrollno(char r[])
{
	int i = 0;
	for (; r[i] != '\0'; i++)
	{
		rollno[i] = r[i];
	}
	rollno[i] = '\0';
}
void AgeCal::setday(int d)
{
	day = d;
}
void AgeCal::setmonth(int m)
{
	month = m;
}
void AgeCal::setyear(int y)
{
	year = y;
}
char* AgeCal::getname()
{
	return name;
}
char* AgeCal::getrollno()
{
	return rollno;
}
int AgeCal::getday(void)
{
	return day;
}
int AgeCal::getmonth(void)
{
	return month;
}
int AgeCal::getyear(void)
{
	return year;
}
void AgeCal::print()
{
	cout << "\n\nDate is " << this->day;
	cout << "\nMonth is " << this->month;
	cout << "\nYear is " << this->year;
	cout << "\nName is " << this->name;
	cout << "\nRollno is " << this->rollno;
}
AgeCal::~AgeCal()
{
}