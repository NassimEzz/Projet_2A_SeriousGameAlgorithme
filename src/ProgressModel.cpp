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
 * @file ProgressModel.cpp
 *
 *
 */

#include "ProgressModel.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cassert>
#include "Utils.h"

using namespace std;

ProgressModel::ProgressModel() : _pathToProgress(string(ASSET_DIRECTORY) + "/progression/" + "progress.txt") {
    _nbLevel = 9;
}

void ProgressModel::writeInProgressFile(const string &lineToWrite) {
    ofstream fileWO(_pathToProgress);
    if (fileWO.good()) {
        fileWO << lineToWrite;
        fileWO.close();
    } else {
        throw "Problem while opening the output file";
    }
}

void ProgressModel::initProgressFile() {
    std::string initLine;
    for (int i = 0; i < _nbLevel; i++) {
        initLine += to_string(LevelProgress::NOT_DONE);
    }
    ofstream fileWO(_pathToProgress);
    if (fileWO.good()) {
        fileWO << initLine;
        fileWO.close();
    } else {
        throw "Problem while creating the output file";
    }
}

void ProgressModel::setLevelProgression(int noLevel, int levelProgress) {
    assert((noLevel >= 1) && (noLevel <= _nbLevel));
    string progressLine = getProgress();
    progressLine[noLevel - 1] = char(levelProgress + '0');
    writeInProgressFile(progressLine);
}

void ProgressModel::setDone(int noLevel) {
    setLevelProgression(noLevel, LevelProgress::DONE);
}

void ProgressModel::setNotDone(int noLevel) {
    setLevelProgression(noLevel, LevelProgress::NOT_DONE);
}

void ProgressModel::setPerfectlyDone(int noLevel) {
    setLevelProgression(noLevel, LevelProgress::PERFECTLY_DONE);
}

std::string ProgressModel::getProgress() {
    std::string progressLine;
    ifstream fileRO(_pathToProgress);
    if (!fileRO.good()) {
        fileRO.close();
        initProgressFile();
        fileRO = ifstream(_pathToProgress);
    }
    if (fileRO.good()) {
        getline(fileRO, progressLine);
    } else {
        throw "Can't read the file !";
    }
    fileRO.close();
    return progressLine;
}
