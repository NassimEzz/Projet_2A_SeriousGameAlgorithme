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
 * @version 0.0 - 13/03/2021
 */

/**
 * @file ProgressModel.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_PROGRESSMODEL_H
#define P2A_SERIOUS_GAME_PROGRESSMODEL_H

#include <string>
#include <fstream>

class ProgressModel {
public :
    ProgressModel();

    std::string getProgress();

    void setDone(int noLevel);

    void setNotDone(int noLevel);

    void setPerfectlyDone(int noLevel);

private:
    int _nbLevel;
    std::string _pathToProgress;

    void writeInProgressFile(const std::string &lineToWrite);

    void initProgressFile();

    void setLevelProgression(int noLevel, int levelProgress);
};


#endif //P2A_SERIOUS_GAME_PROGRESSMODEL_H
