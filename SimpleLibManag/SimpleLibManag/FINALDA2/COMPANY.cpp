#include "COMPANY.h"

const string type1 = "class vietnamBook";
const string type2 = "class foreignBook";
const int LIMITDAY = 7;
void COMPANY::addBook()
{
	cout << "Input Type of Book 1. Vietnamese 2. Foreign" << endl;
	char type;
	cin >> type;
	BOOK*book;
	if (type == '1')
	{
		book = new vietnamBook();
		book->input();
	}
	else if (type == '2')
	{
		book = new foreignBook();
		book->input();
	}
	else
	{
		cout << "N/A" << endl;
		return;
	}
	for (size_t i = 0; i < this->bookData.size(); i++)
	{
		if (book->getBookID() == this->bookData[i]->getBookID())
		{
			cout << "Book with ID " << book->getBookID() << " has been exist" << endl;
			return;
		}
	}
	this->bookData.push_back(book);
	cout << "Add Successfullly" << endl;
}

void COMPANY::deleteBook()
{
	string tempID;

	cout << "Input ID of Book to Delete: " << endl;
	getline(cin >> ws, tempID);

	for (size_t i = 0; i < this->bookData.size(); i++)
	{
		if (this->bookData[i]->getBookID() == tempID)
		{
			this->bookData[i] = this->bookData[this->bookData.size() - 1];
			this->bookData.pop_back();

			cout << "Delete Successful" << endl;
			return;
		}
	}
	cout << "non-exist Book with ID " << tempID << endl;
}

int COMPANY::findBookByID(string tempID)
{
	for (size_t i = 0; i < this->bookData.size(); i++)
	{
		if (this->bookData[i]->getBookID() == tempID)
		{
			this->bookData[i]->output();

			cout << "Found" << endl;

			return 1;
		}
	}

	cout << "non-exist Book With ID " << tempID << endl;
	return 0;
}

int COMPANY::findBookByName(string tempName)
{
	for (size_t i = 0; i < this->bookData.size(); i++)
	{
		if (this->bookData[i]->getBookName() == tempName)
		{
			this->bookData[i]->output();

			cout << "Found" << endl;

			return 1;
		}
	}

	cout << "non-exist Book with Name " << tempName << endl;
	return 0;
}

int COMPANY::findBookByAuthor(string tempAuthor)
{
	bool flag = 0;
	for (size_t i = 0; i < this->bookData.size(); i++)
	{
		if (this->bookData[i]->getAuthorName() == tempAuthor)
		{
			flag = 1;
			this->bookData[i]->output();
		}
	}
	if (flag == 1)
	{
		cout << "Found" << endl;
		return 1;
	}
	else
	{
		cout << "non-exist Book of Author " << tempAuthor << endl;
		return 0;
	}
}

int COMPANY::findBookByISBN(string tempISBN)
{
	for (size_t i = 0; i < this->bookData.size(); i++)
	{
		if (this->bookData[i]->getISBN() == tempISBN)
		{
			this->bookData[i]->output();

			cout << "Found" << endl;

			return 1;
		}
	}

	cout << "non-exist Book with ISBN code " << tempISBN << endl;
	return 0;
}

void COMPANY::updateBook()
{
	string tempID;

	cout << "Input Book ID to Update: " << endl;
	getline(cin >> ws, tempID);

	for (size_t i = 0; i < this->bookData.size(); i++)
	{
		if (this->bookData[i]->getBookID() == tempID)
		{
			string tempName;
			cout << "Re-Input Book Name: " << endl;
			getline(cin >> ws, tempName);
			this->bookData[i]->setBookName(tempName);

			string tempAuthor;
			cout << "Re-Input Book Author: " << endl;
			getline(cin >> ws, tempAuthor);
			this->bookData[i]->setAuthorName(tempAuthor);

			string tempPub;
			cout << "Re-Input Publishment Company: " << endl;
			getline(cin >> ws, tempPub);
			this->bookData[i]->setPublishCom(tempPub);

			float tempPrice;
			cout << "Re-Input Price: " << endl;
			cin >> tempPrice;
			this->bookData[i]->setPrice(tempPrice);

			if (typeid(this->bookData[i]).name() == type2)
			{
				string tempISBN;
				cout << "Re-Input ISBN Code: " << endl;
				getline(cin >> ws, tempISBN);
				this->bookData[i]->setISBN(tempISBN);
			}

			cout << "Update Successfully" << endl;

			return;
		}
	}
	cout << "non-exist Book with ID " << tempID << endl;
}

