#include <iostream>
#include <fstream>
#include "LibItems.h"
using namespace std;

void LibItems::addReference(int num)
{
  if(referenceCount == 0)
	{
		RefList = new reference[num];
	}
	else if(referenceCount == referenceCap)
	{
		reference *temp;
		temp = new reference[referenceCap+num];
		for(int i=0; i< referenceCount;i++)
		{
			temp[i]=RefList[i];
		}
		delete[] RefList;
		RefList = temp;
		referenceCap +=num;
	}
	RefList[referenceCount].set();
	RefList[referenceCount].setref();
	referenceCount +=1;
}

void LibItems::addBook(int num)
{
	if(bookCount == 0)
		{
			BooksList = new book[num];
		}
		else if(bookCount == bookCap)
		{
			book *temp;
			temp = new book[bookCap+num];
			for(int i=0; i< bookCount;i++)
			{
				temp[i]=BooksList[i];
			}
			delete[] BooksList;
			BooksList = temp;
			bookCap +=num;
		}
		BooksList[bookCount].set();
		BooksList[bookCount].setbook();
		bookCount +=1; 
}

void LibItems::addDVD(int num)
{
	if(dvdCount == 0)
		{
			DVDList = new dvd[num];
		}
		else if(dvdCount == dvdCap)
		{
			dvd *temp;
			temp = new dvd[dvdCap+num];
			for(int i=0; i< dvdCount;i++)
			{
				temp[i]=DVDList[i];
			}
			delete[] DVDList;
			DVDList = temp;
			dvdCap +=num;
		}
		DVDList[dvdCount].set();
		DVDList[dvdCount].setdvd();
		dvdCount +=1;
}

void LibItems::addCD(int num)
{
	if(cdCount == 0)
		{
			CDList = new cd[num];
		}
		else if(cdCount == cdCap)
		{
			cd *temp;
			temp = new cd[cdCap+num];
			for(int i=0; i< cdCount;i++)
			{
				temp[i]=CDList[i];
			}
			delete[] CDList;
			CDList = temp;
			cdCap +=num;
		}
		CDList[cdCount].set();
		CDList[cdCount].setcd();
		cdCount +=1;
}
void LibItems::removeReference(int num)
{
    int temp2;
	  cout << "Please enter the reference book's ID: " << endl;
	  cin >> temp2;
		for(int i=0; i< referenceCount;i++)
		{
			if(temp2 == RefList[i].getItemID())
			{
				reference *temp3;
				temp3 = new reference[referenceCap+num];
				for(int x=0; x< referenceCount; x++)
				{
					if(RefList[x].getItemID() != temp2)
					{
						if(x<i) 
						{			
							temp3[x]=RefList[x];
						}
						else
						{
							temp3[x-1]=RefList[x];
						}
					}
				}
				delete [] RefList;
				RefList = temp3;
				referenceCount -=1;
				cout << "Reference book has been removed from the system." << endl;
			}
		}
}

void LibItems::removeBook(int num)
{
	int temp2;
		cout << "Please enter the book's ID: " << endl;
		cin >> temp2;
		for(int i=0; i< bookCount;i++)
		{
			if(temp2 == BooksList[i].getItemID())
			{
				book *temp3;
				temp3 = new book[bookCap+num];
				for(int x=0; x< bookCount; x++)
				{
					if(BooksList[x].getItemID() != temp2)
					{
						if(x<i) 
						{			
							temp3[x]=BooksList[x];
						}
						else
						{
							temp3[x-1]=BooksList[x];
						}
					}
				}
				delete [] BooksList;
				BooksList = temp3;
				bookCount -=1;
				cout << "Book has been removed from the system." << endl;
			}
		}
}
	
