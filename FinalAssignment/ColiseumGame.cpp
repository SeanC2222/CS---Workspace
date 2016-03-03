#include <iostream>
#include <cstdlib>
#include <ctime>

#include "coliseum.h"
#include "creature.h"
#include "gladiator.h"
#include "barbarian.h"
#include "creatiger.h"
#include "creaspike.h"
#include "item.h"
#include "sword.h"
#include "shield.h"

void clearScreen() {for (int i = 0; i < 120; i++){ std::cout << std::endl;}}

bool displayGameInfo();
void displayCharaInfo(Creature*);
bool checkCharaStatus(Creature*);
void displayRoomInfo(Coliseum*, Creature*);
void trapDamage(Coliseum*, Creature*);
void displayActionChoices(Coliseum*, Creature*);
int performAction(Coliseum*,int,Creature*);
void retrieveItemFromGround(Coliseum*, Creature*);
void dropItemFromInventory(Coliseum*,Creature*);
void viewCharacterInventory(Creature*);
std::string getChoice();
void moveCharacter(Coliseum*);
void randomBattle(Creature*);
Creature* combat(Creature*, Creature*);
int gladiatorCombatEvent(Creature*,Creature*);


int main(){
   //Seeds random for game instance
   srand(time(NULL));
   clearScreen();
   bool gMode = displayGameInfo();
   //Creates Character
   Creature* chara;

   if (gMode){
      chara = new Gladiator(1000);
   } else {
      chara = new Gladiator;
   }

   //Creates Coliseum
   Coliseum* board;
   board = new Coliseum;

   //User choice
   std::string choice = "";

   //Victory Condition Trigger
   int victoryCondition = -1;

   //Game Loop   
   do{

      //Resets victory condition
      victoryCondition = 0;
      clearScreen();

      //Updates player on Room info
      displayRoomInfo(board, chara);

      //If player is in a trap, update player and update character
      trapDamage(board,chara);

      //Check if player is dead
      if(!checkCharaStatus(chara)){
         break;
      }

      //Display current health
      displayCharaInfo(chara);

      //Display action options
      displayActionChoices(board, chara);

      //Gets player action
      choice = getChoice();
      if (atoi(choice.c_str())){

	 //Executes player action choice and stores in victoryCondition
    	 victoryCondition = performAction(board, atoi(choice.c_str()), chara);
      } else if (choice == "quit"){
	 break;
      } else {
    	 std::cout << "You can't do that." << std::endl;
      }

      //If player moved during turn, trigger possible random battle
      if (victoryCondition == 2){
    	  randomBattle(chara);
      }
      std::cin.ignore(100,'\n');
   }while(choice != "quit" && victoryCondition != 6);

   delete board;
   delete chara;

   return 0;
}

bool displayGameInfo(){

   std::cout << "Welcome to the Coliseum!!!\n\n"
	     << "Only the mightiest of warriors can brave the sands and return to the\n"
	     << "Coliseum's gate with the Hero's Sash! Traps and Barbarians riddle the\n"
	     << "sands, and loot from fallen warriors before you may be found!\n"
	     << "Only one question remains.....\n\n"
	     << "Are you ready??? [Type \'I\' to start with 1000 HP] ";
   std::string choice = getChoice();

   if (choice == "i"){
      return true;
   } else {
      return false;
   }
}

void displayCharaInfo(Creature* chara){
   std::cout << "\t\t" << "Gladiator Health: " << chara->getHealth() << std::endl;
   return;
}

bool checkCharaStatus(Creature* chara){
   //If character is dead, return false
   if(chara->getHealth() <= 0){
      std::cout << "Our hero has been vanquished!\n\n\n\n"
	        << "GAME OVER." << std::endl;
      return false;
   //Else character is alive return true
   } else {
      return true;
   }
}

void displayRoomInfo(Coliseum* c, Creature* chara){

   //Displays current room info
   if (c->getCurRoom()->getRoomT() == GATE){
      std::cout << "You're standing at the coliseum gate." << std::endl;
   } else if (c->getCurRoom()->getRoomT() == OPEN_SAND){
      std::cout << "The dusty sand swirls around you in the coliseum." << std::endl;
   } else if (c->getCurRoom()->getRoomT() == TIGER_TRAP){
      std::cout << "You've come across a Tiger Trap!!!" << std::endl;
   } else if (c->getCurRoom()->getRoomT() == SPIKE_PIT){
      std::cout << "You've fallen into a Spike Pit!!!" << std::endl;
   }

   std::cin.ignore(100,'\n');
   clearScreen();

   //Displays wall info to player
   if (!c->getCurRoom()->N)
      std::cout << "A wall stands to the north." << std::endl;
   if (!c->getCurRoom()->E)
      std::cout << "A wall stands to the east." << std::endl;
   if (!c->getCurRoom()->W)
      std::cout << "A wall stands to the west." << std::endl;
   if (!c->getCurRoom()->S)
      std::cout << "A wall stands to the south." << std::endl; 

   std::cout << std::endl;

   return;
}

