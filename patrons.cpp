#include <iostream>
#include <fstream>
#include "patrons.h"
using namespace std;

        void Patrons::find(Patrons *patV)  //Function is used to find a patrons info and show it
	{
		int temp;
		cout << "Enter the Patron's ID: " << endl;
		cin >> temp;
		for(int i=0; i< patronCount; i++)
		{
			if(temp == PatronsList[i].getid())
			{
				PatronsList[i].get();
				break;
			}
			else
			{
				cout << "That Patron ID does not exist in the system." << endl;
			}
		}
	}
        void Patrons::add(Patrons *patV, int num)  //Function is used to add a new Patron
	{
		if(patronCount == 0)
		{
			PatronsList = new Patron[num];
		}
		else if(patronCount == patronCap)
		{
			Patron *temp;
			temp = new Patron[patronCap+num];
			for(int i=0; i< patronCount;i++) 
			{
				temp[i]= PatronsList[i];
			}
			delete[] PatronsList;
			PatronsList = temp;
			patronCap+=num;
		}
		PatronsList[patronCount].set();
		patronCount += 1;
	}
        void Patrons::edit(Patrons *patV)  //Function is used to edit patrons information
	{
		int tempID;
		cout << "Enter the Patron's ID to edit their information." << endl;
		cin >> tempID;
		for(int i=0;i<patronCount;i++)
		{
			if(tempID == PatronsList[i].getid())
			{
				PatronsList[i].editPatron();
				break;
			}
		}	
	}
        void Patrons::remove(Patrons *patV, int num)  //Function deletes a patrons
	{
		int temp2;
		cout << "Please enter the patron's ID: " << endl;
		cin >> temp2;
		for(int i=0; i< patronCount;i++)
		{
			if(temp2 == PatronsList[i].getid())
			{
				Patron *temp3;
				temp3 = new Patron[patronCap+num];
				for(int x=0; x< patronCount; x++)
				{
					if(PatronsList[x].getid() != temp2)
					{
						if(x<i) 
						{			
							temp3[x]=PatronsList[x];
						}
						else
						{
							temp3[x-1]=PatronsList[x];
						}
					}
				}
				delete [] PatronsList;
				PatronsList = temp3;
				patronCount -=1;
				cout << "Patron has been removed from the system." << endl;
			}
		}
	}
        void Patrons::print_List(Patrons *patV)  //function prints a list of all patrons
	{
		for(int i=0;i<patronCount;i++)
		{
			cout << "Patron ID #" << i+1 << ": " << PatronsList[i].getid() << endl;
			cout << "Patron's First Name: " << PatronsList[i].getfirstN() << endl;
			cout << "Patron's Last Name: " << PatronsList[i].getLastN() << endl;
			cout << "Patron's standing: " << PatronsList[i].getStanding() << endl;
			cout << "Patron's address: " << PatronsList[i].getAddress() << endl;
			cout << "Patron's email address: " << PatronsList[i].getEmail() << endl;
			cout << "Patron's phone number: " << PatronsList[i].getPhone() << endl;
			cout << "Patron's fine balance:$ " << PatronsList[i].getPatronFine() << endl;
			cout << "Number of books borrowed: " << PatronsList[i].getbooksBorr() << endl;
			cout << "Number of DVD's borrowed: " << PatronsList[i].getdvdBorr() << endl;
			cout << "Number of CD's borrowed: " << PatronsList[i].getcdBorr() << endl;
		}
	}
				void Patrons::addFine(Patrons *patV)  //Function lets a librarian manually add a fine to a patrons balance
	{
		int temp;
		cout << "Enter the Patron's ID:" << endl;
		cin >> temp;
		for(int i=0;i<patronCount;i++)
		{
			if(temp == PatronsList[i].getid())
			{
				PatronsList[i].setPatronFine();
				break;
			}
			else
			{
				cout << "That ID does not exist in the system." << endl;
			}
		}
	}
void Patrons::payPatronFine(Patrons *patV)  //lets a patron pay a fine
{
	unsigned int tempID;
	cout << "Please enter the Patron's ID: " << endl;
	cin >> tempID;
	for(int i=0; i<patronCount;i++)
	{
		if(tempID == PatronsList[i].getid())
		{
			if(PatronsList[i].getStanding() == "Bad")
			{
				PatronsList[i].payFine();
				break;
			}
			else
			{
				cout << "Patron is in good standing, no fines owed.";
			}
		}
		else
		{
			"Patron does not exist in the system.";
		}
	}
}
int Patrons::BooksOut(Patrons *patV, unsigned int patronID)  //Function shows a list of books a patron has out
{
	for(int i=0; i< patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			return PatronsList[i].getbooksBorr();
			break;
		}
	}
}

int Patrons::dvdOut(Patrons *patV, unsigned int patronID)
{
	for(int i=0;i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			return PatronsList[i].getdvdBorr();
			break;
		}
	}
}

