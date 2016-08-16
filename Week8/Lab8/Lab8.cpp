#include <iostream>
#include <string>

//Length of single "Side" of mobius strip
#define MOBIUS_LENGTH 5

/* Container: Room
 * Description: Imitates a room
 * Data: std::pair<char,int> loc - Stores lat/long coordinates as a pair
 *	 std::string desc - Stores a description of the room
 *	 Room* N - A pointer to the room to the "north"
 *	 Room* S - A pointer to the room to the "south"
 *	 Room* E - A pointer to the room to the "east"
 *	 Room* W - A pointer to the room to the "west"
 */
struct Room{
   std::pair<char, int> loc;
   std::string desc;
   Room* N;
   Room* S;
   Room* E;
   Room* W;

};
/* Function: void clearScreen()
 * Description: Outputs empty lines to clear the screen
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: Console has effectively clear screen
 */
void clearScreen() {for(int i = 0; i < 100; i++) {std::cout << std::endl;} return;}

/* Function: Room* buildStrip(Room*)
 * Description: Builds a mobius strip data structure by linking 2 seperate
 *    linear data structures
 * Paramters: Room* - The root pointer of the data structure
 * Pre-Conditions: Passed Room* must be initialized as a new Room
 * Post-Conditions: Returns pointer to root of data structure
 */
Room* buildStrip(Room*);

/* Function: Room* buildLength(Room*)
 * Description: Builds a linear data structure that links bidirectionally north
 *    to south. East and west links back to the same node
 * Paramters: Room* - The root pointer of the "side" being created
 * Pre-Condtions: Passed Room* must be initialized as a new Room
 * Post-Conditions: Returns pointer to root of data structure
 */
Room* buildLength(Room*);

/* Function: Room* tieTogether(Room*, Room*)
 * Description: Links two separate linear data structures into a mobius strip
 *    style data structure. Mobius strip - 1 dimensional circular structure.
 * Parameters: Room*, Room* - The two linear data structures to be linked
 * Pre-Conditions: Two linear data structures, and pointers to the two roots
 * Post-Conditions: Returns pointer to root of Mobius Strip data structure
 */
Room* tieTogether(Room*,Room*);

/* Function: traverseWorld(Room*, bool)
 * Description: Moves the user through the linked list data structure
 * Paramters:  Room* - The current room of the data structure to move from
 *	       Bool - True or false condtion to print room labels
 * Pre-Conditions: Complete room data structure linked list
 * Post-Condition: Returns the next room pointer of the user's selection
 */
Room* traverseWorld(Room*,bool);

/* Function: goNorth(Room*), goSouth(Room*), goEast(Room*), goWest(Room*)
 * Description: Moves in direction indicated by the function name within
 *    the data structure.
 * Paramters: Room* - The current room of the data structure to move from
 * Pre-Conditions: Complete room data structure linked list
 * Post-Conditions: Returns the next room in the direction indicated by the
 *    function name
 */
Room* goNorth(Room*);
Room* goSouth(Room*);
Room* goEast(Room*);
Room* goWest(Room*);

/* Function: deallocateMem(Room*)
 * Description: Deallocates data structure object
 * Parameters: Room* - Root of data structure to be deallocated
 * Pre-Condtions: Linear data structure of length 2 * MOBIUS_LENGTH
 * Post-Conditions: Releases all rooms from memory
 */
void deallocateMem(Room*);

int main(){

   //Root of mobius data structure
   Room* mobius = new Room;
   //Builds mobius data structure
   mobius->loc.first = 'O';
   mobius = buildStrip(mobius);
   //Count of continuous North movements
   int count = 0;
   //Used to turn room labels on or off
   bool labels = false;
   //Clears screen
   clearScreen();
   std::cout << "You find yourself standing on a mobius strip in space." << std::endl;
   std::cout << "Would you like room labels on? (\'y\'/\'n\') ";
   //If user wants labels, sets labels TRUE
   if (tolower(std::cin.get()) == 'y'){
      labels = true;
   }
   //Updates user on their selection
   std::cout << "Labels: ";
   if (labels){
      std::cout << "ON\n" << std::endl;
   } else {
      std::cout << "OFF\n" << std::endl;
   }
   std::cin.ignore(100,'\n');
   std::cin.ignore(100,'\n');

   do{
      //Previous room location
      Room* prev = mobius;
      //Updates user location in data structure
      mobius = traverseWorld(mobius, labels);
      //If user moves north, count increments
      if (prev->N == mobius){
	 count++;
      //Else count returns to 0
      } else {
	 count = 0;
      }
      std::cout << std::endl;
   }while (count < 10);

   std::cout << "As you walk onward you feel gravity shifting around you.\n"
       << "You lift off the strange curved world falling towards the loop's center...\n"
       << "As you free fall into nothing you feel an electric buzz in the air and you pass out.\n";
   std::cin.ignore(100,'\n');

   for(int i = 0; i < MOBIUS_LENGTH; i++){
      clearScreen();
      for(int j = i; j > 0; j--){
	 std::cout << ".";
      }
      std::cin.ignore(100,'\n');
   }

   std::cout << "You awake and find yourself face down in the desert. You look around\n"
        << "and see the highway. As you approach the only sign in the area reads:\n\n"
        << "Area 51.\n" << std::endl;

   deallocateMem(mobius);
   return 0;
}