void COMPANY::loadBook()
{
	this->bookFile.open("BookFile.txt", ios::in);

	if (bookFile.fail() == true)
		return;

	BOOK*temp;
	do
	{
		string type;
		getline(bookFile, type, ',');

		if (type == "1")
		{
			temp = new vietnamBook();

			string tempID;
			getline(bookFile, tempID, ',');
			temp->setBookID(tempID);


			string tempName;
			getline(bookFile, tempName, ',');
			temp->setBookName(tempName);


			string tempAuthor;
			getline(bookFile, tempAuthor, ',');
			temp->setAuthorName(tempAuthor);

			string tempPub;
			getline(bookFile, tempPub, ',');
			temp->setPublishCom(tempPub);


			float tempPrice;
			bookFile >> tempPrice;
			temp->setPrice(tempPrice);

			bookFile >> ws;

			this->bookData.push_back(temp);
		}
		if (type == "2")
		{
			temp = new foreignBook();

			string tempID;
			getline(bookFile, tempID, ',');
			temp->setBookID(tempID);


			string tempName;
			getline(bookFile, tempName, ',');
			temp->setBookName(tempName);


			string tempAuthor;
			getline(bookFile, tempAuthor, ',');
			temp->setAuthorName(tempAuthor);

			string tempPub;
			getline(bookFile, tempPub, ',');
			temp->setPublishCom(tempPub);


			float tempPrice;
			bookFile >> tempPrice;
			temp->setPrice(tempPrice);

			char buffer;
			bookFile >> buffer;
			bookFile >> ws;

			string tempISBN;
			getline(bookFile, tempISBN);
			temp->setISBN(tempISBN);

			this->bookData.push_back(temp);
		}

	} while (!bookFile.eof());
	this->bookFile.close();
}

void COMPANY::saveBook()
{
	this->bookFile.open("BookFile.txt", ios::out);
	for (size_t i = 0; i < this->bookData.size(); i++)
	{
		if (typeid(*this->bookData[i]).name() == type1)
		{
			bookFile << "1,";
			bookFile << this->bookData[i]->getBookID() << ',';
			bookFile << this->bookData[i]->getBookName() << ',';
			bookFile << this->bookData[i]->getAuthorName() << ',';
			bookFile << this->bookData[i]->getPublishCom() << ',';
			bookFile << this->bookData[i]->getPrice();
			bookFile << endl;
		}

		if (typeid(*this->bookData[i]).name() == type2)
		{
			bookFile << "2,";
			bookFile << this->bookData[i]->getBookID() << ',';
			bookFile << this->bookData[i]->getBookName() << ',';
			bookFile << this->bookData[i]->getAuthorName() << ',';
			bookFile << this->bookData[i]->getPublishCom() << ',';
			bookFile << this->bookData[i]->getPrice() << ',';
			bookFile << this->bookData[i]->getISBN();
			bookFile << endl;
		}
	}
	this->bookFile.close();
}

int COMPANY::bookMenu()
{
	system("cls");
	cout << "WHAT DO YOU WANT TO DO" << endl;
	cout << "1. Add New Book " << endl;
	cout << "2. Delete Book" << endl;
	cout << "3. Search by ID" << endl;
	cout << "4. Search by Name" << endl;
	cout << "5. Search by Author" << endl;
	cout << "6. Search by ISBN code" << endl;
	cout << "7. Update Book Data" << endl;
	cout << "0. Exit" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Please Choose your Selection" << endl;

	int choice;
	cin >> choice;

	return choice;
}

