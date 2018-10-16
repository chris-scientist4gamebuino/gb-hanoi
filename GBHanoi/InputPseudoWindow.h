// author: chris-scientist
// created at: 16/10/2018

#ifndef INPUTPSEUDOWINDOW
#define INPUTPSEUDOWINDOW

#include <Gamebuino-Meta.h>

#include "Lang.h"

class InputPseudoWindow {
  private:
    char pseudo[5] = "    ";
  public:
    char * getPseudo();
};

#endif

