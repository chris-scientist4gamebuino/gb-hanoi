// author: chris-scientist
// created at: 30/09/2018
// updated at: 04/10/2018

#include "BoardGameController.h"

BoardGameController::BoardGameController(BoardGameModel * aBoardGameModel, BoardGameView * aBoardGameView) : 
  boardGameModel(aBoardGameModel), 
  boardGameView(aBoardGameView),  
  indexSelectedTower(1), 
  stateManager(new GameStateManager())
{
  
}

void BoardGameController::run() {
  manageCommands();
  paint();
}

void BoardGameController::manageCommands() {

  if(stateManager->isAboutState()) {
    // Si nous sommes sur l'écran des crédits...

    if(gb.buttons.pressed(BUTTON_B)) {
      //
      // Afficher le menu
      //
      stateManager->nextState();
    }
    
  } else if(stateManager->isPauseState()) {
    // Si la partie est en pause...

    if(gb.buttons.pressed(BUTTON_A)) {
      //
      // Retourner à la partie
      //
      stateManager->setState(GameStateManager::GAME_STATE);
    } else if(gb.buttons.pressed(BUTTON_B)) {
      //
      // Accéder au menu (et réinitiliser le jeu)
      //
      resetGame();
      stateManager->setState(GameStateManager::MENU_STATE);
    }
    
  } else if(stateManager->isFinishState()) {
    // Si le partie est finie (état)...
    
    if(gb.buttons.pressed(BUTTON_A)) {
      //
      // Refaire une partie (et réinitialiser le jeu)
      //
      resetGame();
      stateManager->setState(GameStateManager::SET_START_STATE);
    } else if(gb.buttons.pressed(BUTTON_B)) {
      //
      // Accéder au menu (et réinitialiser le jeu)
      //
      resetGame();
      stateManager->setState(GameStateManager::MENU_STATE);
    }
    
  } else if(boardGameModel->isFinish(stateManager->isGameState())) {
    // Si la partie en cours est finie alors on modifie l'état
    
    stateManager->setState(GameStateManager::FINISH_STATE);
    
  } else if(stateManager->isGameState()) {
    // Si une partie est en cours...
    
    if(gb.buttons.pressed(BUTTON_RIGHT)) {
      //
      // Déplacer le curseur / anneau vers la droite
      //
      if(!boardGameModel->isRingSelected()) {
        do {
          indexSelectedTower = (indexSelectedTower == 2 ? 0 : indexSelectedTower + 1);
        } while(boardGameModel->getTower(boardGameModel->getIndexTower(indexSelectedTower))->getListOfRing()->isEmpty());
      } else {
        indexSelectedTower = (indexSelectedTower == 2 ? 0 : indexSelectedTower + 1);
        boardGameModel->getRingSelected()->setCurTowerIndex(boardGameModel->getIndexTower(indexSelectedTower));
      }
    } else if(gb.buttons.pressed(BUTTON_LEFT)) {
      //
      // Déplacer le curseur / anneau vers la gauche
      //
      if(!boardGameModel->isRingSelected()) {
        do {
          indexSelectedTower = (indexSelectedTower == 0 ? 2 : indexSelectedTower - 1);
        } while(boardGameModel->getTower(boardGameModel->getIndexTower(indexSelectedTower))->getListOfRing()->isEmpty());
      } else {
        indexSelectedTower = (indexSelectedTower == 0 ? 2 : indexSelectedTower - 1);
        boardGameModel->getRingSelected()->setCurTowerIndex(boardGameModel->getIndexTower(indexSelectedTower));
      }
    } else if(gb.buttons.pressed(BUTTON_A)) {
      //
      // Sélectionner / désélectionner un anneau
      //
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
      //
      // Affecter l'anneau sélectionné à sa tour d'origine
      //
      if(boardGameModel->isRingSelected()) {
        boardGameModel->getTower(boardGameModel->getRingSelected()->getTowerIndex())->addRing(boardGameModel->getRingSelected());
        boardGameModel->setIsRingSelected(false);
        // Si la tour est vide alors on passe à la suivante
        while(boardGameModel->getTower(boardGameModel->getIndexTower(indexSelectedTower))->getListOfRing()->isEmpty()) {
          indexSelectedTower = (indexSelectedTower == 2 ? 0 : indexSelectedTower + 1);
        }
      }
    } else if(gb.buttons.pressed(BUTTON_MENU)) {
      //
      // Mettre en pause
      //
      stateManager->nextState();
    }
    
  } else if(stateManager->isSetEndState()) {
    // Si l'utilisateur doit choisir la tour de destination
    
    if(gb.buttons.pressed(BUTTON_RIGHT)) {
      //
      // Sélectionner la tour à droite
      //
      do {
        indexSelectedTower = (indexSelectedTower == 3 ? 0 : indexSelectedTower + 1);
      } while(boardGameModel->getIndexTower(indexSelectedTower) == boardGameModel->getStartIndexTower());
    } else if(gb.buttons.pressed(BUTTON_LEFT)) {
      //
      // Sélectionner la tour à gauche
      //
      do {
        indexSelectedTower = (indexSelectedTower == 0 ? 3 : indexSelectedTower - 1);
      } while(boardGameModel->getIndexTower(indexSelectedTower) == boardGameModel->getStartIndexTower());
    } else if(gb.buttons.pressed(BUTTON_A)) {
      //
      // Valider la tour de destination
      //
      boardGameModel->setEndIndexTower(indexSelectedTower);
      // Par défaut, l'index est sur la tour qui contient tout les anneaux
      while(boardGameModel->getStartIndexTower() != boardGameModel->getIndexTower(indexSelectedTower)) {
        indexSelectedTower = (indexSelectedTower >= 2 ? 0 : indexSelectedTower + 1);
      }
      stateManager->nextState();
    }
    
  } else if(stateManager->isSetStartState()) {
    // Si l'utilisateur doit choisir la tour de départ
    
    if(gb.buttons.pressed(BUTTON_RIGHT)) {
      //
      // Sélectionner la tour à droite
      //
      indexSelectedTower = (indexSelectedTower == 2 ? 0 : indexSelectedTower + 1);
    } else if(gb.buttons.pressed(BUTTON_LEFT)) {
      //
      // Sélectionner la tour à gauche
      //
      indexSelectedTower = (indexSelectedTower == 0 ? 2 : indexSelectedTower - 1);
    } else if(gb.buttons.pressed(BUTTON_A)) {
      //
      // Valider la tour de départ
      //
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
  if(stateManager->isPauseState()) {
    //
    // Affichr l'écran de pause
    //
    Window::paintPauseWindow();
    
  } else if(stateManager->isMenuState()) {
    //
    // Afficher et gérer le menu
    //
    switch(Window::paintMenu()) {
      case 0:
        stateManager->nextState();
      break;
      case 1:
        stateManager->setState(GameStateManager::ABOUT_STATE);
      break;
    }
    
  } else if(stateManager->isAboutState()) {
    //
    // Afficher les crédits
    //
    Window::paintAboutWindow();
    
  } else if(! stateManager->isFinishState()) {
    //
    // Afficher le plateau de jeu
    //
    if(stateManager->isSetStartState()) {
      gb.display.print(Lang::getStart());
    } else if(stateManager->isSetEndState()) {
      gb.display.print(Lang::getEnd());
    }
    
    boardGameView->paint((stateManager->isSetStartState() || stateManager->isSetEndState() || stateManager->isGameState()) ? boardGameModel->getIndexTower(indexSelectedTower) : -1, stateManager->isGameState());
    
  } else {
    //
    // Afficher l'écran de félicitations (lorsque le joueur à gagné)
    //
    Window::paintWinnerWindow();
    
  }
}

void BoardGameController::resetGame() {
  boardGameModel->resetTower();
  indexSelectedTower = 1;
  boardGameModel->setStartIndexTower(3);
  boardGameModel->setEndIndexTower(3);
  boardGameModel->setIsRingSelected(false);
}

