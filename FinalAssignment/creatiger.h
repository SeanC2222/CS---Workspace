#ifndef CREATIGER_H
#define CREATIGER_H

#include <string>
#include "creature.h"

class CreaTiger: public Creature{
   protected:
      virtual int attack();
      virtual int defend();

   public:
      CreaTiger();
      ~CreaTiger();
      std::string getAttackInfo();
      std::string getDefenseInfo();
};

#endif
