// author: chris-scientist
// created at: 29/09/2018
// updated at: 02/10/2018

#include "BoardGameModel.h"

BoardGameModel::BoardGameModel() : 
  tower1(new TowerModel(TOWER_1)), 
  tower2(new TowerModel(TOWER_2)), 
  tower3(new TowerModel(TOWER_3)), 
  listOfRing(new LinkedList<RingModel *>()), 
  startIndexTower(TOWER_NO_END), 
  endIndexTower(TOWER_NO_END),
  _isRingSelected(false)
{
  listOfRing->addTop(new RingModel(RING_7));
  listOfRing->addTop(new RingModel(RING_6));
  listOfRing->addTop(new RingModel(RING_5));
  listOfRing->addTop(new RingModel(RING_4));
  listOfRing->addTop(new RingModel(RING_3));
  listOfRing->addTop(new RingModel(RING_2));
  listOfRing->addTop(new RingModel(RING_1));
}

// Initialiser les tours
void BoardGameModel::initTower() {
  // initialisation de la tour qui accueillera les anneaux
  TowerModel * tower = tower2;
  switch(startIndexTower) {
    case TOWER_1:
      tower = tower1;
    break;
    case TOWER_3:
      tower = tower3;
    break;
  }

  // on supprime les éventuels anneaux qui sont affectés aux tours
  tower1->resetTower();
  tower2->resetTower();
  tower3->resetTower();

  // initialisation de la tour
  ItemLinkedList<RingModel *> * item = listOfRing->getLastItem();
  for(int i=0 ; i<listOfRing->getSize() ; i++) {
    tower->addRing(item->getValue());
    if(item->havePrevious()) {
      item = item->getPrevious();
    }
  }
}

void BoardGameModel::resetTower() {
  tower1->resetTower();
  tower2->resetTower();
  tower3->resetTower();
}

TowerModel * BoardGameModel::getTower1() {
  return tower1;
}

TowerModel * BoardGameModel::getTower2() {
  return tower2;
}

TowerModel * BoardGameModel::getTower3() {
  return tower3;
}

TowerModel * BoardGameModel::getTower(const int anIndexOfTower) const {
  switch(anIndexOfTower) {
    case TOWER_1:
      return tower1;
    break;
    case TOWER_2:
      return tower2;
    break;
    case TOWER_3:
      return tower3;
    break;
  }
}

void BoardGameModel::setStartIndexTower(const int anIndex) {
  if(anIndex > -1 && anIndex < 4) {
    startIndexTower = towersIndex[anIndex];
  } else {
    startIndexTower = TOWER_2;
  }
}

void BoardGameModel::setEndIndexTower(const int anIndex) {
  if(anIndex > -1 && anIndex < 4) {
    endIndexTower = towersIndex[anIndex];
  } else {
    endIndexTower = TOWER_NO_END;
  }
}

int BoardGameModel::getStartIndexTower() const {
  return startIndexTower;
}

int BoardGameModel::getEndIndexTower() const {
  return endIndexTower;
}

int BoardGameModel::getIndexTower(const int anIndex) {
  if(! (anIndex > -1 && anIndex < 4)) {
    return TOWER_2;
  }
  return towersIndex[anIndex];
}

const int * BoardGameModel::getEndIndexTowers() {
  int j = 0;
  for(int i=0 ; i<3 ; i++) {
    int index = towersIndex[i];
    if(index != startIndexTower) {
      endIndexTowers[j] = index;
      j++;
    }
  }
  return endIndexTowers;
}

bool BoardGameModel::isRingSelected() const {
  return _isRingSelected;
}

void BoardGameModel::setIsRingSelected(bool isSelected) {
  _isRingSelected = isSelected;
}

void BoardGameModel::setRingSelected(RingModel * aRing) {
  ringSelected = aRing;
  _isRingSelected = true;
}

RingModel * BoardGameModel::getRingSelected() const {
  return ringSelected;
}

bool BoardGameModel::isFinish(bool isGame) const {
  if(isGame) {
    if(endIndexTower != TOWER_NO_END) {
      // Si une tour est défini comme destination
      TowerModel * tower = getTower(endIndexTower);
      return tower->getListOfRing()->getSize() == NB_RING;
    }
    // Sinon si la tour de destination n'est pas fixe
    TowerModel * towerA;
    TowerModel * towerB;
    switch(startIndexTower) {
      case TOWER_1:
        towerA = tower2;
        towerB = tower3;
      break;
      case TOWER_2:
        towerA = tower1;
        towerB = tower3;
      break;
      case TOWER_3:
        towerA = tower1;
        towerB = tower2;
      break;
    }
    return (towerA->getListOfRing()->getSize() == NB_RING) ||
           (towerB->getListOfRing()->getSize() == NB_RING);
    }
  return false;
}

