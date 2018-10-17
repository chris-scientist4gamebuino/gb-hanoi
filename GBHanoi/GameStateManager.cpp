// author: chris-scientist
// created at: 03/10/2018
// updated at: 04/10/2018

#include "GameStateManager.h"

GameStateManager::GameStateManager() : indexOfState(0) {
  
}

void GameStateManager::nextState() {
  indexOfState = (indexOfState == (NB_STATE - 1) ? 0 : indexOfState + 1);
}

void GameStateManager::setState(const int aState) {
  int index = 0;
  while(aState != states[index] && index < NB_STATE) {
    index++;
  }
  indexOfState = index;
}

bool GameStateManager::isMenuState() const {
  return states[indexOfState] == MENU_STATE;
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

bool GameStateManager::isPauseState() const {
  return states[indexOfState] == PAUSE_STATE;
}

bool GameStateManager::isFinishState() const {
  return states[indexOfState] == FINISH_STATE;
}

bool GameStateManager::isHighScoreState() const {
  return states[indexOfState] == HIGH_SCORE_STATE;
}

bool GameStateManager::isInitRandomMode() const {
  return states[indexOfState] == INIT_RANDOM_MODE_STATE;
}

bool GameStateManager::isAboutState() const {
  return states[indexOfState] == ABOUT_STATE;
}