void COMPANY::bookRun(int choice)
{
//	this->loadBook();
	do
	{
		choice = bookMenu();
		switch (choice)
		{
		case 1:
		{
			this->addBook();
			system("pause");
			break;
		}
		case 2:
		{
			this->deleteBook();
			system("pause");
			break;
		}
		case 3:
		{
			string tempID;
			cout << "Input ID of Book to Find: " << endl;
			getline(cin >> ws, tempID);

			this->findBookByID(tempID);
			system("pause");
			break;
		}
		case 4:
		{
			string tempName;
			cout << "input Name Of Book to Find: " << endl;
			getline(cin >> ws, tempName);

			this->findBookByName(tempName);
			system("pause");
			break;
		}
		case 5:
		{
			string tempAuthor;
			cout << "Input Name of Author to Find: " << endl;
			getline(cin >> ws, tempAuthor);

			this->findBookByAuthor(tempAuthor);
			system("pause");
			break;
		}
		case 6:
		{
			string tempISBN;
			cout << "Input ISBN code to Find: " << endl;
			getline(cin >> ws, tempISBN);

			this->findBookByISBN(tempISBN);
			system("pause");
			break;
		}
		case 7:
		{
			this->updateBook();
			system("pause");
			break;
		}
		}
	} while (choice != 0);
//	this->saveBook();
}

void COMPANY::addReader()
{
	READER reader;
	reader.input();

	for (size_t i = 0; i < this->readerData.size(); i++)
	{
		if (this->readerData[i].getReaderID() == reader.getReaderID())
		{
			cout << "Reader with ID " << reader.getReaderID() << " has been eixist" << endl;

			return;
		}
	}
	if (reader.getReaderID() == "")return;

	this->readerData.push_back(reader);
	cout << "Add successfully" << endl;
}

void COMPANY::deleteReader()
{
	string tempID;

	cout << "Input ID of Reader to Delete: " << endl;
	getline(cin >> ws, tempID);

	for (size_t i = 0; i < this->readerData.size(); i++)
	{
		if (this->readerData[i].getReaderID() == tempID)
		{

			this->readerData[i] = this->readerData[this->readerData.size() - 1];

			this->readerData.pop_back();

			cout << "Delete Successfully" << endl;
			return;
		}
	}

	cout << "non-exist Reader with ID " << tempID << endl;
}

int COMPANY::findReader(string tempID)
{

	for (size_t i = 0; i < this->readerData.size(); i++)
	{
		if (this->readerData[i].getReaderID() == tempID)
		{
			this->readerData[i].output();

			cout << "Found" << endl;

			return 1;
		}
	}

	cout << "non-exist Reader with ID " << tempID << endl;
	return 0;
}

void COMPANY::updateReader()
{
	string tempID;

	cout << "Input ID of Reader to Update: " << endl;
	getline(cin >> ws, tempID);

	for (size_t i = 0; i < this->readerData.size(); i++)
	{
		if (this->readerData[i].getReaderID() == tempID)
		{
			string tempName;
			cout << "Re-Input REader Name: " << endl;
			getline(cin >> ws, tempName);

			this->readerData[i].setReaderName(tempName);

			cout << "Update Successfully" << endl;
			return;
		}
	}
	cout << "non-exist Reader with ID " << tempID << endl;
}

void COMPANY::loadReader()
{
	this->readerFile.open("ReaderFile.txt", ios::in);

	if (readerFile.fail() == true)
		return;
	do
	{
		READER temp;
		string tempID;
		getline(readerFile >> ws, tempID, ',');
		temp.setReaderID(tempID);

		string tempName;
		getline(readerFile >> ws, tempName);
		temp.setReaderName(tempName);

		if (readerFile.eof()) break;

		this->readerData.push_back(temp);

	} while (!readerFile.eof());
	this->readerFile.close();
}

void COMPANY::saveReader()
{

	this->readerFile.open("ReaderFile.txt", ios::out);

	for (size_t i = 0; i < this->readerData.size(); i++)
	{

		readerFile << this->readerData[i].getReaderID() << ',';
		readerFile << this->readerData[i].getReaderName();
		readerFile << endl;

	}

	this->readerFile.close();
}

int COMPANY::readerMenu()
{
	system("cls");
	cout << "WHAT DO YOU WANT TO DO" << endl;
	cout << "1. Add Reader" << endl;
	cout << "2. Delete Reader" << endl;
	cout << "3. Find Reader" << endl;
	cout << "4. Update Reader Infor" << endl;
	cout << "0. Exit" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Please choose your selection" << endl;

	int choice;
	cin >> choice;
	return choice;
}

