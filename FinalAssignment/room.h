#ifndef ROOM_H
#define ROOM_H

#include <vector>

#include "item.h"

enum roomType{OPEN_SAND, TIGER_TRAP, SPIKE_PIT, GATE};

class Room{

   friend class Coliseum;

   protected:   
      roomType roomT;
      std::vector<Item*> roomInventory;
      
   public:
      Room* N;
      Room* E;
      Room* W;
      Room* S;
      Room();
      ~Room();
      roomType getRoomT();
      std::vector<Item*> getRoomInventory();
      void placeItem(Item*);
      Item* getItem(int);
      Item* collectItem(int);
};

#endif
