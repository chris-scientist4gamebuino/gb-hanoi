// author: chris-scientist
// created at: 29/09/2018
// updated at: 02/10/2018

#ifndef RINGMODEL
#define RINGMODEL

#include "Constantes.h"

class RingModel {
  private:
    int index;
    int towerIndex; // indice de la tour auquel est rattaché l'anneau (par défaut 0, ce qui ne correspond à aucune tour)
    int curTowerIndex; // indice de la tour qui survolé par l'anneau
  public:
    RingModel(int anIndex);
    int getIndex() const;
    void setTowerIndex(const int aTowerIndex);
    int getTowerIndex() const;
    void setCurTowerIndex(const int aTowerIndex);
    int getCurTowerIndex() const;
};

#endif

