#pragma once
#ifndef __READER_H__
#define __READER_H__

#include <iostream>
#include <string>

using namespace std;

class READER
{
private:
	string readerID;
	string readerName;
public:
	READER();
	READER(string, string);
	READER(const READER&);
	~READER();

	string getReaderID()const;
	string getReaderName()const;

	void setReaderID(string);
	void setReaderName(string);

	void input();
	void output();
};
#endif