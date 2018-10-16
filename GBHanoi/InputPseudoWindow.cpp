// author: chris-scientist
// created at: 16/10/2018

#include "InputPseudoWindow.h"

char * InputPseudoWindow::getPseudo() {
  gb.gui.keyboard(Lang::getYourPseudo(), pseudo);
  gb.display.clear();
  
  return pseudo;
}

