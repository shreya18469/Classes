#include <iostream>
#include <cstring>
#include "movies.h"
#include "media.h"

using namespace std;
int movie::getType() {
  return 3;
}
//constructors and destructors
movie::movie() {

}

movie::~movie() {

}


//movie getters and setters
void movie::setDirector(char di[]) {
  strcpy(director, di);
}

void movie::setDuration(int du) {
  duration = du;
}

void movie::setRating(int r) {
  rating = r;
}

char* movie::getDirector() {
  return director;
}

int movie::getDuration() {
  return duration;
}
int movie::getRating() {
  return rating;
}
