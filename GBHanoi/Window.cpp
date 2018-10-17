  // author: chris-scientist
// created at: 02/10/2018
// updated at: 16/10/2018

#include "Window.h"

void Window::paintAboutWindow() {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.println();
  gb.display.println();
  gb.display.println();
  gb.display.println("     Met'Hanoi");
  gb.display.setColor(WHITE);
  gb.display.println(Lang::getCreatedBy());
  gb.display.setColor(BROWN);
  gb.display.println("   chris-scientist");
  gb.display.setColor(WHITE);
  gb.display.println();
  gb.display.println();
  gb.display.println();
  gb.display.print(Lang::getGoToMenu());
}

void Window::paintHighScoreWindow(HighScoreManager * aScoreManager) {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.println(Lang::getHighScore());
  gb.display.println("");
  const int listHighScore[3] = { HighScoreManager::HIGH_SCORE_1, HighScoreManager::HIGH_SCORE_2, HighScoreManager::HIGH_SCORE_3 };
  for(int i=0 ; i<aScoreManager->getNbHighScore() ; i++) {
    int index = listHighScore[i];
    HighScore * highScore = aScoreManager->getHighScore(index);
    if(index == aScoreManager->getIndexNewHighScore()) {
      gb.display.setColor(BROWN);
    } else {
      gb.display.setColor(WHITE);
    }
    gb.display.printf("%s ", highScore->getName());

    unsigned int rest = highScore->getScore();

    const unsigned int DAYS_IN_FRAMES    = 24*60*60*1;
    const unsigned int HOURS_IN_FRAMES   = 60*60*1;
    const unsigned int MINUTES_IN_FRAMES = 60*1;
    const unsigned int SECONDS_IN_FRAMES = 1;
  
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

    gb.display.cursorX = 22;
    if(nbDays > 0) {
      gb.display.printf("%d d", nbDays);
    } else {
      gb.display.printf("%d h ", nbHours);
      if(nbMinutes < 10) {
        gb.display.print("0");
      }
      gb.display.printf("%d m ", nbMinutes);
      if(nbSeconds < 10) {
        gb.display.print("0");
      }
      gb.display.printf("%d s", nbSeconds);
    }
    gb.display.println("");
  }

  // Afficher en bas de l'écran "retourner au menu"
  int l = aScoreManager->getNbHighScore();
  while(l<3) {
    gb.display.println();
    l++;
  }
  gb.display.println();
  gb.display.println();
  gb.display.println();
  gb.display.println();
  gb.display.setColor(WHITE);
  gb.display.print(Lang::getGoToMenu());
}

const int Window::paintMenu() {
  const char* items[] = {
    Lang::getNewPart(),
    Lang::getRandomMode(),
    Lang::getHighScore(),
    Lang::getAbout()
  };

  const uint8_t indexItem = gb.gui.menu("Menu", items);
  int choice = 0;
  if(items[indexItem] == Lang::aboutFR || items[indexItem] == Lang::aboutEN) {
    choice = 3;
  } else if(items[indexItem] == Lang::randomModeFR || items[indexItem] == Lang::randomModeEN) {
    choice = 2;
  } else if(items[indexItem] == Lang::highScoreFR || items[indexItem] == Lang::highScoreEN) {
    choice = 1;
  }
  return choice;
}

void Window::paintPauseWindow() {
  gb.display.setFontSize(2);
  gb.display.setColor(BROWN);
  gb.display.println();
  gb.display.println();
  gb.display.println("  Pause");
  gb.display.setFontSize(1);
  gb.display.setColor(WHITE);
  gb.display.println();
  gb.display.println();
  gb.display.println(Lang::getGetBackPart());
  gb.display.println(Lang::getGoToMenu());
}


void Window::paintWinnerWindow() {
  bool isEnLang = Lang::isEnglishLanguage();
  
  gb.display.setColor(BROWN);
  if(isEnLang) {
    gb.display.setFontSize(1);
    gb.display.println("");
    gb.display.println("");
  } else {
    gb.display.setFontSize(2);
  }
  gb.display.println("");
  gb.display.println("");
  gb.display.println(Lang::getCongratulations());

  gb.display.setColor(WHITE);
  gb.display.setFontSize(1);
  if(isEnLang) {
    gb.display.println();
    gb.display.println("");
  }
  gb.display.println();
  gb.display.println(Lang::getToRetry());
  gb.display.println(Lang::getGoToMenu());
}