int Patrons::cdOut(Patrons *patV, unsigned int patronID)
{
	for(int i=0;i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			return PatronsList[i].getcdBorr();
			break;
		}
	}
}

void Patrons::updateBookCount(unsigned int patronID) //function updates the amount of books a patron has
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].updateBookCnt();
			break;
		}
	}
}

void Patrons::updatedvdCount(unsigned int patronID)
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].updatedvdCnt();
			break;
		}
	}
}

void Patrons::updatecdCount(unsigned int patronID)
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].updatecdCnt();
			break;
		}
	}
}

void Patrons::addLostBookFine(unsigned int patronID, double BookC)  //Function adds a book price to a patrons fine balance
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].addlostbookfine(BookC);
			break;
		}
	}
}

void Patrons::addLostdvdFine(unsigned int patronID, double dvdC)
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].addlostdvdfine(dvdC);
			break;
		}
	}
}

void Patrons::addLostcdFine(unsigned int patronID, double cdC)
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].addlostcdfine(cdC);
			break;
		}
	}
}
void Patrons::updatePStatus(unsigned int patronID)  //function updates the status of a patron
{
	for(int i=0;i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].updatePStatus2();
			break;
		}
	}
}

void Patrons::addressLabel(Patrons *patV) //Function prints out an address label for a patron
{
	int temp;
	cout << "Enter the patron's id number" << endl;
	cin >> temp;
	for(int i=0; i< patronCount; i++)
	{
		if(temp == PatronsList[i].getid())
		{
		PatronsList[i].getLabel();
		break;
		}
	}
}

int Patrons::patronC()  //function returns the patron count number
{
	return(patronCount);
}

int Patrons::patroncap()  //function returns the patron cap number
{
	return(patronCap);
}

void Patrons::fineList(Patrons *patV)  //function shows a list of patrons that have a fine
{
	cout << "List of patrons with fines: " << endl;
	for(int i=0; i<patronCount;i++)
	{
		if(PatronsList[i].getPatronFine() !=0)
		{
			PatronsList[i].get(); 
		}
	}
}

	void Patrons::saveList()  //function is used in part of saving data to a textfile
	{
		for(int i=0; i<patronCount;i++)
		{
			PatronsList[i].saveList2();
		}
	}

void Patrons::freememory()  //function is used to free patronslist memory
{
	if(patronCount > 0)
	{
		delete[] PatronsList;
	}
}

void Patrons::readCount(unsigned int &line) //function is used in part of loading data to the program
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> patronCount;
	line++;
	cout << "Patron Count: " << patronCount << endl;
	fin2.close();
}

void Patrons::readCap(unsigned int &line)  //function is used in part of loading data to the program
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> patronCap;
	line++;
	cout << "Patron Cap: " << patronCap << endl;
	fin2.close();
}

void Patrons::readFile(unsigned int &line)  //function is used in part of loading data to the program
{
	for(int i=0;i<patronCount;i++)
	{
		PatronsList[i].readfile(line);
	}
}
	
void Patrons::readfileadd() //function is used in loading data to program and allocates the memory
{
	PatronsList = new Patron[patronCap];
}

void Patrons::addoverduebfine(unsigned int patronID, int overduefine, double bookFine)  //function adds a fine to a patrons balance for overdue books
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
				PatronsList[i].addoverduebfine2(overduefine,bookFine);
				break;
		}
	}
}
void Patrons::addoverduedfine(unsigned int patronID, int overduefine, double dvdFine)  //function adds a fine to a patrons balance for overdue dvds
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
				PatronsList[i].addoverduedfine2(overduefine,dvdFine);
				break;
		}
	}
}
void Patrons::addoverduecfine(unsigned int patronID, int overduefine, double cdFine)  //function adds a fine to a patrons balance for overdue cds
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
				PatronsList[i].addoverduecfine2(overduefine,cdFine);
				break;
		}
	}
}

void Patrons::addoverdueList(unsigned int patronID)  //function shows a list of patrons with overdue books
{
	for(int i=0;i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].addoverdueList2();
			break;
		}
	}
}

void Patrons::overdueList(Patrons *patV)
{
	for(int i=0;i<patronCount;i++)
	{
		if(PatronsList[i].getoverdueList2() == 1)
		{
			PatronsList[i].get();
		}
	}
}

void Patrons::erasebookBorr2(unsigned int patronID)  //function erases the value of books borrowed for a patron when it is checked in
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].erasebookBorr3();
			break;
		}
	}
}

void Patrons::erasedvdBorr2(unsigned int patronID)
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].erasedvdBorr3();
			break;
		}
	}
}

void Patrons::erasecdBorr2(unsigned int patronID)
{
	for(int i=0; i<patronCount;i++)
	{
		if(patronID == PatronsList[i].getid())
		{
			PatronsList[i].erasecdBorr3();
			break;
		}
	}
}