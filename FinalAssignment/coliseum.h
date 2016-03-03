#ifndef COLISEUM_H
#define COLISEUM_H

#include <string>
#include "room.h"

class Coliseum{

   private:
      Room* curRoom;
      Room* gateRoom;

   public:
      Coliseum();
      ~Coliseum();
      Room* getCurRoom();
      bool moveRooms(std::string);
};



#endif
