// author: chris-scientist
// created at: 04/10/2018
// updated at: 16/10/2018

#include "HighScore.h"

HighScore::HighScore(char* aName, unsigned int aScore) : score(aScore) {
  strncpy(nameOfScore, aName, 5);
}

// a.compare(b)
// Si a == b alors retourner 0
// Si a > b alors retourner 1
// Si a < b alors retourner -1
int HighScore::compareTime(const unsigned int aTimeInSeconds) {
  if(score == aTimeInSeconds) {
    return 0;
  } else if(score > aTimeInSeconds) {
    return 1;
  } else {
    return -1;
  }
}

const char* HighScore::getName() const {
  return nameOfScore;
}

unsigned int HighScore::getScore() const {
  return score;
}

void HighScore::setName(char* aName) {
  strncpy(nameOfScore, aName, 5);
}

void HighScore::setScore(unsigned int aScore) {
  score = aScore;
}

