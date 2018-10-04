// author: chris-scientist
// created at: 30/09/2018
// updated at: 02/10/2018

#include "BoardGameView.h"

BoardGameView::BoardGameView(BoardGameModel * aModel) : model(aModel) {
  
}

void BoardGameView::paint(int anIndexTower4Arrow, bool isGame) {
  // Dessiner les tours vides
  paintBackground();
  
  // Dessiner les anneaux
  paintTower(model->getTower1());
  paintTower(model->getTower2());
  paintTower(model->getTower3());

  if(isGame && model->isRingSelected()) {
    // Dessiner l'anneau sélectionné
    paintRingSelected(model->getRingSelected());
  } else if(
     (
       anIndexTower4Arrow != -1 && 
       anIndexTower4Arrow != TOWER_NO_END && 
       model->getStartIndexTower() != anIndexTower4Arrow
     ) || 
     (
       isGame && !model->isRingSelected()
     )
  ) {
    // Dessiner la flèche de sélection
    paintArrow(anIndexTower4Arrow);
  } else if(anIndexTower4Arrow == TOWER_NO_END) {
    // Afficher les index des tours de destination
    const int * indexTowers = model->getEndIndexTowers();
    gb.display.printf("%d %s %d", indexTowers[0], Lang::getOr(), indexTowers[1]);
  }

  // Dessiner le drapeau marquant la position de fin
  if(model->getStartIndexTower() != TOWER_NO_END) {
    paintStartFlag(model->getStartIndexTower());
  }
  
  // Dessiner le drapeau marquant la position d'arrivée
  if(model->getEndIndexTower() != TOWER_NO_END) {
    paintFinishFlag(model->getEndIndexTower());
  }
}

void BoardGameView::paintTower(TowerModel * aTower) {
  int x = 1 + (aTower->getIndex() * 26) - 26;
  int y = 31;
  LinkedList<RingModel *> * listOfRing = aTower->getListOfRing();
  if(! listOfRing->isEmpty()) {
    // Récupérer l'anneau le plus en-dessous
    ItemLinkedList<RingModel *> * item = listOfRing->getLastItem();
    for(int i=0 ; i<listOfRing->getSize() ; i++) {
      // dessiner l'anneau
      gb.display.drawImage(x, y, SpritesManager::getRing(item->getValue()->getIndex()));
      // récupérer l'anneau suivant (s'il existe)
      if(item->havePrevious()) {
        item = item->getPrevious();
      }
      y -= 3; // le prochain anneau doit être dessiné 3 pixels au dessus de l'actuel
    }
  }
}

void BoardGameView::paintBackground() {
  int x = 1;
  int y = 10;
  for(int i=0 ; i<3 ; i++) {
    gb.display.drawImage(x, y, SpritesManager::getTower());
    x += 26;
  }
}

void BoardGameView::paintArrow(int anIndexTower) {
  int x = 12 + (anIndexTower * 26) - 26;
  gb.display.fillRect(x, 8, 4, 1);
  gb.display.fillRect(x+1, 9, 2, 1);
}

void BoardGameView::paintStartFlag(int anIndexTower) {
  int x = 1 + (anIndexTower * 26) - 26;
  gb.display.drawImage(x, 40, SpritesManager::getStartFlag());
}

void BoardGameView::paintFinishFlag(int anIndexTower) {
  int x = 1 + (anIndexTower * 26) - 26;
  gb.display.drawImage(x, 40, SpritesManager::getFinishFlag());
}

void BoardGameView::paintRingSelected(RingModel * aRing) {
  int x = 1 + (aRing->getCurTowerIndex() * 26) - 26;
  gb.display.drawImage(x, 7, SpritesManager::getRing(aRing->getIndex()));
}

