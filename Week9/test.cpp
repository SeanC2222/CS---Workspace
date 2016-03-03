#include "stack.h"
#include "queue.h"
#include <iostream>

using namespace std;

void doesNothing(Stack);

int main(){

   int temp = 0;

   Stack myStack;

   int count = 0;

   cout << "Enter a value for stack index " << count << ": ";
   while (cin >> temp){
      count++;
      myStack.push(temp);
      cout << "Enter a value for stack index " << count << ": ";
   }
   
   cout << "Stack values: " << endl;
   while (count > 0){
      cout << myStack.peek() << endl;
      myStack.pop();
      count--;
   }

   cout << endl;

   cin.clear();
   cin.ignore(100,'\n');

   Queue myQueue;

   cout << "Enter a value for queue index " << count << ": ";
   while (cin >> temp){
      count++;
      myQueue.addBack(temp);
      cout << "Enter a value for queue index " << count << ": ";
   }

   cout << "Queue values: " << endl;
   while (count > 0){
      cout << myQueue.getFront() << endl;
      myQueue.removeFront();
      count--;
   }
   return 0;
}   

