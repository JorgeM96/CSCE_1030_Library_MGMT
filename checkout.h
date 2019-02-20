#include "patrons.h"
#include "LibItems.h"
class Checkout
{
        private:
        unsigned int checkoutID;
        unsigned int patronID;
        unsigned int bookID[5];
				unsigned int dvdID[2];
				unsigned int cdID[2];
				int bookcount;
				int cdCount;
				int dvdCount;
				int avcount;
				int numCheckouts;
        int checkoutDate;
				std::string timeDate;

	public:
        std::string set(Patrons *patV,LibItems *Lib,int bookP,int dvdP,int cdP);
				void erasebookBorr(Patrons *patV);
				void erasedvdBorr(Patrons *patV);
				void erasecdBorr(Patrons *patV);
				void set2(LibItems *Lib);
				void setdvd2(LibItems *Lib);
				void setdvd3(LibItems *Lib);
				void setcd2(LibItems *Lib);
				void setcd3(LibItems *Lib);
				void set3(LibItems *Lib);
				void setFineBook(Patrons *patV, LibItems *Lib);
				void setFinedvd(Patrons *patV, LibItems *Lib);
				void setFinecd(Patrons *patV, LibItems *Lib);
				void setPStatus(Patrons *patV);
        void get();
				unsigned int getid();
				unsigned int getPID();
				unsigned int getBID();
				int getNumCheckouts();
				void bookList(LibItems *Lib);
				void dvdList(LibItems *Lib);
				void cdList(LibItems *Lib);
				void saveList2();
				void readfile(unsigned int &line);
				void overduebFine(Patrons *patV, int overduefine, double bookFine);
				void overduedFine(Patrons *patV, int overduefine, double dvdFine);
				void overduecFine(Patrons *patV, int overduefine, double cdFine);

	Checkout()
	{
		numCheckouts=0;
		bookcount=0;
	  dvdCount =0;
		cdCount=0;
		avcount=0;
	}
};