/*ENCODING = UTF-8*/
/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students. No portion of this
 * document may be reproduced, copied or revised without written
 * permission of the authors.
 */

/**
 * @author Navid Kavian <navid.kavian@ecole.ensicaen.fr>
 * @version 1.0
 */


#ifndef LEVELRULER_H_INCLUDED
#define LEVELRULER_H_INCLUDED

#include <string>
#include "Level.h"
#include "Event.h"

class Level;

class LevelRuler : public WindowContent {
public :
    LevelRuler(const std::string &pathToRules, const std::string &levelBackground,
               Level *level, Window *window, const std::string &title);

    ~LevelRuler() override;

    void addButton(std::unique_ptr<Button> &&/*button*/) override {};

    void displayMeOnWindow() override;

    void receiveEvent(Event event) override;

private :
    std::string _levelBackground;
    ifstream _ruleFile;
    Level *_level;
};

#endif // LEVELRULER_H_INCLUDED
