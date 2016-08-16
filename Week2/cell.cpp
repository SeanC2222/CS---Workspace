#include "cell.h"
//Basic Cell constructor
Cell::Cell(){
   lifeStatus = 0;
   nextLifeStatus = 0;
}
//Specific Cell constructor, sets lifeStatus to L
Cell::Cell(int L){
   lifeStatus = L;
   nextLifeStatus = 0;
}
//Sets cell lifeStatus to L
void Cell::setLifeStatus(int L){
   lifeStatus = L;
   return;
}
//Flips value of cell lifeStatus
void Cell::flipLifeStatus(){
   if (lifeStatus == 0)
      lifeStatus = 1;
   else
      lifeStatus = 0;
   return;
}
//Returns lifeStatus of cell
int Cell::getLifeStatus(){
   return lifeStatus;
}
//Sets nextLifeStatus of cell to L
void Cell::setNextLifeStatus(int L){
   nextLifeStatus = L;
   return;
}
//Flips value of cell nextLifeStatus
void Cell::flipNextLifeStatus(){
   if (nextLifeStatus == 0)
      nextLifeStatus = 1;
   else
      nextLifeStatus = 0;
   return;
}
//Returns nextLifeStatus
int Cell::getNextLifeStatus(){
   return nextLifeStatus;
}
