#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "checkout.h"
using namespace std;

        string Checkout::set(Patrons *patV, LibItems *Lib,int bookP,int dvdP,int cdP)  //function used to set a checkouts information
	{
		int i=-1;
		int choice;
		int itemTemp;
		
		cout << "Please enter the checkout ID number." << endl;
		cin >> checkoutID;
		cout << "Please enter the Patron's ID number." << endl;
		cin >> patronID;
		int patronBooksOut = patV->BooksOut(patV,patronID);
		int patronDVDOUT = patV->dvdOut(patV,patronID);
		int patronCDOUT = patV->cdOut(patV,patronID);
		cout << "=========================================" << endl;
		cout << "Which item does the patron want to checkout? (Enter the menu number)" << endl;
		cout << "1.Reference book " << endl << "2. Book" << endl << "3. DVD" << endl << "4.CD" << endl;
		cout << "=========================================" << endl;
		cin >> itemTemp;
		
		if(itemTemp == 1)
		{
			cout << "Patrons are not allowed to checkout reference books" << endl;
		}
		
		if(itemTemp == 2)
		{
			while(i!=0)
			{
				cout << "Please enter the Book's ID number." << endl;
				cin >> bookID[bookcount];
			
				patV->updateBookCount(patronID); //Increment book counter
				Lib->updateBookStatus(bookID[bookcount]);  
				bookcount++;
				time_t now = time(0);
				timeDate = ctime(&now);
				cout << "The exact time of this checkout is: " << timeDate << endl;
				cout << "The loan period for books is: " << bookP << " day(s)." << endl;
				cout << "Would they like to checkout more books? (type 1 for yes, 2 for no): " << endl;
				cin >> choice;
				if(choice == 1 && patronBooksOut < 5)
				{
					i = -1;
				}
				else if(choice ==2)
				{
					i=0;
				}
				else if(choice == 1 && patronBooksOut >= 5)
				{
					cout << "Number of books borrowed by patron is: 5" << endl;
					cout << "This patron may not checkout more books until they have returned at least one" << endl;
					break;
				}
			}
			return(timeDate);
			numCheckouts++; 
		}
	
		if(itemTemp == 3)
		{
			while(i!=0)
			{
				cout << "Please enter the DVD's ID number." << endl;
				cin >> dvdID[avcount];
			
				patV->updatedvdCount(patronID); //Increment DVD counter
				Lib->updatedvdStatus(dvdID[avcount]);  //update dvd status to out 
				avcount++;
				dvdCount++;
				time_t now = time(0);
				timeDate = ctime(&now);
				cout << "The exact time of this checkout is: " << timeDate << endl;
				cout << "The loan period for DVD's is: " << dvdP << " day(s)" << endl;
				cout << endl << "Would they like to checkout more DVDs? (type 1 for yes, 2 for no): " << endl;
				cin >> choice;
				if(choice == 1 && patronDVDOUT < 2)
				{
					i = -1;
				}
				else if(choice ==2)
				{
					i=0;
				}
				else if(choice == 1 && patronDVDOUT >= 2)
				{
					cout << "Number of DVD's borrowed by patron is: 2" << endl;
					cout << "This patron may not checkout more DVD's until they have returned at least one" << endl;
					break;
				}
			}
			return(timeDate);
			numCheckouts++;
		}
		
		if(itemTemp == 4)
		{
			while(i!=0)
				{
					cout << "Please enter the CD's ID number." << endl;
					cin >> cdID[avcount];
			
					patV->updatecdCount(patronID); //Increment cd counter
					Lib->updatecdStatus(cdID[avcount]);  //update cd status to out
					avcount++;
					cdCount++;
					time_t now = time(0);
					timeDate = ctime(&now);
					cout << "The exact time of this checkout is: " << timeDate << endl;
					cout << "The loan period for CD's is: " << cdP << " day(s)" << endl;
					cout << endl << "Would they like to checkout more cd's? (type 1 for yes, 2 for no): " << endl;
					cin >> choice;
					if(choice == 1 && patronCDOUT < 2)
					{
						i = -1;
					}
					else if(choice ==2)
					{
						i=0;
					}
					else if(choice == 1 && patronCDOUT >= 2)
					{
						cout << "Number of CD's borrowed by patron is: 2" << endl;
						cout << "This patron may not checkout more CD's until they have returned at least one" << endl;
						break;
					}
				}
				return(timeDate);
				numCheckouts++; 
		}
	}
		
	void Checkout::set2(LibItems *Lib)  //function used to change the books status
	{
		cout << "Enter the Book's ID number: " << endl;
		cin >> bookID[bookcount];
		Lib->updateBookStatus2(bookID[bookcount]);
	}

	void Checkout::setdvd2(LibItems *Lib)
	{
		cout << "Enter the DVD's ID number: " << endl;
		cin >> dvdID[dvdCount];
		Lib->updatedvdStatus2(dvdID[dvdCount]);
	}

	void Checkout::setdvd3(LibItems *Lib)
	{
		cout << "Enter the DVD's ID number: " << endl;
		cin >> dvdID[dvdCount];
		Lib->updatedvdStatus3(dvdID[dvdCount]);
	}

	void Checkout::setcd2(LibItems *Lib)
	{
		cout << "Enter the CD's ID number: " << endl;
		cin >> cdID[cdCount];
		Lib->updatecdStatus2(cdID[cdCount]);
	}

	void Checkout::setcd3(LibItems *Lib)
	{
		cout << "Enter the CD's ID number: " << endl;
		cin >> cdID[cdCount];
		Lib->updatecdStatus3(cdID[cdCount]);
	}
	
	void Checkout::set3(LibItems *Lib)  //function used to change the books status
	{
		cout << "Enter the Book's ID number: " << endl;
		cin >> bookID[bookcount];
		Lib->updateBookStatus3(bookID[bookcount]);
	}
	void Checkout::setFineBook(Patrons *patV, LibItems *Lib)  //function used to set a fine for a checkout
	{
		double BookC;
		cout << "Enter the Book's ID number: " << endl;
		cin >> bookID[bookcount];
		cout << "Enter the patron's ID number: " << endl;
		cin >> patronID;
		BookC = Lib->getBookCost(bookID[bookcount],BookC);
		patV->addLostBookFine(patronID,BookC);
	}

	void Checkout::setFinedvd(Patrons *patV, LibItems *Lib)
	{
		double dvdC;
		cout << "Enter the DVD's ID number: " << endl;
		cin >> dvdID[dvdCount];
		cout << "Enter the patron's ID number: " << endl;
		cin >> patronID;
		dvdC = Lib->getdvdCost(dvdID[dvdCount],dvdC);
		patV->addLostdvdFine(patronID,dvdC);
	}

	void Checkout::setFinecd(Patrons *patV, LibItems *Lib)
	{
		double cdC;
		cout << "Enter the CD's ID number: " << endl;
		cin >> cdID[cdCount];
		cout << "Enter the patron's ID number: " << endl;
		cin >> patronID;
		cdC = Lib->getcdCost(cdID[cdCount],cdC);
		patV->addLostcdFine(patronID,cdC);
	}
     void Checkout::get()  //function used to show information of a checkout
	{
		cout << "Checkout ID: " << checkoutID << endl;
		cout << "Patron's ID: " << patronID << endl;
		for(int i=0;i<cdCount;i++)
		{
			cout << "CD ID: " << cdID[i] << endl;
			cout << "CD's turn in date: " << checkoutDate << endl;
		}
		for(int i=0;i<dvdCount;i++)
		{
			cout << "DVD ID: " << dvdID[i] << endl;
			cout << "DVD's turn in date: " << checkoutDate << endl;
		}
		for(int i=0;i<bookcount;i++)
		{
			cout << "Book ID: " << bookID[i] << endl;
			cout << "Book's turn in date: " << checkoutDate << endl;
		}
	}

	unsigned int Checkout::getid()  //function used to return value of checkoutID
	{
	 return(checkoutID);
	}
