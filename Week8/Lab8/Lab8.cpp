#include <iostream>

struct Room{
	std::pair<char, int> loc;
	Room* N;
	Room* S;
	Room* E;
	Room* W;
};

Room* buildStrip(Room*);
Room* buildLength(Room*);

int main(){
	Room* mobius = new Room;
	mobius->loc.first = 'a';
	mobius->loc.second = 1;
	buildStrip(mobius);
	return 0;
}

Room* buildStrip(Room* r){
	r = buildLength(r, 5);
	Room* inner = new Room;
	inner = buildLength(inner,5);
	tieTogether(r, inner);
	return r;
}

Room* buildLength(Room* r, int l){
	Room* start = r;
	for (int i = 0; i < l; i++){
		r->N = new Room;
		r->N->S = r;
		r = r->N;
	}
	r->N = start
	start->S = r;
	r = start;
	delete start;
	return r;
}

