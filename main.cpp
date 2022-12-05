/*
Shreya Suresh
12/4/22
Classes- database that stores video games, music, and movies. User can add, search, delete or quit.
 */
#include <iostream>
#include <cstring>
#include "media.h"
#include "videogames.h"
#include "movies.h"
#include "music.h"
#include <vector>

using namespace std;

vector <media*>* medialist;
//add media to the database
void addMedia(vector <media*>* medialist) {
  int mediatype = 0;
  cout << "Enter 1 if you want to add a videogame, 2 if you want to add a music, or 3 if you want to add a movie" << endl;
  cin >> mediatype;
  //adds videogame after user inputs data
  if (mediatype == 1) {
    videogame* v = new videogame();
    char title[100];
    cout << "What is the title?" << endl;
    cin.get();
    cin.get(title, 100);
    cin.get();
    v->setTitle(title);
    int yr = 0;
    cout << "What year was the video game published?" << endl;
    cin >> yr;
    v->setYear(yr);
    char pubs[100];
    cout << "Who is the publisher" << endl;
    cin.get();
    cin.get(pubs, 100);
    cin.get();
    v->setPublisher(pubs);
    int rating = 0;
    cout << "What is the rating" << endl;
    cin >> rating;
    v->setRating(rating);
    v->getType();
    medialist->push_back(v);
  }
  //adds music after user inputs data
  else if (mediatype == 2) {
    music* mu = new music();
    char title[100];
    cout << "What is the title?" << endl;
    cin.get();
    cin.get(title, 100);
    cin.get();
    mu->setTitle(title);
    int yr = 0;
    cout << "What year what it published?"<< endl;
    cin >> yr;
    mu->setYear(yr);
    char pubs[100];
    cout << "Who is the publisher?" << endl;
    cin.get();
    cin.get(pubs, 100);
    cin.get();
    mu->setPublisher(pubs);
    int dur = 0;
    cout << "How long is the song(seconds)?" << endl;
    cin >> dur;
    mu->setDuration(dur);
    medialist->push_back(mu);
    char artist[100];
    cout << "Who is the artist?" << endl;
    cin.get();
    cin.get(artist, 100);
    cin.get();
    mu->setArtist(artist);
  }
  //add movies after user inputs data
  else if (mediatype == 3) {
    movie* mo = new movie();
    char title[100];
    cout << "What is the title?" << endl;
    cin.get();
    cin.get(title, 100);
    cin.get();
    mo->setTitle(title);
    int yr = 0;
    cout << "What year did the movie release?" << endl;
    cin >> yr;
    mo->setYear(yr);
    char direct[100];
    cout << "Who is the director?" << endl;
    cin.get();
    cin.get(direct, 100);
    cin.get();
    mo->setDirector(direct);
    int rating = 0;
    cout << "What is the rating?" << endl;
    cin >> rating;
    mo->setRating(rating);
    int dur = 0;
    cout << "How long is the movie(minutes)?" << endl;
    cin >> dur;
    mo->setDuration(dur);
    medialist->push_back(mo);
  }
}

void deleteMedia(vector <media*>* medialist) { // delete media from the database
  int index = -1; // set index to impossible number
  char searchtype[3];
  cout << "Do you want to delete by title(Enter 1), or do you want to delete by year(Enter 2)" << endl;
  cin >> searchtype;

  if (searchtype[0] == '1') { // delete by title
    cout << "Deleting by title" << endl;
    char inputstr[100];
    cout << "What title are you deleting?" << endl;
    cin >> inputstr;
    videogame* v;
    music* mu;
    movie* mo;
    bool foundt = true;
    do {
      foundt = false;
      index = -1;
      for (int i = 0; i < medialist->size(); i++) {
	media* m = (*medialist)[i];
	if (m->getType() == 1) { 
	  v = (videogame*)m;
	  if (strcmp(inputstr, v->getTitle()) == 0) {
	    index = i;
	    break;
	  }
	}
	if (m->getType() == 2) { 
	  mu = (music*)m;
	  if (strcmp(inputstr, mu->getTitle()) == 0) {
	    index = i;
	    break;
      }
    }
	if (m->getType() == 3) { 
	  mo = (movie*)m;
	  if (strcmp(inputstr, mo->getTitle()) == 0) {
	    index = i;
	    break;
	  }
	}
      }
      if (index > -1) { // erase media
	char yn;
	cout << "Are you sure you want to delete this? Enter y or n." << endl;
	cin >> yn;
	if (yn == 'y'){
	foundt = true;
	delete (*medialist)[index]; 
	medialist->erase(medialist->begin()+index);
	cout << "Deleted." << endl;
	index = -1;
	} else {
	  cout << "Cancelled delete." << endl;
	  return;
	}
      }
    } 
    while(foundt);
  }

  else if (searchtype[0] == '2') { // delete by year
      int input = 0;
      cout << "What year are you deleting?" << endl;
      cin >> input;
      videogame* v;
      music* mu;
      movie* mo;
      bool found = true;
      do {
	found = false;
	index = -1;
	for (int i = 0; i < medialist->size(); i++) { 
	  media* m = (*medialist)[i];
	  if (m->getType() == 1) {
	    v = (videogame*)m;
	    if (input == v->getYear()) {
	index = i;
	break;
      }
    }

    if (m->getType() == 2) {
      mu = (music*)m;
      if (input == mu->getYear()) {
	index = i;
	break;
      }
    }
    if (m->getType() == 3) {
      mo = (movie*)m;
      if (input == mo->getYear()) {
	index = i;
	break;
      }
    }
    }
    if (index > -1) {
      char yn;
      cout << "Are you sure you want to delete this? Enter y or n." << endl;
      cin >> yn;
      if (yn == 'y'){
      found = true;
      delete (*medialist)[index];
      medialist->erase(medialist->begin()+index);
      cout << "Deleted." << endl;
      index = -1;
      } else{
	cout << "Cancelled delete." << endl;
 	return;
      } 
    }

 } while (found);

    }
    else {
      cout << "Enter a valid type" << endl;
      cin >> searchtype;

    }
  }
