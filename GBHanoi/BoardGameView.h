// author: chris-scientist
// created at: 30/09/2018
// updated at: 02/10/2018

#ifndef BOARDGAMEVIEW
#define BOARDGAMEVIEW

#include "Constantes.h"
#include "SpritesManager.h"
#include "LinkedList.h"
#include "ItemLinkedList.h"
#include "TowerModel.h"
#include "BoardGameModel.h"
#include "Lang.h"
#include "TimeModel.h"

class BoardGameView {
  private:
    BoardGameModel * model;

    void paintTower(TowerModel * aTower);
    void paintBackground();
    void paintArrow(int anIndexTower);
    void paintStartFlag(int anIndexTower);
    void paintFinishFlag(int anIndexTower);
    void paintRingSelected(RingModel * aRing);
    void paintTimer(const int * aTime);
  public:
    BoardGameView(BoardGameModel * aModel);
    void paint(int anIndexTower4Arrow, bool isGame, const int * aTime, bool showTime);
};

#endif

