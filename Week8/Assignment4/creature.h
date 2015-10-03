#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature{
   protected:
      int armor;
      int strength;
      int maxHealth;
      double attackMod;
      std::string creatureName;
      virtual int attack() = 0;
      virtual int defend() = 0;
      int team;

   public:
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
      virtual std::string getAttackInfo() = 0;
      virtual std::string getDefenseInfo() = 0;

      void setTeam(int);
      int getTeam();
      int replenishHealth();
};

#endif
