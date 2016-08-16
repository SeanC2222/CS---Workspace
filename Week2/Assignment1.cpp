//Author: Sean Mulholland
//Date: 1/18/15
//File Name: Assignment1.cpp
//
//File Purpose: This is Assignment1 for CS162, that is an implementation of 
//    John Conway's Game of Life. It requires cell.h, cell.cpp, board.h, and
//    board.cpp to compile and function together.
//    This implementation focuses on the individual evolution as it outputs
//    each generation of cell automation, with a 1 second pause in between 
//    each frame.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>

#include "cell.h"
#include "board.h"

//Simple function to output 100 blank lines to console
void clearScreen() {for (int i = 0; i < 100; i++){cout << endl;}}

//Displays intro screen
void displayWelcomeMenu();

//Gets user input and formats to a common format
string getInput();

//Starts instance of Game of Life
string blankGame();

//Adds a cell to Board&
void addCell(Board&);

//Builds pattern and adds a pattern to Board&
void addPattern(Board&);
Board buildPattern(Board&);

//Copies Board into Board&
void insertPattern(Board&, Board);

//Adds a glider pattern to Board&
void addGlider(Board&);

//Adds a glider gun pattern to Board&
void addGliderGun(Board&);

//Adds an oscillator pattern to Board&
void addOscillator(Board&);
Board buildBlinker();
Board buildFigure8();
Board buildPinwheel();
Board buildPulsar();

//Outputs LifeStatus of Cells in Board&
void viewBoard(Board&);

//Applies rules from Game of Life to Board&
void runGame(Board&);
bool checkBoardSize(Board&);
void adjustBoardSize(Board&);
void findNextLifeStatus(Board&);
void updateLifeStatus(Board&);

//Pause program for up to 1 second
void pauseOneSec(int);

//Outputs rules to console
void displayHowTheGameWorks();

//Starts program, and based on user input starts game, outputs rules, or quits
int main(){
   
   string userChoice;
   do{
      //displays intro screen
      displayWelcomeMenu();
      //gets common format user input
      userChoice = getInput();
	 //Starts new game
	 if (userChoice ==  "1" ||
	     userChoice == "start" ||
	     userChoice ==  "startgame" ||
	     userChoice ==  "startthegame")
	    userChoice = blankGame();
	 //Outputs rules to console
	 else if (userChoice == "2" ||
		  userChoice == "howthegameworks" ||
		  userChoice == "howgameworks")
	    displayHowTheGameWorks();
	 //Quits game
	 else if (userChoice == "3" ||
		  userChoice == "quit")
	    break;
	 else
	    cout << "Not a valid command." << endl;
   }while (userChoice != "3" && 
	   userChoice != "quit" &&
	   userChoice != "0" &&
	   userChoice != "-1");
   return 0;
}

//Outputs intro screen to console
void displayWelcomeMenu(){
   clearScreen();
   cout << "Welcome to the Game of Life created by John Conway!\n"
        << endl
        << "1) Start the game\n"
        << "2) How the game works\n"
        << "3) Quit\n" << endl;
   cout << "What would you like to do?";
   return;
}

//Gets user input in the form of a string, sets all alphabetic characters
//to lowercase and removes spaces. Returns formatted string, userChoice
string getInput(){
   string userChoice;
   getline(cin, userChoice);
   for (unsigned i = 0; i < userChoice.length(); i++){
      userChoice.at(i) = tolower(userChoice.at(i));
      if (userChoice.at(i) == ' '){
	 userChoice.erase(i,1);
	 i--;
      }
   }
   return userChoice;
}

