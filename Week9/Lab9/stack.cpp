#include <cstdlib>
#include <iostream>
#include "stack.h"

Stack::Stack(){
   this->top = new node;
   this->top->data = -1;
   this->top->next = NULL;
   this->top->prev = NULL;
}
   
Stack::~Stack(){
   while(!isEmpty()){
      this->pop();
   }
   delete this->top;
   this->top = NULL;
}
      
void Stack::push(int n){
   this->top->next = new node;
 
   this->top->data = n;
   this->top->next->prev = this->top;
   this->top = this->top->next;
   this->top->next = NULL;

   return;
}

int Stack::peek(){
   return this->top->prev->data;
}

void Stack::pop(){
   if (isEmpty()){
      return;
   } else {
      node* temp;
      temp = this->top;
      this->top = this->top->prev;
      delete temp;
      return;
   }
}

bool Stack::isEmpty(){
   if (this->top->prev == NULL){
      return true;
   } else {
      return false;
   }
}
