// author: chris-scientist
// created at: 29/09/2018
// updated at: 02/10/2018

#ifndef TOWERMODEL
#define TOWERMODEL

#include "RingModel.h"
#include "LinkedList.cpp"

class TowerModel {
  private:
    int index;
    LinkedList<RingModel *> * listOfRing;
  public:
    TowerModel(int anIndex);
    void addRing(RingModel * aRing);
    void resetTower();
    int getIndex() const;
    LinkedList<RingModel *> * getListOfRing();
    bool allowToAddRing(RingModel * aRing) const;
};

#endif

