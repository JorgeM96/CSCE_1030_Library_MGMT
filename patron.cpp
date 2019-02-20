#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "patron.h"   
using namespace std;

        void Patron::set()  //function asks user to enter patrons information
	{
		cout << "Please enter the patron's ID number." << endl;
    cin >> patronID;
    cout << "Please enter the patron's first name." << endl;
    cin >> patronFirstN;
		cout << "Please enter the patron's last name." << endl;
		cin >> patronLastN;	
    cout << "Default standing: " << endl << patronStanding << endl;
    cout << "Please enter the patron's address." << endl;
		cin.ignore();
    getline(cin,patronAddress);
		cout << "Please enter the patron's city of residence" << endl;
		cin >> city;
		cout << "Please enter the patron's state of residence" << endl;
		cin >> state;
		cout << "Please enter the patron's zipcode." << endl;
		cin >> zipcode;
    cout << "Please enter the patron's email." << endl;
    cin >> patronEmail;
    cout << "Please enter the patron's phone number." << endl;
    cin >> patronPhoneN;
    cout << "Fine Balance: $" << patronFineBal << endl;
    cout << "Books borrowed: " << booksBorrowed << endl;
		cout << "DVD's borrowed: " << dvdsBorrowed << endl;
		cout << "CD's borrowed: " << cdsBorrowed << endl;
	}
				void Patron::editPatron()  //function lets librarian choose what to edit in a patrons information
	{  
		int choice, i=1;
		cout << "Pick an option to edit." << endl;
		cout << "1. Patron name" << endl << "2. Address" << endl <<  "3. email address" << endl <<
		"4. Phone number" << endl;
		cin >> choice;
		while(i !=0)
		{
			if(choice == 1)
			{
				cout << "Enter the patron's first name" << endl;
				cin >> patronFirstN;
				cout << "Enter the patron's last name" << endl;
				cin >> patronLastN;
				choice =0;
				break;
			}
			else if(choice == 2)
			{
				cout << "Enter the patron's address" << endl;
				cin.ignore();
				getline(cin,patronAddress);
				cout << "Enter the patron's city" << endl;
				cin >> city;
				cout << "Enter the patron's state" << endl;
				cin >> state;
				cout << "Enter the patron's zipcode" << endl;
				cin >> zipcode;
				choice =0;
				break;
			}
			else if(choice == 3)
			{
				cout << "Enter the patron's email address" << endl;
				cin >> patronEmail;
				choice =0;
				break;
			}
			else if(choice == 4)
			{
				cout << "Enter the patron's phone number" << endl;
				cin >> patronPhoneN;
				choice =0;
				break;
			}
			else
			{
				cout << "That is not an option.\n";
				break;
			}
		}
		
		
	}
	unsigned int Patron::getid()  //function returns value of patronID
	{
		return(patronID);
	}
	string Patron::getfirstN()  //function returns value of patrons first name
	{
			return(patronFirstN);
	}
	string Patron::getLastN()  //function returns value of patrons last name
	{
		return(patronLastN);
	}
	string Patron::getStanding()  //function returns value of patron standing
	{
		return(patronStanding);
	}
	string Patron::getAddress()  //function returns value of patrons address
	{
		return(patronAddress);
	}
	string Patron::getEmail()  //function returns value of patron email
	{
		return(patronEmail);
	}
	string Patron::getPhone()  //function returns value of patrons phone number
	{
		return(patronPhoneN);
	}
void Patron::setPatronFine()  //function that inputs a patrons new updated balance and sets their status to bad
{
	cout << "Enter the patron's new fine." << endl;
	cin >> patronFineBal;
	patronStanding = "Bad";
}
int Patron::getPatronFine()  //function returns a patrons fine balance
{
	return(patronFineBal);
}
int Patron::getbooksBorr()  ///function returns number of books borrowed by a patron
{
	return(booksBorrowed);
}

int Patron::getdvdBorr()
{
	return(dvdsBorrowed);
}

