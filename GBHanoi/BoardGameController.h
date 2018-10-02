// author: chris-scientist
// created at: 30/09/2018
// updated at: 02/10/2018

#ifndef BOARDGAMECONTROLLER
#define BOARDGAMECONTROLLER

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "BoardGameModel.h"
#include "BoardGameView.h"
#include "Window.h"

class BoardGameController {
  private:
    BoardGameModel * boardGameModel;
    BoardGameView * boardGameView;
    bool isStart; // true = pour indiquer que la tour de départ a été choisi, false sinon
    bool isEnd; // true = pour indiquer que la tour de fin a été choisi, false sinon
    bool isTowerInit; // true = pour indiquer que les tours sont initialisés, false sinon
    bool isGame; // true = pour indiquer que le jeu est en cours, false sinon
    bool isFinish; // true = pour indiquer que le jeu est finie, false sinon
    int indexSelectedTower;
    
    void resetGame();
  public:
    BoardGameController(BoardGameModel * aBoardGameModel, BoardGameView * aBoardGameView);
    void manageCommands();
    void paint();
};

#endif

