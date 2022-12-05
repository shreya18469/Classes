#include <iostream>
#include <cstring>
#include "music.h"
#include "media.h"

using namespace std;
int music::getType() {
  return 2;
}

music::music() {

}

music::~music() {

}


//music getters and setters
void music::setArtist(char a[]) {
  strcpy(artist, a);
}

void music::setDuration(int du) {
  duration = du;
}

void music::setPublisher(char p[]) {
  strcpy(publisher, p);
}

char* music::getArtist() {
  return artist;
}

int music::getDuration() {
  return duration;
}

char* music::getPublisher() {
  return publisher;
}