void LibItems::removeDVD(int num)
{
	int temp2;
		cout << "Please enter the DVD's ID: " << endl;
		cin >> temp2;
		for(int i=0; i< dvdCount;i++)
		{
			if(temp2 == DVDList[i].getItemID())
			{
				dvd *temp3;
				temp3 = new dvd[dvdCap+num];
				for(int x=0; x< dvdCount; x++)
				{
					if(DVDList[x].getItemID() != temp2)
					{
						if(x<i) 
						{			
							temp3[x]=DVDList[x];
						}
						else
						{
							temp3[x-1]=DVDList[x];
						}
					}
				}
				delete [] DVDList;
				DVDList = temp3;
				dvdCount -=1;
				cout << "DVD has been removed from the system." << endl;
			}
		}
}

void LibItems::removeCD(int num)
{
	int temp2;
		cout << "Please enter the CD's ID: " << endl;
		cin >> temp2;
		for(int i=0; i< cdCount;i++)
		{
			if(temp2 == CDList[i].getItemID())
			{
				cd *temp3;
				temp3 = new cd[cdCap+num];
				for(int x=0; x< cdCount; x++)
				{
					if(CDList[x].getItemID() != temp2)
					{
						if(x<i) 
						{			
							temp3[x]=CDList[x];
						}
						else
						{
							temp3[x-1]=CDList[x];
						}
					}
				}
				delete [] CDList;
				CDList = temp3;
				cdCount -=1;
				cout << "CD has been removed from the system." << endl;
			}
		}
}

void LibItems::editReference()
{
  int tempID;
		cout << "Enter the Reference Book's ID to edit the information." << endl;
		cin >> tempID;
		for(int i=0;i<referenceCount;i++)
		{
			if(tempID == RefList[i].getItemID())
			{
				RefList[i].editItem();
				RefList[i].editref();
				break;
			}
		}
}

void LibItems::editBook()
{
	int tempID;
	cout << "Enter the Book's ID to edit the information." << endl;
	cin >> tempID;
	for(int i=0;i<bookCount;i++)
	{
		if(tempID == BooksList[i].getItemID())
		{
			BooksList[i].editItem();
			BooksList[i].editbook();
			break;
		}
	}
}

void LibItems::editDVD()
{
	int tempID;
		cout << "Enter the DVD's ID to edit the information." << endl;
		cin >> tempID;
		for(int i=0;i<dvdCount;i++)
		{
			if(tempID == DVDList[i].getItemID())
			{
				DVDList[i].editItem();
				DVDList[i].editdvd();
				break;
			}
		}
}

void LibItems::editCD()
{
	int tempID;
		cout << "Enter the CD's ID to edit the information." << endl;
		cin >> tempID;
		for(int i=0;i<cdCount;i++)
		{
			if(tempID == CDList[i].getItemID())
			{
				CDList[i].editItem();
				CDList[i].editcd();
				break;
			}
		}
}

void LibItems::findReference()
{
  int temp;
		cout << "Enter the Reference Book's ID: " << endl;
		cin >> temp;
		for(int i=0;i<referenceCount;i++)
		{
			if(temp == RefList[i].getItemID())
			{
				RefList[i].get();
				RefList[i].getref();
				break;
			}
			else
			{
				cout << "That Reference Book ID does not exist in the system." << endl;
			}
		}
}

void LibItems::findBook()
{
	int temp;
	cout << "Enter the Book's ID: " << endl;
	cin >> temp;
	for(int i=0;i<bookCount;i++)
	{
  	if(temp == BooksList[i].getItemID())
  	{
			BooksList[i].get();
			BooksList[i].getbook();
			break;
		}
		else
		{
			cout << "That Book ID does not exist in the system." << endl;
		}
	}
}

void LibItems::findDVD()
{
	int temp;
		cout << "Enter the DVD's ID: " << endl;
		cin >> temp;
		for(int i=0;i<dvdCount;i++)
		{
			if(temp == DVDList[i].getItemID())
			{
				DVDList[i].get();
				DVDList[i].getdvd();
				break;
			}
			else
			{
				cout << "That DVD ID does not exist in the system." << endl;
			}
		}
}

