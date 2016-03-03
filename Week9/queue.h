#ifndef myQUEUE_H
#define myQUEUE_H

class Queue{

   struct node{
      int data;
      node* next;
      node* prev;
   };

   private:
      node* start;
      node* end;
      bool isEmpty();

   public:
      Queue();
      ~Queue();

      void addBack(int);
      int getFront();
      void removeFront();
};

#endif
