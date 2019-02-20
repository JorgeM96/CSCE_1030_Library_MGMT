#include "LibItem.h"
#include "reference.h"
#include "book.h"
#include "dvd.h"
#include "cd.h"
class LibItems
{
  protected:   
	int referenceCount;
	int referenceCap;
	reference *RefList;
	int bookCount;
	int bookCap;
	book *BooksList;
	int dvdCount;
	int dvdCap;
	dvd *DVDList;
	int cdCount;
	int cdCap;
	cd *CDList;
	
	public:
	void addReference(int num);
	void addBook(int num);
	void addDVD(int num);
	void addCD(int num);
  void removeBook(int num);
	void removeReference(int num);
	void removeDVD(int num);
	void removeCD(int num);
  void editBook();
	void editReference();
	void editDVD();
	void editCD();
  void findBook();
	void findReference();
	void findDVD();
	void findCD();
	void updateBookStatus(unsigned int bookID);
	void updateBookStatus2(unsigned int bookID);
	void updateBookStatus3(unsigned int bookID);
	void updatedvdStatus(unsigned int dvdID);
	void updatedvdStatus2(unsigned int dvdID);
	void updatedvdStatus3(unsigned int dvdID);
	void updatecdStatus(unsigned int cdID);
	void updatecdStatus2(unsigned int cdID);
	void updatecdStatus3(unsigned int cdID);
	void updateStatus();
	void updateStatus2();
	void updateStatus3();
	int getCost();
	double getBookCost(unsigned int bookID, double BookC);
	double getdvdCost(unsigned int dvdID, double dvdC);
	double getcdCost(unsigned int cdID, double cdC);
	int itemC();
	int itemcap();
	void printBookTitle(unsigned int bookID);
	void printDVDTitle(unsigned int dvdID);
	void printCDTitle(unsigned int cdID);
	void printitemTitle();
	void savebookList();
	void saverefList();
	void savedvdList();
	void savecdList();
	void freememory();
	void readbookCount(unsigned int &line);
	void readbookCap(unsigned int &line);
	void readrefCount(unsigned int &line);
	void readrefCap(unsigned int &line);
	void readdvdCount(unsigned int &line);
	void readdvdCap(unsigned int &line);
	void readcdCount(unsigned int &line);
	void readcdCap(unsigned int &line);
	void readfileadd();
	void readbookFile(unsigned int &line);
	void readrefFile(unsigned int &line);
	void readdvdFile(unsigned int &line);
	void readcdFile(unsigned int &line);	
	int bookC();
	int bookcap();
 	int refC();
	int refcap();
	int dvdC();
	int dvdcap();
	int cdC();
	int cdcap();
	
	LibItems(int num)
	{
		referenceCount=0;
		referenceCap = num;
		bookCount =0;
		bookCap = num;
		dvdCount =0;
		dvdCap = num;
		cdCount = 0;
		cdCap = num;
	}
};