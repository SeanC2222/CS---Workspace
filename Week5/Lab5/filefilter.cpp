#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
#include "filefilter.h"

//Base Constructor
FileFilter::FileFilter(){
   //Nothing to initialize
}

/* Function: void FileFilter::doFilter(ifstream&, ofstream&)
 * Description: Gets input, tranforms it, and outputs to ofstream
 * Parameters:	  ifstream& ifs - input source
 *		  ofstream& ofs - output location
 * Pre-Conditions: Valid input source opened and ready for transformation
 * Post-Conditions: Both streams still open, ifs at EOF, ofs transformed
 */
void FileFilter::doFilter(ifstream& ifs, ofstream& ofs){
   char temp;
   while (ifs.peek() != EOF){
      temp = ifs.get();
      temp = transform(temp);
      ofs << temp;
   }
   return;
}

//FileNoFilter Constructor
FileNoFilter::FileNoFilter() {
   //Nothing to initialize
}

/* Function: char FileNoFilter(char)
 * Description: Returns character passed to function unchanged
 * Paramters:  char c - Any valid character
 * Pre-Conditions: None
 * Post-Conditions: c is returned to function call
 */
char FileNoFilter::transform(char c) {
   return c;
}

//FileToUpper Constructor
FileToUpper::FileToUpper() {
   //Nothing to initialize
}

/* Function: FileToUpper::transform(char)
 * Description: If c is alphabetic, return uppercase c, else return c
 * Parameters:	  char c - Any valide character
 * Pre-Conditions: None
 * Post-Conditions: c is returned to function call
 */
char FileToUpper::transform(char c) {
   return toupper(c);
}

//FileToCaesar constructor, no arguments
FileToCaesar::FileToCaesar() {
   this->key = 0;
}

//FileToCaesar constructor, key initialized to c
FileToCaesar::FileToCaesar(int c) {
   this->key = c;
}

/* Function: void FileToCaesar::setKey(int)
 * Description: Sets the encryption key to an integer value
 * Parameters:	  int c - valid int 
 * Pre-Conditions: None
 * Post-Conditions: key of instantiation is set to c
 */
void FileToCaesar::setKey(int c) {
   this->key = c;
   return;
}

/* Function: char FileToCaesar::transform(char)
 * Description: If character is whitespace return it, else transforms character
 *	        c by associated key value
 * Parameters:	  char c - valid character
 * Pre-Conditions: None
 * Post-Conditions: returns either whitespace, or transformed c
 */
char FileToCaesar::transform(char c) {
   //If whitespace return unchanged
   if (c == ' ' || c == '\n'){
      return c;
   //Else transform character
   } else {
      //Returns base character c,
      //    plus key value mod 26 (Lab requirement)
      return (c + (this->key % (26)));
   }
}

//FileToCipher constructor, no arguments
FileToCipher::FileToCipher() {
   this->key = 0;
}

//FileToCipher constructor, key initialized to c
FileToCipher::FileToCipher(int c) {
   this->key = c;
}

/* Function: void FileToCipher::setKey(int)
 * Description: Sets the encryption key to an integer value
 * Parameters:	  int c - valid int 
 * Pre-Conditions: None
 * Post-Conditions: key of instantiation is set to c
 */
void FileToCipher::setKey(int c){
   this->key = c;
   return;
}

/* Function: void doFilter(ifstream&, ofstream&)
 * Description: Overrides FileFilter::doFilter to format output
 * Parameters:	  ifstream& ifs - Open valid input stream
 *		  ofstream& ofs - valid output stream
 * Pre-Conditions: ifs must be valid and open, and ofs must be open
 * Post-Conditions: ifs still open, tranformed output sent to ofs
 */
void FileToCipher::doFilter(ifstream& ifs, ofstream& ofs) {

   //Temporary character for manipulation
   char temp;

   //Character Count for formatting
   int cCount = 0;

   //While ifs isn't at the EOF
   while (ifs.peek() != EOF){
      temp = ifs.get();

      //Ignores whitespace
      if (temp == ' ' || temp == '\n'){
	 continue;
      }

      //Tranforms, and outputs temp
      temp = this->transform(temp);
      ofs << temp;

      //Increments character count
      cCount++; 

      //Every 5 characters output a space
      if (cCount % 5 == 0){
	 ofs << ' ';
      }
      
      //Every 25 characters output an endline, and reset cCount
      if(cCount % 25 == 0){
	 ofs << '\n';
	 cCount = 0;
      }
   }

   return;
}

/* Function: FileToCipher::transform(char)
 * Description: Performs Cipher transform first, then upper transform
 * Parameters:	  char c - valid char c
 * Pre-Conditions: None
 * Post-Conditions: Returns transformed char c
 */
char FileToCipher::transform(char c) {
   return FileToUpper::transform(FileToCaesar::transform(c));
}
