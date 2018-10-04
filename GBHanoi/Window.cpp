// author: chris-scientist
// created at: 02/10/2018
// updated at: 04/10/2018

#include "Window.h"

void Window::paintAboutWindow() {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.println();
  gb.display.println();
  gb.display.println();
  gb.display.println("     Met'Hanoi");
  gb.display.setColor(WHITE);
  gb.display.println(Lang::getCreatedBy());
  gb.display.setColor(BROWN);
  gb.display.println("   chris-scientist");
  gb.display.setColor(WHITE);
  gb.display.println();
  gb.display.println();
  gb.display.println();
  gb.display.print(Lang::getGoToMenu());
}

const int Window::paintMenu() {
  const char* items[] = {
    Lang::getNewPart(),
    Lang::getAbout()
  };

  const uint8_t indexItem = gb.gui.menu("Menu", items);
  int choice = 0;
  if(items[indexItem] == Lang::aboutFR || items[indexItem] == Lang::aboutEN) {
    choice = 1;
  }
  return choice;
}

void Window::paintPauseWindow() {
  gb.display.setFontSize(2);
  gb.display.setColor(BROWN);
  gb.display.println();
  gb.display.println();
  gb.display.println("  Pause");
  gb.display.setFontSize(1);
  gb.display.setColor(WHITE);
  gb.display.println();
  gb.display.println();
  gb.display.println(Lang::getGetBackPart());
  gb.display.println(Lang::getGoToMenu());
}


void Window::paintWinnerWindow() {
  bool isEnLang = Lang::isEnglishLanguage();
  
  gb.display.setColor(BROWN);
  if(isEnLang) {
    gb.display.setFontSize(1);
    gb.display.println("");
    gb.display.println("");
  } else {
    gb.display.setFontSize(2);
  }
  gb.display.println("");
  gb.display.println("");
  gb.display.println(Lang::getCongratulations());

  gb.display.setColor(WHITE);
  gb.display.setFontSize(1);
  if(isEnLang) {
    gb.display.println();
    gb.display.println("");
  }
  gb.display.println();
  gb.display.println(Lang::getToRetry());
  gb.display.println(Lang::getGoToMenu());
}

