#ifndef CREATURE_H
#define CREATURE_H

#include <vector>
#include <string>
#include "item.h"

class Creature{
   protected:
      int armor;
      int health;
      int maxHealth;
      double attackMod;
      double defenseMod;
      std::string creatureName;
      virtual int attack() = 0;
      virtual int defend() = 0;
      std::vector<Item*> inventory;
      bool hasHerosSash;

   public:
      virtual ~Creature();
      //Returns Creature Specific Attack Value
      virtual int getAttack();
      //Returns Creature Specific Defense Value
      virtual int getDefense();
      //Returns Creature Specific Armor Value
      virtual int getArmor();
      //Returns Creature Health
      int getHealth();
      //Returns Net Damage to strength
      int modifyHealth(int, int);
      //Returns Creature Type Name
      std::string getCreatureName();
      void modifyAttackMod();
      void replenishHealth();
      bool addItemToInventory(Item*);
      std::vector<Item*> getInventory();
      Item* removeItemFromInventory(int);
      bool getHasHerosSash();
};

#endif
