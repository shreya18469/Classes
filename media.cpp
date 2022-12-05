#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;
int media::getType() {
  return 0;
}
//constructors and destructors
media::media() {

}

media::~media() {

}


//methods for the fields the child classes have in common

void media::setYear(int y) {
  year = y;
}

void media::setTitle(char t[]) {
  strcpy(title, t);
}

char* media::getTitle() {
  return title;
}

int media::getYear() {
  return year;
}
