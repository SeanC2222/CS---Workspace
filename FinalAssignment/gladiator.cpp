#include <vector>
#include <iostream>

#include "gladiator.h"
#include "creature.h"
#include "dice.h"

/* Function: Gladiator::Gladiator()
 * Description: Constructs Gladiator Creature instance
 * Post-COnditions: Constructed Gladiator Creature instance
 */
Gladiator::Gladiator(){
   this->armor = 0;
   this->health = 25;
   this->maxHealth = this->health;
   this->attackMod = 1.0;
   this->defenseMod = 1.0;
   this->creatureName = "Gladiator";
   this->hasHerosSash = false;
}

/* Function: Gladiator::Gladiator(int)
 * Description: Cheater Gladiator instance with custom health
 * Parameters: int H - Calling function selected Gladiator Health
 * Post-Condtions: Constructed Gladiator Creature instance with Health H
 */
Gladiator::Gladiator(int H){
   this->armor = 0;
   this->health = H;
   this->maxHealth = this->health;
   this->attackMod = 1.0;
   this->defenseMod = 1.0;
   this->creatureName = "Gladiator";
   this->hasHerosSash = false;
}

Gladiator::~Gladiator(){
   while (this->inventory.size() > 0){
      delete this->inventory.at(0);
      this->inventory.erase(this->inventory.begin(), this->inventory.begin()+1);
   }
}

//Gladiator attack function, simulates 2d6 roll
int Gladiator::attack(){
   Dice D(6);
   return D.rollDice(2);
}

//Gladiator defense function, simulates 1d5 roll
int Gladiator::defend(){
   Dice D(5);
   return D.rollDice(1);
}

