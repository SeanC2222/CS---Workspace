#ifndef REPTILE_H
#define REPTILE_H

#include <string>
#include "creature.h"

class Reptile: public Creature{

   protected:
      virtual int attack();
      virtual int defend();

   public:
      Reptile();
      std::string getAttackInfo();
      std::string getDefenseInfo();
};

#endif
