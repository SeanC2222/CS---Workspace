/* Author: Sean C Mulholland
 * Date: 2/11/15
 * Description: This is a simple combat demo between a select few
 *	 types of fantasy creatures. The user can view info about each
 *	 creature, or run through a combat scenario between two creatures.
 * Pre-Compile Conditions: Must have dice.h, dice.cpp
 *				     creature.h, creature.cpp
 *				     barbarian.h, barbarian.cpp
 *				     goblin.h, goblin.cpp
 *				     reptile.h, reptile.cpp
 *				     blueman.h, blueman.cpp
 *				     shadow.h, shadow.cpp
 *			   in compile directory.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include <stack>

#include "dice.h"
#include "creature.h"
#include "barbarian.h"
#include "goblin.h"
#include "reptile.h"
#include "blueman.h"
#include "shadow.h"

/* Function: void ClearScreen() 
 * Description: Ouputs 100 blank lines effectively clearing the console.
 * Pre-Conditions: None.
 * Post-Conditions: Blank viewable console screen.
 */
void clearScreen();

/* Function: void displayIntro()
 * Description: Displays the intro to the program explaining the program.
 * Pre-Conditions: None.
 * Post-Conditions: Outputs program intro to console.
 */
void displayIntro();

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

/* Function: void startcreatureCombat(std::string) 
 * Description: Calls the function that the user selected from start menu.
 * Pre-Conditions: User has been prompted the start menu, and a choice has been
 *	           input. Formatted string is passed into function.
 * Post-Conditions: None.
 */
void callStartMenuChoice(std::string);

/* Function: void creatureCombat()
 * Description: Starts the combat Demo option of the program. Asks user for
 *	        their choice of creatures to battle.
 * Pre-Conditions: None.
 * Post-Conditions: None.
 */
void creatureCombat();

/* Function: void charSelection(Creature*&)
 * Description: Show's user choice of creature types to create. 
 * Pre-Conditions: Creature* has been created and passed to function.
 * Post-Conditions: User selected creature type is assigned to Creature*.
 */
void charSelection(Creature*&);

/* Function: void charCreation(Creature*&, std::string);
 * Description: Get's the user's character type selection, and assigns it to 
 *	        pointer reference passed to function.
 * Pre-Conditions: User has been prompted for their selection choice, and 
 *		   choice is passed to function.
 * Post-Conditions: Appropriate character type is assigned to Creature*.
 */
void charCreation(Creature*&, std::string);

/* Function: int combat(Creature*&, Creature*&)
 * Description: Combat simulation of two Creatures.
 * Pre-Conditions: 2 Creature*'s initialized and passed to function.
 * Post-Conditions: Returns 1 or 2 for winning team #
 */
Creature* combat(Creature*, Creature*);

/* Function: void creatureCombatEvent(Creature*&, Creature*&) 
 * Description: Creature attack phase. Firse creature attacks second creature.
 * Pre-Conditions: 2 Creature*'s initialized and passed to function.
 * Post-Conditions: None.
 */
void creatureCombatEvent(Creature*&, Creature*&);

/* Function: void viewCreatureInfo() 
 * Description: Allows the user to see the stats of the separate creature types.
 * Pre-Conditions: None.
 * Post-Conditions: None.
 */
void viewCreatureInfo();

/* Function: std::queue<Creature*> buildTeam 
 * Description: builds a queue of Creature* objects to battle as teams.
 * Pre-Conditions: declared queue being assigned return value
 * Post-Conditions: returns built team
 */
std::queue<Creature*> buildTeam(int,int);

/* Function: void autoCombat(std::queue<Creature*>,std::queue<Creature*>,int&) 
 * Description: Battles the two teams of creatures against one another.
 * Pre-Conditions: Two evenly built queues of instanciated Creature*s
 * Post-Conditions: Winner in combat is declared and function returns
 */
void autoCombat(std::queue<Creature*>, std::queue<Creature*>, int&);

int main() {

   std::string choice;

   clearScreen();
   displayIntro();
   std::cin.ignore(100,'\n');

   do{
      srand(time(NULL));
      clearScreen();
      displayMenu();
      choice = getChoice();
      callStartMenuChoice(choice);
   } while (choice != "quit" && choice != "3");


   return 0;
}

void clearScreen(){
   for(int i = 0; i < 100; i++){
      std::cout << "\n";
   }
   return;
}

void displayIntro(){

   std::cout << "Welcome to Creature Combat.\n\n"
	     << "Two players will create their team and battle it out in the arena.\n"
	     << "The users will select the number of creatures for each team\n"
	     << "and then build their teams. The battle is a game of chance built\n"
	     << "on a dice system so character selection is key.\n\n"
	     << "Let the games begin!\n" << std::endl;
   return;
}

