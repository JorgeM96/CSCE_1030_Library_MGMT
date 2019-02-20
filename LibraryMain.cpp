/* Author: Jorge Moreno
   Email: jorgemoreno3@my.unt.edu
   Instructor: Dr. Keathly
   Date: 3/13/17
   Description: This program makes use of classes to create a library management system that includes a menu for different features. */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "checkouts.h"
using namespace std;

const int MEMORY = 10;  //Constant int used for dynamic array re allocation.
//change this finemult later to be in an admin MENU
int main()
{
	cout << "CSCE 1040 Computer Science II" << endl;
	cout << "Homework 4: Library Management System" << endl;
	cout << "Jorge Moreno, jorgemoreno3@my.unt.edu" << endl;
	
	Patrons patV(MEMORY);   //these 3 lines declare a variable for an instance of the collection classes
	Checkouts checkV(MEMORY);
	LibItems Lib(MEMORY);

	double bookFine=0; //these 3 lines are for the fine rates
	double dvdFine=0;
	double cdFine=0;
	int bookP=0;  //these 3 lines are for the loan periods
	int dvdP=0;
	int cdP=0;
	int choice = -1;  //These 2 choice ints are used for the menu
	int choice2 = -1;
	int choice3 = -1;
	int adminC = -1;
	
	while(choice!=0)  //This loop shows the menu every time the user is done with an option
	{
		cout << "====================================================================" << endl; //Begin the menu
		cout << "Choose a menu option number for your desired category." << endl;
		cout << "1. Patrons" << endl << "2. Items" << endl << "3. Checkouts/Checkins" << endl << "4. Save data to system." << endl <<
		"5. Load data to system." << endl << "6. Admin Menu " << endl << "7. Exit Program" << endl;
		cout << "====================================================================" << endl;
		cin >> choice;
	
		switch(choice)  //Menu showing all the operations done on patrons
		{
			case 1:
			cout << "====================================================================" << endl;
			cout << "Choose an option for Patrons." << endl;
			cout << "1. Add a new patron. " << endl << "2. Find a patron. " << endl << "3. Edit a patron's information." << endl << 
			"4. Remove a patron." << endl << "5. Print a list of all patrons." << endl << "6. Print a list of items a patron has checked out." << endl << 
			"7. Add a fine to a Patron" << endl << "8. Let a patron pay a fine" << endl << "9. Print an address label for a patron." << endl << 
			"10. Print a list of patrons with fines." << endl << "11. Print a list of patrons with overdue books." << endl;
			cout << "====================================================================" << endl;
			cin >> choice2;
			
				switch(choice2)
				{
					case 1: patV.add(&patV, MEMORY);
					break;
					case 2: patV.find(&patV);
					break;
					case 3: patV.edit(&patV);
					break;
					case 4: patV.remove(&patV, MEMORY);  
					break;
					case 5: patV.print_List(&patV);
					break;
					case 6: checkV.itemList(&Lib);
					break;
					case 7: patV.addFine(&patV);  
					break;
					case 8: patV.payPatronFine(&patV); 
					break;
					case 9: patV.addressLabel(&patV);
					break;
					case 10: patV.fineList(&patV);
					break;
					case 11: patV.overdueList(&patV);
					break;
					default:
						cout << "That is not a Patron option." << endl;
					break;
				}

			break;

			case 2:  //Menu that shows all the operations on items
			cout << "=======================================================" << endl;
			cout << "Choose an item from the Library." << endl;
			cout << "1. Books " << endl << "2. Reference books." << endl << 
			"3. DVDs " << endl << "4. CDs " << endl;
			cout << "=======================================================" << endl;
			cin >> choice3;
			
			if(choice3 ==1)
			{
				cout << "======================================================" << endl;
				cout << "Choose an option from the books menu" << endl;
				cout << "1. add a book to the library catalog" << endl << "2. remove a book from the library catalog" << endl <<
				"3. Edit a book" << endl << "4. Find a book in the system." << endl;
				cout << "=======================================================" << endl;
				cin >> choice3;
				
				switch(choice3)
				{
					case 1: Lib.addBook(MEMORY);
					break;
					case 2: Lib.removeBook(MEMORY);
					break;
					case 3: Lib.editBook();
					break;
					case 4: Lib.findBook();
					break;
					default: 
						cout << "This is not a book menu option" << endl;
					break;
				}
				break;
			}
				
			if(choice3 == 2)
			{
				cout << "======================================================" << endl;
				cout << "Choose an option from the reference books menu" << endl;
				cout << "1. add a reference book to the library catalog" << endl << "2. remove a reference book from the library catalog" << endl <<
				"3. Edit a reference book." << endl << "4. Find a reference book in the system." << endl;
				cout << "======================================================" << endl;
				cin >> choice3;	
			
				switch(choice3)
				{
					case 1: Lib.addReference(MEMORY);
					break;
					case 2: Lib.removeReference(MEMORY);
					break;
					case 3: Lib.editReference();
					break;
					case 4: Lib.findReference();
					break;
					default: 
						cout << "This is not a reference book menu option" << endl;
					break;
				}
				break;
			}
			
			if(choice3 == 3)
			{
				cout << "======================================================" << endl;
				cout << "Choose an option from the DVD menu" << endl;
				cout << "1. add a DVD to the library catalog" << endl << "2. remove a DVD from the library catalog" << endl <<
				"3. Edit a DVD." << endl << "4. Find a DVD in the system." << endl;
				cout << "======================================================" << endl;
				cin >> choice3;
			
				switch(choice3)
				{
					case 1: Lib.addDVD(MEMORY);
					break;
					case 2: Lib.removeDVD(MEMORY);
					break;
					case 3: Lib.editDVD();
					break;
					case 4: Lib.findDVD();
					break;
					default:
						cout << "This is not a DVD menu option" << endl;
					break;
				}
				break;
			}
				
			if(choice3 == 4)
			{
				cout << "======================================================" << endl;
				cout << "Choose an option from the CD menu" << endl;
				cout << "1. add a CD to the library catalog" << endl << "2. remove a CD from the library catalog" << endl <<
				"3. Edit a CD." << endl << "4. Find a CD in the system." << endl;
				cout << "======================================================" << endl;
				cin >> choice3;
			
				switch(choice3)
				{
					case 1: Lib.addCD(MEMORY);
					break;
					case 2: Lib.removeCD(MEMORY);
					break;
					case 3: Lib.editCD();
					break;
					case 4: Lib.findCD();
					break;
					default:
						cout << "This is not a CD menu option" << endl;
					break;
				}
				break;
			}
			else if(choice3 <0 || choice3 >4)  //THIS ISNT WORKING
			{
				cout << "That is not an item menu option" << endl;
				break;
			}
			break;
				
			case 3:  //menu that shows all the operations on checkouts
			cout << "=====================================================" << endl;
			cout << "Choose an option for checkouts." << endl;
			cout << "1. Checkout a library item." << endl << "2. Check in a library item." << endl << "3. Re-checkout an item." << endl <<
			"4. Find a checkout in the system." << endl;
			cout << "=====================================================" << endl;
			cin >> choice2;
				
				switch(choice2)
				{
					case 1: checkV.addcheckout(&checkV,&patV,&Lib,MEMORY,bookP,dvdP,cdP);
					break;
					case 2: checkV.returnBook(&checkV, &patV, &Lib,MEMORY,bookFine,dvdFine,cdFine,bookP,dvdP,cdP);
					break;
					case 3: checkV.recheckout(&checkV,&patV,&Lib,bookP,dvdP,cdP);
					break;
					case 4: checkV.findCheckout(&checkV);
					break; 
					default:
					cout << "That is not a checkout option." << endl;
					break;
				}
			break;
			
			case 4:  //This option saves all entered information on a textfile
				{
					ofstream fout;
					int patronCount = patV.patronC();
					int patronCap = patV.patroncap();
					int bookCount = Lib.bookC();
					int bookCap = Lib.bookcap();
					int refCount = Lib.refC();
					int refCap = Lib.refcap();
					int dvdCount = Lib.dvdC();
					int dvdCap = Lib.dvdcap();
					int cdCount = Lib.cdC();
					int cdCap = Lib.cdcap();
					int checkoutCount = checkV.checkC();
					int checkoutCap = checkV.checkcap();
			
					cout << "Saving data to file: Libraydata.txt" << endl;
	
					fout.open("Librarydata.txt");
					if(fout.fail())
					{
						cout << "Unable to save to file!" << endl;
						exit(EXIT_FAILURE);
					}
					cout << "Data transfer has begun." << endl;
	
					fout <<bookP <<" "<<dvdP <<" "<<" "<<cdP <<" "<<bookFine <<" "<<dvdFine << " " <<cdFine << endl;
					fout << patronCount << endl;
					fout << patronCap << endl;
					fout << bookCount << endl;
					fout << bookCap << endl;
					fout << refCount << endl;
					fout << refCap << endl;
					fout << dvdCount << endl;
					fout << dvdCap << endl;
					fout << cdCount << endl;
					fout << cdCap << endl;
					fout << checkoutCount << endl;
					fout << checkoutCap << endl;
						
					patV.saveList();
				  Lib.savebookList();
					Lib.saverefList();
					Lib.savedvdList();
					Lib.savecdList();
				  checkV.saveList();
					cout << "Library data has been saved to file: Librarydata.txt" << endl;
		}		
			break;
	
			case 5: //This option loads data from the saved file
				{
					ifstream fin;
					unsigned int line =1;
					int count,cap;
					cout << "Opening file: Librarydata.txt" << endl;
				
					fin.open("Librarydata.txt");
					if(fin.fail())
					{
						cout << "Unable to open this file." << endl;
						exit(EXIT_FAILURE);
					}
					cout << "Input file opened, retreiving information." << endl;
			
					//call functions to read in the counts and caps
					fin >> bookP >> dvdP >> cdP >> bookFine >> dvdFine >> cdFine;
					patV.readCount(line);
					patV.readCap(line);
					Lib.readbookCount(line);
					Lib.readbookCap(line);
					Lib.readrefCount(line);
					Lib.readrefCap(line);
					Lib.readdvdCount(line);
					Lib.readdvdCap(line);
					Lib.readcdCount(line);
					Lib.readcdCap(line);
					checkV.readCount(line);
					checkV.readCap(line);
			
					patV.readfileadd();
					patV.readFile(line);
					Lib.readfileadd();
					Lib.readbookFile(line);
					Lib.readrefFile(line);
					Lib.readdvdFile(line);
					Lib.readcdFile(line);
					checkV.readfileadd();
					checkV.readFile(line);
				  cout << "Library Data has been opened and is ready to be used." << endl;
		}
				break;
			case 6: 
				int option;  //variable used to choose an option
				cout << "===========================================" << endl;
				cout << "Please choose an option from the Admin menu" << endl;
				cout << "1.loan periods" << endl << "2.fine amounts" << endl;
				cout << "===========================================" << endl;
				cin >> adminC;
				if(adminC == 1)
				{
					cout << "Choose an item to add a loan period: " << endl;
					cout << "1.Book" << endl << "2.DVD" << endl << "3.CD" << endl;
					cin >> option;
					if(option ==1)
					{
						cout << "Current loan period: " << bookP << endl; 
						cout << "Enter the loan period for books (days)" << endl;
						cin >> bookP;
					}
					else if(option ==2)
					{
						cout << "Current loan period: " << dvdP << endl;
						cout << "Enter the loan period for DVD's (days)" << endl;
						cin >> dvdP;
					}
					else if(option ==3)
					{
						cout << "Current loan period: " << cdP << endl;
						cout << "Enter the loan period for CD's (days)" << endl;
						cin >> cdP;
					}
					else
					{
						cout << "Please choose a correct option." << endl;
					}
				}
				else if(adminC == 2)
				{
					cout << "Choose an item to add a fine amount: " << endl;
					cout << "1. Book" << endl << "2. DVD" << endl << "3.CD" << endl;
					cin >> option;
					if(option ==1)
					{
						cout << "Current Book fine rate: " << bookFine << endl;
						cout << "Enter the fine amount for books: $ ";
						cin >> bookFine;
					}
					else if(option ==2)
					{
						cout << "Current DVD fine rate: " << dvdFine << endl;
						cout << "Enter the fine amount for dvds: $ ";
						cin >> dvdFine;
					}
					else if(option ==3)
					{
						cout << "Current CD fine rate: " << cdFine << endl;
						cout << "Enter the fine amount for cds: $ ";
						cin >> cdFine;
					}
					else
					{
						cout << "Please choose a correct option." << endl;
					}
				}
				else
				{
					cout << "Please choose an option from the admin menu." << endl;
				}
			break;
			case 7: //this function closes the program.
			{
				cout << "Library system will now close." << endl;
				exit(EXIT_FAILURE);
			}
				break; 

			default:  //This checks if what the user entered is actually an option
				cout << "Please enter a menu number or exit the program." << endl;
				break;
		}
	}
	patV.freememory();  //These 3 lines free the memory 
	checkV.freememory();
	Lib.freememory();
	return 0;
}
