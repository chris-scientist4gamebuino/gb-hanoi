// author: chris-scientist
// created at: 27/09/2018
// updated at: 14/10/2018

#include "TimeModel.h"

TimeModel::TimeModel() : timeInSeconds(0), tempTime(0), initialized(false) {
  rtc.begin();
  rtc.setY2kEpoch(0);
}

void TimeModel::reset() {
  timeInSeconds = 0;
  tempTime = 0;
  initialized = false;
}

void TimeModel::initTime() {
  if(! initialized) {
    rtc.setY2kEpoch(0);
    initialized = true;
  }
}

void TimeModel::pause() {
  if(tempTime != 0) {
    timeInSeconds += tempTime;
    tempTime = 0;
    initialized = false;
  }
}

void TimeModel::computeTime() {
  unsigned long rest = timeInSeconds + tempTime;

  const unsigned long DAYS_IN_FRAMES    = 24*60*60*1;
  const unsigned long HOURS_IN_FRAMES   = 60*60*1;
  const unsigned long MINUTES_IN_FRAMES = 60*1;
  const unsigned long SECONDS_IN_FRAMES = 1;

  int nbDays = 0;
  int nbHours = 0;
  int nbMinutes = 0;
  int nbSeconds = 0;

  // Calculer les jours
  if(rest >= DAYS_IN_FRAMES) {
    nbDays = (int)(rest / DAYS_IN_FRAMES);
    rest = (rest - (nbDays * DAYS_IN_FRAMES));
  }
  // Calculer les heures
  if(rest >= HOURS_IN_FRAMES) {
    nbHours = (int)(rest / HOURS_IN_FRAMES);
    rest = (rest - (nbHours * HOURS_IN_FRAMES));
  }
  // Calculer les minutes
  if(rest >= MINUTES_IN_FRAMES) {
    nbMinutes = (int)(rest / MINUTES_IN_FRAMES);
    rest = (rest - (nbMinutes * MINUTES_IN_FRAMES));
  }
  // Calculer les secondes
  if(rest >= SECONDS_IN_FRAMES) {
    nbSeconds = (int)(rest / SECONDS_IN_FRAMES);
    rest = (rest - (nbSeconds * SECONDS_IN_FRAMES));
  }

  valueOfTime[DAYS_NUMBER] = nbDays;
  valueOfTime[HOURS_NUMBER] = nbHours;
  valueOfTime[MINUTES_NUMBER] = nbMinutes;
  valueOfTime[SECONDS_NUMBER] = nbSeconds;
}

const int * TimeModel::getTime() {
  computeTime();
  return valueOfTime;
}

const unsigned int TimeModel::getTimeInSeconds() const {
  return timeInSeconds;
}

void TimeModel::incrementTime() {
  tempTime = rtc.getY2kEpoch();
}

unsigned int TimeModel::getTempTime() {
  return tempTime;
}

