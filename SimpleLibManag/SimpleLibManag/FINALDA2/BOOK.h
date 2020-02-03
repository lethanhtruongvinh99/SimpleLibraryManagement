#pragma once
#ifndef __BOOK_H__
#define __BOOK_H__

#include <iostream>
#include <string>

using namespace std;

class BOOK
{
protected:
	string bookID;
	string bookName;
	string authorName;
	string publishCom;
	float price;
public:
	BOOK();
	BOOK(string, string, string, string, float);
	BOOK(const BOOK&);
	~BOOK();

	string getBookID()const;
	string getBookName()const;
	string getAuthorName()const;
	string getPublishCom()const;
	float getPrice()const;
	virtual string getISBN() = 0;

	void setBookID(string);
	void setBookName(string);
	void setAuthorName(string);
	void setPublishCom(string);
	void setPrice(float);
	virtual void setISBN(string) = 0;

	virtual void input();
	virtual void output();
};

class vietnamBook :public BOOK
{
public:
	string getISBN();
	void setISBN(string);

	void input();
	void output();
};

class foreignBook : public BOOK
{
private:
	string ISBN;

public:
	/*foreignBook();
	foreignBook(string, string, string, string, float, bool, string);
	foreignBook(const foreignBook&);
	~foreignBook();*/

	string getISBN();
	void setISBN(string);

	void input();
	void output();
};
#endif