//Outputs rules to console with pauses between section
void displayHowTheGameWorks(){
   clearScreen();
   cout << endl
        << "   The Game of Life, also known simply as Life, is a cellular\n"
        << "automaton devised by British mathematician John Horton Conway\n"
        << "in 1970. The \"game\" is a zero-player game, meaning that its\n"
        << "evolution is determined by its initial state, requiring no\n"
        << "further input. One interacts with the Game of Life by creating\n"
        << "an initial configuration and observing how it evolves or, for\n"
        << "advanced players, by creating patterns with particular\n"
        << "properties.\n\n"
        << " - Description taken from Wikipedia\n"
        << "https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life\n"
        << "Press enter to continue.";
   cin.ignore(100,'\n');
   cout << endl
        << "   The basic rules of evolution are as follows:\n\n"
        << "1) If a cell is currently living and has less than 2 neighbors\n"
        << "\tit dies.\n\n"
        << "2) If a cell is currently living and has 2 or 3 neighbors it\n"
        << "\tlives on to the next generation.\n\n"
        << "3) If a cell is currently living and has more than 3 neighbors\n"
        << "\tit dies from overcrowding.\n\n"
        << "4) If a cell is currently dead and has exactly 3 neighbors it\n"
        << "\tis birthed.\n\n"
        << "Press enter to continue.";
   cin.ignore(100,'\n');
   cout << endl
        << "   This implementation operates on a turn basis. All births and\n"
        << "deaths occur at the same time between turns.\n\n"
        << "   This version also offers the option to add cells, as a user, \n"
        << "between generations.\n\n"
        << "   There are also select patterns that can be added that exhibit\n"
        << "unique features.\n\n"
	<< "\t\tEnjoy!!!!!\n"
        << "Press enter to return to main menu.";
   cin.ignore(100,'\n');
   return;
}

//Starts a new Game of Life on a new board gameboard
//return string is for flagging user's choice to quit the program
string blankGame(){
   //Gameboard housing all cells 
   Board gameboard;
   string userChoice;
   //Game Loop
   do{
      clearScreen();
      cout << "Build options:\n"
	   << endl
	   << "1) Change a Cell\n"
	   << "2) Add New Pattern\n"
	   << "3) Add Glider\n"
	   << "4) Add Glider Gun\n"
	   << "5) Add Oscillator\n"
	   << "6) View Board\n"
	   << "7) Start Game\n"
	   << "8) Display How the Game Works\n"
	   << "9) Return to Main Menu\n" << endl;
      cout << "What would you like to do?";
      //Gets user input in common format
      userChoice = getInput(); 
      //Adds cell to gameboard  
      if (userChoice == "1" ||
	  userChoice == "addcell\n" ||
	  userChoice == "cell")
	 addCell(gameboard);
      //Adds pattern to gameboard
      else if (userChoice == "2" ||
	       userChoice == "addnewpattern" ||
	       userChoice == "addpattern")
	 addPattern(gameboard);
      //Adds glider pattern to gameboard
      else if (userChoice == "3" ||
	       userChoice == "addglider" ||
	       userChoice == "glider")
	 addGlider(gameboard);
      //Adds glider gun pattern to gameboard
      else if (userChoice == "4" ||
	       userChoice == "addglidergun" ||
	       userChoice == "glidergun")
	 addGliderGun(gameboard);
      //Adds oscillator of user choice to gameboard
      else if (userChoice == "5" ||
	       userChoice == "addoscillator" ||
	       userChoice == "oscillator")
	 addOscillator(gameboard);
      //Views current lifeStatus of Cells in gameboard
      else if (userChoice == "6" ||
	       userChoice == "viewboard" ||
	       userChoice == "view"){
	 viewBoard(gameboard);
	 cin.ignore(100, '\n');
      //Applies Conways rules user defined number of times
      } else if (userChoice == "7" ||
	       userChoice == "startgame" ||
	       userChoice == "start")
	 runGame(gameboard);
      //Displays the rules
      else if (userChoice == "8" ||
	       userChoice == "display" ||
	       userChoice == "displayhowthegameworks" ||
	       userChoice == "help")
	 displayHowTheGameWorks();
      //Returns to main menu and forgets gameboard contents
      else if (userChoice == "9" ||
	       userChoice == "back" ||
	       userChoice == "return" ||
	       userChoice == "returntothemainmenu")
	 ;
      //Quits game
      else if (userChoice == "quit" ||
	       userChoice == "exit")
	 break;
   }while (userChoice != "9" && 
	   userChoice != "back" && 
	   userChoice != "return" &&
	   userChoice != "returntothemainmenu");
   return userChoice;
}

