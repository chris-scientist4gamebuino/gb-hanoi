// author: chris-scientist
// created at: 03/10/2018

#include "GameStateManager.h"

GameStateManager::GameStateManager() : indexOfState(0) {
  
}

void GameStateManager::nextState() {
  indexOfState = (indexOfState == (NB_STATE - 1) ? 0 : indexOfState + 1);
}

bool GameStateManager::isSetStartState() const {
  return states[indexOfState] == SET_START_STATE;
}

bool GameStateManager::isSetEndState() const {
  return states[indexOfState] == SET_END_STATE;
}

bool GameStateManager::isGameState() const {
  return states[indexOfState] == GAME_STATE;
}

bool GameStateManager::isFinishState() const {
  return states[indexOfState] == FINISH_STATE;
}

