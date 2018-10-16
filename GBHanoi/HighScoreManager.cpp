// author: chris-scientist
// created at: 04/10/2018
// updated at: 16/10/2018

#include "HighScoreManager.h"

HighScoreManager::HighScoreManager() : 
  highScore1(new HighScore("    ", 0)), 
  highScore2(new HighScore("    ", 0)), 
  highScore3(new HighScore("    ", 0)), 
  nbHighScore(0),
  inPseudoWindow(new InputPseudoWindow()),
  indexNewHighScore(0) 
{

}

// Charger les meilleurs scores
void HighScoreManager::loadAllHighScore() {
  int nbHighScoreSaved = gb.save.get(NB_HIGH_SCORE_BLOCK);
  if(nbHighScoreSaved > 0) {

    // Charger le meilleur score 1
    char temp1[5];
    gb.save.get(NAME_HIGH_SCORE_1_BLOCK, temp1, 5);
    highScore1->setName(temp1);
    highScore1->setScore(gb.save.get(SCORE_HIGH_SCORE_1_BLOCK));
    nbHighScore++;

    // Charger le meilleur score 2
    if(nbHighScoreSaved >= 2) {
      char temp2[5];
      gb.save.get(NAME_HIGH_SCORE_2_BLOCK, temp2, 5);
      highScore2->setName(temp2);
      highScore2->setScore(gb.save.get(SCORE_HIGH_SCORE_2_BLOCK));
      nbHighScore++;
    }

    // Charger le meilleur score 3
    if(nbHighScoreSaved >= 3) {
      char temp3[5];
      gb.save.get(NAME_HIGH_SCORE_3_BLOCK, temp3, 5);
      highScore3->setName(temp3);
      highScore3->setScore(gb.save.get(SCORE_HIGH_SCORE_3_BLOCK));
      nbHighScore++;
    }
  }
}

// Enregistrer les meilleurs scores
void HighScoreManager::saveAllHighScore() const {
  switch(nbHighScore) {
    case 1:
      saveHighScore((char*)highScore1->getName(), highScore1->getScore(), NAME_HIGH_SCORE_1_BLOCK, SCORE_HIGH_SCORE_1_BLOCK);
    break;
    case 2:
      saveHighScore((char*)highScore1->getName(), highScore1->getScore(), NAME_HIGH_SCORE_1_BLOCK, SCORE_HIGH_SCORE_1_BLOCK);
      saveHighScore((char*)highScore2->getName(), highScore2->getScore(), NAME_HIGH_SCORE_2_BLOCK, SCORE_HIGH_SCORE_2_BLOCK);
    break;
    case 3:
      saveHighScore((char*)highScore1->getName(), highScore1->getScore(), NAME_HIGH_SCORE_1_BLOCK, SCORE_HIGH_SCORE_1_BLOCK);
      saveHighScore((char*)highScore2->getName(), highScore2->getScore(), NAME_HIGH_SCORE_2_BLOCK, SCORE_HIGH_SCORE_2_BLOCK);
      saveHighScore((char*)highScore3->getName(), highScore3->getScore(), NAME_HIGH_SCORE_3_BLOCK, SCORE_HIGH_SCORE_3_BLOCK);
    break;
  }
  gb.save.set(NB_HIGH_SCORE_BLOCK, nbHighScore);
}

void HighScoreManager::saveHighScore(char * aName, unsigned int aScore, int aBlockName, int aBlockScore) const {
  gb.save.set(aBlockName, aName);
  gb.save.set(aBlockScore, aScore);
}

bool HighScoreManager::saveScoreIfNewHighScore(const unsigned int aTimeOfPart) {
  // Comparer le score actuel aux scores en mémoire
  const int highScoreIndex = setHighScore4Time(aTimeOfPart);

  // S'il y a un nouveau meilleur score le sauvegarder
  bool haveNewHighScore = (highScoreIndex != 0);
  if(haveNewHighScore) {
    saveAllHighScore();
  }
  indexNewHighScore = highScoreIndex;
  
  return haveNewHighScore;
}

