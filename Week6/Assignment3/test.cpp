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

void clearScreen();
void displayIntro();
void displayMenu();
std::string getChoice();
void startCombatDemo(std::string);

void combatDemo();
void charSelection(Creature*&);
void charCreation(Creature*&, std::string);
void combat(Creature*&, Creature*&);
void creatureCombatEvent(Creature*&, Creature*&);
void viewCreatureInfo();

int main() {
   
   srand(time(NULL));
   std::string choice;

   displayIntro();

   do{
      clearScreen();
      displayMenu();
      choice = getChoice();
      startCombatDemo(choice);
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
   std::string choice;

   std::getline(std::cin, choice);
   std::cout << choice << std::endl;
   for (unsigned i = 0; i < choice.length(); i++){
      choice[i] = tolower(choice.at(i));
      if (choice.at(i) == ' '){
	 choice.erase(choice.begin() + i);
	 i--;
      }
   }
   return choice;
}

void startCombatDemo(std::string c){

   if (c == "1" || c == "start"){
      combatDemo();
   } else if (c == "2" || c == "view" || 
	      c == "viewcreature" || c == "viewcreatureinfo"){
      viewCreatureInfo();
   } else if (c == "3" || c == "quit"){
      return;
   } else {
      std::cout << "Invalid choice. Try Again." << std::endl;
   }
   return;
}

void combatDemo(){

   clearScreen();

   Creature* Char1;
   std::cout << "Creature 1:\n";
   charSelection(Char1);

   clearScreen();

   Creature* Char2;
   std::cout << "Creature 2:\n";
   charSelection(Char2);

   combat(Char1, Char2);

   delete Char1;
   delete Char2;
}

void charSelection(Creature* &c){

   std::cout << "Select your creature:\n\n"
	     << "1) Barbarian\n"
	     << "2) Goblin\n"
	     << "3) Reptile Person\n"
	     << "4) Blue Man\n"
	     << "5) The Shadow\n";

   std::string choice = getChoice();

   charCreation(c, choice);

   return;
}

void charCreation(Creature* &c, std::string choice){

   if (choice == "1" || choice == "barbarian"){
      c = new Barbarian();
   } else if (choice == "2" || choice == "goblin"){
      c = new Goblin();
   } else if (choice == "3" || choice == "reptileperson"){
      c = new Reptile();
   } else if (choice == "4" || choice == "blueman"){
      c = new BlueMan();
   } else if (choice == "5" || choice == "theshadow" || choice == "shadow"){
      c = new Shadow();
   } else {
      std::cout << "Invalid choice. Try again.\n";
      std::cin.ignore(100,'\n');
      charSelection(c);
   }

   return;
}

void viewCreatureInfo(){

   std::cout << "Viewing Character Info:\n\n";

   Creature* charTemp;
   charSelection(charTemp);

   std::cout << "Armor: " << charTemp->getArmor() << std::endl;
   if (charTemp->getCreatureName() == "The Shadow"){
      std::cout << "50% of the time The Shadow is someplace else and "
	        << "recieves no damage." << std::endl;
   }
   std::cout << "Strength: " << charTemp->getHealth() << std::endl;
   std::cout << "Attack: " << charTemp->getAttackInfo() << std::endl;
   std::cout << "Defense: " << charTemp->getDefenseInfo() << std:: endl;
   std::cout << "Press enter to continue..." << std::endl;
   std::cin.ignore(100,'\n');
   return;
}

void combat(Creature* &Char1, Creature* &Char2){

   clearScreen();

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

   if (flip == 2){
	 Creature* temp;
	 temp = Char1;
	 Char1 = Char2;
	 Char2 = temp;
   }

   int counter = 1;

   do {

      clearScreen();

      std::cout << "Round " << counter << ": \n";
      std::cout << Char1->getCreatureName() <<  " 1:"
	        << "			     "
	        << Char2->getCreatureName() << " 2:\n"
	        << "Health: " << Char1->getHealth()
	        << "			     Health: " << Char2->getHealth()
	        << std::endl << std::endl;

      creatureCombatEvent(Char1, Char2);

      if (Char2->getHealth() > 0){

	 creatureCombatEvent(Char2, Char1);

      } else {

	 std::cout << std::endl;
	 std::cout << Char2->getCreatureName() << " has been vanquished!"
		   << std::endl;
      }
      
      if (Char1->getHealth() <= 0){

	 std::cout << std::endl;
	 std::cout << Char1->getCreatureName() << " has been vanquished!"
		    << std::endl;
      }

      counter++;

   } while (Char1->getHealth() > 0 && Char2->getHealth() >0);

   std::cout << "COMBAT OVER!" << std::endl;
   std::cin.ignore(100,'\n');
   return;
}

void creatureCombatEvent(Creature* &Char1, Creature* &Char2){

   int attack = Char1->getAttack();
   std::cout << "Attack by " << Char1->getCreatureName() << ": "
	     << attack << std::endl;;
   if (Char1->getCreatureName() == "Goblin" && 
       Char2->getCreatureName() != "Goblin" && 
       attack == 12){
   
      std::cout << "Achilles tendon injured! " << Char2->getCreatureName() 
	        << " attack halved for the rest of combat!" << std::endl;
      Char2->modifyAttackMod();
   }
   std::cin.ignore(100,'\n');

   int defense = Char2->getDefense();
   std::cout << "Defense by " << Char2->getCreatureName() << ": "
	     << defense;
   std::cin.ignore(100,'\n');

   int damageDone = Char2->modifyHealth(attack, defense);
   std::cout << "Damage done to " << Char2->getCreatureName() << ": "
	     << damageDone;
   std::cin.ignore(100,'\n');

   std::cout << std::endl;
   return;
}
