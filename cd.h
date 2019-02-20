//this is the cd header
#include "LibItem.h"
class cd: public LibItem
{
  private:
  std::string label;
  std::string artist;
  int songs;
  
  public:
  void setcd();
  void getcd();
  void editcd();
  void savecd();
  void readcd(unsigned int &line);
};