#include"AgeCal.h"

#include<iostream>
#include<fstream>
using namespace std;

void DOB(AgeCal &s1);
void COB(AgeCal &s2);
AgeCal findage(AgeCal s1, AgeCal s2);
int daysmonth(int month, int year);
void displayage(AgeCal &s);

void reading(ifstream &fin);
void smaller_record(AgeCal *ptr, AgeCal &s, int size);
void menu(void);
void operation(AgeCal *ptr, int size);
void greater_record(AgeCal *ptr, AgeCal &s, int size);
int equal_record(AgeCal *ptr, AgeCal &s, int size);
void most_year(AgeCal *ptr, AgeCal &s, int size);
void most_month(AgeCal *ptr, AgeCal &s1, int size);
int main()
{
	AgeCal s1, s2, s3;
	ifstream fin;
	DOB(s1);
	COB(s2);
	s3 = findage(s1, s2);
	displayage(s3);

	char arr[20];
	cout << "\n\n\nEnter your file name : ";
	cin.ignore(1);	
	cin.getline(arr, 20);
	fin.open(arr);
	if (!fin)
	{
		cout << "\n\nFile not found...soory\n";
		return 0;
	}
	else
	{
		reading(fin);
	}
}

void reading(ifstream  &fin)
{
	int size = 0, d = 0;
	char temp1[20] = { 0 }, temp2[20] = { 0 };
	fin >> size;
	AgeCal *ptr;
	ptr = new AgeCal[size];
	for (int i = 0; i < size; i++)
	{
		fin >> d;
		ptr[i].setday(d);
		fin >> d;
		ptr[i].setmonth(d);
		fin >> d;
		ptr[i].setyear(d);
		fin >> temp1;
		ptr[i].setname(temp1);
		fin >> temp2;
		ptr[i].setrollno(temp2);
	}
	operation(ptr, size);
	delete []ptr;
	ptr=nullptr;
}
void operation(AgeCal *ptr, int size)
{
	AgeCal s1,s2;
	int d=0, m=0, y=0,opt=0,c1=0,c2=0;
	char ch = y;

	s1.setday(d);
	s1.setmonth(m);
	s1.setyear(y);
	while (ch != 'n')
	{
		menu();
		cin >> opt;
		cout << "\n\nEnter a any date(date,month,year : ";
		cin >> d >> m >> y;
		switch (opt)
		{
			case 1:
			{
				smaller_record(ptr, s1, size);
				break;
			}
			case 2:
			{
				greater_record(ptr, s1, size);
				break;
			}
			case 3:
			{
				d = equal_record(ptr, s1, size);
				cout << "Total equal rccord is : " << d;
				break;
			}
			case 4:
			{
				cout << "Enter a second date : ";
				cin >> d >> m >> y;
				s2.setday(d);
				s2.setmonth(m);
				s2.setyear(y);
				for (int i = 0; i < size; i++)
				{
					if (s1.getyear() < ptr[i].getyear() && s2.getyear() > ptr[i].getyear())
					{	
						ptr[i].print();
					}
				}
				break;
			}
			case 5:
			{
				most_year(ptr, s1, size);
				break;
			}
			case 6:
			{
				most_month(ptr, s1, size);
				break;
			}
			default:
			{
				cout << "Enter a wrong input: ";
			}
		}
		cout << "\n\nYou want to task again : \nEnter y <yes> or n<no> :  ";
		cin >> ch;
	}
}
void most_year(AgeCal *ptr, AgeCal &s1, int size)
{
	int c1 = 0, c2 = 0, c = 0;
	for (int i = 0; i<size; i++)
	{
		c2 = 0;
		s1.setyear(ptr[i].getyear());
		for (int j = 0; j < size; j++)
		{
			if (s1.getyear() == ptr[i].getyear())
			{
				c2++;
			}
		}
		if (c1<c2)
		{
			c1 = c2;
			c = i;
		}
	}
	for (int k = 0; k < c2; k++)
	{
		if (ptr[c].getyear() == ptr[k].getyear())
		{
			ptr[k].print();
		}
	}
}
void most_month(AgeCal *ptr, AgeCal &s1, int size)
{
	int c1 = 0, c2 = 0, c = 0;
	for (int i = 0; i<size; i++)
	{
		c2 = 0;
		s1.setmonth(ptr[i].getmonth());
		for (int j = 0; j < size; j++)
		{
			if (s1.getmonth() == ptr[i].getmonth())
			{
				c2++;
			}
		}
		if (c1<c2)
		{
			c1 = c2;
			c = i;
		}
	}
	for (int k = 0; k < c2; k++)
	{
		if (ptr[c].getmonth() == ptr[k].getmonth())
		{
			ptr[k].print();
		}
	}
}

