#include "blueman.h"
#include "creature.h"
#include "dice.h"

BlueMan::BlueMan(){
   this->armor = 3;
   this->strength = 12;
   this->attackMod = 1.0;
   this->creatureName = "Blue Man";
}

int BlueMan::attack(){
   Dice D(10);
   return D.rollDice(2);
}

int BlueMan::defend(){
   Dice D(6);
   return D.rollDice(3);
}

std::string BlueMan::getAttackInfo(){
   return "2D10 attack power";
}

std::string BlueMan::getDefenseInfo(){
   return "3D6 defense";
}


