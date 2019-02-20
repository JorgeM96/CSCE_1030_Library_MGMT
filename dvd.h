//this is the header file for dvd
#include "LibItem.h"
class dvd: public LibItem
{
  private:
  std::string studioP;
  std::string rating;
  double duration;
  
  public:
  void setdvd();
  void getdvd();
  void editdvd();
  void savedvd();
  void readdvd(unsigned int &line);
};