//Adds cell to board passed to function
void addCell(Board& board){
   string tempStr;
   int x, y;
   //Size trait of board used to adjust coordinates to viewable world
   int size = board.getBoardSize();
   clearScreen();
   viewBoard(board);
   
   cout << "What cell would you like to change?" << endl;
   //Gets cell x coordinate
   do{
      cout << "X: ";
      getline(cin,tempStr);
      x = atoi(tempStr.c_str()) - 1;
   } while (x < 0 || x >= board.getBoardWidth());
   //Gets cell y coordinate
   do{
      cout << "Y: ";
      getline(cin,tempStr);
      y = atoi(tempStr.c_str()) - 1;
   } while (y < 0 || y >= board.getBoardHeight());
   //Flips cell LifeStatus at location (y,x) in gameboard
   Cell* tempCell = &board.getCell(y + size,x + size);
   tempCell->flipLifeStatus();
   tempCell = NULL;
   return;
}

//Builds pattern and inserts it in gameboard
void addPattern(Board& gameboard){
   Board patternboard = buildPattern(gameboard);
   insertPattern(gameboard, patternboard);

   return;
}

//Builds user defined pattern by repeatedly calling addCell() onto a 
//user specified patternboard
Board buildPattern (Board& gameboard){

   int x, y;
   string tempStr;
   clearScreen();

   cout << "How big of a pattern would you like to make?" << endl;
   //Gets width of patternboard
   do{
      cout << "X: ";
      tempStr = getInput();
      x = atoi(tempStr.c_str());
   } while (x < 0 || x >= gameboard.getBoardWidth());
   //Gets height of pattern board
   do{
      cout << "Y: ";
      tempStr = getInput();
      y = atoi(tempStr.c_str());
   } while (y < 0 || y >= gameboard.getBoardHeight());
   //Creates patternboard
   Board patternboard(y,x);    
   //Adds cells to pattern board until user is finished
   do{
      viewBoard(patternboard);
      addCell(patternboard);
      viewBoard(patternboard);
      cout << "Change another cell? (\'y\'/\'n\') ";
      tempStr = getInput();
   }while (tempStr != "n" && tempStr != "no" && tempStr != "quit");
   return patternboard;
}

//Copies life status of patterboard to user specified location on gameboard
void insertPattern(Board& gameboard, Board patternboard){
   int x, y;
   int size = gameboard.getBoardSize();
   string tempStr;
   clearScreen();
   //Shows current lifeStatus of gameboard
   viewBoard(gameboard);

   cout << "Where would you like to put the pattern?" << endl
	<< "Pattern will be placed based on top left coordinate." << endl;
   //Gets top left x coordinate of where to place pattern
   do{
      cout << "X: ";
      tempStr = getInput();
      x = atoi(tempStr.c_str()) + size - 1;
   } while (x < 0 || x >= gameboard.getBoardWidth());
   //Gets top left y coordinate of where to place pattern
   do{
      cout << "Y: ";
      tempStr = getInput();
      y = atoi(tempStr.c_str()) + size - 1;
   } while (y < 0 || y >= gameboard.getBoardHeight());
   //Transposes lifeStatus from patternboard to relative gameboard locations
   Cell* tempCell;
   for (int i = 0; i < patternboard.getBoardHeight(); i++){
      for (int j = 0; j < patternboard.getBoardWidth(); j++){
	 tempCell = &gameboard.getCell(y + i,x + j);
	 tempCell->setLifeStatus(patternboard.getCell(i,j).getLifeStatus());
      }
   }
   tempCell = NULL;
   return;
}