void searchMedia(vector <media*>* medialist) { // allow user to search the database
  int searchty;
  cout << "Do you want to search by title(enter 1) or year(enter 2)" << endl;
  cin >> searchty;
  if (searchty == 1){ // search by title
    char input[40];
    cout << "What's the title?" << endl;
    cin >> input;
    videogame* v;
    music* mu;
    movie* mo;
    for (int i = 0; i < medialist->size(); i++){
      media* me = (*medialist)[i];
      if(me->getType() == 1){
	v = (videogame*)me;
	if (strcmp(input, v->getTitle()) == 0){
	  cout << "Videogame: Title: " <<v->getTitle() << " Year: " << v->getYear() << " Publisher: " << v->getPublisher() << " Rating: " <<v->getRating()<<endl;
	}
      }
      if (me->getType() == 2){
	mu = (music*)me;
	if (strcmp(input, mu->getTitle()) == 0){
	  cout << "Music: Title: " << mu->getTitle() << " Year: " << mu->getYear() << " Artist: " << mu->getArtist() << " Duration: "<< mu->getDuration() << " Publisher: " << mu->getPublisher() << endl;
	}
      }
      if (me->getType() == 3){
	mo = (movie*)me;
	if (strcmp(input, mo->getTitle()) == 0){
	  cout << "Movie: Title: " << mo->getTitle() << " Year: " << mo->getYear() << " Director: " << mo->getDirector()  << " Duration: " << mo->getDuration() << " Rating: " << mo->getRating() << endl;


	}
      }
    }

  } else if(searchty == 2){ // search by year
    int input = 0;
    cout << "What's the year?" << endl;
    cin >> input;
    videogame* v;
    music* mu;
    movie* mo;
    for (int i = 0; i < medialist->size(); i++){
      media* me = (*medialist)[i];
      if(me->getType() == 1){
	 v = (videogame*)me;
      if (input == v->getYear()) {
     cout << "Videogame: Title: "<< v->getTitle() << " Year: " << v->getYear()<< " Publisher: " << v->getPublisher() << " Rating: " << v->getRating() << endl;
      }
    }
      if (me->getType() == 2){
	mu = (music*) me;
	if (input == mu->getYear()){
	  cout << "Music: Title: " << mu->getTitle() << " Year: " << mu->getYear()<< " Artist: " << mu->getArtist() << " Duration: "<< mu->getDuration() << " Publisher: " << mu->getPublisher() << endl;
	}
      }
      if (me->getType() == 3){
	mo = (movie*)me;
	if (input == mo->getYear()){
	  cout << "Movie: Title: " << mo->getTitle() << " Year: " << mo->getYear() << " Director: " << mo->getDirector()  << " Duration: " << mo->getDuration() <<" Rating: " << mo->getRating() << endl;
	}
      }
  }
  } else {
    cout << "Enter a valid input(1 or 2)" << endl;
    return;
    cin >> searchty;
  }
}
//display all media
void printMedia(vector <media*>* medialist) {
 videogame* v;
 music* mu;
 movie* mo;
  for (int i = 0; i < medialist->size(); i++) {
    media* m = (*medialist)[i];
    //cout << m->getType() << endl;
    if (m->getType() == 1) {
      v = (videogame*)m;
      cout << "Videogame: Title: "<< v->getTitle() << " Year: " << v->getYear() << " Publisher: " << v->getPublisher() << " Rating: " << v->getRating() << endl;
    }
    if (m->getType() == 2) {
      mu = (music*)m;
      cout << "Music: Title: " << mu->getTitle() << " Year: " << mu->getYear() << " Artist: " << mu->getArtist() << " Duration: "<< mu->getDuration() << " Publisher: " << mu->getPublisher() << endl;
    }
    if (m->getType() == 3) {
      mo = (movie*)m;
      cout << "Movie: Title: " << mo->getTitle() << " Year: " << mo->getYear() << " Director: " << mo->getDirector()  << " Duration: " << mo->getDuration() <<" Rating: " << mo->getRating() << endl;
    }

  }
}
void getResponse(char response[10]) {
  bool running = true;
  cout << "Enter ADD, SEARCH, PRINT, DELETE, or QUIT" << endl;
  cin >> response;
  running = true;
}

int main() {
  vector <media*>* medialist = new vector<media*>();
  char response[10];
  bool running = true;
  getResponse(response);

  while (running == true) {
    if (response[0] == 'A' && response[1] == 'D' && response[2] == 'D') {
      addMedia(medialist);
      getResponse(response);
 }
    else if (response[0] == 'S' && response[1] == 'E' && response[2] == 'A' && response[3] =='R' && response[4] == 'C' && response[5] == 'H') {
   searchMedia(medialist);
   getResponse(response);
 }
    else if (response[0] == 'D' && response[1] == 'E' && response[2] == 'L' && response[3] == 'E' && response[4] == 'T' && response[5] == 'E') {
      deleteMedia(medialist);
      getResponse(response);
 }
    else if (response[0] == 'P' && response[1] == 'R' && response[2] == 'I' && response[3] =='N' && response[4] == 'T') {
      printMedia(medialist);
      getResponse(response);
 }
      else if (response[0] == 'Q' && response[1] == 'U' && response[2] == 'I' && response[3] =='T') {
	return 0;
   }
      else {
	cout << "Enter a valid response" << endl;
	getResponse(response);
   }
  }
}

