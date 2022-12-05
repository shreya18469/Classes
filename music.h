#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

#ifndef MUSIC_H
#define MUSIC_H

//music class
class music: public media {
  public:
  music();
  ~music();
  void setArtist(char a[]);
  void setDuration(int du);
  void setPublisher(char p[]);
  char* getArtist();
  int getDuration();
  char* getPublisher();
  int getType();
  private:
  char artist[100];
  int duration;
  char publisher[100];
};


#endif


