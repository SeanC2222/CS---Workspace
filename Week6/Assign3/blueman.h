#ifndef BLUEMAN_H
#define BLUEMAN_H

#include <string>
#include "creature.h"

class BlueMan: public Creature{

   protected:
      virtual int attack();
      virtual int defend();

   public:
      BlueMan();
      std::string getAttackInfo();
      std::string getDefenseInfo();
};

#endif
