#ifndef OPENSAND_H
#define OPENSAND_H

#include "room.h"

class OpenSand: public Room{

   friend class Coliseum;
   friend class Room;

   private:
      //Nothing
   public:
      OpenSand();
      ~OpenSand();
};

#endif
