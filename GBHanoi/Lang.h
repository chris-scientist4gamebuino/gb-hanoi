// author: chris-scientist
// created at: 03/10/2018
// updated at: 16/10/2018

#ifndef LANG
#define LANG

#include <Gamebuino-Meta.h>

class Lang {
  public:
    static const char* aboutFR;
    static const char* aboutEN;
    static const char* congratulationsFR;
    static const char* congratulationsEN;
    static const char* createdByFR;
    static const char* createdByEN;
    static const char* endFR;
    static const char* endEN;
    static const char* getBackPartFR;
    static const char* getBackPartEN;
    static const char* goToMenuFR;
    static const char* goToMenuEN;
    static const char* highScoreFR;
    static const char* highScoreEN;
    static const char* newPartFR;
    static const char* newPartEN;
    static const char* orFR;
    static const char* orEN;
    static const char* startFR;
    static const char* startEN;
    static const char* toRetryFR;
    static const char* toRetryEN;
    static const char* yourPseudoFR;
    static const char* yourPseudoEN;

    static const bool isEnglishLanguage();
    static const char* getAbout();
    static const char* getCongratulations();
    static const char* getCreatedBy();
    static const char* getEnd();
    static const char* getGetBackPart();
    static const char* getGoToMenu();
    static const char* getHighScore();
    static const char* getNewPart();
    static const char* getOr();
    static const char* getStart();
    static const char* getToRetry();
    static const char* getYourPseudo();
};

#endif