void displayMenu(){

   std::cout << "Creature Combat \n\n"
	     << "1) Start Combat\n"
	     << "2) View Creature Info\n"
	     << "3) Quit\n"
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

void callStartMenuChoice(std::string c){
   //Calls Combat
   if (c == "1" || c == "start"){
      clearScreen();
      creatureCombat();
   //Calls Creature information
   } else if (c == "2" || c == "view" || 
	      c == "viewcreature" || c == "viewcreatureinfo"){
      clearScreen();
      viewCreatureInfo();
   //Quits program
   } else if (c == "3" || c == "quit"){
      return;
   //Notifies user of invalid entry
   } else {
      std::cout << "Invalid choice. Try Again." << std::endl;
   }
   return;
}

void creatureCombat(){

   std::cout << "How many creatures would you like to battle? ";

   int creatureCount = 0;

   do{
      creatureCount = atoi(getChoice().c_str());
   } while (creatureCount <= 0);

   std::string choice;

   //Team1
   std::queue<Creature*> team1;
   team1 = buildTeam(1, creatureCount);
   clearScreen();

   //Team2
   std::queue<Creature*> team2;
   team2 = buildTeam(2, creatureCount);
   clearScreen();

   autoCombat(team1, team2, creatureCount);

   std::cin.ignore(100,'\n');
   
   return;
}

std::queue<Creature*> buildTeam(int teamNum, int creatureCount){

   //Queue representing creature team
   std::queue<Creature*> team;
   //User Choice
   std::string choice;
   //Creates temp Creature*
   Creature* temp;

   do{
      //If team has size, deallocate memory and pop front index
      while(team.size() != 0){
	 delete team.front();
	 team.pop();
      }

      //For Creature Count, get creature choice and assign team number
      for (int i = 0; i < creatureCount; i++){
	 clearScreen();
	 std::cout << "Team " << teamNum << ", Creature " << i+1 << ":\n";
	 //Assigns new creature to temp
	 charSelection(temp);
	 //Assigns team number to creature
	 temp->setTeam(teamNum);
	 //Adds creature to team
	 team.push(temp);
      }

      clearScreen();

      std::cout << "Team " << teamNum << ":\n" << std::endl;
      //Output names of all team's creatures
      for (int i = 0; i < creatureCount; i++){
	 std::cout << i+1 << ") " << team.front()->getCreatureName() << std::endl;
	 //Adds copy of Creature* at end of team
	 team.emplace(team.front());
	 //Removes index at front of team
	 team.pop();
      }

      //Validates user wants team as defined
      std::cout << "Is this the team you want to battle? ";
      choice = getChoice();


   }while (choice != "y" && choice != "yes");
   //Returns team
   return team;
}

void autoCombat(std::queue<Creature*> team1, std::queue<Creature*> team2, int& creatureCount){
   //Counter for team's points
   int* teamPoints = new int[2];
   teamPoints[0] = 0;
   teamPoints[1] = 0;
   //Counter for fight number
   int fight = 0;
   //Point value
   int points = 1;

   //In function Creature*
   Creature* temp;
   //Holds Creature* in order of death (creature on top is higher rank)
   std::stack<Creature*> rankings;

   do{
      //Increment fight counter
      fight++;
      std::cout << "Fight number " << fight << std::endl;
      //Adds loser to rankings
      rankings.push(combat(team1.front(), team2.front()));
      //If the newest creature in rankings is on team 1, remove from team 1
      if(rankings.top() == team1.front()){
	 //Add points to team 2's counter
	 std::cout << "Point to team 2!\n" << std::endl;
	 teamPoints[1] += points;
	 //Remove from team 1
	 team1.pop();
	 //Rotate winner to back of team 2
	 team2.front()->replenishHealth();
	 team2.emplace(team2.front());
	 team2.pop();
      //Else newest creature in rankings is on team 2, remove from team 2
      } else {
	 //Adds points to team 1's counter
	 std::cout << "Point to team 1!\n" << std::endl;
	 teamPoints[0] += points;
	 //Remove from team 2
	 team2.pop();
	 //Rotates winner to back of team 1
	 team1.front()->replenishHealth();
	 team1.emplace(team1.front());
	 team1.pop();
      }
      //First cycle through creatures, points = 1, second cycle points = 2
      if(fight == creatureCount){
	 points++;
	 creatureCount--;
      }
   //Battle lasts as long as teams have creatures
   } while (team1.size() && team2.size());

   //If team 1 wins with more than 1 creature left, battle each other until
   //ranking is determined
   while (team1.size() > 1){
      temp = team1.front();
      team1.pop();
      rankings.push(combat(temp, team1.front()));
      if (rankings.top() == team1.front()){
	 team1.emplace(temp);
	 team1.pop();
      }
   }
   
   //When Team1 only has 1 creature left, add it to rankings and remove from
   //team 1
   if (team1.size() == 1){
      rankings.push(team1.front());
      team1.pop();
   }

   //If team2 wins with more than 1 creature left, battle each other until
   //ranking is determined
   while (team2.size() > 1){
      temp = team2.front();
      team2.pop();
      rankings.push(combat(temp, team2.front()));
      if (rankings.top() == team2.front()){
	 team2.emplace(temp);
	 team2.pop();
      }
   }
   //When Team 2 only has 1 creature left, add it to rankings and remove from
   //team 2
   if (team2.size() == 1){
      rankings.push(team2.front());
      team2.pop();
   }

   //Output Winner's rank
   int rank = 0;

   //While rankings has creatures
   while (rankings.size() > 0){
      //Output the first 3 creatures as ranked
      if (rank <= 2)
	 std::cout << ++rank << ") " << rankings.top()->getCreatureName() 
		   << " Team " << rankings.top()->getTeam() << std::endl;
      //Deallocates Creature instance
      delete rankings.top();
      //Pops top of rankings
      rankings.pop();
   }

   //Display team points
   std::cout << "Team 1 Victory Points: " << teamPoints[0] << "\t" 
	     << "Team 2 Victory Points: " << teamPoints[1] << std::endl;

   //Declare the winner
   if (teamPoints[0] > teamPoints[1]){
      std::cout << "Team 1 wins!" << std::endl;
   } else {
      std::cout << "Team 2 wins!" << std::endl;
   }

   //Frees Memory
   delete [] teamPoints;

   return;
}


void charSelection(Creature* &c){

   std::cout << "Select your creature:\n\n"
	     << "1) Barbarian\n"
	     << "2) Goblin\n"
	     << "3) Reptile Person\n"
	     << "4) Blue Man\n"
	     << "5) The Shadow\n";
   //Gets user input
   std::string choice = getChoice();
   //Creates a creature in c
   charCreation(c, choice);

   return;
}

void charCreation(Creature* &c, std::string choice){
   //Creates Barbarian in c
   if (choice == "1" || choice == "barbarian"){
      c = new Barbarian();
   //Creates Goblin in c
   } else if (choice == "2" || choice == "goblin"){
      c = new Goblin();
   //Creates Reptile in c
   } else if (choice == "3" || choice == "reptileperson"){
      c = new Reptile();
   //Creates BlueMan in c
   } else if (choice == "4" || choice == "blueman"){
      c = new BlueMan();
   //Creates The Shadow in c
   } else if (choice == "5" || choice == "theshadow" || choice == "shadow"){
      c = new Shadow();
   //Tells user their choice was invalid.
   } else {
      std::cout << "Invalid choice. Try again.\n";
      std::cin.ignore(100,'\n');
      //Recursively calls character selection for c
      charSelection(c);
   }

   return;
}

void viewCreatureInfo(){

   std::cout << "Viewing Character Info:\n\n";
   //Temporary Character to view stats
   Creature* charTemp;
   charSelection(charTemp);
   clearScreen();
   //If the character is the Shadow, display special Armor properties.
   if (charTemp->getCreatureName() == "The Shadow"){
      std::cout << "Armor: 0" << std::endl;
      std::cout << "50% of the time The Shadow is someplace else and "
	        << "recieves no damage." << std::endl;
   //Else display armor properties
   } else {
      std::cout << "Armor: " << charTemp->getArmor() << std::endl;
   }
   //Displays Character Traites
   std::cout << "Strength: " << charTemp->getHealth() << std::endl;
   std::cout << "Attack: " << charTemp->getAttackInfo() << std::endl;
   std::cout << "Defense: " << charTemp->getDefenseInfo() << std:: endl;
   std::cout << "Press enter to continue..." << std::endl;
   std::cin.ignore(100,'\n');
   delete charTemp;
   return;
}

Creature* combat(Creature* Char1, Creature* Char2){


   //Simulates a coin flip to start
   int flip = rand() % 2 + 1;

   //If Creature 2 wins coin toss, assign them to Char1 so they attack first
   if (flip == 2){
	 Creature* temp;
	 temp = Char1;
	 Char1 = Char2;
	 Char2 = temp;
	 temp = NULL;
   }

   //Combat Round Counter
   int counter = 1;

   do {

      //Creature Char1 attacks Char2
      creatureCombatEvent(Char1, Char2);

      //If Char2 is alive, Char2 attacks Char1
      if (Char2->getHealth() > 0){

	 creatureCombatEvent(Char2, Char1);
      //Else Char2 is not alive, and user is notified
      } else {

	 std::cout << Char2->getCreatureName() << " has been vanquished!"
		   << std::endl;
      }
      //If Char1 dies in Char2's counter attack, user is notified
      if (Char1->getHealth() <= 0){

	 std::cout << Char1->getCreatureName() << " has been vanquished!"
		    << std::endl;
      }

      counter++;
   //Run Simulation while both creatures are alive
   } while (Char1->getHealth() > 0 && Char2->getHealth() >0);
   
   std::cout << "COMBAT OVER!" << std::endl;
   std::cin.ignore(100,'\n');

   //Returns winning team 
   if (Char2->getHealth() > 0) {
      return Char1;
   } else {
      return Char2;
   }
}

void creatureCombatEvent(Creature* &Char1, Creature* &Char2){
   //Get Attack value from Char1
   int attack = Char1->getAttack();
   //If Char1 is a goblin, and Char2 is not a goblin, and Char1's attack is 12
   //the special Achilles modifier is triggered
   if (Char1->getCreatureName() == "Goblin" && 
       Char2->getCreatureName() != "Goblin" && 
       attack == 12){
   
      Char2->modifyAttackMod();
   }
   //Gets Defense from Char2
   int defense = Char2->getDefense();
   //Imparts damage to Char2
   Char2->modifyHealth(attack, defense);
   return;
}