void LibItems::findCD()
{
	int temp;
		cout << "Enter the CD's ID: " << endl;
		cin >> temp;
		for(int i=0;i<cdCount;i++)
		{
			if(temp == CDList[i].getItemID())
			{
				CDList[i].get();
				CDList[i].getcd();
				break;
			}
			else
			{
				cout << "That CD ID does not exist in the system." << endl;
			}
		}
}

void LibItems::updatedvdStatus(unsigned int dvdID)
{
	for(int i=0; i<dvdCount;i++)
	{
		if(dvdID == DVDList[i].getItemID())
		{
			DVDList[i].updateStatus();
			break;
		}
	}
}

void LibItems::updateBookStatus(unsigned int bookID)
{
	for(int i=0; i<bookCount;i++)
	{
		if(bookID == BooksList[i].getItemID())
		{
			BooksList[i].updateStatus();
			break;
		}
	}
}

void LibItems::updatecdStatus(unsigned int cdID)
{
	for(int i=0; i<cdCount;i++)
	{
		if(cdID == CDList[i].getItemID())
		{
			CDList[i].updateStatus();
			break;
		}
	}
}

void LibItems::updateBookStatus2(unsigned int bookID)
{
  for(int i=0; i<bookCount;i++)
	{
		if(bookID == BooksList[i].getItemID())
		{
			BooksList[i].updateStatus2();
			break;
		}
	}
}
	
void LibItems::updateBookStatus3(unsigned int bookID)
{
  for(int i=0; i<bookCount;i++)
	{
		if(bookID == BooksList[i].getItemID())
		{
			BooksList[i].updateStatus3();
			break;
		}
	} 
}

void LibItems::updatedvdStatus2(unsigned int dvdID)
{
	for(int i=0; i<dvdCount;i++)
	{
		if(dvdID == DVDList[i].getItemID())
		{
			DVDList[i].updatedvdstatus2();
			break;
		}
	}
}

void LibItems::updatedvdStatus3(unsigned int dvdID)
{
	for(int i=0; i<dvdCount;i++)
	{
		if(dvdID == DVDList[i].getItemID())
		{
			DVDList[i].updatedvdstatus3();
			break;
		}
	} 
}

void LibItems::updatecdStatus2(unsigned int cdID)
{
	for(int i=0; i<cdCount;i++)
	{
		if(cdID == CDList[i].getItemID())
		{
			CDList[i].updatecdstatus2();
			break;
		}
	}
}

void LibItems::updatecdStatus3(unsigned int cdID)
{
	for(int i=0; i<cdCount;i++)
	{
		if(cdID == CDList[i].getItemID())
		{
			CDList[i].updatecdstatus3();
			break;
		}
	} 
}

double LibItems::getBookCost(unsigned int bookID, double BookC)
{
  for(int i=0;i<bookCount;i++)
	{
		if(bookID == BooksList[i].getItemID())
		{
			BookC = BooksList[i].getBookCost2();
		}
	}
	return(BookC);
}

double LibItems::getdvdCost(unsigned int dvdID, double dvdC)
{
	for(int i=0;i<dvdCount;i++)
	{
		if(dvdID == DVDList[i].getItemID())
		{
			dvdC = DVDList[i].getdvdCost2();
		}
	}
	return(dvdC);
}

double LibItems::getcdCost(unsigned int cdID, double cdC)
{
	for(int i=0;i<cdCount;i++)
	{
		if(cdID == CDList[i].getItemID())
		{
			cdC = CDList[i].getcdCost2();
		}
	}
	return(cdC);
}

void LibItems::printBookTitle(unsigned int bookID)
{
	for(int i=0;i<bookCount;i++)
	{
		if(bookID == BooksList[i].getItemID())
		{
			BooksList[i].printItemTitle();
		}
	}
}

void LibItems::printDVDTitle(unsigned int dvdID)
{
	for(int i=0;i<dvdCount;i++)
	{
		if(dvdID == DVDList[i].getItemID())
		{
			DVDList[i].printItemTitle();
		}
	}
}