void trapDamage(Coliseum* c, Creature* chara){

   Creature* temp = NULL;

   //If current room is a trap, create "creature" instance of trap
   //and trigger combat event to apply damage
   if (c->getCurRoom()->getRoomT() == TIGER_TRAP){
      temp = new CreaTiger;
      int damageDone = gladiatorCombatEvent(temp, chara);
      std::cout << "TRAP IS SPRUNG!!!" << std::endl;
      std::cout << damageDone << " damage done to hero!\n" << std::endl;
   } else if (c->getCurRoom()->getRoomT() == SPIKE_PIT){
      temp = new CreaSpike;
      int damageDone = gladiatorCombatEvent(temp, chara);
      std::cout << "TRAP IS SPRUNG!!!" << std::endl;
      std::cout << damageDone << " damage done to hero!\n" << std::endl;
   }
   if (temp != NULL){
	   delete temp;
   }

   return;
}

void displayActionChoices(Coliseum* c, Creature* chara){

   std::cout << "Room Actions:\n\n"
        << "1) Look Around\n"
        << "2) Move\n"
        << "3) Pick Up Item\n"
        << "4) Drop Item\n"
        << "5) View Inventory\n";

   //If victory conditions are satisfied (player has Hero's Sash, and is
   //in GATE room, give them victory option
   if (chara->getHasHerosSash() && c->getCurRoom()->getRoomT() == GATE){
      std::cout << "6) Exit Arena\n";
   }

   std::cout << std::endl;

   return;
}

int performAction(Coliseum* c, int choice, Creature* chara){

   //If choice 1, player looks on ground for items
   if (choice == 1){
      clearScreen();
      if (c->getCurRoom()->getRoomInventory().size()){
	 std::cout << "On the ground you see:\n" << std::endl;
    	 for (unsigned i = 1; i <= c->getCurRoom()->getRoomInventory().size(); i++){
	   std::cout << i << ") "
    		     << c->getCurRoom()->getRoomInventory().at(i-1)->getItemName()
		     << std::endl;
    	 }
      } else {
    	 std::cout << "You see no items to be gathered." << std::endl;
      }
      return 1;

   //Else if choice 2, call move function
   } else if (choice == 2){
      moveCharacter(c);
      return 2;

   //Else if choice 3, call retrieveItem function
   } else if (choice == 3){
      retrieveItemFromGround(c,chara);
      return 3;

   //Else if choice 4, call dropItem function
   } else if (choice == 4){
      dropItemFromInventory(c,chara);
      return 4;

   //Else if choice 5, call viewInventory function
   } else if (choice == 5){
      viewCharacterInventory(chara);
      return 5;

   //Else if victory conditions are true, and player chooses to win return
   //6 to set victory condition trigger
   } else if (choice == 6 && chara->getHasHerosSash()){
      std::cout << "You exit the arena basking in the glory and adoration of the crowd.";
      return 6;

   //Else invalid choice
   } else {
      std::cout << "Not a valid choice." << std::endl;
   }
   return -1;
}

void moveCharacter(Coliseum* c){
    std::cout << "Where would you like to move? ";
    std::string dirChoice = getChoice();
    if (c->moveRooms(dirChoice)){
      std::cout << "You move " << dirChoice << "..." << std::endl;
    } else {
      std::cout << "You can't do that.";
    }
}

