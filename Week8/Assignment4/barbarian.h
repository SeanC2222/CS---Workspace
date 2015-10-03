#ifndef BARBARIAN_H
#define BARBARIAN_H

#include <string>
#include "creature.h"

class Barbarian: public Creature{
   protected:
      virtual int attack();
      virtual int defend();

   public:
      Barbarian();
      ~Barbarian();
      std::string getAttackInfo();
      std::string getDefenseInfo();
};

#endif
