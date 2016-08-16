#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "creature.h"

class Barbarian: public Creature{
   protected:
      virtual int attack();
      virtual int defend();

   public:
      Barbarian();
      ~Barbarian();
};

#endif