void smaller_record(AgeCal *ptr, AgeCal &s, int size)
{
	cout << "\nThose record is less than given DoB\n\n";
	for (int i = 0; i < size; i++)
	{
		if (s.getyear() > ptr[i].getyear())
		{
			ptr[i].print();
		}
		else if (s.getyear() == ptr[i].getyear())
		{
			if (s.getmonth() > ptr[i].getmonth())
			{
				ptr[i].print();
			}
			else if (s.getmonth() == ptr[i].getmonth())
			{
				if (s.getday() > ptr[i].getday())
				{
					ptr[i].print();
				}
			}
		}
	}
}
int equal_record(AgeCal *ptr, AgeCal &s, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (ptr[i].getyear() == s.getyear())
		{
			if (ptr[i].getmonth() == s.getmonth())
			{
				if (ptr[i].getday() == s.getday())
				{
					count++;
				}
			}
		}
	}
	return count;
}
void greater_record(AgeCal *ptr, AgeCal &s, int size)
{
	cout << "\nThose record is greater than given DoB\n\n";
	for (int i = 0; i < size; i++)
	{
		if (s.getyear() < ptr[i].getyear())
		{
			ptr[i].print();
		}
		else if (s.getyear() == ptr[i].getyear())
		{
			if (s.getmonth() < ptr[i].getmonth())
			{
				ptr[i].print();
			}
			else if (s.getmonth() == ptr[i].getmonth())
			{
				if (s.getday() < ptr[i].getday())
				{
					ptr[i].print();
				}
			}
		}
	}
}

void menu(void)
{
	cout << "\n\n1 : print all the students in the record which are smaller than the given dates";
	cout << "\n 2: print all the students in the record which are greater than the given dates";
	cout << "\n 3 : print the count of all the students which has the same date of birth";
	cout << "\n 4 : Given two dates d1 and d2, print all the students which are in between (d1,d2)";
	cout << "\n : 5 rint all the students of the year which are most occurring";
	cout << "\n 6 : rint all the students of the month which are most occurring";
	cout << "\n\n\nEnter your opinion :   ";
}

				//PART # 01
void DOB(AgeCal &s1)
{
	int d = 0, m = 0, y = 0;
	cout << "Enter your DOB (date,month,year) : ";
	cin >> d >> m >> y;
	if (d >= 1 && d <= 31)
	{
		s1.setday(d);
	}
	else
	{
		cout << "\nYou enter a wrong date  : \n so i set a day by default is 1";
		d = 1;
		s1.setday(d);

	}
	if (m >= 1 && m <= 12)
	{
		s1.setmonth(m);
	}
	else
	{
		cout << "\nYou enter a wrong month  : \n so i set a day by default is 1";
		m = 1;
		s1.setmonth(m);
	}
	s1.setyear(y);
}
void COB(AgeCal &s2)
{
	int d = 0, m = 0, y = 0;
	cout << "\n\nEnter your current DOB(date,month,year) :  ";
	cin >> d >> m >> y;
	if (d >= 1 && d <= 31)
	{
		s2.setday(d);
	}
	else
	{
		cout << "\nYou enter a wrong date  : \n so i set a day by default is 1";
		d = 1;
		s2.setday(d);

	}
	if (m >= 1 && m <= 12)
	{
		s2.setmonth(m);
	}
	else
	{
		cout << "\nYou enter a wrong month  : \n so i set a day by default is 1";
		m = 1;
		s2.setmonth(m);
	}
	s2.setyear(y);
}
AgeCal findage(AgeCal s1, AgeCal s2)
{
	int d, m, y;
	AgeCal res;
	d = s2.getday() - s1.getday();
	if (d<0)
	{
		m = s2.getmonth();
		m--;
		res.setmonth(m);
		d += daysmonth(s2.getmonth(), s2.getyear());
		if (d < 0)
		{
			m--;
			res.setmonth(m);
			d += daysmonth(s2.getmonth(), s2.getyear());
		}
	}
	m = s2.getmonth() - s1.getmonth();
	if (m < 0)
	{
		y = res.getmonth();
		y--;
		res.setmonth(m);
		m += 12;
	}
	y = s2.getyear() - s1.getyear();

	res.setday(d);
	res.setmonth(m);
	res.setyear(y);
	return res;
}
int daysmonth(int month, int year)
{
	int days = 0;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		days += 30;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
	{
		days += 31;
	}
	else if (month == 2 && year % 4 == 0)
	{
		days += 29;
	}
	else
	{
		days += 28;
	}
	return days;
}
void displayage(AgeCal &s)
{
	cout << "Your age is " << s.getyear() << " year ";
	cout << " " << s.getmonth() << " month";
	cout << " " << s.getday() << " days";
}
