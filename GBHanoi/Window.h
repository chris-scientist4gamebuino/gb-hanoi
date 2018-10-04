// author: chris-scientist
// created at: 02/10/2018
// updated at: 04/10/2018

#ifndef WINDOW
#define WINDOW

#include <Gamebuino-Meta.h>

#include "Lang.h"

class Window {
  public:
    static void paintAboutWindow();
    static const int paintMenu();
    static void paintPauseWindow();
    static void paintWinnerWindow();
};

#endif

