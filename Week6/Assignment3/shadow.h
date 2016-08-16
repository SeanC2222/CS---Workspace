#ifndef SHADOW_H
#define SHADOW_H

#include <string>
#include "creature.h"

class Shadow: public Creature{

   protected:
      virtual int attack();
      virtual int defend();

   public:
      Shadow();
      std::string getAttackInfo();
      std::string getDefenseInfo();
      int getArmor();
};

#endif
