#ifndef GOBLIN_H
#define GOBLIN_H

#include <string>
#include "creature.h"

class Goblin: public Creature{

   protected:
      virtual int attack();
      virtual int defend();

   public:
      Goblin();
      std::string getAttackInfo();
      std::string getDefenseInfo();
};

#endif
