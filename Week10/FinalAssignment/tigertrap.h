#ifndef TIGERTRAP_H
#define TIGERTRAP_H

#include "room.h"

class TigerTrap: public Room{

   friend class Coliseum;

   private:
      //Nothing
   public:
      TigerTrap();
      ~TigerTrap();
};

#endif
