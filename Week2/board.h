#ifndef BOARD_H
#define BOARD_H

#include <vector>
using std::vector;

#include "cell.h"

class Board{

   private:
      vector< vector<Cell> > board;
      int width, height, size;
      void adjustCellInfo();
      
   public:
      Board();
      Board(int,int);
      int getBoardWidth();
      int getBoardHeight();
      int getBoardSize();
      vector< vector<Cell> >& getBoard();
      void increaseBoardSize();
      Cell& getCell(int, int);

}; 
#endif
