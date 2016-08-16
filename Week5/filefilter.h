#ifndef FILEFILTER_H
#define FILEFILTER_H

#include <fstream>

//Parent Class of all filter classes
class FileFilter{
   protected:
      virtual char transform(char) = 0;
   public:
      FileFilter();
      virtual void doFilter(std::ifstream&, std::ofstream&);
};

//Non-Filtered output
class FileNoFilter : public FileFilter{
   protected:
      char transform(char);
   public:
      FileNoFilter();

};

//All Alphabetic Characters converted to uppercase
class FileToUpper : public FileFilter {
   protected:
      char transform(char);
   public:
      FileToUpper();
};

//Simple Caesar encryption filter
class FileToCaesar : public FileFilter {
   protected:
      char transform(char);
      char key;
   public:
      FileToCaesar();
      FileToCaesar(int);
      void setKey(int);
};

//Combined FiletoCaesar and FiletoUpper filters
class FileToCipher : public FileToCaesar, public FileToUpper {
   protected:
      char transform(char);
   public:
      FileToCipher();
      FileToCipher(int);
      void setKey(int);
      virtual void doFilter(std::ifstream&, std::ofstream&);
};
#endif
