//this is the cpp file for cd
#include <iostream>
#include <fstream>
#include "cd.h"
class cd;
using namespace std;

void cd::setcd()
{
  cout << "Please enter the cd's label company: " << endl;
  cin >> label;
  cout << "Please enter the cd's artist: " << endl;
  cin >> artist;
  cout << "Please enter the number of songs on this cd: " << endl;
  cin >> songs;
}
void cd::getcd()
{
  cout << "CD's label company: " << label << endl;
  cout << "CD's artist: " << artist << endl;
  cout << "Number of songs on CD: " << songs << endl;
}
void cd::editcd()
{
  cout << "Please enter the cd's label company: " << endl;
  cin >> label;
  cout << "Please enter the cd's artist: " << endl;
  cin >> artist;
  cout << "Please enter the number of songs on this cd: " << endl;
  cin >> songs;
}
void cd::savecd()
{
  ofstream fout2;
  fout2.open("Librarydata.txt", ios_base::app);
  fout2 << label << " " << artist << " " << songs << endl;
  fout2.close();
}
void cd::readcd(unsigned int &line)
{
  ifstream fin2;
	fin2.open("Librarydata.txt");
	char array[256];
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> label >> artist >> songs;
	line+=1;
	fin2.close();
}