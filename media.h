#include <iostream>
#include <cstring>

using namespace std;

#ifndef MEDIA_H
#define MEDIA_H

class media {
 public:
  media();
  ~media();
  void setTitle(char t[]);
  char* getTitle();
  void setYear(int y);
  int getYear();
 virtual int getType();
 private:
  int year;
  char title[100];
};


#endif
