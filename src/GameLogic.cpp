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

#include "GameLogic.h"
#include "Utils.h"
#include <string>

GameLogic::GameLogic(const std::string &pathToLogicFile) {

    ifstream solutionsTable(pathToLogicFile);

    if (solutionsTable) {
        string nbPerfectSolutions;
        string rollingSolution;
        getline(solutionsTable, nbPerfectSolutions);
        _nbPerfectSolutions = stoi(nbPerfectSolutions, nullptr);
        while (getline(solutionsTable, rollingSolution)) {
            _solutionsTable += rollingSolution + " ";
        }
    } else {
        std::cout << "Error while loading the logic file." << std::endl;
    }
}

int GameLogic::checkAnswer(const string &list) {
    // return the iterator of _solutionsTable which begins the first occurrence of list
    // in our case, there are no duplicates in the logicFile so as it returns an iterator =! _solutionsTable
    // if list is included into _solutionsTable
    auto it = std::search(_solutionsTable.begin(), _solutionsTable.end(), list.begin(), list.end());

    if (it < _solutionsTable.begin() + long(_nbPerfectSolutions * list.size())) {
        return LevelProgress::PERFECTLY_DONE;
    } else if (it != _solutionsTable.end()) {
        return LevelProgress::DONE;
    } else if (list.find('0') == string::npos){
        return LevelProgress::WRONGLY_DONE;
    } else {
        return LevelProgress::NOT_DONE;
    }
}

