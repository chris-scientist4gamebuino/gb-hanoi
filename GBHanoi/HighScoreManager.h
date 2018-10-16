// author: chris-scientist
// created at: 04/10/2018
// updated at: 16/10/2018

#ifndef HIGHSCOREMANAGER
#define HIGHSCOREMANAGER

#include <Gamebuino-Meta.h>

#include "HighScore.h"
#include "InputPseudoWindow.h"

class HighScoreManager {
  private:
    static const int NB_HIGH_SCORE_BLOCK = 0;
    static const int NAME_HIGH_SCORE_1_BLOCK = 1;
    static const int SCORE_HIGH_SCORE_1_BLOCK = 2;
    static const int NAME_HIGH_SCORE_2_BLOCK = 3;
    static const int SCORE_HIGH_SCORE_2_BLOCK = 4;
    static const int NAME_HIGH_SCORE_3_BLOCK = 5;
    static const int SCORE_HIGH_SCORE_3_BLOCK = 6;
  
    HighScore * highScore1;
    HighScore * highScore2;
    HighScore * highScore3;
    int nbHighScore;
    InputPseudoWindow * inPseudoWindow;
    int indexNewHighScore;

    void saveHighScore(char * aName, unsigned int aScore, int aBlockName, int aBlockScore) const;
    const int setHighScore4Time(const unsigned int aTimeOfPart);
  public:
    static const int HIGH_SCORE_1 = 1;
    static const int HIGH_SCORE_2 = 2;
    static const int HIGH_SCORE_3 = 3;

    HighScoreManager();
    void loadAllHighScore();
    void saveAllHighScore() const;
    HighScore * getHighScore(const int anIndex);
    bool saveScoreIfNewHighScore(const unsigned int aTimeOfPart);
    void resetIndexNewHighScore();
    const int getNbHighScore() const;
    const int getIndexNewHighScore() const;
};

#endif

