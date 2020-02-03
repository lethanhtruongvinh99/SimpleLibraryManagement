#pragma once
#ifndef __COMPANY_H__
#define __COMPANY_H__

#include "BOOK.h"
#include "READER.h"
#include "BILL.h"

#include <vector>
#include <fstream>
class COMPANY
{
private:
	vector<BOOK*>bookData;
	vector<READER>readerData;
	vector<BILL>billData;
	
	fstream bookFile;
	fstream readerFile;
	fstream billFile;
	fstream fineFile;

public:

// for BOOK

	void addBook();
	void deleteBook();
	int findBookByID(string);
	int findBookByName(string);
	int findBookByAuthor(string);
	int findBookByISBN(string);
	void updateBook();

	void loadBook();
	void saveBook();

	int bookMenu();
	void bookRun(int);

//for READER
	void addReader();
	void deleteReader();
	int findReader(string);
	void updateReader();

	void loadReader();
	void saveReader();

	int readerMenu();
	void readerRun(int);

//for BILL	
	void addBill();
	//void deleteBill();
	
	void loadBill();
	void saveBill();

	int billMenu();
	void billRun(int);

//for COMPANY

	int menu();
	void run(int);
};
#endif // !__COMPANY_H__
