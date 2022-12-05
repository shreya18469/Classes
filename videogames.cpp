#include <iostream>
#include <cstring>
#include "videogames.h"
#include "media.h"

using namespace std;
int videogame::getType() {
  return 1;
}

//constructors and destructors

videogame::videogame() {

}

videogame::~videogame() {

}
//videogame getters and setters
void videogame::setPublisher(char p[]) {
  strcpy (publisher, p);
}

void videogame:: setRating(int r) {
  rating = r;
}

char* videogame::getPublisher() {
  return publisher;
}

int videogame::getRating() {
  return rating;
}
