#pragma once
#ifndef __BILL_H__
#define __BILL_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class myDate
{
private:
	int dd;
	int mm;
	int yy;
public:
	myDate();
	myDate(int, int, int);
	myDate(const myDate&);
	myDate& operator=(const myDate&);
	~myDate();

	int getDd()const;
	void setDd(int);
	int getMm()const;
	void setMm(int);
	int getYy()const;
	void setYy(int);

	void input();
	void output();

	int toInt();
	bool isValue();
	int distance(myDate);
};

class BILL
{
private:
	string borrowerID;
	string billID;
	vector<string>listBook;
	myDate loanDay;
	myDate returnDay;
	float fine;
public:
	BILL();
	BILL(string, string,vector<string>, myDate, myDate, float);
	BILL(const BILL&);
	~BILL();

	int getLoanDd()const;
	void setLoanDd(int);
	int getLoanMm()const;
	void setLoanMm(int);
	int getLoanYy()const;
	void setLoanYy(int);

	int getReturnDd()const;
	void setReturnDd(int);
	int getReturnMm()const;
	void setReturnMm(int);
	int getReturnYy()const;
	void setReturnYy(int);

	string getBorrowerID()const;
	string getBillID()const;
	vector<string>getListBook()const;
	myDate getLoanDay()const;
	myDate getReturnDay()const;
	float getFine()const;

	void setBorrowerID(string);
	void setBillID(string);
	void setListBook(vector<string>);
	void setLoanDay(myDate);
	void setReturnDay(myDate);
	void setFine(float);

	void pushBookID(string);

	void input();
	void output();

};
#endif // !__BILL_H__
