// author: chris-scientist
// created at: 29/09/2018
// updated at: 02/10/2018

#include "TowerModel.h"

TowerModel::TowerModel(int anIndex) : index(anIndex), listOfRing(new LinkedList<RingModel *>()) {
  
}

// Ajouter un anneau à la tour
void TowerModel::addRing(RingModel * aRing) {
  aRing->setTowerIndex(index);
  aRing->setCurTowerIndex(index);
  listOfRing->addTop(aRing);
}

// Supprimer les anneaux de la tour
void TowerModel::resetTower() {
  while(! listOfRing->isEmpty()) {
    listOfRing->removeTop();
  }
}

int TowerModel::getIndex() const {
  return index;
}

LinkedList<RingModel *> * TowerModel::getListOfRing() {
  return listOfRing;
}

// Déterminer si l'anneau sélectionner (aRing) peut être ajouter à la tour
bool TowerModel::allowToAddRing(RingModel * aRing) const {
  if(listOfRing->isEmpty()) {
    // On autorise l'ajout si la tour est vide
    return true;
  } else {
    // En revanche si la tour n'est pas vide il faut comparer l'anneau sélectionnée et l'anneau au dessus de la tour
    return aRing->getIndex() < listOfRing->getTop()->getIndex();
  }
  return false;
}

