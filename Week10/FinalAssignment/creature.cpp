#include <cmath>
#include <string>
#include <vector>
#include <iostream>

#include "creature.h"
#include "item.h"
#include "dice.h"

/* Function: Creature::~Creature()
 * Description: Creature Destructor, no explicit deallocation necessary
 */
Creature::~Creature(){
   //Nothing Needed
}
/* Function: Creature::getAttack()
 * Description: Gets creature instance attack value
 * Pre-Conditions: Creature instances in combat
 * Post-COnditions: Returns attack value from creature instance
 */
int Creature::getAttack(){
   return static_cast<int>(ceil(this->attack() * this->attackMod));
}

/* FUnction: Creature::getDefense()
 * Description: Gets creature instance defense value
 * Pre-Conditon: Creature instances in combat
 * Post-Condition: Returns attack value from creature instance
 */
int Creature::getDefense(){
   return static_cast<int>(ceil(this->defend() * this->defenseMod));
}

//Unneccessary
int Creature::getArmor(){
   return this->armor;
}

/* Function: Creature::getHealth()
 * Description: Gets creature instance current health
 * Pre-Condtions: None
 * Post-Conditions: Returns in of creature instance health
 */
int Creature::getHealth(){
   return this->health;
}

/* Function: Creature::modifyHealth(int, int)
 * Description: Modifies the health of the creature instance by attack
 *    and defense variables
 * Pre-Condtions: Creature instantiated to have health modified
 * Post-COndtions: Creatures health is modified
 */
int Creature::modifyHealth(int rawAttack, int defense){
   int damage = rawAttack - defense;
   int armor = this->getArmor();
   if (damage >= armor) {
      this->health -= (damage - armor);
      //If Health is less than 0, change to 0
      if (this->health < 0){
	 this->health = 0;
      }
      return (damage - armor);
   } else {
      return (0);
   }
}

/* Function: Creature::getCreatureName()
 * Description: Gets creature instance name
 * Pre-Condition: None
 * Post-Condtion: Returns creature instance name
 */
std::string Creature::getCreatureName(){
   return this->creatureName;
}

/* Function: Creature::addItemToInventory(Item*)
 * Description:: Adds Item* to creature instance inventory vector if total
 *    item weight in inventory is less than 180
 * Parameters: Item* - Item pointer to instantiated Item
 * Pre-Condtions: Instantiated Item that pointer points to
 * Post-Condtions: Stored Pointer in inventory vector if "weight" of item
 *    doesn't cause total weight to go above 180, else returns false
 */
bool Creature::addItemToInventory(Item* I){
   int invWeight = 0;

   for (unsigned i = 0; i < this->inventory.size(); i++){
      invWeight += inventory.at(i)->getItemWeight();
   }
   //If item puts inventory above 180, don't add, return false
   if (invWeight + I->getItemWeight() > 110){
      return false;
   }

   this->inventory.push_back(I);
   //If Item is named Gladius modify attack mod by 1.5
   if (I->getItemName() == "Gladius"){
      std::cout << "Attack increased!" << std::endl;
      this->attackMod *= 1.5;
   //If Item is named Parmula modify defense mod by 1.5
   } else if (I->getItemName() == "Parmula"){
      this->defenseMod *= 1.5;
      std::cout << "Defense increased!" << std::endl;
   //Sets Hero'S Sash Condition if in inventory
   } else if (I->getItemName() == "Hero's Sash"){
      this->hasHerosSash = true;
   }

   //If item is stored, return true
   return true;
}

/* Function: Creature::getInventory()
 * Description: Returns vector of Item* from character instance
 */
std::vector<Item*> Creature::getInventory(){
   return inventory;
}

/* Function: Creature::removeItemFromInventory(int)
 * Descrption: Removes Item* from inventory vector at location int
 * Parameters: int - index of removed item
 * Pre-Condition: Known location of item to be removed
 * Post-COndtion: Item* is removed from inventory, and same Item* is returned
 */
Item* Creature::removeItemFromInventory(int i){
   //If item removed is Gladius, remove attack mod bonus
   if (this->inventory.at(i)->getItemName() == "Gladius"){
      this->attackMod /= 1.5;
   //If item removed is Parmula, remove defense mod bonus
   } else if (this->inventory.at(i)->getItemName() == "Parmula"){
      this->defenseMod /= 1.5;
   //If Hero's Sash is removed, remove Hero's Sash Condition
   } else if (this->inventory.at(i)->getItemName() == "Hero's Sash"){
      this->hasHerosSash = false;
   }
   //Temporarily store dropped item location
   Item* droppedItem = inventory.at(i);
   //Remove from vector
   this->inventory.erase(inventory.begin() + i);
   //Return dropped item
   return droppedItem;
}

/* Function: Creature::replenishHealth()
 * Description: Increases Health variable by at most 15 HP
 * Post-Conditions: Creature instance has health increase by 15, or to max HP
 */
void Creature::replenishHealth(){

   if (this->getHealth() + 15 > this->maxHealth){
	 this->health = this->maxHealth;
   } else {
	 this->health += 15;
   }

   return;
}

/* Function: Creature::getHasHerosSash()
 * Description: Checks if Creature has Hero's Sash Condition
 * Post-COndtions: Returns True if Creature meets Hero's Sash Condtion
 *    Returns false if Creature doesn't meet Hero's Sash Condition
 */
bool Creature::getHasHerosSash(){
   return this->hasHerosSash;
}     
