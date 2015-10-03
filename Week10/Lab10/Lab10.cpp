#include <iostream>
#include <chrono>

using namespace std;

int fibNum(int);
int recFibNum(int);
long factorial(int);
long recFactorial(int);

int main(){

   int index = 0;

   cout << "Which index of the Fibonacci number would you like to test? ";
   cin >> index;

   int a = 0;

   std::chrono::high_resolution_clock clck;
   std::chrono::high_resolution_clock::time_point start = clck.now();

   for (int i = 0; i < index+1; i++){
      a = fibNum(a);
   }

   std::chrono::high_resolution_clock::time_point end = clck.now();
   std::chrono::duration<double> diff = end - start;

   cout << "Fibonacci Iterative time: " << diff.count() << endl;

   start = clck.now();
   recFibNum(index);
   end = clck.now();
   diff = end - start;

   cout << "Fibonacci Recursive time: " << diff.count() << endl;

   start = clck.now();
   factorial(index);
   end = clck.now();
   diff = end - start;

   cout << "Factorial (Single Recursion) time: " << diff.count() << endl;
   
   start = clck.now();
   recFactorial(index);
   end = clck.now();
   diff = end - start;

   cout << "Factorial (Tail Recursion) time: " << diff.count() << endl;

   return 0;

}

int fibNum(int a){

   static int b = 1;
   a += b;
   b = (a-b);

   return a;
}

int recFibNum(int a){

   if (a == 0 || a == 1){
      return 1;
   } else {
      return recFibNum(a-1) + recFibNum(a-2);
   }
}

long factorialHelper(int n, int results){
   if (n == 1){
      return results;
   } else {
      return factorialHelper(n-1,n*results);
   }
}

long factorial(int n){
   return factorialHelper(n,1);
}

long recFactorial(int n){
   if (n == 1){
      return 1;
   } else {
      return n * recFactorial(n-1);
   }
}
