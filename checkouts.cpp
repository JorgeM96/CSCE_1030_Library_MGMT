#include <iostream>
#include <fstream>
#include <string>
#include "checkouts.h"
using namespace std;

       void Checkouts::addcheckout(Checkouts *checkV,Patrons *patV, LibItems *Lib,int num,int bookP,int dvdP,int cdP) //function lets a librarian add a checkout
	{
		if(checkoutCount == 0)
		{
			CheckoutsList = new Checkout[num];
		}
		else if(checkoutCount == checkoutCap)
		{
			Checkout *temp;
			temp = new Checkout[checkoutCap+num];
			for(int i=0; i<checkoutCount;i++)
			{
				temp[i]=CheckoutsList[i];
			}
			delete[] CheckoutsList;
			CheckoutsList = temp;
			checkoutCap+=num;
		}
		timedate = CheckoutsList[checkoutCount].set(patV,Lib,bookP,dvdP,cdP);
		checkoutCount +=1;
	}

        void Checkouts::returnBook(Checkouts *checkV, Patrons *patV, LibItems *Lib,int num,double bookFine,double dvdFine,double cdFine,int bookP,int dvdP,int cdP)  //function lets a patron return a book
	{
		int temp;
		int booktemp;
		int choice;
		int itemS;
		int overdue;
		int daysOverdue;
		int overduefine;
		cout << "Enter the checkout ID to checkin the patron's item." << endl;
		cin >> temp;
		cout << "What item is the patron returning? " << endl;
		cout << "1.Book " << endl << "2.DVD" << endl << "3.CD" << endl;
		cin >> choice;
		if(choice ==1)
		{
			cout << "Does the Patron have the book with them? (Type 1 for yes, 2 for no)" << endl;
			cin >> itemS;
			if(itemS == 1)
			{
				cout << "This book was taken out: " << timedate << " and the loan period for books is: " << bookP << "day(s)" << endl;
				cout << "Is this item overdue? (Type 1 for yes, 2 for no)" << endl;
				cin >> overdue;
				if(overdue == 1)
				{
					CheckoutsList[checkoutCount].overduebFine(patV,overduefine,bookFine); //FIX TO CHANGE FINE DUE TO DIFF ITEM PRICE
					cout << "Overdue fine has been added to patron's fine balance." << endl;
				}
				for(int i=0; i<checkoutCount;i++)  //checkoutCount
				{
					if(temp == CheckoutsList[i].getid())
					{
						Checkout *temp2;
						temp2 = new Checkout[checkoutCap+num];
						for(int j=0; j<checkoutCount;j++)
						{
							if(CheckoutsList[j].getid() != temp)
							{
								if(j<i)
								{
									temp2[j]=CheckoutsList[j];
								}
								else
								{
									temp2[j-1]=CheckoutsList[j];
								}
							}
						}
						delete [] CheckoutsList;
						CheckoutsList = temp2;
						checkoutCount -=1;
						cout << "Patron's item has successfully been checked in." << endl;
			  		cout << "Changing the amount of patron's borrowed books." << endl;  //CHANGE ITEM BORR AMOUNT 
						CheckoutsList[checkoutCount].erasebookBorr(patV);
						cout << "Changing book status." << endl;
						CheckoutsList[checkoutCount].set2(Lib);
						cout << "Book status has changed." << endl; 
					}
				}
			}
			else
			{
		  	cout << "Adding book cost to patron's fine balance." << endl;
				CheckoutsList[checkoutCount].setFineBook(patV,Lib);
				cout << "Setting Patron status to bad." << endl;
				CheckoutsList[checkoutCount].setPStatus(patV);
				cout << "Setting book status to 'Lost'" << endl;
				CheckoutsList[checkoutCount].set3(Lib); 
			}
		}
		else if(choice == 2)
		{
			cout << "Does the Patron have the DVD with them? (Type 1 for yes, 2 for no)" << endl;
			cin >> itemS;
			if(itemS == 1)
			{
				cout << "This DVD was taken out: " << timedate << " and the loan period for DVD's is: " << dvdP << "day(s)" << endl;
				cout << "Is this item overdue? (Type 1 for yes, 2 for no)" << endl;
				cin >> overdue;
				if(overdue == 1)
				{
					CheckoutsList[checkoutCount].overduedFine(patV,overduefine,dvdFine); //FIX TO CHANGE FINE DUE TO DIFF ITEM PRICE
					cout << "Overdue fine has been added to patron's fine balance." << endl;
				}
				for(int i=0; i<checkoutCount;i++)  //checkoutCount
				{
					if(temp == CheckoutsList[i].getid())
					{
						Checkout *temp2;
						temp2 = new Checkout[checkoutCap+num];
						for(int j=0; j<checkoutCount;j++)
						{
							if(CheckoutsList[j].getid() != temp)
							{
								if(j<i)
								{
									temp2[j]=CheckoutsList[j];
								}
								else
								{
									temp2[j-1]=CheckoutsList[j];
								}
							}
						}
						delete [] CheckoutsList;
						CheckoutsList = temp2;
						checkoutCount -=1;
						cout << "Patron's item has successfully been checked in." << endl;
			  		cout << "Changing the amount of patron's borrowed DVD's." << endl;  //CHANGE ITEM BORR AMOUNT 
						CheckoutsList[checkoutCount].erasedvdBorr(patV);
						cout << "Changing DVD status." << endl;
						CheckoutsList[checkoutCount].setdvd2(Lib);
						cout << "DVD status has changed." << endl; 
					}
				}
			}
			else
			{
		  	cout << "Adding DVD cost to patron's fine balance." << endl;
				CheckoutsList[checkoutCount].setFinedvd(patV,Lib);
				cout << "Setting Patron status to bad." << endl;
				CheckoutsList[checkoutCount].setPStatus(patV);
				cout << "Setting DVD status to 'Lost'" << endl;
				CheckoutsList[checkoutCount].setdvd3(Lib); 
			}
		}
		else if(choice ==3)
		{
			cout << "Does the Patron have the CD with them? (Type 1 for yes, 2 for no)" << endl;
			cin >> itemS;
			if(itemS == 1)
			{
				cout << "This CD was taken out: " << timedate << " and the loan period for CD's is: " << cdP << "day(s)" << endl;
				cout << "Is this item overdue? (Type 1 for yes, 2 for no)" << endl;
				cin >> overdue;
				if(overdue == 1)
				{
					CheckoutsList[checkoutCount].overduecFine(patV,overduefine,cdFine); //FIX TO CHANGE FINE DUE TO DIFF ITEM PRICE
					cout << "Overdue fine has been added to patron's fine balance." << endl;
				}
				for(int i=0; i<checkoutCount;i++)  //checkoutCount
				{
					if(temp == CheckoutsList[i].getid())
					{
						Checkout *temp2;
						temp2 = new Checkout[checkoutCap+num];
						for(int j=0; j<checkoutCount;j++)
						{
							if(CheckoutsList[j].getid() != temp)
							{
								if(j<i)
								{
									temp2[j]=CheckoutsList[j];
								}
								else
								{
									temp2[j-1]=CheckoutsList[j];
								}
							}
						}
						delete [] CheckoutsList;
						CheckoutsList = temp2;
						checkoutCount -=1;
						cout << "Patron's item has successfully been checked in." << endl;
			  		cout << "Changing the amount of patron's borrowed CD's." << endl;  //CHANGE ITEM BORR AMOUNT 
						CheckoutsList[checkoutCount].erasecdBorr(patV);
						cout << "Changing CD status." << endl;
						CheckoutsList[checkoutCount].setcd2(Lib);
						cout << "CD status has changed." << endl; 
					}
				}
			}
			else
			{
		  	cout << "Adding CD cost to patron's fine balance." << endl;
				CheckoutsList[checkoutCount].setFinecd(patV,Lib);
				cout << "Setting Patron status to bad." << endl;
				CheckoutsList[checkoutCount].setPStatus(patV);
				cout << "Setting CD status to 'Lost'" << endl;
				CheckoutsList[checkoutCount].setcd3(Lib); 
			}
		}
	}

