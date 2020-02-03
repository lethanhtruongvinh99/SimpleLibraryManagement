#include "BOOK.h"

BOOK::BOOK()
{
	this->bookID = "";
	this->bookName = "";
	this->authorName = "";
	this->publishCom = "";
	this->price = 0;
}

BOOK::BOOK(string tempID, string tempName, string tempAuthor, string tempPub, float tempPrice)
{
	this->bookID = tempID;
	this->bookName = tempName;
	this->authorName = tempAuthor;
	this->publishCom = tempPub;
	this->price = tempPrice;
}

BOOK::BOOK(const BOOK&A)
{
	this->bookID = A.bookID;
	this->bookName = A.bookName; 
	this->authorName = A.authorName;
	this->publishCom = A.publishCom;
	this->price = A.price;

}

BOOK::~BOOK(){}

string BOOK::getBookID()const
{
	return this->bookID;
}

string BOOK::getBookName()const
{
	return this->bookName;
}

string BOOK::getAuthorName()const
{
	return this->authorName;
}

string BOOK::getPublishCom()const
{
	return this->publishCom;
}

float BOOK::getPrice()const
{
	return this->price;
}

void BOOK::setBookID(string tempID)
{
	this->bookID = tempID;
}

void BOOK::setBookName(string tempName)
{
	this->bookName = tempName;
}

void BOOK::setAuthorName(string tempAuthor)
{
	this->authorName = tempAuthor;
}

void BOOK::setPublishCom(string tempPub)
{
	this->publishCom = tempPub;
}

void BOOK::setPrice(float tempPrice)
{
	this->price = tempPrice;
}

void BOOK::input()
{
	cout << "Input Name of Book: " << endl;
	getline(cin >> ws, this->bookName);

	cout << "Input ID of Book: " << endl;
	getline(cin >> ws, this->bookID);

	cout << "Input Name of Author: " << endl;
	getline(cin >> ws, this->authorName);

	cout << "Input Name of Publish Company: " << endl;
	getline(cin >> ws, this->publishCom);

	cout << "Input Price of Book" << endl;
	cin >> this->price;
}

void BOOK::output()
{
	cout << "Name of Book: " << this->bookName << endl;

	cout << "ID of Book: " << this->bookID << endl;

	cout << "Name of Author: " << this->authorName << endl;

	cout << "Publish Company: " << this->publishCom << endl;

	cout << "Price: " << this->price << endl;

}

string vietnamBook::getISBN()
{
	return "";
}

void vietnamBook::setISBN(string tempISBN)
{
	cout << "Vietnamese Book don't have ISBN" << endl;
	return;
}

void vietnamBook::input()
{
	BOOK::input();
}

void vietnamBook::output()
{
	BOOK::output();
}

string foreignBook::getISBN()
{
	return this->ISBN;
}

void foreignBook::setISBN(string tempISBN)
{
	this->ISBN = tempISBN;
}

void foreignBook::input()
{
	BOOK::input();

	cout << "Input ISBN code: " << endl;
	getline(cin >> ws, this->ISBN);
}

void foreignBook::output()
{
	BOOK::output();

	cout << "ISBN Code: " << this->ISBN << endl;
}