// author: chris-scientist
// created at: 30/09/2018
// updated at: 03/10/2018

#ifndef BOARDGAMECONTROLLER
#define BOARDGAMECONTROLLER

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "BoardGameModel.h"
#include "BoardGameView.h"
#include "Window.h"
#include "GameStateManager.h"
#include "Lang.h"
#include "TimeModel.h"
#include "HighScoreManager.h"

class BoardGameController {
  private:
    BoardGameModel * boardGameModel;
    BoardGameView * boardGameView;
    GameStateManager * stateManager;
    TimeModel * timeModel;
    HighScoreManager * scoreManager;
    int indexSelectedTower;
    
    void resetGame();
    void manageCommands();
    void paint();
  public:
    BoardGameController(BoardGameModel * aBoardGameModel, BoardGameView * aBoardGameView);
    void run();
};

#endif

