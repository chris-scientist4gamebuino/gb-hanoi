// author: chris-scientist
// created at: 17/10/2018
// description: déterminer le mode de jeu

#ifndef GAMEMODEMANAGER
#define GAMEMODEMANAGER

class GameModeManager {
  public:
    static const int NO_SELECTED_MODE = 0;
    static const int CLASSIC_MODE = 1;
    static const int RANDOM_MODE = 2;

    GameModeManager();
    bool isClassicMode() const;
    bool isRandomMode() const;
    void setSelectedMode(const int aMode);
  private:
    int selectedMode;
    bool isValidMode(const int aMode) const;
};

#endif

