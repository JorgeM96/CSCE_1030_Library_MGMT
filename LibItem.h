//Make sure to have this in checkouts and include in main and remove book header
#ifndef _LibItem
#define _LibItem
class LibItem
{
	protected:   //check if protected is right
	 unsigned int itemID;
   std::string itemName;
   std::string itemGenre;
   double itemCost;
	 std::string itemStatus;
	 	
	public:
	virtual void set();
	virtual void get();
	unsigned int getItemID();
	double getItemCost();
	void editItem();
	void updateStatus();
	void updateStatus2();
	void updateStatus3();
	void updatedvdstatus2();
	void updatedvdstatus3();
	void updatecdstatus2();
	void updatecdstatus3();
	double getBookCost2();
	double getdvdCost2();
	double getcdCost2();
	virtual void printItemTitle();
	virtual void savelist();
	virtual void readfile(unsigned int &line);
	
	//add more or remove later as i need
	LibItem()
	{
		itemStatus = "In";
	}
};
#endif