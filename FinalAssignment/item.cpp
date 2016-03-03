#include <string>
#include "item.h"

/* Function: Item::getItemName()
 * Description: Get's item instance's name variable
 * Post-Condition: Returns item name
 */
std::string Item::getItemName(){
   return this->itemName;
}

/* Function: Item::getiModAmount()
 * Description: Returns iModAmount from item instance
 */
int Item::getiModAmount(){
   return this->iModAmount;
}

/* Function: Item::getItemWeight()
 * Description: Returns Item weight
 */
int Item::getItemWeight(){
   return this->itemWeight;
}

/* Function: Item::getItemType()
 * Description: Returns Item type
 */
itemType Item::getItemType(){
   return this->itemT;
}
