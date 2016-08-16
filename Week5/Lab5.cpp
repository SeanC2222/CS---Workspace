#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "filefilter.h"

void showFilterMenu();
void useFilter(ifstream&, ofstream&, int);

int main(){

   //Input text document
   ifstream ifs ("test.txt");

   //Output source
   ofstream ofs ("tresults.txt", ofstream::out);
   
   if (ifs.good()){
      cout << "This program can output encrypted text to a file named \n"
	   << "\"tresults.txt\". The encrypted texts are output to this\n"
	   << "file, and overwrite any previous file data." << endl;

      int choice;

      do{
	 showFilterMenu();
	 if (cin >> choice){
	    useFilter(ifs, ofs, choice);
	    cin.ignore(100,'\n');
	 } else if (choice > 4 || choice <= 0){
	    cout << "Please enter a valid choice.";
	    cin.ignore(100,'\n');
	 } else {
	    cin.clear();
	    cin.ignore(100,'\n');
	    cout << "Please enter a valid choice." << endl;
	 }
      } while (choice <= 4 && choice > 0);
   } else {
      ifs.clear();
      cout << "\"test.txt\" does not exist in current directory. Please\n"
	   << "create a document labelled \"test.txt\" and enter information\n"
	   << "to be filtered." << endl;
   }
 
   return 0;
}

void showFilterMenu(){
   cout << "Filter Choices:\n\n"
        << "1) No Filter\n"
        << "2) To Upper Case\n"
        << "3) Caesar Filter\n"
        << "4) Cipher Filter\n"
        << "5) Quit\n" << endl;
   return;
}

void useFilter(ifstream& ifs, ofstream& ofs, int c){

   if (c == 1){
         FileNoFilter fnf; 
	 fnf.doFilter(ifs, ofs);
	 ofs << '\n';

	 ifs.clear();
	 ifs.seekg(ifs.beg);

   } else if (c == 2){
	 FileToUpper u;
	 u.doFilter(ifs, ofs);
	 ofs << '\n';
	 
	 ifs.clear();
	 ifs.seekg(ifs.beg);

   } else if (c == 3){
      cout << "What integer key would you like to use?";
      int tempKey;
      if (cin >> tempKey){
	 FileToCaesar c(tempKey);
	 c.doFilter(ifs, ofs);
	 ofs << '\n';
	 cin.ignore(100,'\n');
      } else {
	 cin.clear();
	 cin.ignore(100,'\n');
	 cout << "Wrong input. Returning." << endl;
      }
      ifs.clear();
      ifs.seekg(ifs.beg);

   } else if (c == 4){
      cout << "What integer key would you like to use?";
      int tempKey;
      if (cin >> tempKey){
	 FileToCipher ciph(tempKey);
	 ciph.doFilter(ifs, ofs);
	 ofs << '\n';
	 cin.ignore(100,'\n');
      } else {
	 cin.clear();
	 cin.ignore(100,'\n');
	 cout << "Wrong input. Returning." << endl;
      } 

      ifs.clear();
      ifs.seekg(ifs.beg);
   }
   return;
}      
