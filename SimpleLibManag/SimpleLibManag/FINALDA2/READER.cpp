#include "READER.h"

READER::READER() 
{
	this->readerID = "";
	this->readerName = "";
}

READER::READER(string tempID, string tempName)
{
	this->readerID = tempID;
	this->readerName = tempName;
}

READER::READER(const READER&A)
{
	this->readerID = A.readerID;
	this->readerName = A.readerName;
}

READER::~READER(){}

string READER::getReaderID()const
{
	return this->readerID;
}

string READER::getReaderName()const
{
	return this->readerName;
}

void READER::setReaderID(string tempID)
{
	this->readerID = tempID;
}

void READER::setReaderName(string tempName)
{
	this->readerName = tempName;
}

void READER::input()
{
	cout << "Input Reader ID: " << endl;
	getline(cin >> ws, this->readerID);

	cout << "Input Reader Name: " << endl;
	getline(cin >> ws, this->readerName);
}

void READER::output()
{
	cout << "Reader ID: " << this->readerID << endl;
	
	cout << "Reader Name: " << this->readerName << endl;
}