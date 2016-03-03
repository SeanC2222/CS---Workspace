#include "creaspike.h"
#include "creature.h"
#include "dice.h"

/* Function: CreaSpike::CreaSpike()
 * Description: Constructor for "creature" instance of spike pit
 * Pre-Conditions; Spike Pit monster encountered
 * Post-Conditions: COnstructs "creature" instance of spike pit
 */
CreaSpike::CreaSpike(){
   this->armor = 0;
   this->health = 12;
   this->maxHealth = this->health;
   this->attackMod = 1.0;
   this->creatureName = "Spike Pit!";
}

/* Function: CreaSpike::~CreaSpike()
 * Description: CreaSpike Destructor, no expicit deallocation necessary
 */
CreaSpike::~CreaSpike(){
   //No explicit deallocation necessary
}

/* Function: CreaSpike::attack()
 * Description: Damage done by spike pit. Max 8, min 4
 */
int CreaSpike::attack(){
   Dice D(4);
   return D.rollDice(1) + 4;
}

//Unneccessary
int CreaSpike::defend(){
   return 255;
}

