#include <cstdlib>
#include <iostream>

#include "coliseum.h"
#include "room.h"
#include "gate.h"
#include "opensand.h"
#include "tigertrap.h"
#include "spikepit.h"
#include "item.h"
#include "sword.h"
#include "shield.h"
#include "potion.h"
#include "herossash.h"
#include "carcass.h"


/* Function: Coliseum::Coliseum()
 * Description: Constructor for Coliseum of rooms. Root room
 *    is location G. All other locations are open sand unless
 *    trap condition is met during construction.
 *
 *    Diagram of Coliseum:
 *    __ __ __ __ __ __
 *   |__|__|__|__|__|__|
 *    G_|__|__|__|__|__|
 *   |__|__|__|__|__|__|
 *
 *
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: Constructs 3 rows tall by 5 columns long grid
      of Rooms of various types. Distribues items in rooms
*/
Coliseum::Coliseum(){
   //Pointer to build linked structure
   Room* temp;
   temp = new Gate;
   //Random number to find where to set traps
   int randomTrap;
   //Sets max number of random traps to 4
   int maxTraps = 3;
   //Stores starting location
   this->curRoom = temp;
   //Stores gateroom for deallocation
   this->gateRoom = temp;

   //Builds linear linked list, with North and South rooms connected
   for (int i = 0; i < 5; i++){
      //Sets random trap value
      randomTrap = rand() % 4;

      //Builds E-W linked list
      //If trap condition build a trap to E
      if (randomTrap == 0 && maxTraps >= 0){
	 temp->E = new TigerTrap;
	 randomTrap = rand() % 4;
	 maxTraps--;
      //If trap condtion build a trap to E
      } else if (randomTrap == 1 && maxTraps >= 0){
	 temp->E = new SpikePit;
	 randomTrap = rand() % 4;
	 maxTraps--;
      //Else build open sand to E
      } else {
         temp->E = new OpenSand;
	 randomTrap = rand() % 4;
      }
      //Tie E room to current room
      temp->E->W = temp;

      //Builds northern link to linked list
      //If trap condition build a trap to N
      if (randomTrap == 0 && maxTraps >= 0){
	 temp->N = new TigerTrap;
	 randomTrap = rand() % 4;
	 maxTraps--;
      //If trap condition build a trap to N
      } else if (randomTrap == 1 && maxTraps >= 0){
	 temp->N = new SpikePit;
	 randomTrap = rand() % 4;
	 maxTraps--;
      //Else build open sand to N
      } else {
         temp->N = new OpenSand;
	 randomTrap = rand() % 4;
      }
      //Tie N room to current room
      temp->N->S = temp;


      //Builds room south of current room
      //If trap condition build a trap to S
      if (randomTrap == 0 && maxTraps >= 0){
	 temp->S = new TigerTrap;
	 randomTrap = rand() % 4;
	 maxTraps--;
      //If trap condition build a trap to S
      } else if (randomTrap == 1 && maxTraps >= 0){
	 temp->S = new SpikePit;
	 randomTrap = rand() % 4;
	 maxTraps--;
      //Else build open sand to S
      } else {
         temp->S = new OpenSand;
	 randomTrap = rand() % 4;
      } 
      //Links S room to current room
      temp->S->N = temp;
      
      //Move current room E by one room
      temp = temp->E;
   }
   
   //Builds final N rooms
   //If trap condition build trap N
   if (randomTrap == 0 && maxTraps >= 0){
      temp->N = new TigerTrap;
      randomTrap = rand() % 4;
      maxTraps--;
   //If trap condition build trap N
   } else if (randomTrap == 1 && maxTraps >= 0){
      temp->N = new SpikePit;
      randomTrap = rand() % 4;
      maxTraps--;
   //Else build open sand N
   } else {
      temp->N = new OpenSand;
      randomTrap = rand() % 4;
   }
   //Link N to current room
   temp->N->S = temp;

   //Builds final S room
   //If trap condition build trap S
   if (randomTrap == 0 && maxTraps >= 0){
      temp->S = new TigerTrap;
      randomTrap = rand() % 4;
      maxTraps--;
   //If trap condition build trap S
   } else if (randomTrap == 1 && maxTraps >= 0){
      temp->S = new SpikePit;
      randomTrap = rand() % 4;
      maxTraps--;
   //Else build open sand S
   } else {
      temp->S = new OpenSand;
      randomTrap = rand() % 4;
   } 
   //Link S to current room
   temp->S->N = temp;
   
   //Heading East to West, Link all N and S
   //rooms in a westerly direction
   for (int i = 0; i < 5; i++){
      //Links N room W, to W room N
      temp->N->W = temp->W->N;
      //Links S room W to W room S
      temp->S->W = temp->W->S;
      //Moves current room to W
      temp = temp->W;
   }

   //Heading West to East, Link all N and S
   //rooms in an easterly direction
   for (int i = 0; i < 5; i++){
      //Links N room E, to E room N
      temp->N->E = temp->E->N;
      //Links S room E, to E room S
      temp->S->E = temp->E->S;
      temp = temp->E;
   }

   //Reset temp to gate location
   temp = this->curRoom;

   //Build a temporary item
   Item* tempItem;

   //Picks a random seed location for item placement
   int randomLocation = rand() % 15;

   //Distributes item randomly across board
   for (int i = 0; i < 5; i++){

      if (i == 0){
	 tempItem = new Sword;
      } else if (i == 1){
	 tempItem = new Shield;
      } else if (i == 2){
	 tempItem = new Potion;
      } else if (i == 3){
	 tempItem = new Carcass;
      } else {
	 tempItem = new HerosSash;
      }

      //Picks north, East, or South to place item
      if (randomLocation % 3 == 0){
	 temp->N->placeItem(tempItem);
      } else if (randomLocation % 3 == 1){
	 temp->E->placeItem(tempItem);
      } else {
	 temp->S->placeItem(tempItem);
      }
      temp = temp->E;
      randomLocation++;
   }
}

/* Function: Coliseum::~Coliseum()
 * Description: Destructor
 * Pre-Conditions: Existing Coliseum
 * Post-Conditions: Coliseum is deallocated
 */
Coliseum::~Coliseum(){

   Room* temp = this->gateRoom;

   while (temp->E != NULL){
      delete temp->N;
      delete temp->S;
      temp = temp->E;
      delete temp->W;
   }
   delete temp->N;
   delete temp->S;
   delete temp;

}

/* Function: Coliseum::getCurRoom()
 * Description: returns curRoom
 */
Room* Coliseum::getCurRoom(){
   return this->curRoom;
}

/* Function: Coliseum::moveRooms(std::string)
 * Description: Moves curRoom to a different room in linked structure
 * Parameters: std::string - formatted string for north(n), south(s), east(e)
 *    or west(w) direction of movement
 * Pre-Conditions: None
 * Post-Conditions: this->curRoom location is updated
 *		    returns bool true if movement was made, false if not
 */
bool Coliseum::moveRooms(std::string s){

   Room* beforeMove = this->curRoom;

   if (s == "north" || s == "n"){
      this->curRoom = curRoom->N;
   } else if (s == "east" || s == "e"){
      this->curRoom = curRoom->E;
   } else if (s == "west" || s == "w"){
      this->curRoom = curRoom->W;
   } else if (s == "south" || s == "s"){
      this->curRoom = curRoom->S;
   } else {
	  this->curRoom = NULL;
   }
   
   //If movement can't be made, return false
   if (curRoom == NULL){
      curRoom = beforeMove;
      return false;
   }
   //If movement successful, return true
   return true;
}
