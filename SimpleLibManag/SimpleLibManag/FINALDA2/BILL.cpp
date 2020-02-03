#include "BILL.h"

myDate::myDate() {}
myDate::myDate(int tempDd, int tempMm, int tempYy)
{
	this->dd = tempDd;
	this->mm = tempMm;
	this->yy = tempYy;
}

myDate::myDate(const myDate&A)
{
	this->dd = A.dd;
	this->mm = A.mm;
	this->yy = A.yy;
}

myDate& myDate::operator=(const myDate&A)

{
	this->dd = A.dd;
	this->mm = A.mm;
	this->yy = A.yy;
	return *this;
}

myDate::~myDate() {}

int myDate::getDd()const
{
	return this->dd;
}

void myDate::setDd(int temp)
{
	this->dd = temp;
}

int myDate::getMm()const
{
	return this->mm;
}

void myDate::setMm(int temp)
{
	this->mm = temp;
}

int myDate::getYy()const
{
	return this->yy;
}

void myDate::setYy(int temp)
{
	this->yy = temp;
}

void myDate::input()
{
	cout << "Input Day: " << endl;
	cin >> this->dd;

	cout << "Input Month: " << endl;
	cin >> this->mm;

	cout << "Input Year: " << endl;
	cin >> this->yy;
}

void myDate::output()
{
	cout << this->mm << "/" << this->dd << "/" << this->yy << endl;
}

bool myDate::isValue()
{
	int dayMax;
	if (this->yy < 0 || this->mm < 0 || this->mm> 12 || this->dd < 0 || this->dd> 31)
	{
		return 0;
	}
	else
	{
		switch (this->mm)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			dayMax = 31;
			break;
		case 2:
			if ((this->yy % 4 == 0 && this->yy % 100 != 0) || (this->yy % 400 == 0))
				dayMax = 29;
			else
				dayMax = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			dayMax = 30;
			break;
		}
		if (this->dd > dayMax)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int myDate::toInt()
{
	if (this->mm < 3)
	{
		this->yy--;
		this->mm += 12;
	}
	return 365 * this->yy + this->yy / 4 - this->yy / 100 + this->yy / 400 + (153 * this->mm - 457) / 5 + this->dd - 306;
}

int myDate::distance( myDate A)
{
	return abs(this->toInt() - A.toInt());
}

BILL::BILL() {}

BILL::BILL(string tempBorrowerID, string tempBillID, vector<string>tempListID, myDate tempLoanDay, myDate tempPayDay, float tempFine)
{
	this->borrowerID = tempBorrowerID;
	this->billID = tempBillID;
	this->listBook = tempListID;
	this->loanDay = tempLoanDay;
	this->returnDay = tempPayDay;
	this->fine = tempFine;
}

BILL::BILL(const BILL&A)
{
	this->borrowerID = A.borrowerID;
	this->billID = A.billID;
	this->listBook = A.listBook;
	this->loanDay = A.loanDay;
	this->returnDay = A.returnDay;
	this->fine = A.fine;
}

BILL::~BILL(){}

string BILL::getBorrowerID()const
{
	return this->borrowerID;
}

string BILL::getBillID()const
{
	return this->billID;
}

vector<string> BILL::getListBook()const
{
	return this->listBook;
}

myDate BILL::getLoanDay()const
{
	return this->loanDay;
}

myDate BILL::getReturnDay()const
{
	return this->returnDay;
}

float BILL::getFine()const
{
	return this->fine;
}

void BILL::setBorrowerID(string temp)
{
	this->borrowerID = temp;
}

void BILL::setBillID(string temp)
{
	this->billID = temp;
}

void BILL::setListBook(vector<string>tempListBook)
{
	this->listBook = tempListBook;
}

void BILL::setLoanDay(myDate temp)
{
	this->loanDay = temp;
}

void BILL::setReturnDay(myDate temp)
{
	this->returnDay = temp;
}

void BILL::setFine(float temp)
{
	this->fine = temp;
}

int BILL::getLoanDd()const
{
	return this->loanDay.getDd();
}
void BILL::setLoanDd(int temp)
{
	this->loanDay.setDd(temp);
}
int BILL::getLoanMm()const
{
	return this->loanDay.getMm();
}
void BILL::setLoanMm(int temp)
{
	this->loanDay.setMm(temp);
}
int BILL::getLoanYy()const
{
	return this->loanDay.getYy();
}
void BILL::setLoanYy(int temp)
{
	this->loanDay.setYy(temp);
}

int BILL::getReturnDd()const
{
	return this->returnDay.getDd();
}
void BILL::setReturnDd(int temp)
{
	this->returnDay.setDd(temp);
}

int BILL::getReturnMm()const
{
	return this->returnDay.getMm();
}

void BILL::setReturnMm(int temp)
{
	this->returnDay.setMm(temp);
}
int BILL::getReturnYy()const
{
	return this->returnDay.getYy();
}

void BILL::setReturnYy(int temp)
{
	this->returnDay.setYy(temp);
}

void BILL::pushBookID(string tempID)
{
	this->listBook.push_back(tempID);
}

void BILL::input()
{
	cout << "Input Reader ID: " << endl;
	getline(cin >> ws, this->borrowerID);

	cout << "Input Bill ID: " << endl;
	getline(cin >> ws, this->billID);

}

void BILL::output()
{
	cout << "Reader ID: " << this->borrowerID << endl;

	cout << "Bill ID: " << this->billID << endl;

	cout << "Loan Day: ";
	this->loanDay.output();

	cout << "Return Day: ";
	this->returnDay.output();

	cout << "List ID Book: ";

	for (size_t i = 0; i < this->listBook.size(); i++)
	{
		cout << this->listBook[i] << " ";
	}
	cout << endl;

	cout << "Fine: " << this->fine << endl;
}
