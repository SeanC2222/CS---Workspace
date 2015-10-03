#include "goblin.h"
#include "dice.h"

Goblin::Goblin(){
   this->armor = 3;
   this->strength = 8;
   this->attackMod = 1.0;
   this->creatureName = "Goblin";
}

int Goblin::attack(){
   Dice D(6);
   return D.rollDice(2);
}

int Goblin::defend(){
   Dice D(6);
   return D.rollDice(1);
}

std::string Goblin::getAttackInfo(){
   return "2D6, with Achilles Special\n**Achilles: if 2D6 = 12, opponent's attack cut in half.";
}

std::string Goblin::getDefenseInfo(){
   return "1D6 defense";
}
