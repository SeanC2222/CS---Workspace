#include <fstream>
using std::fstream;

#include <ios>
using std::ios_base;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>

void clearScreen() {for(int i = 0; i < 99; i++){cout << endl;}}
int promptUser(int i);
void buildFile(fstream&, int, int);

int main(){
   
   fstream fs;

   for (char i = '1'; i < '5'; i++){
      string fileName = "input";
      int numInts = promptUser(i-48);//-48 to adjust ASCII value
      fileName.append(1, i);
      fileName.append(".txt");
      fs.open(fileName.c_str(), std::fstream::out);
      buildFile(fs, numInts, i);
      fs.close();
   }

   return 0;

}

int promptUser(int i){

   int numInts = 0; 

   do{
      clearScreen();
      cout << "How many random integers would you like to generate for file " 
	   << i << "? (More than 1000)" << endl;
      cin >> numInts;
      cin.ignore(100,'\n');
 
  } while (numInts < 1000);

   return numInts;
}

void buildFile (fstream& fs, int numInts, int i){
   srand(time(NULL));
   int numCount = 0;
   int zeroPosition = numInts/4;
   while (numCount < numInts){
      if (numCount == zeroPosition *(i-48) && (i-48) != 4){
	 fs << "0" << endl;
	 numCount++;
      }     
      fs << rand() % 9 + 1 << endl;
      numCount++;
   }
   
   return;
}      
