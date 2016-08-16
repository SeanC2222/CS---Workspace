#ifndef CELL_H
#define CELL_H

class Cell{
   
   private:
      int lifeStatus;
      int nextLifeStatus;

   public:
      Cell();
      Cell(int L);
      void setLifeStatus(int);
      void flipLifeStatus();
      int getLifeStatus();

      void setNextLifeStatus(int);
      void flipNextLifeStatus();
      int getNextLifeStatus();    
};

#endif