//Builds and inserts a glider pattern into gameboard at user specified location
void addGlider(Board& gameboard){
   Board gliderPattern(3,3);
   Cell* tempCell;
   //Manually builds glider pattern 
   tempCell = &gliderPattern.getCell(0,1);
   tempCell->setLifeStatus(1);

   tempCell = &gliderPattern.getCell(1,2);
   tempCell->setLifeStatus(1);

   for (int i = 0; i < 3; i++){
      tempCell = &gliderPattern.getCell(2,i);
      tempCell->setLifeStatus(1);
   } 
   //Displays glider pattern before inserting
   viewBoard(gliderPattern);
   cout << "Press enter to continue.";
   cin.ignore(100,'\n');
   //inserts glider pattern at user specified location
   insertPattern(gameboard, gliderPattern);
   return;
}

//Builds and inserts a glider gun pattern into gameboard at user location
void addGliderGun(Board& gameboard){
   Board gliderGunPattern(11,38);
   Cell* tempCell;
   //Manually builds a glider gun pattern
   for (int i = 6; i < 8; i++){
      for (int j = 1; j < 3; j++){
	 tempCell = &gliderGunPattern.getCell(i,j);
	 tempCell->setLifeStatus(1);
      }
   }

   for (int i = 3; i < 6; i++){
      for (int j = 21; j < 23; j++){
	 tempCell = &gliderGunPattern.getCell(i,j);
	 tempCell->setLifeStatus(1);
      }
   }
   tempCell = &gliderGunPattern.getCell(2,23);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(6,23);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(1,25);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(2,25);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(6,25);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(7,25);
   tempCell->setLifeStatus(1);
   
   tempCell = &gliderGunPattern.getCell(5,11);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(6,11);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(7,11);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(4,12);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(8,12);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(3,13);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(9,13);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(3,14);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(9,14);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(6,15);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(4,16);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(8,16);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(5,17);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(6,17);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(7,17);
   tempCell->setLifeStatus(1);
   tempCell = &gliderGunPattern.getCell(6,18);
   tempCell->setLifeStatus(1);

   for (int i = 3; i < 5; i++){
      for (int j = 35; j < 37; j++){
	 tempCell = &gliderGunPattern.getCell(i,j);
	 tempCell->setLifeStatus(1);
      }
   }
   //Displays glider gun pattern to user
   viewBoard(gliderGunPattern);
   cout << "Press enter to continue.";
   cin.ignore(100,'\n');
   //inserts glider gun pattern into gameboard at user location
   insertPattern(gameboard, gliderGunPattern);
   return;
}

//Builds and inserts an oscillator of user choice into gameboard
void addOscillator(Board& gameboard){
   string userChoice;
   do{
      clearScreen();
      cout << "Types of oscillators:\n" << endl
	   << "1. Blinker (1x3)\n"
	   << "2. Figure 8 (6x6)\n"
	   << "3. Pinwheel (12x12)\n"
	   << "4. Pulsar  (13x13)\n"
	   << "5. Back to Game Menu\n" << endl;
      cout << "Which oscillator would you like to add? ";
      userChoice = getInput();
      //inserts Blinker patter into gameboard at user location
      if (userChoice == "1" ||
	  userChoice == "blinker"){
	 insertPattern(gameboard, buildBlinker());	 
      //Inserts Figure8 pattern into gameboard at user location
      } else if (userChoice == "2" ||
	         userChoice == "figure8"){
	 insertPattern(gameboard, buildFigure8());
      //Inserts pinwheel pattern into gameboard at user location
      } else if (userChoice == "3" ||
	         userChoice == "pinwheel"){
	 insertPattern(gameboard, buildPinwheel());
      //Inserts Pulsar pattern into gameboard at user location
      } else if (userChoice == "4" ||
	         userChoice == "pulsar"){
	 insertPattern(gameboard, buildPulsar());
      //Returns to previous menu
      } else if (userChoice == "5" ||
	         userChoice == "back"){
	 return;
      } else {
	 cout << "Invalid input. Press enter and try again.";
	 cin.ignore(100,'\n');
      }
   }while (userChoice != "5" && 
	   userChoice != "back" &&
	   userChoice != "backtogamemenu");
   
   return;
}

