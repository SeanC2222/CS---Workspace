#include "spikepit.h"

//Spike Pit Room COnstructor
SpikePit::SpikePit(){
   this->roomT = SPIKE_PIT;
}

//Spike Pit room Destructor
SpikePit::~SpikePit(){
   delete this; 
}