unsigned int Checkout::getPID() //function used to return value of patronID
{
	return(patronID);
}
unsigned int Checkout::getBID()  //function used to return value of bookID
{
	return(bookID[bookcount]);
}
int Checkout::getNumCheckouts()  //function used to return value of number of checkouts
{
	return numCheckouts;
}
void Checkout::setPStatus(Patrons *patV)  //function used to set a patrons status
{
	cout << "Enter the patron's id number." << endl;
	cin >> patronID;
	patV->updatePStatus(patronID);
}
void Checkout::bookList(LibItems *Lib)  //functions used to print list of books 
{
	int booknum=0;
	for(int i=0;i<bookcount;i++)
	{
		Lib->printBookTitle(bookID[i]);
	}
}
void Checkout::dvdList(LibItems *Lib)
{
	int dvdnum=0;
	for(int i=0;i<dvdCount;i++)
	{
		Lib->printDVDTitle(dvdID[i]);
	}
}
void Checkout::cdList(LibItems *Lib)
{
	int cdnum=0;
	for(int i=0;i<cdCount;i++)
	{
		Lib->printCDTitle(cdID[i]);
	}
}

void Checkout::saveList2()  //function used to save checkout data to file
{
	ofstream fout2;
	fout2.open("Librarydata.txt", ios_base::app);
	fout2 << checkoutID << " " << patronID << endl;
	fout2 << bookID[0] << " " << bookID[1] << " " << bookID[2] << " " << bookID[3] << " " << bookID[4] << endl;
	fout2 << bookcount << " " << numCheckouts << " " << checkoutDate << endl;
	fout2.close();
}

