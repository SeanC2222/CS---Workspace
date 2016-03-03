#ifndef GATE_H
#define GATE_H

#include "room.h"

class Gate: public Room{

   friend class Coliseum;
   friend class Room;

   private:
      //Nothing
   public:
      Gate();
      ~Gate();
};

#endif
