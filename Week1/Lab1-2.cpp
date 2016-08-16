#include <iostream>
#include "f.h"
#include "g.h"

int main() {
   char a = 0;
   do{
      std::cout << "Which function would you liKe, \"f()\" or \"g()\" \n"
	        << "Type \'0\' to exit." << std::endl;

      std::cin >> a;
      std::cin.ignore(1000,'\n');
      if (a == 'f') {
	 f();
	 std::cout << "Press enter to continue." << std::endl;
      }
      if (a == 'g') {
	 g();
	 std::cout << "Press enter to continue." << std::endl;
      }
      if (a != 'f' && a != 'g' && a != '0'){
	 std::cout << "Not a valid function. Press enter to continue."
		   << std::endl;
      } 
      if (a != '0'){
	 std::cin.ignore(1000,'\n');
      }
   }while (a != '0'); 

   return 0;
}