void COMPANY::readerRun(int choice)
{
	//this->loadReader();

	do
	{
		choice = this->readerMenu();
		switch (choice)
		{
		case 1:
		{
			this->addReader();
			system("pause");
			break;
		}
		case 2:
		{
			this->deleteReader();
			system("pause");
			break;
		}
		case 3:
		{
			string tempID;
			cout << "Input ID of Reader to Find: " << endl;
			getline(cin >> ws, tempID);

			this->findReader(tempID);
			system("pause");
			break;
		}
		case 4:
		{
			this->updateReader();
			system("pause");
			break;
		}
		default:
			break;
		}
	} while (choice != 0);

	//this->saveReader();
}

void COMPANY::addBill()
{
	/*this->loadBook();

	this->loadReader();*/

	BILL tempBill;
	tempBill.input();

	bool flag = 0;

	for (size_t k = 0; k < this->billData.size(); k++)
	{
		if (this->readerData[k].getReaderID() == tempBill.getBillID())
		{
			flag = 1;
			cout << "BILL with ID " << tempBill.getBillID() << " has been exist" << endl;
			return;
		}
	}

	flag = 0;

	for (size_t k = 0; k < this->readerData.size(); k++)
	{
		if (this->readerData[k].getReaderID() == tempBill.getBorrowerID())
			flag = 1;
	}
	if (flag == 0)
	{
		cout << "non-exist Reader with ID " << tempBill.getBorrowerID();
		return;
	}

	cout << "Input Loan Day: " << endl;
	myDate tempLoan;
	do
	{
		tempLoan.input();
	} while (tempLoan.isValue() == 0);

	cout << "Input Number of Book to Borrow: " << endl;
	int number;
	cin >> number;

	int i = number;

	cout << "Input ID of Book: " << endl;
	do
	{
		cout << number - i + 1 << "/" << number << ": ";

		string tempID;
		getline(cin >> ws, tempID);

		if (this->findBookByID(tempID) == 1)
		{
			tempBill.pushBookID(tempID);
			i--;
		}
		else continue;

	} while (i > 0);

	cout << "Input Return Day: " << endl;
	myDate tempReturn;
	do
	{
		tempReturn.input();
	} while (tempReturn.isValue() == 0);

	tempBill.setLoanDay(tempLoan);
	tempBill.setReturnDay(tempReturn);

	int fineDay = tempReturn.distance(tempLoan) - LIMITDAY + 1;
	if (fineDay <= 0) fineDay = 0;

	float tempFine;
	int nV = 0;
	int nF = 0;

	vector<string>tempListBook;
	tempListBook = tempBill.getListBook();

	for (size_t i = 0; i < tempListBook.size(); i++)
	{
		for (size_t j = 0; j < this->bookData.size(); j++)
		{
			if (tempListBook[i] == this->bookData[j]->getBookID())
			{
				if (typeid(*this->bookData[j]).name() == type1)
					nV++;
				if (typeid(*this->bookData[j]).name() == type2)
					nF++;
			}
		}
	}
	
	tempFine = (float)(fineDay * (nV * 10000 + nF * 20000));
	tempBill.setFine(tempFine);

	this->billData.push_back(tempBill);
}

void COMPANY::loadBill()
{
	this->billFile.open("BillFile.txt", ios::in);

	if (billFile.fail() == true) return;
	
	do
	{
		BILL tempBill;
		string tempBillID;
		getline(billFile, tempBillID, ',');
		tempBill.setBillID(tempBillID);

		string tempBorID;
		getline(billFile, tempBorID, ',');
		tempBill.setBorrowerID(tempBorID);

		string tempListID;
		getline(billFile, tempListID, ',');

		int pre = 0;
		for (size_t i = 0; i < tempListID.length(); i++)
		{
			string tempID;
			if (tempListID[i] == ' ')
			{
				tempID.assign(tempListID, pre , i - pre );
				tempBill.pushBookID(tempID);
				pre = i + 1;
			}
		}
		int d, m, y;
		char buffer;

		billFile >> d;
		billFile >> buffer;
		tempBill.setLoanDd(d);
		billFile >> m;
		billFile >> buffer;
		tempBill.setLoanMm(m);
		billFile >> y;
		billFile >> buffer;
		tempBill.setLoanYy(y);

		billFile >> d;
		billFile >> buffer;
		tempBill.setReturnDd(d);
		billFile >> m;
		billFile >> buffer;
		tempBill.setReturnMm(m);
		billFile >> y;
		billFile >> buffer;
		tempBill.setReturnYy(y);
		
		float tempFine;
		billFile >> tempFine;

		billFile >> ws;
		tempBill.setFine(tempFine);
	
		this->billData.push_back(tempBill);
	} while (!this->billFile.eof());

	this->billFile.close();
}

