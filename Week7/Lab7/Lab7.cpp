#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
#include <fstream>
using std::fstream;
#include <string>
using std::string;
#include <iomanip>
#include <vector>
using std::vector;
#include <chrono>
#include <exception>

/* Function: void ClearScreen() 
 * Description: Ouputs 100 blank lines effectively clearing the console.
 * Pre-Conditions: None.
 * Post-Conditions: Blank viewable console screen.
 */
void clearScreen();

/* Function: void displayMenu()
 * Description: Displays the program start menu offering to start a demo combat
 *	        round, view character type info, or quit.
 * Pre-Conditions: None.
 * Post-Conditions: Outputs start menu to console.
 */
void displayMenu();

/* Function: std::string getChoice() 
 * Description: Gets a user choice in the form of a string and formats to a
 *	        common format of all lowercase, and no ' ' characters.
 * Pre-Conditions: User is explained what their choices should be.
 * Post-Conditions: Returns the formatted user choice to function call.
 */
std::string getChoice();

/* Function: void startCombatDemo(std::string) 
 * Description: Calls the function that the user selected from start menu.
 * Pre-Conditions: User has been prompted the start menu, and a choice has been
 *	           input. Formatted string is passed into function.
 * Post-Conditions: None.
 */
void callStartMenuChoice(std::string);

/* Function: void linSearchAlg() 
 * Description: Performs a linear style search on data file.
 * Pre-Conditions: Data files "input1.txt" "input2.txt" "input3.txt" and
 *		   "input4.txt" exist in folder.
 * Post-Conditions: None.
 */
void linSearchAlg();

/* Function: void sortAlg() 
 * Description: Performs a bubble sort and outputs sorted file.
 * Pre-Conditions: Data files "input1.txt" "input2.txt" "input3.txt" and
 *		   "input4.txt" exist in folder.
 * Post-Conditions: "sorted-input#.txt" is generated. 
 */
vector<int> sortAlg();

/* Function: void binaryAlg() 
 * Description: Performs a bubble sort, then binary search of file.
 * Pre-Conditions: Data files "input1.txt" "input2.txt" "input3.txt" and
 *		   "input4.txt" exist in folder.
 * Post-Conditions: "sorted-input#.txt" is generated. 
 */
void binaryAlg();

/* Function: void binSearch() 
 * Description: Performs binary search of file.
 * Pre-Conditions: Data files "input1.txt" "input2.txt" "input3.txt" and
 *		   "input4.txt" exist in folder.
 * Post-Conditions: Search value location returned. 
 */
int binSearch(vector<int>&,int,int,int);

int main(){

   cout << "This program will offer several sorting/searching algorithms for the\n"
        << "user to test out." << endl;

   string choice;

   do {
      clearScreen();
      displayMenu();
      choice = getChoice();
      callStartMenuChoice(choice);
   } while (choice != "quit" && choice != "4");


   return 0;
}

void clearScreen(){
   for(int i = 0; i < 100; i++){
      cout << "\n";
   }
   return;
}

void displayMenu(){

   cout << "Algorithms: \n\n"
        << "1) Linear Search for Value\n"
	<< "2) Bubble Sort Values File\n"
        << "3) Binary Searching\n"
	<< "4) Quit\n"
	<< "What would you like to do? ";
   return;
}

std::string getChoice(){
   //User Choice
   std::string choice;
   //Gets user input
   std::getline(std::cin, choice);
   //Formats user choice
   for (unsigned i = 0; i < choice.length(); i++){
      //Sets characters to lowercase
      choice[i] = tolower(choice.at(i));
      //Removes ' ' characters
      if (choice.at(i) == ' '){
	 choice.erase(choice.begin() + i);
	 i--;
      }
   }
   //Returns Formatted choice
   return choice;
}

void callStartMenuChoice(string choice){

   if (choice == "1" || choice == "search"){
      linSearchAlg();
   } else if (choice == "2" || choice == "sort" || choice == "sortvalues"){
      sortAlg();
   } else if (choice == "3" || choice == "binary" || choice == "binarysearch"){
      binaryAlg();
   } else if (choice == "4" || choice == "quit"){
      return;
   } else {
      cout << "Invalid choice. Try again." << endl;
      cin.ignore(100,'\n');
   }
   return;
}
string pickList(){

   string* inputs;
   inputs = new string[4];
   inputs[0] = "input1.txt";
   inputs[1] = "input2.txt";
   inputs[2] = "input3.txt";
   inputs[3] = "input4.txt";

   clearScreen();

   cout << "Which list would you like to search? (enter list index, not name) " << endl;
   for (int i = 0; i < 4; i++)
      cout << i+1 << ") " << inputs[i] << endl;
   
   int choice = 0;

   do {
      cin >> choice;
      if (cin.fail()){
	 cin.clear();
	 cin.ignore(100,'\n');
	 cout << "Invalid entry." << endl;
      }
      choice--;
   } while (choice < 1 && choice > 4 );

   cin.ignore(100,'\n');
   string sChoice = inputs[choice];
   delete [] inputs;
   return sChoice;
}
 

