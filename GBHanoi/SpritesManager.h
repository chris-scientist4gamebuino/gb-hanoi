// author: chris-scientist
// created at: 26/09/2018
// updated at: 01/10/2018
// description: gestion des sprites

#ifndef SPRITESMANAGER
#define SPRITESMANAGER

#include <Gamebuino-Meta.h>

#include "Constantes.h"

class SpritesManager {
  private:
    static bool finishFlagInitialized;
    static Image finishFlag;
    static bool towerInitialized;
    static Image tower;
    static bool ring1Initialized;
    static Image ring1;
    static bool ring2Initialized;
    static Image ring2;
    static bool ring3Initialized;
    static Image ring3;
    static bool ring4Initialized;
    static Image ring4;
    static bool ring5Initialized;
    static Image ring5;
    static bool ring6Initialized;
    static Image ring6;
    static bool ring7Initialized;
    static Image ring7;

    static Image& getRing1();
    static Image& getRing2();
    static Image& getRing3();
    static Image& getRing4();
    static Image& getRing5();
    static Image& getRing6();
    static Image& getRing7();
  public:
    static Image& getFinishFlag();
    static Image& getTower();
    static Image& getRing(const int aIndexOfRing);
};

#endif