//FOR RECHECKOUT CHANGE TO ASK WHAT ITEM IS BEING RETURNED AND FIX 
     void Checkouts::recheckout(Checkouts *checkV, Patrons *patV, LibItems *Lib,int bookP, int dvdP,int cdP)  //function lets a user recheckout a book
	{
		unsigned int temp;
		cout << "Please enter the checkout ID number: " << endl;
		cin >> temp;
		for(int i=0; i<checkoutCount;i++)
		{
			if(temp == CheckoutsList[i].getid())
			{
				if(CheckoutsList[i].getNumCheckouts() >= 2)
				{
					cout << "You cannot recheckout the item two times in a row." << endl;
					cout << "Check-in this item first.";
				}
				else
				{
					timedate = CheckoutsList[i].set(patV,Lib,bookP,dvdP,cdP);
					cout << "Your item has now been re-checked out." << endl;
					cout << "The new checkout date for this item is : " << timedate << endl;
				}
			}
			else
			{
				cout << "Checkout ID is not in the system." << endl;
			}
		}
	}
        void Checkouts::findCheckout(Checkouts *checkV)  //function lets librarian find a checkout in the system
	{
		int temp;
		cout << "Enter the checkout ID: " << endl;
		cin >> temp;
		for(int i=0; i<checkoutCount;i++)
		{
			if(temp == CheckoutsList[i].getid())
			{
				CheckoutsList[i].get();
				break;
			}
			else
			{
				cout << "That checkout ID does not exist in the system." << endl;
			}
		}
	}
	
	void Checkouts::itemList(LibItems *Lib)  //function used to show list of books a patron has
	{
		int patrontemp;
		cout << "Enter the patron ID to see a list of their checked out books." << endl;
		cin >> patrontemp;
		cout << "Their checked out books are: " << endl;
		for(int i=0; i<checkoutCount;i++)
		{
			if(patrontemp == CheckoutsList[i].getPID())
			{
				CheckoutsList[i].bookList(Lib);
			}
		}
		cout << "-------------------------------" << endl;
		cout << "Their checked out dvd out: " << endl;
		for(int i=0;i<checkoutCount;i++)
		{
			if(patrontemp == CheckoutsList[i].getPID())
			{
				CheckoutsList[i].dvdList(Lib);
			}
		}
		cout << "--------------------------------" << endl;
		cout << "Their checked out cd's are: " << endl;
		for(int i=0;i<checkoutCount;i++)
		{
			if(patrontemp == CheckoutsList[i].getPID())
			{
				CheckoutsList[i].cdList(Lib);
			}
		}
	}
