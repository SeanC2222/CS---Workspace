#include <iostream>

void ptrSwap(int*,int*,int*);

int main() {

   int *a, *b, *c;
   a = new int;
   b = new int;
   c = new int;

   std::cout << "Enter your first variable: ";
   std::cin >> *a;

   std::cout << "Enter your second variable: ";
   std::cin >> *b;

   std::cout << "Enter your third variable: ";
   std::cin >> *c;

   std::cout << "a: " << *a << " b: " << *b << " c: " << *c << std::endl;
   ptrSwap(a,b,c);
   std::cout << "a: " << *a << " b: " << *b << " c: " << *c << std::endl;

   return 0;

}

void ptrSwap(int* low, int* mid, int* high){
   
   int temp;

   if (*high < *low){
      temp = *high;
      *high = *low;
      *low = temp;
   }
   if (*mid < *low){
      temp = *mid;
      *mid = *low;
      *low = temp;
   }
   if (*high < *mid){
      temp = *high;
      *high = *mid;
      *mid = temp;
   }
   return;
}