void LibItems::printCDTitle(unsigned int cdID)
{
	for(int i=0;i<cdCount;i++)
	{
		if(cdID == CDList[i].getItemID())
		{
			CDList[i].printItemTitle();
		}
	}
}
int LibItems::bookC()
{
	return(bookCount);
}
int LibItems::bookcap()
{
	return(bookCap);
}
int LibItems::refC()
{
	return(referenceCount);
}
int LibItems::refcap()
{
	return(referenceCap);
}
int LibItems::dvdC()
{
	return(dvdCount);
}
int LibItems::dvdcap()
{
	return(dvdCap);
}
int LibItems::cdC()
{
	return(cdCount);
}
int LibItems::cdcap()
{
	return(cdCap);
}
void LibItems::savebookList()
{
  for(int i=0;i<bookCount;i++)
	{
		BooksList[i].savelist();
		BooksList[i].savebook();
	}
}
void LibItems::saverefList()
{
	for(int i=0;i<referenceCount;i++)
	{
		RefList[i].savelist();
		RefList[i].saveref();
	}
}
void LibItems::savedvdList()
{
	for(int i=0;i<dvdCount;i++)
	{
		DVDList[i].savelist();
		DVDList[i].savedvd();
	}
}
void LibItems::savecdList()
{
	for(int i=0;i<cdCount;i++)
	{
		CDList[i].savelist();
		CDList[i].savecd();
	}
}
void LibItems::readbookCount(unsigned int &line)
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> bookCount;
	line++;
	cout << "Book Count: " << bookCount << endl;
	fin2.close();
}

void LibItems::readbookCap(unsigned int &line)
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> bookCap;
	line++;
	cout << "Book Cap: " << bookCap << endl;
	fin2.close();
}

void LibItems::readrefCount(unsigned int &line)
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> referenceCount;
	line++;
	cout << "Reference Count: " << referenceCount << endl;
	fin2.close();
}
void LibItems::readrefCap(unsigned int &line)
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> referenceCap;
	line++;
	cout << "Reference Cap: " << referenceCap << endl;
	fin2.close();
}

void LibItems::readdvdCount(unsigned int &line)
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> dvdCount;
	line++;
	cout << "DVD Count: " << dvdCount << endl;
	fin2.close();
}
void LibItems::readdvdCap(unsigned int &line)
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> dvdCap;
	line++;
	cout << "DVD Cap: " << dvdCap << endl;
	fin2.close();
}

void LibItems::readcdCount(unsigned int &line)
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> cdCount;
	line++;
	cout << "CD Count: " << cdCount << endl;
	fin2.close();
}
void LibItems::readcdCap(unsigned int &line)
{
	ifstream fin2;
	char array[256];
	fin2.open("Librarydata.txt");
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> cdCap;
	line++;
	cout << "CD Cap: " << cdCap << endl;
	fin2.close();
}
void LibItems::readfileadd()
{
  BooksList = new book[bookCap];
	RefList = new reference[referenceCap];
	DVDList = new dvd[dvdCap];
	CDList = new cd[cdCap];
}
void LibItems::readbookFile(unsigned int &line)
{
	for(int i=0;i<bookCount;i++)
	{
		BooksList[i].readfile(line);
		BooksList[i].readbook(line);
	}
}
void LibItems::readrefFile(unsigned int &line)
{
	for(int i=0;i<referenceCount;i++)
	{
		RefList[i].readfile(line);
		RefList[i].readref(line);
	}
}
void LibItems::readdvdFile(unsigned int &line)
{
	for(int i=0;i<dvdCount;i++)
	{
		DVDList[i].readfile(line);
		DVDList[i].readdvd(line);
	}
}
void LibItems::readcdFile(unsigned int &line)
{
	for(int i=0;i<cdCount;i++)
	{
		CDList[i].readfile(line);
		CDList[i].readcd(line);
	}
}
void LibItems::freememory()
{
  if(bookCount > 0)
	{
		delete[] BooksList;
	}
	if(referenceCount > 0)
	{
		delete[] RefList;
	}
	if(dvdCount > 0)
	{
		delete[] DVDList;
	}
	if(cdCount >0)
	{
		delete[] CDList;
	}
}
	