//Builds blinker pattern and returns pattern
Board buildBlinker(){
   Board patternboard(1,3);
   Cell* tempCell;
   for (int i = 0; i < patternboard.getBoardWidth(); i++){
      tempCell = &patternboard.getCell(0, i);
      tempCell->setLifeStatus(1);
   }
   tempCell = NULL;
   //Displays Blinker prior to returning pattern
   viewBoard(patternboard);
   cout << "Press enter to continue.";
   cin.ignore(100,'\n');
   return patternboard;
}

//Builds figure8 pattern and returns pattern
Board buildFigure8(){
   Board patternboard(6,6);
   Cell* tempCell;
   for (int i = 0; i < 4; i += 3){
      for(int j = 0; j < 3; j++){
	 for (int k = 0; k < 3; k++){
	    tempCell = &patternboard.getCell(i + j, i + k);
	    tempCell->setLifeStatus(1);
	 }
      }
   }
   tempCell = NULL;
   //Displays pattern prior to returning pattern
   viewBoard(patternboard);
   cout << "Press enter to continue.";
   cin.ignore(100,'\n');
   return patternboard;
}

//Builds Pinwheel pattern and returns pattern
Board buildPinwheel(){
   Board patternboard(12,12);
   Cell* tempCell;
   int rootRow = 4;
   int rootCol = 0;
   for (int i = rootRow; i < rootRow + 2; i++){
      for (int j = rootCol; j < rootCol + 2; j++){
	 tempCell = &patternboard.getCell(i,j);
	 tempCell->setLifeStatus(1);
      }
   }
   rootRow = 0;
   rootCol = 6;
   for (int i = rootRow; i < rootRow + 2; i++){
      for (int j = rootCol; j < rootCol + 2; j++){
	 tempCell = &patternboard.getCell(i,j);
	 tempCell->setLifeStatus(1);
      }
   } 
   rootRow = 10;
   rootCol = 4;
   for (int i = rootRow; i < rootRow + 2; i++){
      for (int j = rootCol; j < rootCol + 2; j++){
	 tempCell = &patternboard.getCell(i,j);
	 tempCell->setLifeStatus(1);
      }
   }
   rootRow = 6;
   rootCol = 10;
   for (int i = rootRow; i < rootRow + 2; i++){
      for (int j = rootCol; j < rootCol + 2; j++){
	 tempCell = &patternboard.getCell(i,j);
	 tempCell->setLifeStatus(1);
      }
   }
   rootRow = 3;
   rootCol = 4;
   for (int j = 0; j < 4; j++){
	 tempCell = &patternboard.getCell(rootRow,rootCol + j);
	 tempCell->setLifeStatus(1);
   }
   rootRow = 8;
   rootCol = 4;
   for (int j = 0; j < 4; j++){
	 tempCell = &patternboard.getCell(rootRow,rootCol + j);
	 tempCell->setLifeStatus(1);
   }
   rootRow = 4;
   rootCol = 3;
   for (int i = 0; i < 4; i++){
	 tempCell = &patternboard.getCell(rootRow + i,rootCol);
	 tempCell->setLifeStatus(1);
   }
   rootRow = 4;
   rootCol = 8;
   for (int i = 0; i < 4; i++){
	 tempCell = &patternboard.getCell(rootRow + i,rootCol);
	 tempCell->setLifeStatus(1);
   }
   tempCell = &patternboard.getCell(5,6);
   tempCell->setLifeStatus(1);
   tempCell = &patternboard.getCell(6,7);
   tempCell->setLifeStatus(1);
   tempCell = &patternboard.getCell(7,5);
   tempCell->setLifeStatus(1);

   tempCell = NULL;
   //Displays pattern prior to returning
   viewBoard(patternboard);
   cout << "Press enter to continue.";
   cin.ignore(100,'\n');
   return patternboard;
}

