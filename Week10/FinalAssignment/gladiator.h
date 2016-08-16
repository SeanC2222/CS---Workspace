#ifndef GLADIATOR_H
#define GLADIATOR_H

#include <string>
#include "creature.h"

class Gladiator: public Creature{
   protected:
      virtual int attack();
      virtual int defend();

   public:
      Gladiator();
      Gladiator(int);
      ~Gladiator();
};

#endif
