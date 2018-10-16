// author: chris-scientist
// created at: 04/10/2018
// updated at: 16/10/2018

#ifndef HIGHSCORE
#define HIGHSCORE

#include <cstring>

class HighScore {
  private:
    char nameOfScore[5];
    unsigned int score;
  public:
    HighScore(char* aName, unsigned int aScore);
    int compareTime(const unsigned int aTimeInSeconds);
    const char* getName() const;
    unsigned int getScore() const;
    void setName(char* aName);
    void setScore(unsigned int aScore);
};

#endif

