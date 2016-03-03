#ifndef mySTACK_H
#define mySTACK_H

class Stack{

   struct node{

      int data;
      node* next;
      node* prev;
   };

   private:
      node* top;
      bool isEmpty();

   public:
      Stack();
      ~Stack();
      void push(int);
      int peek();
      void pop();
};

#endif
