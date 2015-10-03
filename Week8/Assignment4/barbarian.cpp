#include "barbarian.h"
#include "creature.h"
#include "dice.h"

Barbarian::Barbarian(){
   this->armor = 0;
   this->strength = 12;
   this->maxHealth = this->strength;
   this->attackMod = 1.0;
   this->creatureName = "Barbarian";
}

int Barbarian::attack(){
   Dice D(6);
   return D.rollDice(2);
}

int Barbarian::defend(){
   Dice D(6);
   return D.rollDice(2);
}

std::string Barbarian::getAttackInfo(){
   return "2D6 roll attack power.";
}

std::string Barbarian::getDefenseInfo(){
   return "2D6 defense";
}
