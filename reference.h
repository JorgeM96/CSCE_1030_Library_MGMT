//This is the header file for reference
#include "LibItem.h"
class reference: public LibItem
{
  private:
  std::string publisher;
  std::string author;
  
  public:
  void setref();
  void getref();
  void editref();
  void saveref();
  void readref(unsigned int &line);
};