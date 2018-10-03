// author: chris-scientist
// created at: 30/09/2018
// updated at: 03/10/2018

#include "BoardGameController.h"

BoardGameController::BoardGameController(BoardGameModel * aBoardGameModel, BoardGameView * aBoardGameView) : 
  boardGameModel(aBoardGameModel), 
  boardGameView(aBoardGameView),  
  indexSelectedTower(1), 
  stateManager(new GameStateManager())
{
  
}

void BoardGameController::manageCommands() {

  if(stateManager->isFinishState()) {
    if(gb.buttons.pressed(BUTTON_A)) {
      resetGame();
      stateManager->nextState();
    }
  } else if(boardGameModel->isFinish(stateManager->isGameState())) {
    stateManager->nextState();
  } else if(stateManager->isGameState()) {
    if(gb.buttons.pressed(BUTTON_RIGHT)) {
      if(!boardGameModel->isRingSelected()) {
        do {
          indexSelectedTower = (indexSelectedTower == 2 ? 0 : indexSelectedTower + 1);
        } while(boardGameModel->getTower(boardGameModel->getIndexTower(indexSelectedTower))->getListOfRing()->isEmpty());
      } else {
        indexSelectedTower = (indexSelectedTower == 2 ? 0 : indexSelectedTower + 1);
        boardGameModel->getRingSelected()->setCurTowerIndex(boardGameModel->getIndexTower(indexSelectedTower));
      }
    } else if(gb.buttons.pressed(BUTTON_LEFT)) {
      if(!boardGameModel->isRingSelected()) {
        do {
          indexSelectedTower = (indexSelectedTower == 0 ? 2 : indexSelectedTower - 1);
        } while(boardGameModel->getTower(boardGameModel->getIndexTower(indexSelectedTower))->getListOfRing()->isEmpty());
      } else {
        indexSelectedTower = (indexSelectedTower == 0 ? 2 : indexSelectedTower - 1);
        boardGameModel->getRingSelected()->setCurTowerIndex(boardGameModel->getIndexTower(indexSelectedTower));
      }
    } else if(gb.buttons.pressed(BUTTON_A)) {
      if(!boardGameModel->isRingSelected()) {
        TowerModel * tower = boardGameModel->getTower(boardGameModel->getIndexTower(indexSelectedTower));
        boardGameModel->setRingSelected(tower->getListOfRing()->removeTop());
      } else {
        if(boardGameModel->getTower(boardGameModel->getIndexTower(indexSelectedTower))->allowToAddRing(boardGameModel->getRingSelected())) {
          boardGameModel->getTower(boardGameModel->getRingSelected()->getCurTowerIndex())->addRing(boardGameModel->getRingSelected());
          boardGameModel->setIsRingSelected(false);
        }
      }
    } else if(gb.buttons.pressed(BUTTON_B)) {
      if(boardGameModel->isRingSelected()) {
        boardGameModel->getTower(boardGameModel->getRingSelected()->getTowerIndex())->addRing(boardGameModel->getRingSelected());
        boardGameModel->setIsRingSelected(false);
        // Si la tour est vide alors on passe à la suivante
        while(boardGameModel->getTower(boardGameModel->getIndexTower(indexSelectedTower))->getListOfRing()->isEmpty()) {
          indexSelectedTower = (indexSelectedTower == 2 ? 0 : indexSelectedTower + 1);
        }
      }
    }
  } else if(stateManager->isSetEndState()) {
    if(gb.buttons.pressed(BUTTON_RIGHT)) {
      do {
        indexSelectedTower = (indexSelectedTower == 3 ? 0 : indexSelectedTower + 1);
      } while(boardGameModel->getIndexTower(indexSelectedTower) == boardGameModel->getStartIndexTower());
    } else if(gb.buttons.pressed(BUTTON_LEFT)) {
      do {
        indexSelectedTower = (indexSelectedTower == 0 ? 3 : indexSelectedTower - 1);
      } while(boardGameModel->getIndexTower(indexSelectedTower) == boardGameModel->getStartIndexTower());
    } else if(gb.buttons.pressed(BUTTON_A)) {
      boardGameModel->setEndIndexTower(indexSelectedTower);
      // Par défaut, l'index est sur la tour qui contient tout les anneaux
      while(boardGameModel->getStartIndexTower() != boardGameModel->getIndexTower(indexSelectedTower)) {
        indexSelectedTower = (indexSelectedTower >= 2 ? 0 : indexSelectedTower + 1);
      }
      stateManager->nextState();
    }
  } else if(stateManager->isSetStartState()) {
    if(gb.buttons.pressed(BUTTON_RIGHT)) {
      indexSelectedTower = (indexSelectedTower == 2 ? 0 : indexSelectedTower + 1);
    } else if(gb.buttons.pressed(BUTTON_LEFT)) {
      indexSelectedTower = (indexSelectedTower == 0 ? 2 : indexSelectedTower - 1);
    } else if(gb.buttons.pressed(BUTTON_A)) {
      boardGameModel->setStartIndexTower(indexSelectedTower);
      // On incrémente l'index pour ne pas pouvoir sélectionner une fin identique au départ
      indexSelectedTower = (indexSelectedTower == 2 ? 0 : indexSelectedTower + 1);
      // Si la tour de départ est sélectionnée alors on l'initialise
      boardGameModel->initTower();
      stateManager->nextState();
    }
  }
}

void BoardGameController::paint() {
  if(! stateManager->isFinishState()) {
    if(stateManager->isSetStartState()) {
      gb.display.print("Depart");
    } else if(stateManager->isSetEndState()) {
      gb.display.print("Fin ");
    }
    
    boardGameView->paint((stateManager->isSetStartState() || stateManager->isSetEndState() || stateManager->isGameState()) ? boardGameModel->getIndexTower(indexSelectedTower) : -1, stateManager->isGameState());
  } else {
    Window::paintWinnerWindow();
  }
}

void BoardGameController::resetGame() {
  boardGameModel->resetTower();
  indexSelectedTower = 1;
  boardGameModel->setStartIndexTower(3);
  boardGameModel->setEndIndexTower(3);
}