void linSearchAlg(){
   string list = pickList();
   
   std::fstream fs (list.c_str(), std::fstream::in);

   try{
      if (!fs.good()){
	 string s = "File not found.";
	 throw s;
      }
   } catch (string s){
      cout << s << endl;
      return;
   }
   
   cout << "What number from 0 to 9 would you like to search for? ";

   int searchNum = 0;
   cin >> searchNum;
   cin.ignore(100,'\n');
   int index = -1;
   int temp = -1;
   std::chrono::high_resolution_clock clck;
   std::chrono::high_resolution_clock::time_point start = clck.now();

   while (temp != searchNum){
      fs >> temp;
      index++;
      if (fs.eof()){
	 break;
      }
   }
   std::chrono::high_resolution_clock::time_point end = clck.now();
   std::chrono::duration<double> diff = end - start;
   if (fs.eof()){
      cout << "Number not found." << endl;
      fs.clear();
   } else {   
      cout << "Number found at index: " << index << endl;
      cout << "Run time: " << diff.count() << endl;
   }
   cin.ignore(100,'\n');
   fs.close();
   return;
}

vector<int> sortAlg() {
   string list = pickList();
   string sortList = "sorted-" + list;
   std::fstream ifs (list.c_str(), std::fstream::in);

   std::vector<int> sortInts;

   try{
      if (!ifs.good()){
	 string s = "File not found.";
	 throw s;
      }
   } catch (string s) {
      cout << s << endl;
      cin.ignore(100,'\n');
      return sortInts;
   }

   std::fstream ofs (sortList.c_str(), std::fstream::out);
   int next;
   int count = 0;

   while (ifs >> next){
      sortInts.push_back(next);
   }

   std::chrono::high_resolution_clock clck;
   std::chrono::high_resolution_clock::time_point start = clck.now();

   for (int i = sortInts.size() - 1; i >= 0; i--){
      for (int j = 1; j <= i; j++){
	 if (sortInts.at(j-1) > sortInts.at(j)){
	    int temp = sortInts.at(j-1);
	    sortInts.erase(sortInts.begin() + j - 1);
	    sortInts.insert(sortInts.begin() + j,temp);
	 }
      }
   }

   std::chrono::high_resolution_clock::time_point end = clck.now();
   std::chrono::duration<double> diff = end - start;
 
   for (int i = 0; i < sortInts.size(); i++){
      ofs << sortInts.at(i) << endl;
   }
   cout << "Values sorted." << endl;
   cout << "Run time: " << diff.count() << endl;
   cin.ignore(100,'\n');
   return sortInts;
} 
	  
void binaryAlg() {

   vector<int> ints;
   ints = sortAlg();

   int from = 0;
   int to = ints.size()-1;

   int temp;
   cout << "What value would you like to search for? ";
   cin >> temp; 

   cin.ignore(100,'\n');

   if (cin.fail()){
      cout << "Bad input, returning to menu" << endl;
      return;
   }
   
   std::chrono::high_resolution_clock clck;
   std::chrono::high_resolution_clock::time_point start = clck.now();
  
   int loc = binSearch(ints, temp, 0, ints.size()-1);

   std::chrono::high_resolution_clock::time_point end = clck.now();
   std::chrono::duration<double> diff = end - start;

   if (loc == -1){
      cout << "Value not found." << endl;
   } else {
      cout << "Value found." << endl;
   }
   cout << "Total search time: " << diff.count() << endl;
   cin.ignore(100,'\n');

   return;
} 

int binSearch(vector<int>& ints, int key, int min, int max){

   int s = ints.size()/2;
   int val = ints.at(s);
   if (max < min){
      return -1;
   } else {
      int mid = (max - min) / 2;
      
      if(ints.at(mid) > key){
         return binSearch(ints, key, min, mid-1);
      }else if (ints.at(mid) < key){
         return binSearch(ints, key, mid+1, max);
      } else {
         return mid;
      }
   }

}
