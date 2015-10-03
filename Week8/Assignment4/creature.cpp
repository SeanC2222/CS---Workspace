#include <cmath>

#include "creature.h"
#include "dice.h"

int Creature::getAttack(){
   return static_cast<int>(ceil(this->attack() * this->attackMod));
}

int Creature::getDefense(){
   return this->defend();
}

int Creature::getArmor(){
   return this->armor;
}

int Creature::getHealth(){
   return this->strength;
}

int Creature::modifyHealth(int rawAttack, int defense){
   int damage = rawAttack - defense;
   int armor = this->getArmor();
   if (damage >= armor) {
      this->strength -= (damage - armor);
      if (this->strength < 0){
	 this->strength = 0;
      }
      return (damage - armor);
   } else {
      return (0);
   }
}

std::string Creature::getCreatureName(){
   return this->creatureName;
}

void Creature::modifyAttackMod(){
   this->attackMod = 0.50;
   return;
}

void Creature::setTeam(int t){
   this->team = t;
   return;
}

int Creature::getTeam(){
   return this->team;
}

int Creature::replenishHealth(){

   Dice D(this->maxHealth);
   int total = D.rollDice(1);

   this->strength += total;

   if(this->strength > this->maxHealth){
      this->strength = this->maxHealth;
   }

   this->attackMod = 1.0;
   return total;
}      