const int HighScoreManager::setHighScore4Time(const unsigned int aTimeOfPart) {
  int highScoreIndex = 0;

  if(nbHighScore == 0) {
    // S'il n'y a pas de meilleur score

    char * pseudo = inPseudoWindow->getPseudo();
    
    highScore1->setName(pseudo);
    highScore1->setScore(aTimeOfPart);

    nbHighScore = 1;
    highScoreIndex = HIGH_SCORE_1;
  } else {
    const int cmpTime1 = highScore1->compareTime(aTimeOfPart);
    if(cmpTime1 == 0 || cmpTime1 == 1) {
      // Si le score est égale ou meilleur que le score 1

      if(nbHighScore == 3) {
        // High score 3 = High score 2
        highScore3->setName((char*)highScore2->getName());
        highScore3->setScore(highScore2->getScore());
      } else if(nbHighScore == 2) {
        // High score 3 = High score 2
        highScore3->setName((char*)highScore2->getName());
        highScore3->setScore(highScore2->getScore());

        nbHighScore = 3;
      } else {
        nbHighScore = 2;
      }
      // High score 2 = High score 1
      highScore2->setName((char*)highScore1->getName());
      highScore2->setScore(highScore1->getScore());

      char * pseudo = inPseudoWindow->getPseudo();
    
      highScore1->setName(pseudo);
      highScore1->setScore(aTimeOfPart);
      
      highScoreIndex = HIGH_SCORE_1;
      
    } else if(nbHighScore == 1) {
      // S'il n'y a pas de meilleur score 2

      char * pseudo = inPseudoWindow->getPseudo();

      highScore2->setName(pseudo);
      highScore2->setScore(aTimeOfPart);

      nbHighScore = 2;
      highScoreIndex = HIGH_SCORE_2;
      
    } else {
      const int cmpTime2 = highScore2->compareTime(aTimeOfPart);
      if(cmpTime2 == 0 || cmpTime2 == 1) {
        // Si le score est égale ou meilleur que le score 2

        if(nbHighScore == 2) {
          nbHighScore = 3;
        }
        // High score 3 = High score 2
        highScore3->setName((char *)highScore2->getName());
        highScore3->setScore(highScore2->getScore());

        char * pseudo = inPseudoWindow->getPseudo();

        highScore2->setName(pseudo);
        highScore2->setScore(aTimeOfPart);

        highScoreIndex = HIGH_SCORE_2;
        
      } else if(nbHighScore == 2) {
        // S'il n'y a pas de meilleur score 3

        char * pseudo = inPseudoWindow->getPseudo();

        highScore3->setName(pseudo);
        highScore3->setScore(aTimeOfPart);

        nbHighScore = 3;
        highScoreIndex = HIGH_SCORE_3;
        
      } else {
        const int cmpTime3 = highScore3->compareTime(aTimeOfPart);
        if(cmpTime3 == 0 || cmpTime3 == 1) {
          // Si le score est égale ou meilleur que le score 3

          char * pseudo = inPseudoWindow->getPseudo();

          highScore3->setName(pseudo);
          highScore3->setScore(aTimeOfPart);

          highScoreIndex = HIGH_SCORE_3;
        }
      }
    }
  }

  return highScoreIndex;
}

HighScore * HighScoreManager::getHighScore(const int anIndex) {
  switch(anIndex) {
    case HIGH_SCORE_2:
      return highScore2;
    break;
    case HIGH_SCORE_3:
      return highScore3;
    break;
  }
  return highScore1;
}

void HighScoreManager::resetIndexNewHighScore() {
  indexNewHighScore = 0;
}

const int HighScoreManager::getNbHighScore() const {
  return nbHighScore;
}

const int HighScoreManager::getIndexNewHighScore() const {
  return indexNewHighScore;
}

