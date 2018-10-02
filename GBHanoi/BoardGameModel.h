// author: chris-scientist
// created at: 29/09/2018
// updated at: 02/10/2018

#ifndef BOARDGAMEMODEL
#define BOARDGAMEMODEL

#include "Constantes.h"
#include "LinkedList.h"
#include "ItemLinkedList.h"
#include "RingModel.h"
#include "TowerModel.h"

class BoardGameModel {
  private:
    TowerModel * tower1;
    TowerModel * tower2;
    TowerModel * tower3;
    LinkedList<RingModel *> * listOfRing;
    int startIndexTower;
    int endIndexTower;
    int endIndexTowers[2] = { -1, -1 };
    bool _isRingSelected;
    RingModel * ringSelected;
    
    const int towersIndex[4] = { TOWER_1, TOWER_2, TOWER_3, TOWER_NO_END };
  public:
    BoardGameModel();
    void initTower();
    void resetTower();
    TowerModel * getTower1();
    TowerModel * getTower2();
    TowerModel * getTower3();
    TowerModel * getTower(const int anIndexOfTower) const;
    void setStartIndexTower(const int anIndex);
    void setEndIndexTower(const int anIndex);
    int getIndexTower(const int anIndex);
    int getStartIndexTower() const;
    int getEndIndexTower() const;
    const int * getEndIndexTowers();
    bool isRingSelected() const;
    void setIsRingSelected(bool isSelected);
    void setRingSelected(RingModel * aRing);
    RingModel * getRingSelected() const;
    bool isFinish(bool isGame) const;
};

#endif

