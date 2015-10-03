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

void searchAlg();
void sortAlg();
void binaryAlg();

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
        << "1) Search for Value\n"
	<< "2) Sort Values from 2 Files\n"
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
      searchAlg();
      cin.ignore(100,'\n');
   } else if (choice == "2" || choice == "sort" || choice == "sortvalues"){
      sortAlg();
      cin.ignore(100,'\n');
   } else if (choice == "3" || choice == "binary" || choice == "binarysearch"){
      binaryAlg();
      cin.ignore(100,'\n');
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

   string sChoice = inputs[choice];
   delete [] inputs;
   return sChoice;
}
 

void searchAlg(){
   string list = pickList();
   
   std::fstream fs (list.c_str(), std::fstream::in);
   
   cout << "What number from 0 to 9 would you like to search for? ";

   int searchNum = 0;
   cin >> searchNum;
   
   int index = -1;
   int temp = -1;
   while (temp != searchNum){
      fs >> temp;
      index++;
      if (fs.eof()){
	 break;
      }
   }
   if (fs.eof()){
      cout << "Number not found." << endl;
      fs.clear();
   } else {   
      cout << "Number found at index: " << index << endl;
   }
   cin.ignore(100,'\n');

   fs.close();
   return;
}

void sortAlg() {
   string list = pickList();
   string sortList = "sorted-" + list;

   std::fstream ifs (list.c_str(), std::fstream::in);
   std::fstream ofs (sortList.c_str(), std::fstream::out);

   std::vector<int> sortInts;
   int next;
   int count = 0;
   do {
      ifs >> next;
      if (count == 0){
	 sortInts.push_back(next);
      }

      for (int i = 0; i < sortInts.size(); i++){
	 if (next > sortInts.at(i) && i < sortInts.size()-1){
	    continue;
	 } else if (next <= sortInts.at(i)){
	    sortInts.insert(sortInts.begin() + i, next);
	    break;
	 } else if (next > sortInts.at(i) && i == sortInts.size() -1){
	    sortInts.push_back(next);
	    break;
	 }
      }
      count++;
   } while (!ifs.eof());
   cout << " count = " << count << endl;
   cout << sortInts.size() << endl;
   cin.ignore(100,'\n'); 
   for (int i = 0; i < sortInts.size(); i++){
      cout << sortInts.at(i) << endl;
      ofs << sortInts.at(i) << endl;
   }
   return;
} 
	  
void binaryAlg() {
   std::fstream ifs ("inputBin.txt", std::fstream::in);
   int temp;
   std::vector<int> buff;

   while (ifs >> temp){
      buff.push_back(temp);
   }

   temp = 0;
   int i = buff.size()/2;
   int index = i;

   while (temp != 5){
      temp = buff.at(i);
      if (temp > 5){
	 buff.erase(buff.begin() + i, buff.end());
	 i = buff.size()/2;
	 index -= i;
      } else if (temp < 5){
	 buff.erase(buff.begin(), buff.begin() + i + 1);
	 i = buff.size()/2;
	 index += i;
      }
   }
   cout << "5 found at index: " << index << endl;
   return;
}   
