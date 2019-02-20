#include "LibItem.h"
class book: public LibItem
{
  private:
  std::string publisher;
  std::string author;
  
  public:
  void setbook();
  void getbook();
  void editbook();
  void savebook();
  void readbook(unsigned int &line);
};
