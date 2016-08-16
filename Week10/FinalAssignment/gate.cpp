#include "gate.h"

//Gate Room Constructor
Gate::Gate(){
   this->roomT = GATE;
}

Gate::~Gate(){
   delete this;
}

