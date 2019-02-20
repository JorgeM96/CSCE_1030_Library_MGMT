//this is the cpp file for dvd
#include <iostream>
#include <fstream>
#include "dvd.h"
class dvd;
using namespace std;

void dvd::setdvd()
{
  cout << "Please enter the dvd's studio producer: " << endl;
  cin >> studioP;
  cout << "Please enter the dvd's viewer rating: " << endl;
  cin >> rating;
  cout << "Please enter the dvd's time duration (in minutes)" << endl;
  cin >> duration;
}
void dvd::getdvd()
{
  cout << "DVD's studio producer: " << studioP << endl;
  cout << "DVD's viewer rating: " << rating << endl;
  cout << "DVD's time duration (in minutes): " << duration << endl;
}
void dvd::editdvd()
{
  cout << "Please enter the dvd's studio producer: " << endl;
  cin >> studioP;
  cout << "Please enter the dvd's viewer rating: " << endl;
  cin >> rating;
  cout << "Please enter the dvd's time duration (in minutes)" << endl;
  cin >> duration;
}
void dvd::savedvd()
{
  ofstream fout2;
  fout2.open("Librarydata.txt", ios_base::app);
  fout2 << studioP << " " << rating << " " << duration << endl;
  fout2.close();
}
void dvd::readdvd(unsigned int &line)
{
  ifstream fin2;
	fin2.open("Librarydata.txt");
	char array[256];
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> studioP >> rating >> duration;
	line+=1;
	fin2.close();
}