#include <cstdlib>
#include "queue.h"

Queue::Queue(){
   this->start = new node;
   this->end = start;
   this->start->prev = NULL;
   this->start->next = NULL;
   this->start->data = 0;
}

Queue::~Queue(){
   while(!isEmpty()){
      removeFront();
   }
   delete start;
}

void Queue::addBack(int n){
   this->end->next = new node;
   this->end->data = n;
   this->end->next->prev = this->end;
   this->end = this->end->next;
   this->end->next = NULL;
}

int Queue::getFront(){
   return this->start->data;
}

void Queue::removeFront(){
   node* temp = this->start;
   this->start = this->start->next;
   delete temp;
   return;
}

bool Queue::isEmpty(){
   if (this->start == this->end){
      return true;
   } else {
      return false;
   }
}
