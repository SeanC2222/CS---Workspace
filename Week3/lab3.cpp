#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

int processFiles(ifstream&,ifstream&,ofstream&);

int main(){

      ifstream iFSOne ("input1.txt", std::ifstream::in);
      ifstream iFSTwo ("input2.txt", std::ifstream::in);
      ofstream oFS ("oFile.txt");
      
      processFiles(iFSOne, iFSTwo, oFS);
      
      iFSOne.close();
      iFSTwo.close();
      oFS.close();


   return 0;
}

int processFiles (ifstream& iFSOne, ifstream& iFSTwo, ofstream& oFS){
   
   int temp1, temp2;

   iFSOne >> temp1;
   iFSTwo >> temp2;

   do{
      //Both files still have values
      if (!iFSOne.eof() && !iFSTwo.eof()){

	 if (temp1 > temp2){
	    oFS << temp2 << endl;
	    iFSTwo >> temp2;
	 } else {
	    oFS << temp1 << endl;
	    iFSOne >> temp1;
	 }
      //File one still has values
      } else if (!iFSOne.eof()){
	 oFS << temp1 << endl;
	 iFSOne >> temp1;
      ///File Two still has values
      } else {
	 oFS << temp2 << endl;
	 iFSTwo >> temp2;
      }
   } while (!iFSOne.eof() || !iFSTwo.eof());
   return 0;
}