//Builds Pulsar pattern and returns pattern
Board buildPulsar(){
   Board patternboard(13,13);
   Cell* tempCell;
   for (int h = 0; h < 6; h += 5){ 
      for (int i = 0; i < 7; i += 6){
	 for (int j = 0; j < 8; j += 7){
	    for (int k = 2; k < 5; k ++){
	       tempCell = &patternboard.getCell(h + j,k + i);
	       tempCell->setLifeStatus(1);
	    }
	 }
      }
   }
   for (int h = 0; h < 6; h += 5){
      for (int i = 0; i < 7; i += 6){
	 for (int j = 0; j < 8; j += 7){
	    for (int k = 2; k < 5; k ++){
	       tempCell = &patternboard.getCell(k + i, j + h);
	       tempCell->setLifeStatus(1);
	    }
	 }
      }
   }
   //Displays pattern prior to returning
   viewBoard(patternboard);
   cout << "Press enter to continue.";
   cin.ignore(100,'\n');
   return patternboard;
}

//Outputs lifeStatus of each cell in the form of a numbered grid to console
void viewBoard(Board& gameboard){

   int size = gameboard.getBoardSize();

   clearScreen();
   //Outputs 10's value for reference along x axis
   for (int i = 0; i <= gameboard.getBoardWidth() - 2*size; i++){
      if (i % 10 == 0)
	 cout << i / 10;
      else
	 cout << " ";
   }
   cout << endl;
   //Outputs 1's value for reference along x axis
   for(int i = 0; i <= gameboard.getBoardWidth() - 2*size; i++){
      cout << i % 10;
   }
   cout << endl;
   //Outputs 1's value for reference along y axis followed by lifeStatus of row
   for(int i = 1; i <= gameboard.getBoardHeight() - 2*size; i++){
      cout << i % 10;
      for (int j = 0 + size; j < gameboard.getBoardWidth() - size; j++){
	 if (gameboard.getCell(i - 1 + size,j).getLifeStatus() == 0){
	    cout << "-";
	 } else {
	    cout << "0";
	 }
      }
      cout << endl;
   }
   return;
}

//Applies Conways rules to gameboard by checking lifeStatus of each cell and
//lifeStatus of neighbor cells to determine if the cell lives or dies
void runGame(Board& gameboard){
   string tempStr;
   int turns = 0;
   static int turnsRun = 0;
   do{
      clearScreen();
      //Shows current lifeStatus of board
      viewBoard(gameboard);
      cout << endl;
      cout << "How many turns would you like the simulation to run?\n"
	   << "Type \"stop\" or \"quit\" to stop current run. ";
      //Gets user input number of life cycles to run
      tempStr = getInput();
      if (isdigit(tempStr[0])){
         turns = atoi(tempStr.c_str());
      } else if (tempStr == "quit" ||
	         tempStr == "stop") {
	 break;
      } else {
	 cout << "Invalid entry. Press enter to try again.";
	 cin.ignore(100,'\n');
      }
      //For user input number of life cycles, apply the rules
      for (int i = 0; i < turns; i++){
	 //holdTime to pause between frames
	 int holdTime = time(NULL);
	 //Applies rules and stores outcomes as nextLifeStatus for each cell
	 findNextLifeStatus(gameboard);
	 //Makes lifeStatus of each cell equal to nextLifeStatus (1 life cycle)
	 updateLifeStatus(gameboard);
	 //Outputs current lifeStatus of board
	 viewBoard(gameboard);
	 cout << "Turn: " << turnsRun << endl;
	 //Pauses for up to 1 second between life cycle frames
	 pauseOneSec(holdTime);
	 turnsRun++;
      }
      cout << "Turns left: " << turns;
   }while (tempStr != "stop" && tempStr != "quit");
   
   return;
}

