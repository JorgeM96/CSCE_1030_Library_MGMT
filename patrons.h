#include "patron.h"
class Patrons
{
        private:
        int patronCount;
        int patronCap;
        Patron *PatronsList;

        public:
        void find(Patrons *patV);
        void add(Patrons *patV, int num);
        void edit(Patrons *patV);
        void remove(Patrons *patV, int num);
        void print_List(Patrons *patV);
				void addFine(Patrons *patV);
				void payPatronFine(Patrons *patV);
				void addressLabel(Patrons *patV);
				int BooksOut(Patrons *patV, unsigned int patronID);
				int dvdOut(Patrons *patV, unsigned int patronID);
				int cdOut(Patrons *patV, unsigned int patronID);
				void updateBookCount(unsigned int patronID);
				void updatedvdCount(unsigned int patronID);
				void updatecdCount(unsigned int patronID);
				void addLostBookFine(unsigned int patronID, double BookC);
				void addLostdvdFine(unsigned int patronID, double dvdC);
				void addLostcdFine(unsigned int patronID, double cdC);
				void updatePStatus(unsigned int patronID);
				int patronC();
				int patroncap();
				void fineList(Patrons *patV);
				void saveList();
				void freememory();
				void readCount(unsigned int &line);
				void readCap(unsigned int &line);
				void readFile(unsigned int &line);
				void readfileadd();
				void addoverduebfine(unsigned int patronID, int overduefine, double bookFine);
				void addoverduedfine(unsigned int patronID, int overduefine, double dvdFine);
				void addoverduecfine(unsigned int patronID, int overduefine, double cdFine);
				void addoverdueList(unsigned int patronID);
				void overdueList(Patrons *patV);
				void erasebookBorr2(unsigned int patronID);
				void erasedvdBorr2(unsigned int patronID);
				void erasecdBorr2(unsigned int patronID);
				
	Patrons(int a)
	{
		patronCount=0;
		patronCap=a;
	}
};

//ADD ARGUMENTS
