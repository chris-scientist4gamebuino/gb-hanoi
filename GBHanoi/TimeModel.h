// author: chris-scientist
// created at: 27/09/2018
// updated at: 14/10/2018
// description: modèle du chronomètre

// ***********************************************************************
// ** La durée maximum qui peut être calculé avec ce programme est de : **
// ** 49710 jours, 6 heures, 28 minutes et 15 secondes !                **
// **                                                                   **
// ** Autrement dit : 136 années (de 365 jours), 70 jours, 6 heures,    **
// ** 28 minutes et 15 secondes !                                       **
// ***********************************************************************

#ifndef TIMEMODEL
#define TIMEMODEL

#include <RTCZero.h>
#include <Gamebuino-Meta.h>

class TimeModel {
  private:
    unsigned int timeInSeconds;
    unsigned int tempTime;
    bool initialized;
    RTCZero rtc;
    int valueOfTime[4] = {0, 0, 0, 0};

    void computeTime();
  public:
    static const int DAYS_NUMBER = 0;
    static const int HOURS_NUMBER = 1;
    static const int MINUTES_NUMBER = 2;
    static const int SECONDS_NUMBER = 3;

    TimeModel();
    const int * getTime();
    const unsigned int getTimeInSeconds() const;
    void incrementTime();
    void reset();
    void initTime();
    unsigned int getTempTime();
    void pause();
};

#endif

