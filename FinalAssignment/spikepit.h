#ifndef SPIKEPIT_H
#define SPIKEPIT_H

#include "room.h"

class SpikePit: public Room{

   friend class Coliseum;

   private:
      //Nothing
   public:
      SpikePit();
      ~SpikePit();
};

#endif
