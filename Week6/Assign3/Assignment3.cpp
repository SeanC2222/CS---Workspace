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

/* Function: void startCombatDemo(std::string) 
 * Description: Calls the function that the user selected from start menu.
 * Pre-Conditions: User has been prompted the start menu, and a choice has been
 *	           input. Formatted string is passed into function.
 * Post-Conditions: None.
 */
void callStartMenuChoice(std::string);

/* Function: void combatDemo()
 * Description: Starts the combat Demo option of the program. Asks user for
 *	        their choice of creatures to battle.
 * Pre-Conditions: None.
 * Post-Conditions: None.
 */
void combatDemo();

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

/* Function: void combat(Creature*&, Creature*&)
 * Description: Combat simulation of two Creatures.
 * Pre-Conditions: 2 Creature*'s initialized and passed to function.
 * Post-Conditions: None.
 */
void combat(Creature*&, Creature*&);

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


int main() {

   //seeds random
   srand(time(NULL));
   std::string choice;

   displayIntro();
   std::cin.ignore(100,'\n');
   do{
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

   std::cout << "Welcome to the Creature Combat Demo.\n\n"
	     << "This program will demonstrate a simple dice based\n"
	     << "combat system between several types of creatures.\n";
   return;
}

void displayMenu(){

   std::cout << "Creature Combat [DEMO]\n\n"
	     << "1) Start 1 v 1 Combat\n"
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
      combatDemo();
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

void combatDemo(){
   //Creates Creature 1
   Creature* Char1;
   std::cout << "Creature 1:\n";
   charSelection(Char1);

   clearScreen();

   //Creates Creature 2
   Creature* Char2;
   std::cout << "Creature 2:\n";
   charSelection(Char2);
   //Starts Combat between Creatures
   combat(Char1, Char2);

   //Frees memory
   delete Char1;
   delete Char2;
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
   return;
}

void combat(Creature* &Char1, Creature* &Char2){

   clearScreen();
   //Simulates a coin flip to start
   std::cout << "Coin flip to start!" << std::endl;
   int flip = rand() % 2 + 1;

   if (flip == 1){
      std::cout << "  _____  " << std::endl;
      std::cout << " /     \\" << std::endl;
      std::cout << "  Char1  " << std::endl;
      std::cout << " \\_____/" << std::endl;
   } else {
      std::cout << "  _____  " << std::endl;
      std::cout << " /     \\" << std::endl;
      std::cout << "  Char2  " << std::endl;
      std::cout << " \\____/ " << std::endl;
   }
   std::cin.ignore(100,'\n');
   //If Creature 2 wins coin toss, assign them to Char1 so they attack first
   if (flip == 2){
	 Creature* temp;
	 temp = Char1;
	 Char1 = Char2;
	 Char2 = temp;
   }

   //Combat Round Counter
   int counter = 1;

   do {

      clearScreen();
      //Outputs Creature 1 and 2 information
      std::cout << "Round " << counter << ": \n";
      std::cout << Char1->getCreatureName() <<  " 1:"
	        << "			     "
	        << Char2->getCreatureName() << " 2:\n"
	        << "Health: " << Char1->getHealth()
	        << "			     Health: " << Char2->getHealth()
	        << std::endl << std::endl;
      //Creature Char1 attacks Char2
      creatureCombatEvent(Char1, Char2);
      //If Char2 is alive, Char2 attacks Char1
      if (Char2->getHealth() > 0){

	 creatureCombatEvent(Char2, Char1);
      //Else Char2 is not alive, and user is notified
      } else {

	 std::cout << std::endl;
	 std::cout << Char2->getCreatureName() << " has been vanquished!"
		   << std::endl;
      }
      //If Char1 dies in Char2's counter attack, user is notified
      if (Char1->getHealth() <= 0){

	 std::cout << std::endl;
	 std::cout << Char1->getCreatureName() << " has been vanquished!"
		    << std::endl;
      }

      counter++;
   //Run Simulation while both creatures are alive
   } while (Char1->getHealth() > 0 && Char2->getHealth() >0);
   
   std::cout << "COMBAT OVER!" << std::endl;
   std::cin.ignore(100,'\n');
   return;
}

void creatureCombatEvent(Creature* &Char1, Creature* &Char2){
   //Get Attack value from Char1
   int attack = Char1->getAttack();
   std::cout << "Attack by " << Char1->getCreatureName() << ": "
	     << attack << std::endl;;
   //If Char1 is a goblin, and Char2 is not a goblin, and Char1's attack is 12
   //the special Achilles modifier is triggered
   if (Char1->getCreatureName() == "Goblin" && 
       Char2->getCreatureName() != "Goblin" && 
       attack == 12){
   
      std::cout << "Achilles tendon injured! " << Char2->getCreatureName() 
	        << " attack halved for the rest of combat!" << std::endl;
      Char2->modifyAttackMod();
   }
   std::cin.ignore(100,'\n');

   //Gets Defense from Char2
   int defense = Char2->getDefense();
   std::cout << "Defense by " << Char2->getCreatureName() << ": "
	     << defense;
   std::cin.ignore(100,'\n');

   //Imparts damage to Char2
   int damageDone = Char2->modifyHealth(attack, defense);
   std::cout << "Damage done to " << Char2->getCreatureName() << ": "
	     << damageDone;
   std::cin.ignore(100,'\n');

   std::cout << std::endl;
   return;
}
