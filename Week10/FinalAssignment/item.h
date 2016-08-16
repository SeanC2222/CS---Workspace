#ifndef ITEM_H
#define ITEM_H

#include <string>

enum itemType{VITALITY, ATTACK, DEFENSE, KEY};

class Item{

   protected:
      std::string itemName;
      int iModAmount;
      int itemWeight;
      itemType itemT;
      
   public:
      std::string getItemName();
      int getiModAmount();
      int getItemWeight();
      itemType getItemType();

};     

#endif
