// author: chris-scientist
// created at: 17/10/2018

#include "GameModeManager.h"

GameModeManager::GameModeManager() : selectedMode(NO_SELECTED_MODE) {
  
}

bool GameModeManager::isValidMode(const int aMode) const {
  return (aMode == CLASSIC_MODE || aMode == RANDOM_MODE);
}

bool GameModeManager::isClassicMode() const {
  return (selectedMode == CLASSIC_MODE);
}

bool GameModeManager::isRandomMode() const {
  return (selectedMode == RANDOM_MODE);
}

void GameModeManager::setSelectedMode(const int aMode) {
  selectedMode = NO_SELECTED_MODE;
  if( isValidMode(aMode) ) {
    selectedMode = aMode;
  }
}

