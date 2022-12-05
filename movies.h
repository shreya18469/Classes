#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

#ifndef MOVIES_H
#define MOVIES_H

//movie class
class movie: public media {
  public:
  movie();
  ~movie();
  void setDirector(char di[]);
  void setDuration(int du);
  void setRating(int r);
  char* getDirector();
  int getDuration();
  int getRating();
  int getType();
  private:
  char director[100];
  int duration;
  int rating;
};

#endif
