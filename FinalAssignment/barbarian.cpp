#include "barbarian.h"
#include "creature.h"
#include "dice.h"

/* Function: Barbarian::Barbarian()
 * Description: Constructs Barbarian object
 */
Barbarian::Barbarian(){
   this->armor = 0;
   this->health = 12;
   this->maxHealth = this->health;
   this->attackMod = 1.0;
   this->defenseMod = 1.0;
   this->creatureName = "Barbarian";
   this->hasHerosSash = false;
}

/* Function: Barbarian::~Barbarian()
 * Description: Barbarian destructor, no explicit deallocation necessary
 */
Barbarian::~Barbarian(){
   //Nothing explicit needed
}

/* Function: Barbarian::attack()
 * Description: Returns random barbarian atack value emulating roll of 
 *    one six sided die
 * Post-Conditions: Returns int representing Barbarian attack
 */
int Barbarian::attack(){
   Dice D(6);
   return D.rollDice(1);
}

/* Function: Barbarian::defend()
 * Description: Returns random barbarian defense value emulating roll of
 *    one six side die
 * Post-Condtions: Returns int representing defense
 */
int Barbarian::defend(){
   Dice D(6);
   return D.rollDice(1);
}