void Checkout::readfile(unsigned int &line)  //function used to read in data from a file
{
	ifstream fin2;
	line--;
	fin2.open("Librarydata.txt");
	char array[256];
	for(int i=0;i<=line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> checkoutID >> patronID; 
  fin2 >> bookID[0] >> bookID[1] >> bookID[2] >> bookID[3] >> bookID[4];
	fin2 >> bookcount >> numCheckouts >> checkoutDate; 
	fin2.close();
}

void Checkout::overduebFine(Patrons *patV,int overduefine, double bookFine)  //function used to add overdue fines to a patron
{
		cout << "Enter the patron's ID number: " << endl;
		cin >> patronID;
		patV->addoverduebfine(patronID,overduefine,bookFine);
		patV->addoverdueList(patronID);
}
void Checkout::overduedFine(Patrons *patV,int overduefine, double dvdFine)  //function used to add overdue fines to a patron
{
		cout << "Enter the patron's ID number: " << endl;
		cin >> patronID;
		patV->addoverduedfine(patronID,overduefine,dvdFine);
		patV->addoverdueList(patronID);
}
void Checkout::overduecFine(Patrons *patV,int overduefine, double cdFine)  //function used to add overdue fines to a patron
{
		cout << "Enter the patron's ID number: " << endl;
		cin >> patronID;
		patV->addoverduecfine(patronID,overduefine,cdFine);
		patV->addoverdueList(patronID);
}

void Checkout::erasebookBorr(Patrons *patV)  //function used to subtract number of books borrowed by a patron
{
	cout << "What is the patron's ID?" << endl;
	cin >> patronID;
	patV->erasebookBorr2(patronID);
}

void Checkout::erasedvdBorr(Patrons *patV)
{
	cout << "What is the patron's ID?" << endl;
	cin >> patronID;
	patV->erasedvdBorr2(patronID);
}

void Checkout::erasecdBorr(Patrons *patV)
{
	cout << "What is the patron's ID?" << endl;
	cin >> patronID;
	patV->erasecdBorr2(patronID);
}