//Checks board to ensure there is enough space to accomodate cell growth
//outside the viewable world
bool checkBoardSize(Board& gameboard){

   //If there is a cell on the row 0 border, return true
   for (int cols = 0; cols < gameboard.getBoardWidth(); cols++){
      if(gameboard.getCell(0,cols).getLifeStatus() ||
	 gameboard.getCell(0,cols).getNextLifeStatus()){
      return true;
      }
   }

   //If there is a cell on the bottom row, return true
   for (int cols = 0; cols < gameboard.getBoardWidth(); cols++){
      if(gameboard.getCell(gameboard.getBoardHeight()-1, cols).getLifeStatus() ||
	 gameboard.getCell(gameboard.getBoardHeight()-1, cols).getNextLifeStatus()){
      return true;
      }
   }
   
   //If there is a cell in the column 0 border, return true
   for (int rows = 0; rows < gameboard.getBoardHeight(); rows++){
      if (gameboard.getCell(rows, 0).getLifeStatus() ||
	  gameboard.getCell(rows, 0).getNextLifeStatus()){
      return true;
      }
   }
   //If there is a cell in the far right border, return true
   for (int rows = 0; rows < gameboard.getBoardHeight(); rows++){
      if (gameboard.getCell(rows, gameboard.getBoardWidth() - 1).getLifeStatus() ||
	  gameboard.getCell(rows, gameboard.getBoardWidth() - 1).getNextLifeStatus()){
      return true;
      }
   }
   //If no cells are on a border, return false
   return false;
}

//Cycles through all cells, checks the number of living neighbors, and updates
//nextLifeStatus for each cell based on Conway's rules
void findNextLifeStatus(Board& gameboard){
   Cell* temp;

   //Count of living neighbors for each cell
   int lifeCount;

   //celli and cell j represent the middle cell to whom the neighbors belong
   for (int celli = 0; celli < gameboard.getBoardHeight(); celli++){
      for (int cellj = 0; cellj < gameboard.getBoardWidth(); cellj++){
	 lifeCount = 0;
	 //Prior to checking neighbors, check board size and resize if needed
	 if (checkBoardSize(gameboard)){
	    gameboard.increaseBoardSize();
	 }

	 //Check all neighboring cells, edge conditions included
	 for (int i = celli - 1; i <= celli + 1; i++){
	    for(int j = cellj - 1; j <= cellj + 1; j++){
	       if (i < 0 || 
		   j < 0 || 
		   i >= gameboard.getBoardHeight() || 
		   j >= gameboard.getBoardWidth()){
		  continue;
	       } else if (i == celli && j == cellj) {
		  continue;
	       } else {
		  //Counts living neighbors
	          temp = &gameboard.getCell(i,j);
	 	  lifeCount += temp->getLifeStatus();

	       }
	    }
	 }
	 //Points to (celli,cellj) (i.e. center cell)
	 temp = &gameboard.getCell(celli, cellj);
	 //Applies Conway's rules explicitly
	 //If cell is currently alive...
	 if (temp->getLifeStatus() == 1){
	    //...and has less than 2 neighbors it dies.
	    if (lifeCount < 2) {
	       temp->setNextLifeStatus(0);
	    //...and has 2 or 3 neighbors it lives on.
	    } else if (lifeCount == 2 ||
		       lifeCount == 3){
	       temp->setNextLifeStatus(1);
	    //...and has more than 3 neighbors it dies.
	    } else {
	       temp->setNextLifeStatus(0);
	    }
	 //If cell is currently dead...
	 } else {
	    //...and has exactly 3 neighbors it is birthed.
	    if (lifeCount == 3) {
	       temp->setNextLifeStatus(1);
	    //...and has less than 3 neighbors it stays dead.
	    } else if (lifeCount < 3) {
	       temp->setNextLifeStatus(0);
	    //...else it has more than 3 neighbors and stays dead.
	    } else {
	       temp->setNextLifeStatus(0);
	    }
	 }
      }
   }
   temp = NULL;
   return;
}

//Updates the lifeStatus state of every cell to match it's nextLifeStatus
void updateLifeStatus(Board& gameboard){
   Cell* temp;
   //Cycles through each cell and sets lifeStatus equal to nextLifeStatus
   for (int i = 0; i < gameboard.getBoardHeight(); i++){
      for (int j = 0; j < gameboard.getBoardWidth(); j++){
	 temp = &gameboard.getCell(i,j);
	 temp->setLifeStatus(temp->getNextLifeStatus());
      }
   }
   temp = NULL;
   return;
}

//Holds in do/while loop until current time moves beyond holdTime
void pauseOneSec(int holdTime){
   do{
   //Holds in current loop until current time exceeds hold time
   }while (holdTime == time(NULL));
   return;
}
