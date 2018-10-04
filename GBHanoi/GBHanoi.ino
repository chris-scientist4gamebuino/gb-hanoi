// author: chris-scientist
// created at: 20/09/2018
// updated at: 01/10/2018

#include <Gamebuino-Meta.h>

#include "BoardGameController.h"
#include "BoardGameModel.h"
#include "BoardGameView.h"

BoardGameController * controller;

void setup() {
  // initialisation de la gamebuino
  gb.begin();
  // intialisation des objets
  BoardGameModel * model = new BoardGameModel();
  controller = new BoardGameController(model, new BoardGameView(model));
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  // effacer l'écran
  gb.display.clear();

  controller->run();
}
