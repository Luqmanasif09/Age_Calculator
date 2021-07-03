#pragma once
class AgeCal
{
private:
	char name[20];
	char rollno[20];
	int day;
	int month;
	int year;
public:
	AgeCal();
	AgeCal(int, int, int, char name[], char rollno[]);
	void setname(char []);
	void setrollno(char []);
	void setday(int);
	void setmonth(int);
	void setyear(int);
	int getday();
	int getmonth();
	int getyear();
	char* getname();
	char* getrollno();
	void print();
	~AgeCal();
};