int Patron::getcdBorr()
{
	return(cdsBorrowed);
}
        void Patron::get()  //function that retrieves variables in the patron header
	{
		cout << "Patron ID: " << patronID << endl;
		cout << "Patron First Name: " << patronFirstN << endl;
		cout << "Patron Last Name: " << patronLastN << endl;
		cout << "Patron's standing: " << patronStanding << endl;
		cout << "Patron's address: " << patronAddress << " " << city << "," << state << " " << zipcode << endl;
		cout << "Patron's email address: " << patronEmail << endl;
		cout << "Patron's phone number: " << patronPhoneN << endl;
		cout << "Patron's fine balance:$ " << patronFineBal << endl;
		cout << "Number of books borrowed: " << booksBorrowed << endl;
		cout << "Number of DVD's borrowed: " << dvdsBorrowed << endl;
		cout << "Number of CD's borrowed: " << cdsBorrowed << endl;
	}
	
	void Patron::getLabel()  //function gets information about city, state, zipcode of patron and prints their address label
	{
		cout << "----------------------------------" << endl;
		cout << patronFirstN << " " << patronLastN << endl;
		cout << patronAddress << endl;
		cout << city << "," << state << " " << zipcode << endl;
		cout << "-----------------------------------" << endl;
		cout << endl;
	}
        void Patron::payFine()  //function used to pay a patrons fine and change their status
	{
		double tempFinePay;
		if(patronStanding == "Bad")
		{
			cout << "Enter how much patron: " << patronFirstN << " " << patronLastN << " payed today." << endl;
			cin >> tempFinePay;
			patronFineBal -= tempFinePay;
			if(patronFineBal == 0)
			{
				patronStanding = "Good";
				cout << "Patron has paid their fine completely and is in good standing" << endl;
			}
			else if(patronFineBal > 0)
			{
				cout << "Patron's fee balance:$ " << patronFineBal << endl;
				cout << "Fine needs to be fully paid to be in good standing." << endl;
			}
			else if(patronFineBal < 0)
			{
				patronStanding = "Good";
				cout << "Patron has a credit of $ " << -patronFineBal;
				cout << "Patron has returned to good standing." << endl;
				patronFineBal =0;
			}
		}
		else
		{
			cout << "Patron does not owe money and is in good standing." << endl;
			cout << endl;
		}
	}
	void Patron::updateBookCnt()  //updates the amount of books borrowed for a patron by 1
	{
		 booksBorrowed++;
	}

	void Patron::updatedvdCnt()
	{
		dvdsBorrowed++;
	}

	void Patron::updatecdCnt()
	{
		cdsBorrowed++;
	}

	void Patron::addlostbookfine(double BookC)  //adds a fine (book price) to a patrons fine balance
	{
		patronFineBal = patronFineBal + BookC;
	}

	void Patron::addlostdvdfine(double dvdC)
	{
		patronFineBal = patronFineBal + dvdC;
	}

	void Patron::addlostcdfine(double cdC)
	{
		patronFineBal = patronFineBal + cdC;
	}
	void Patron::updatePStatus2()  //updates patrons status to bad
	{
		patronStanding = "Bad";
	}

void Patron::saveList2()  //function used to send data to textfile
{
	ofstream fout2;
	fout2.open("Librarydata.txt", ios_base::app);
	fout2 << patronID << " " <<  patronFirstN << " " << patronLastN << " " << patronStanding << endl; 
	fout2 << patronAddress << endl;
	fout2 << city << " " << state << " " << zipcode << " " << patronEmail << " " << patronPhoneN << " " << patronFineBal <<" " << booksBorrowed << " " << dvdsBorrowed << " " << cdsBorrowed << endl;
	fout2.close();
}

void Patron::readfile(unsigned int &line)   //function used to read data from a file
{
	ifstream fin2;
	fin2.open("Librarydata.txt");
	char array[256];
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> patronID >> patronFirstN >> patronLastN >> patronStanding;
  fin2.ignore();
  getline(fin2,patronAddress);    //FIN THE CITY,STATE,ZIPCODE
	fin2 >> city >> state >> zipcode >> patronEmail >> patronPhoneN >> patronFineBal >> booksBorrowed >> dvdsBorrowed >> cdsBorrowed;
	line+=3; 
	fin2.close();
}

void Patron::addoverduebfine2(int overduefine, int bookFine) //function adds a fine to the patron by number of days overdue
{
	int tempdays;
	cout << "How many days overdue is this book?" << endl;
	cin >> tempdays;
	overduefine = tempdays*bookFine;
	patronFineBal += overduefine;
}
void Patron::addoverduedfine2(int overduefine, int dvdFine) //function adds a fine to the patron by number of days overdue
{
	int tempdays;
	cout << "How many days overdue is this DVD?" << endl;
	cin >> tempdays;
	overduefine = tempdays*dvdFine;
	patronFineBal += overduefine;
}
void Patron::addoverduecfine2(int overduefine, int cdFine) //function adds a fine to the patron by number of days overdue
{
	int tempdays;
	cout << "How many days overdue is this cd?" << endl;
	cin >> tempdays;
	overduefine = tempdays*cdFine;
	patronFineBal += overduefine;
}

void Patron::addoverdueList2()  //function adds the number of overduebooks by 1 
{
	overdueBooks = 1;
}

int Patron::getoverdueList2()  //function returns number of overdue books
{
	return(overdueBooks);
}

void Patron::erasebookBorr3()  //function deletes books borrowed by patron when they check it in
{
	booksBorrowed--;
}

void Patron::erasedvdBorr3()
{
	dvdsBorrowed--;
}

void Patron::erasecdBorr3()
{
	cdsBorrowed--;
}