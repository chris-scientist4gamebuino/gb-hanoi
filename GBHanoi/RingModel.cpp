// author: chris-scientist
// created at: 29/09/2018
// updated at: 02/10/2018

#include "RingModel.h"

RingModel::RingModel(int anIndex) : index(anIndex), towerIndex(TOWER_NO_END), curTowerIndex(TOWER_NO_END) {
  
}

int RingModel::getIndex() const {
  return index;
}

void RingModel::setTowerIndex(const int aTowerIndex) {
  towerIndex = aTowerIndex;
}

int RingModel::getTowerIndex() const {
  return towerIndex;
}

void RingModel::setCurTowerIndex(const int aTowerIndex) {
  curTowerIndex = aTowerIndex;
}

int RingModel::getCurTowerIndex() const {
  return curTowerIndex;
}

