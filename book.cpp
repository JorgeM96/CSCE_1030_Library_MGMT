#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "book.h"
class book;
using namespace std;

 void book::setbook() 
 {
	 cout << "Please enter the book's publisher: " << endl;
	 cin >> publisher;
	 cout << "Please enter the book's author: " << endl;
	 cin >> author;
 }

void book::getbook()
{
	cout << "Book's Publisher: " << publisher << endl;
	cout << "Book's Author: " << author << endl;
}
void book::editbook()
{
	cout << "Enter the book's publisher" << endl;
	cin >> publisher;
	cout << "Enter the book's author: " << endl;
	cin >> author;
}
void book::savebook()
{
	ofstream fout2;
	fout2.open("Librarydata.txt", ios_base::app);
	fout2 << publisher << " " << author << endl;
	fout2.close();
}
void book::readbook(unsigned int &line)
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
