class Patron
{
    
	private:
        unsigned int patronID;
        std::string patronFirstN; 
	      std::string patronLastN;
        std::string patronStanding;
        std::string patronAddress;
        std::string patronEmail;
        std::string patronPhoneN;
				std::string city;
				std::string state;
				std::string zipcode;
        int patronFineBal;
        int booksBorrowed;
				int dvdsBorrowed;
				int cdsBorrowed;
				int overdueBooks;
	
	public:
	      unsigned int getid();
				std::string getfirstN();
				std::string getLastN();
				std::string getStanding();
				std::string getAddress();
				std::string getEmail();
				int getPatronFine();
				int getbooksBorr();
				int getdvdBorr();
				int getcdBorr();
				std::string getPhone();
				void setPatronFine();
        void set();
				void editPatron();
        void get();
				void getLabel();
        void addFine();  
        void payFine();
				void updateBookCnt();
				void updatedvdCnt();
				void updatecdCnt();
				void addlostbookfine(double BookC);
				void addlostdvdfine(double dvdC);
				void addlostcdfine(double cdC);
				void updatePStatus2();
				void saveList2();
				void readfile(unsigned int &line);
				void addoverduebfine2(int overduefine, int bookFine);
				void addoverduedfine2(int overduefine, int dvdFine);
				void addoverduecfine2(int overduefine, int cdFine);
				void addoverdueList2();
				int getoverdueList2();
				void erasebookBorr3();
				void erasedvdBorr3();
				void erasecdBorr3();
				
	Patron()
	{
		patronFineBal=0;
		booksBorrowed=0;
		dvdsBorrowed=0;
		cdsBorrowed=0;
		patronStanding = "Good";
		overdueBooks=0;
	}
};


