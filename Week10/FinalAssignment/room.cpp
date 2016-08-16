#include <vector>

#include "room.h"
#include "item.h"

//Room Instance Constructor
Room::Room(){
   this->N = NULL;
   this->E = NULL;
   this->W = NULL;
   this->S = NULL;
}

//Room instance destructor
Room::~Room(){
   while(roomInventory.size() > 0){
      delete roomInventory.at(0);
      roomInventory.erase(roomInventory.begin(), roomInventory.begin()+1);
   }
}

//Returns room Type (OPEN_SAND, GATE, TIGER_TRAP, SPIKE_PIT)
roomType Room::getRoomT(){
   return this->roomT;
}

//Returns room Inventory vector
std::vector<Item*> Room::getRoomInventory(){
   return this->roomInventory;
}

/* Function: Room::placeItem(Item*)
 * Description: Places item* in Room inventory vector
 * Post-Condtions: Item* is stored in vector
 */
void Room::placeItem(Item* I){
   this->roomInventory.push_back(I);
   return;
}

//Returns Item at index i in roomInventory vector
Item* Room::getItem(int i){
   return roomInventory.at(i);
}

/* Function: Room::collectItem(int)
 * Description: Returns Item* from index i, and erases Item* at index i from
 *    room inventory
 * Parameter: int i - index of item to be returned/removed
 * Pre-Condition: Known location of object to be returned/removed
 * Post-Condtion: Item is removed from inventory and returned
 */
Item* Room::collectItem(int i){

   Item* returnItem;
   
   returnItem = roomInventory.at(i);
   roomInventory.erase(roomInventory.begin() + i);
   return returnItem;
}
