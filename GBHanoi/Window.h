// author: chris-scientist
// created at: 02/10/2018
// updated at: 16/10/2018

#ifndef WINDOW
#define WINDOW

#include <Gamebuino-Meta.h>

#include <cstring>

#include "Lang.h"
#include "HighScoreManager.h"
#include "HighScore.h"

class Window {
  public:
    static void paintAboutWindow();
    static void paintHighScoreWindow(HighScoreManager * aScoreManager);
    static const int paintMenu();
    static void paintPauseWindow();
    static void paintWinnerWindow();
};

#endif

