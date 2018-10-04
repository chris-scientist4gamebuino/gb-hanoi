// author: chris-scientist
// created at: 03/10/2018
// updated at: 04/10/2018

#include "Lang.h"

const char* Lang::aboutFR = "A propos";
const char* Lang::aboutEN = "About";
const char* Lang::congratulationsFR = "  Gagne";
const char* Lang::congratulationsEN = "  Congratulations";
const char* Lang::createdByFR = "    presente par";
const char* Lang::createdByEN = "     created by";
const char* Lang::endFR = "Fin ";
const char* Lang::endEN = "End ";
const char* Lang::getBackPartFR = "(A) reprendre partie";
const char* Lang::getBackPartEN = "(A) get back part";
const char* Lang::goToMenuFR = "(B) acceder au menu";
const char* Lang::goToMenuEN = "(B) go to menu";
const char* Lang::newPartFR = "Nouvelle partie";
const char* Lang::newPartEN = "New part";
const char* Lang::orFR = "ou";
const char* Lang::orEN = "or";
const char* Lang::startFR = "Depart";
const char* Lang::startEN = "Start";
const char* Lang::toRetryFR = "(A) pour recommencer";
const char* Lang::toRetryEN = "(A) to retry";

const bool Lang::isEnglishLanguage() {
  return (gb.language.getCurrentLang() == LANG_EN);
}

const char* Lang::getAbout() {
  const MultiLang aboutLang[] = {
    { LANG_EN, Lang::aboutEN },
    { LANG_FR, Lang::aboutFR }
  };

  return gb.language.get(aboutLang);
}

const char* Lang::getCongratulations() {
  const MultiLang congratulationsLang[] = {
    { LANG_EN, Lang::congratulationsEN },
    { LANG_FR, Lang::congratulationsFR }
  };

  return gb.language.get(congratulationsLang);
}

const char* Lang::getCreatedBy() {
  const MultiLang createdByLang[] = {
    { LANG_EN, Lang::createdByEN },
    { LANG_FR, Lang::createdByFR }
  };

  return gb.language.get(createdByLang);
}

const char* Lang::getEnd() {
  const MultiLang endLang[] = {
    { LANG_EN, Lang::endEN },
    { LANG_FR, Lang::endFR }
  };

  return gb.language.get(endLang);
}

const char* Lang::getGetBackPart() {
  const MultiLang getBackPartLang[] = {
    { LANG_EN, Lang::getBackPartEN },
    { LANG_FR, Lang::getBackPartFR }
  };

  return gb.language.get(getBackPartLang);
}

const char* Lang::getGoToMenu() {
  const MultiLang goToMenuLang[] = {
    { LANG_EN, Lang::goToMenuEN },
    { LANG_FR, Lang::goToMenuFR }
  };

  return gb.language.get(goToMenuLang);
}

const char* Lang::getNewPart() {
  const MultiLang newPartLang[] = {
    { LANG_EN, Lang::newPartEN },
    { LANG_FR, Lang::newPartFR }
  };

  return gb.language.get(newPartLang);
}

const char* Lang::getOr() {
  const MultiLang orLang[] = {
    { LANG_EN, Lang::orEN },
    { LANG_FR, Lang::orFR }
  };

  return gb.language.get(orLang);
}

const char* Lang::getStart() {
  const MultiLang startLang[] = {
    { LANG_EN, Lang::startEN },
    { LANG_FR, Lang::startFR }
  };

  return gb.language.get(startLang);
}

const char* Lang::getToRetry() {
  const MultiLang toRetryLang[] = {
    { LANG_EN, Lang::toRetryEN },
    { LANG_FR, Lang::toRetryFR }
  };

  return gb.language.get(toRetryLang);
}
  
