#include "shadow.h"
#include "creature.h"
#include "dice.h"

Shadow::Shadow(){
   this->armor = 0;
   this->strength = 12;
   this->maxHealth = this->strength;
   this->attackMod = 1.0;
   this->creatureName = "The Shadow";
}

int Shadow::attack(){
   Dice D(10);
   return D.rollDice(2);
}

int Shadow::defend(){
   Dice D(6);
   return D.rollDice(1);
}

int Shadow::getArmor(){
   Dice D(2);
   if (D.rollDice(1) == 2){
      return 10000;
   } else {
      return this->armor;
   }
}

std::string Shadow::getAttackInfo(){
   return "2D10 attack power";
}

std::string Shadow::getDefenseInfo(){
   return "1D6 defense";
}
