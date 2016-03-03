#ifndef CREASPIKE_H
#define CREASPIKE_H

#include <string>
#include "creature.h"

class CreaSpike: public Creature{
   protected:
      virtual int attack();
      virtual int defend();

   public:
      CreaSpike();
      ~CreaSpike();
      std::string getAttackInfo();
      std::string getDefenseInfo();
};

#endif
