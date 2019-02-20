//this is the cpp file for reference
#include <iostream>
#include <fstream>
#include "reference.h"
class reference;
using namespace std;

void reference::setref()
{
  cout << "Please enter the reference book's publisher: " << endl;
	cin >> publisher;
	cout << "Please enter the reference book's author: " << endl;
	cin >> author;
}
void reference::getref()
{
  cout << "Reference book's publisher: " << publisher << endl;
  cout << "Reference book's author: " << author << endl;
}
void reference::editref()
{
	cout << "Please enter the reference book's publisher: " << endl;
	cin >> publisher;
	cout << "Please enter the reference book's author: " << endl;
	cin >> author;
}
void reference::saveref()
{
	ofstream fout2;
	fout2.open("Librarydata.txt", ios_base::app);
	fout2 << publisher << " " << author << endl;
	fout2.close();
}
void reference::readref(unsigned int &line)
{
	ifstream fin2;
	fin2.open("Librarydata.txt");
	char array[256];
	for(int i=0;i<line;i++)
	{
		fin2.getline(array,256);
	}
	fin2 >> publisher >> author;
	line+=1;
	fin2.close();
}