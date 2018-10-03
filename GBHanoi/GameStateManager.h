// author: chris-scientist
// created at: 03/10/2018

#ifndef GAMESTATEMANAGER
#define GAMESTATEMANAGER

class GameStateManager {
  private:
    static const int SET_START_STATE = 10;
    static const int SET_END_STATE = 20;
    static const int GAME_STATE = 30;
    static const int FINISH_STATE = 40;
    static const int NB_STATE = 4;
  
    int indexOfState;
    const int states[NB_STATE] = { SET_START_STATE, SET_END_STATE, GAME_STATE, FINISH_STATE };
  public:
    GameStateManager();
    void nextState();
    bool isSetStartState() const;
    bool isSetEndState() const;
    bool isGameState() const;
    bool isFinishState() const;
};

#endif

