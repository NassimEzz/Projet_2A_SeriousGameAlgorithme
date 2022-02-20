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
 * @author Julien Zaïdi <julien.zaidi@ecole.ensicaen.fr>
 * @version 0.0 - 27/12/2020
 */

/**
 * @file LevelSelectorThemeFactory.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_LEVELSELECTORTHEMEFACTORY_H
#define P2A_SERIOUS_GAME_LEVELSELECTORTHEMEFACTORY_H


#include "Button.h"
#include "ICommand.h"
#include <utility>
#include <memory>

class LevelSelectorThemeFactory {
public:
    virtual std::unique_ptr<Button> makeLevelButton(unsigned int level, std::shared_ptr<ICommand> command) = 0;

    virtual std::unique_ptr<Button> makeNextPageButton(std::shared_ptr<ICommand> command) = 0;

    virtual std::unique_ptr<Button> makePrevPageButton(std::shared_ptr<ICommand> command) = 0;

    virtual std::unique_ptr<Button> makeQuitPageButton(std::shared_ptr<ICommand> command) = 0;

    virtual std::unique_ptr<Button> makeMenuButton(std::shared_ptr<ICommand> command) = 0;
};


#endif //P2A_SERIOUS_GAME_LEVELSELECTORTHEMEFACTORY_H
