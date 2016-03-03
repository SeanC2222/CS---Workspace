#include "creatiger.h"
#include "creature.h"
#include "dice.h"

/* Function: CreaTiger::CreaTiger()
 * Description: Creates "creature" instance of Tiger Trap
 * Pre-Conditions: Encountered Tiger Trap
 * Post-Conditions; COnstructed "creature" instance of Tiger Trap
 */
CreaTiger::CreaTiger(){
   this->armor = 0;
   this->health = 12;
   this->maxHealth = this->health;
   this->attackMod = 1.0;
   this->creatureName = "Tiger";
}

/* Function: CreaTiger::~CreaTiger()
 * Description: CreaTiger Destructor, no explicit deallocation necessary
 */
CreaTiger::~CreaTiger(){
   //Nothing to deallocate
}

/* Function: CreaTiger::attack()
 * Description: Attack from "creature" instance of Tiger Trap
 *    Min 3, Max 9
 */
int CreaTiger::attack(){
   Dice D(6);
   return D.rollDice(1) + 3;
}

//Unneccesary
int CreaTiger::defend(){
   Dice D(6);
   return D.rollDice(1);
}

