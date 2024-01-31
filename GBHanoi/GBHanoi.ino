// author: chris-scientist
// created at: 31/01/2024

#include <Gamebuino-Meta.h>

void setup() {
  // initialisation de la gamebuino
  gb.begin();
}

void loop() {
  // boucle d'attente
  gb.waitForUpdate();

  // effacer l'écran
  gb.display.clear();

  gb.display.print("Met'hanoi 2.x.x...");
}
