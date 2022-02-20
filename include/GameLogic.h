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
 * @author Landry Marquis <landry.marquis@ecole.ensicaen.fr>
 * @version 0.0 - 15/02/2021
 */

/**
 * @file GameLogic.cpp
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_GAMELOGIC_H
#define P2A_SERIOUS_GAME_GAMELOGIC_H

#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <functional>
#include "Window.h"
#include "DraggableRectangle.h"
#include "Receiver.h"

class GameLogic {
public:
    explicit GameLogic(const std::string &pathToLogicFile);

    int checkAnswer(const string &list);

private:
    std::string _solutionsTable;
    unsigned int _nbPerfectSolutions;
};

#endif //P2A_SERIOUS_GAME_GAMELOGIC_H
