#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "LibItem.h"
using namespace std;
 
void LibItem::set()
{
	cout << "Please enter the item's ID: " << endl;
	cin >> itemID;
	cout << "Please enter the item's Title: " << endl;
	cin.ignore();
	getline(cin,itemName);
	cout << "Please enter the item's Genre: " << endl;
	cin >> itemGenre;
	cout << "Please enter the item's price: " << endl;
	cin >> itemCost;
	cout << "Item's status: " << itemStatus << endl;
}

void LibItem::get()
{
	cout << "Item ID: " << itemID << endl;
	cout << "Item title: " << itemName << endl;
	cout << "Item Genre: " << itemGenre << endl;
	cout << "Item Price: " << itemCost << endl;
	cout << "Item Status: " << itemStatus << endl;
}

unsigned int LibItem::getItemID()
{
	return(itemID);
}	
	
double LibItem::getItemCost()
{
	return(itemCost);
}
	
void LibItem::editItem()
{
	int choice, i=1;
		cout << "Pick an option to edit." << endl;
		cout << "1. Item title" << endl << "2. Item genre" << endl << "3. Item status" << endl <<
		"4. Item price" << endl;
		cin >> choice;
		while(i !=0)
		{
			if(choice == 1)
			{
				cout << "Enter the Item's title" << endl;
				cin.ignore();
				getline(cin,itemName);
				choice =0;
				break;
			}
			else if(choice ==2)
			{
				cout << "Enter the Item's genre" << endl;
				cin >> itemGenre;
				choice =0;
				break;
			}
			else if(choice == 3)
			{
				cout << "Enter the Item's status" << endl;
				cin >> itemStatus;
				choice=0;
				break;
			}
			else if(choice == 4)
			cout << "Enter the Item's price" << endl;
			cin >> itemCost;
			choice =0;
			break;
		}
	
}
	
void LibItem::updateStatus()
{
	itemStatus = "Out";
}
	
void LibItem::updateStatus2()
{
	itemStatus = "In";
}
	
void LibItem::updateStatus3()
{
	itemStatus = "Lost";
}

void LibItem::updatedvdstatus2()
{
	itemStatus = "In";
}

void LibItem::updatedvdstatus3()
{
	itemStatus = "Lost";
}

void LibItem::updatecdstatus2()
{
	itemStatus = "In";
}

void LibItem::updatecdstatus3()
{
	itemStatus = "Lost";
}

double LibItem::getBookCost2()
{
	return(itemCost);
}

double LibItem::getdvdCost2()
{
	return(itemCost);
}

double LibItem::getcdCost2()
{
	return(itemCost);
}

void LibItem::printItemTitle()  //function cout the book name
{
	cout << itemName << endl;
}
void LibItem::savelist()
{
	ofstream fout2;
	fout2.open("Librarydata.txt", ios_base::app);
	fout2 << itemID << endl;
	fout2 << itemName << endl;
	fout2 << itemGenre << " " << itemCost << " " << itemStatus << endl;
	fout2.close();
}

void LibItem::readfile(unsigned int &line)
{
	ifstream fin2;
	fin2.open("Librarydata.txt");
	char array[256];
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> itemID;
	fin2.ignore();
	getline(fin2,itemName);
	fin2 >> itemGenre >> itemCost >> itemStatus;
	line+=3; 
	fin2.close();
}

//add more functions later