int Checkouts::checkC()  //function returns the value of checkout count
{
	return(checkoutCount);
}

int Checkouts::checkcap()  //function returns the value of checkout capacity
{
	return(checkoutCap);
}

void Checkouts::saveList()  //function used to save checkout data to a file
{
	for(int i=0;i<checkoutCount;i++)
	{
		CheckoutsList[i].saveList2();
	}
}

void Checkouts::freememory()  //function used to free CheckoutsList memory
{
	if(checkoutCount > 0)
	{
		delete[] CheckoutsList;
	}
}

void Checkouts::readCount(unsigned int &line)  //function used to read the data info to a text
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> checkoutCount;
	line++;
	cout << "Checkout count: " << checkoutCount << endl;
	fin2.close();
}

void Checkouts::readCap(unsigned int &line)  //function used to read the data info 
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> checkoutCap;
	line++;
	cout << "Checkout cap: " << checkoutCap << endl;
	fin2.close();
}

void Checkouts::readfileadd()  //function used to create memory allocation when file is read in
{
	CheckoutsList = new Checkout[checkoutCap];
}

void Checkouts::readFile(unsigned int &line)  //function used to read in all checkout files
{
	for(int i=0;i<checkoutCount;i++)
	{
		CheckoutsList[i].readfile(line);
	}
} 
