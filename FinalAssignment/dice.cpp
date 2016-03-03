#include <cstdlib>
#include <ctime>
#include "dice.h"



Dice::Dice(int s) : sides(s){
   //sides initialized in initialization list
}

/*Function: Dice::rollDice(int)
 * Description: Simulates dice roll
 * Post-Condition: Returns simulated dice roll
 */
int Dice::rollDice(int times){
   int sum = 0;
   for (int rolls = 0; rolls < times; rolls++){
      sum += (rand() % this->sides + 1);
   }
   return sum;
}
