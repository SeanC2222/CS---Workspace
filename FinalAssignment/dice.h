#ifndef DICE_H
#define DICE_H

#include <cstdlib>

class Dice{

   private:
      int sides;

   public:
      Dice();
      Dice(int);
      int rollDice(int);
      
};

#endif