Room* buildStrip(Room* r){
   //Builds outer side of strip
   r = buildLength(r);
   //Builds inner side of strip
   Room* s = new Room;
   s->loc.first = 'I';
   s = buildLength(s);
   //Ties together outer and inner sides to 1-D structure
   r = tieTogether(r,s);
   return r;
}

Room* buildLength(Room* r){
   //Root of linear data structure
   Room* start = r;

   //Builds a linear Room data strucutre of length MOBIUS_LENGTH
   for (int i = 0; i < MOBIUS_LENGTH; i++){
      //Creates a new room to the north
      r->N = new Room;
      //Sets location
      r->N->loc.first = r->loc.first;
      r->loc.second = i + 1;
      //Sets all links to appropriate targets
      r->N->S = r;
      r->N->E = r->N;
      r->N->W = r->N;
      r->N->N = NULL;
      //Adds description to each room
      if (i == 0){
	 r->desc = "You see the strip stretch north and south into the distance.\nLooking east and west you see the strip end abrubtly...";
      } else if (i == 1){
	 r->desc = "You see into the distance to the north that the world starts to bend.\nLooking east and west you see the strip's edges end abruptly...";
      } else if (i == 2){
	 r->desc = "Gravity seems to hold you as you step onto the curve. \nFurther north, the world continues to bend to the south the world extends\nout of sight.\nLooking east and west you see the strip's edges end abruptly still...";
      } else if (i == 3){
	 r->desc = "You find yourself disoriented as the world extends it's curve both north and south.\nEast and west you see the edges drop abruptly...";
      } else if (i == 4){
	 r->desc = "You step off the curve. To the north the world flattens and to the\nsouth you see the strange curve of the world.\nLooking east and west you see the strip's edges end abruptly...";
      } else {
	 r->desc = "DERP";
      }
      r = r->N;
  }
   //Moves r to the south by one room, and deletes extra room
   Room* temp = r;
   r = r->S;
   delete temp;
   //Connects both ends of the data structure
   r->N = start;
   start->S = r;
   //Sets r to the start of data structure
   r = start;
   //Returns r
   return r;
}

Room* tieTogether(Room* r, Room* s){
   //For every matching link in r and s, sets the appropriate link targets
   for(int i = 0; i < MOBIUS_LENGTH; i++){
      //E/W moves to the equivalent link in s
      r->E = s;
      r->W = s;
      //E/W moves to the equivalent link in r
      s->E = r;
      s->W = r;
      //Progress through the data structure
      r = r->N;
      s = s->N;
   }
   //Sets North in r, link 3, to North in s link 3 (r3 moves to s4) and does
   // the same for s
   r->N->N->N = s->N->N->N;
   s->N->N->N = r->S->S;

   //Sets South in r, link 3, to South in s link 3 (r4 move to s3) and same
   // does the same for s
   Room* temp = r->S->S->S;
   r->S->S->S = s->S->S->S;
   s->S->S->S = temp;
    
   return r;
}

Room* traverseWorld(Room* curRoom, bool labels){
   //User choice
   std::string choice;
   //clears screen
   clearScreen();
   //If labels, then updates user on current location
   if (labels){
      std::cout << "Current Location: " << curRoom->loc.first << curRoom->loc.second << std::endl;
   }
   //outputs room description
   std::cout << curRoom->desc << std::endl;
   //Prompts user on where to go
   std::cout << "Which direction would you like to go?";
   getline(std::cin, choice);

   //Calls appropriate movement choice
   if(choice == "north" || choice == "n"){
      return goNorth(curRoom);
   } else if (choice == "south" || choice == "s"){
      return goSouth(curRoom);
   } else if (choice == "east" || choice == "e"){
      return goEast(curRoom);
   } else if (choice == "west" || choice == "w"){
      return goWest(curRoom);
   } else {
      return curRoom;
   }
}

Room* goNorth(Room* curRoom){
   //If it points to Null, stop user from moving
   if(curRoom->N == NULL){
      std::cout << "Can't go any further north..." << std::endl;
      return curRoom;
   //Else return north
   } else {
      return curRoom->N;
   }
}

Room* goSouth(Room* curRoom){
   if(curRoom->S == NULL){
      std::cout << "Can't go any further south..." << std::endl;
      return curRoom;
   } else {
      return curRoom->S;
   }
}

Room* goEast(Room* curRoom){
   if(curRoom->E == NULL){
      std::cout << "Can't go any further east..." << std::endl;
      return curRoom;
   } else {
      return curRoom->E;
   }
}

Room* goWest(Room* curRoom){
   if(curRoom->W == NULL){
      std::cout << "Can't go any further west..." << std::endl;
      return curRoom;
   } else {
      return curRoom->W;
   }
}

void deallocateMem(Room* r){

   Room* temp;
   //For each link, move r forward then deletes link
   for(int i = 0; i < 2 * MOBIUS_LENGTH; i++){
      temp = r;
      r = r->N;
      delete temp;
   }
   
   return;
}
