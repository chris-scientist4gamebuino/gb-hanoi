// author: chris-scientist
// created at: 02/10/2018

#include "Window.h"

void Window::paintWinnerWindow() {
  gb.display.setColor(BROWN);
  gb.display.setFontSize(2);
  gb.display.println("");
  gb.display.println("");
  gb.display.println("  GAGNE");

  gb.display.setColor(WHITE);
  gb.display.setFontSize(1);
  gb.display.println();
  gb.display.println("(A) pour rejouer");
  //gb.display.println("(B) acceder au menu");
}