void COMPANY::saveBill()
{
	this->billFile.open("BillFile.txt", ios::out);

	for (size_t i = 0; i < this->billData.size(); i++)
	{
		billFile << this->billData[i].getBillID() << ',';
		billFile << this->billData[i].getBorrowerID() << ',';

		vector<string>tempListID = this->billData[i].getListBook();
		for (size_t j = 0; j < tempListID.size(); j++)
		{
			billFile << tempListID[j] << " ";
		}
		billFile << ',';

		billFile << this->billData[i].getLoanDd() << '/' << this->billData[i].getLoanMm() << '/' << this->billData[i].getLoanYy() << ',';

		billFile << this->billData[i].getReturnDd() << '/' << this->billData[i].getReturnMm() << '/' << this->billData[i].getReturnYy() << ',';

		billFile << this->billData[i].getFine();

		billFile << endl;

	}

	this->billFile.close();
}

int COMPANY::billMenu()
{
	system("cls");
	cout << "1. Add new Bill" << endl;
	cout << "0. Eixt" << endl;
	cout << "----------------------------" << endl;
	cout << "Please Input your Choice" << endl;

	int choice;
	cin >> choice;

	return choice;
}

void COMPANY::billRun(int choice)
{
	//this->loadBill();

	do
	{
		choice = this->billMenu();
		switch (choice)
		{
		case 1:
		{
			this->addBill();
			system("pause");
			break;
		}
		}
	} while (choice != 0);

	//this->saveBill();
}

int COMPANY::menu()
{
	system("cls");

	cout << "WHAT YOU WANT TO DO" << endl;
	cout << "1. Work with BOOK" << endl;
	cout << "2. Work with READER" << endl;
	cout << "3. Work with BILL" << endl;
	cout << "4. Output READERs have OVERDUE Book" << endl;
	cout << "0. Exit" << endl;
	cout << "------------------------------------" << endl;
	cout << "Please Input your choice" << endl;

	int choice;
	cin >> choice;
	return choice;
}

void COMPANY::run(int choice)
{
	this->loadBill();
	this->loadBook();
	this->loadReader();
	this->fineFile.open("FineFile.txt", ios::out);
	do
	{
		choice = this->menu();
		switch (choice)
		{

		case 1:
		{
			int bookChoice = 0;
			this->bookRun(bookChoice);
			break;
		}
		case 2:
		{
			int readerChoice = 0;
			this->readerRun(readerChoice);
			break;
		}
		case 3:
		{
			int billChoice = 0;
			this->billRun(billChoice);
			break;
		}
		case 4:
		{
			for (size_t i = 0; i < this->billData.size(); i++)
			{
				if (this->billData[i].getFine() > 0)
				{
					for (size_t j = 0; j < this->readerData.size(); j++)
					{
						if (this->readerData[j].getReaderID()==this->billData[i].getBorrowerID())
						{
							this->readerData[j].output();
							fineFile << "ID is: "<<this->readerData[j].getReaderID()<<',';
							fineFile << "Name is: "<<this->readerData[j].getReaderName() << ',';
							cout << "Fine Money is: " << this->billData[i].getFine() << endl;
							fineFile << "Fine Money is: " << this->billData[i].getFine() << endl;
							break;
						}
					//	else continue;
						
					}
					system("pause");
				}
			}
			break;
		}
		}
	} while (choice!= 0);
	this->saveBill();
	this->saveBook();
	this->saveReader();
}