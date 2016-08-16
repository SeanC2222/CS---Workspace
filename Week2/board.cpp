#include <vector>
#include "cell.h"
#include "board.h"

//Basic Constructor
Board::Board(){
   //20 is arbitrary
   height = 20;
   //79 instead of 80 because of y axis inclusion
   width = 79;
   //Size starts at 0 until resized
   size = 0;
   for(int i = 0; i < height; i++){
      vector<Cell> row;
      for(int j = 0; j < width; j++){
	 row.push_back(Cell());
      }
      board.push_back(row);
   }
}

//Specific size constructor
Board::Board(int ROWS, int COLUMNS){
   //Rows can be any reasonable amount for console
   height = ROWS;
   //Columns shouldn't exceed 79 unless console is resized
   width = COLUMNS;
   //Size starts at 0 until resized
   size = 0;

   for(int i = 0; i < height; i++){
      vector<Cell> row;
      for(int j = 0; j < width; j++){
	 row.push_back(Cell());
      }
      board.push_back(row);
   }
}

//Returns width
int Board::getBoardWidth(){
   return width;
}
//Returns height
int Board::getBoardHeight(){
   return height;
}
//Returns size
int Board::getBoardSize(){
   return size;
}
//Increases board's dimensions by 2 rows and 2 columns
void Board::increaseBoardSize(){
   //Adds 2 rows to board
   vector<Cell> row(width,Cell());
   board.push_back(row);
   board.push_back(row);
   //updates current height
   height += 2;
   //Adds 2 columns to board rows
   for (int i = 0; i < height; i++){
      board[i].push_back(Cell());
      board[i].push_back(Cell());
   }
   //updates current width
   width += 2;
   //Calls adjustCellInfo() to adjust data to appropriate location
   Board::adjustCellInfo();
   return;
}

//Private function to move all cell data after board has been resized
void Board::adjustCellInfo(){
   //Sets lifeStatus of all previous Cells to one higher row and one higher col
   for (int i = height - 1; i > 0; i--){
      for (int j = width - 1; j > 0; j--){
	 board[i][j].setLifeStatus(board[i - 1][j - 1].getLifeStatus());
	 board[i][j].setNextLifeStatus(board[i - 1][j - 1].getNextLifeStatus());
      }
   }
   //Sets new row 0 to all 0 life status
   for (int i = 0; i < width; i++){
      board[0][i].setLifeStatus(0);
      board[0][i].setNextLifeStatus(0);
   }
   //Sets new col 0 to all 0 life status
   for (int i = 0; i < height; i++){
      board[i][0].setLifeStatus(0);
      board[i][0].setNextLifeStatus(0);
   }
   //Increases board size
   size++;
   return;
}

//Returns board
vector< vector<Cell> >& Board::getBoard(){
   return board;
}

//returns Cell& at board[row][column]
Cell& Board::getCell(int row, int column){
   return board[row][column];
}