void retrieveItemFromGround(Coliseum* c, Creature* chara){

   clearScreen();

   //Copies Room inventory to local vector
   std::vector<Item*> curRoomInv = c->getCurRoom()->getRoomInventory();

   //If vector has nothing in it update player and return
   if (curRoomInv.size() == 0){
      std::cout << "Nothing there!" << std::endl;
      return;

   //Else display contents, and prompt user for selection
   } else {
      std::cout << "Which item would you like?\n" << std::endl;
      for (unsigned i = 1; i <= curRoomInv.size(); i++){
	 std::cout << i << ") "
		   << curRoomInv.at(i-1)->getItemName() 
		   << std::endl;
      }

      unsigned choice = atoi(getChoice().c_str());

      //If invalid choice return
      if (choice > c->getCurRoom()->getRoomInventory().size() || choice <= 0){
	 std::cout << "Invalid choice. Returning to action menu." << std::endl;
   	 return;
      }

      //If succesffuly added to player inventory, remove from room inventory
      if(chara->addItemToInventory(curRoomInv.at(choice-1))){
	 std::cout << "Item retrieved!" << std::endl;
	 c->getCurRoom()->collectItem(choice-1);

      //If item can't be added, tell player to drop something
      } else {
	 std::cout << "Item can't be retrieved! Drop something!" << std::endl;
      }

   }
   return;
}

void dropItemFromInventory(Coliseum* c, Creature* chara){

   clearScreen();
   //Copies player inventory to local vector
   std::vector<Item*> charaInv = chara->getInventory();

   //If vector has contents prompt user for selection
   if (charaInv.size() > 0){
      std::cout << "Which item would you like to drop?\n";
      for (unsigned i = 0; i < charaInv.size(); i++){
	 std::cout << i+1 << ") " << charaInv.at(i)->getItemName()
	    << "   Weight: " << charaInv.at(i)->getItemWeight()
	    << std::endl;
      }

   	  unsigned choice = atoi(getChoice().c_str());

   	  if (choice > chara->getInventory().size() || choice <= 0){
   		  std::cout << "Invalid choice. Returning to action menu." << std::endl;
   		  return;
   	  }


      //Creates temporary item to place into room inventory
      Item* tempItem = chara->removeItemFromInventory(choice-1);
      c->getCurRoom()->placeItem(tempItem);
      std::cout << tempItem->getItemName();
      std::cout << " dropped onto ground!" << std::endl;

   //else vector has no contents, user is updated and returns
   } else {
      std::cout << "No items in inventory!" << std::endl;
   } 

   return;
}

void viewCharacterInventory(Creature* chara){

   clearScreen();

   //Variable to check if player has potion
   int potionLocation = -1;

   std::vector<Item*> charaInv = chara->getInventory();

   //If player has no inventory update player and return
   if (charaInv.size() == 0){
      std::cout << "You have nothing in your inventory." << std::endl;
      return;
   }

   //Else output inventory contents, and if a potion is found store location
   for (unsigned i = 0; i < charaInv.size(); i++){
      if (charaInv.at(i)->getItemName() == "Potion"){
	 potionLocation = i;
      }
      std::cout << i+1 << ") " << charaInv.at(i)->getItemName()
	   << "   Weight: " << charaInv.at(i)->getItemWeight() << std::endl;
   }

   std::string choice;

   //If a potion is found, prompt user if they want to use it
   if (potionLocation != -1){
      std::cout << "Would you like to use the potion? ";
      choice = getChoice();

      //If yes, replenish health and remove potion from inventory
      if (choice == "yes" || choice == "y"){
	 Item* tempPotion = chara->getInventory().at(potionLocation);
	 chara->replenishHealth();
	 chara->removeItemFromInventory(potionLocation);
	 delete tempPotion;
      }
   }

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

void randomBattle(Creature* chara){

   //Possible creature to battle
   Creature* temp = NULL;

   //Roll to see if battle occurs
   int battleRoll = rand() % 10;

   //If roll is a 9, random battle occurs
   if (battleRoll >= 9){
      clearScreen();
      std::cout << "AN ENEMY BARBARIAN APPROACHES!" << std::endl;
      std::cin.ignore(100,'\n');
      temp = new Barbarian;
      //Autocombat between barbarian and player
      combat(chara, temp);
   }

   if (temp != NULL){
      delete temp;
   }
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
      gladiatorCombatEvent(Char1, Char2);

      //If Char2 is alive, Char2 attacks Char1
      if (Char2->getHealth() > 0){

	 gladiatorCombatEvent(Char2, Char1);
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

int gladiatorCombatEvent(Creature* attacker, Creature* defender){

   //Get Attack value
   int attack = attacker->getAttack();

   //Gets Defense from defender
   int defense = defender->getDefense();

   //Imparts damage to defender
   defender->modifyHealth(attack, defense);

   int damageDone = attack-defense;
   if (damageDone < 0){
      damageDone = 0;
   }
   return (damageDone);
}

