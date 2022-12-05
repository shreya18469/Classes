#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

//videogame class
class videogame: public media {
  public:
  videogame();
  ~videogame();
  void setPublisher(char p[]);
  void setRating(int r);
  char* getPublisher();
  int getRating();
  int getType();
  private:
  char publisher[100];
  int rating;
};

#endif
