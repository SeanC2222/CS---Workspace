#include "reptile.h"
#include "creature.h"
#include "dice.h"

Reptile::Reptile(){
   this->armor = 7;
   this->strength = 18;
   this->maxHealth = this->strength;
   this->attackMod = 1.0;
   this->creatureName = "Reptile Person";
}

int Reptile::attack(){
   Dice D(6);
   return D.rollDice(3);
}

int Reptile::defend(){
   Dice D(6);
   return D.rollDice(1);
}

std::string Reptile::getAttackInfo(){
   return "3D6 attack power";
}

std::string Reptile::getDefenseInfo(){
   return "1D6 defense";
}



