#include "checkout.h"
class Checkouts
{
        private:
        int checkoutCount;
        int checkoutCap;
				std::string timedate;
        Checkout *CheckoutsList;

        public:
        void addcheckout(Checkouts *checkV,Patrons *patV,LibItems *Lib,int num,int bookP,int dvdP,int cdP);
    	  void returnBook(Checkouts *checkV, Patrons *patV, LibItems *Lib, int num, double bookFine,double dvdFine,double cdFine,int bookP,int dvdP,int cdP);
        void recheckout(Checkouts *checkV, Patrons *patV, LibItems *Lib,int bookP,int dvdP,int cdP);
        void findCheckout(Checkouts *checkV);
				void itemList(LibItems *Lib);
				void saveList();
				int checkC();
				int checkcap();
				void freememory();
				void readCount(unsigned int &line);
				void readCap(unsigned int &line);
				void readfileadd();
				void readFile(unsigned int &line);

	Checkouts(int a)
	{
		checkoutCount=0;
		checkoutCap=a;
	}
};

//ADD ARGUMENTS
