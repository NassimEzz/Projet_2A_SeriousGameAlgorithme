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
 * @version 0.0 - 06/03/2021
 */

/**
 * @file ProgressWindowContent.cpp.cc
 *
 *
 */

#include "ProgressWindowContent.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cassert>
#include "Utils.h"

using namespace std;

ProgressWindowContent::ProgressWindowContent(Window *window, const string &title, int nbLevel,
                                             const std::string &backgroundPath)
        : WindowContent(window, title), _nbLevel(nbLevel), _backgroundPath(backgroundPath) {

}

void ProgressWindowContent::handleClickEvent(unsigned int x, unsigned int y) {
    for (auto &button : _arrButton) {
        if (button->overlap(x, y)) {
            button->onClick();
        }
    }
}

void ProgressWindowContent::receiveEvent(Event event) {
    if (event.getType() == EventType::MOUSEDOWN) {
        handleClickEvent(event.getX(), event.getY());
    }
}

void ProgressWindowContent::addButton(unique_ptr<Button> &&button) {
    _arrButton.push_back(std::move(button));
}

void ProgressWindowContent::displayMeOnWindow() {
    _window->clearScreen();
    _window->setTitle(_title);
    _window->drawPng(0, 0, _backgroundPath);

    for (auto &button : _arrButton) {
        button->drawMe(*_window);
    }

    _levelProgression = _progress.getProgress();
    for (int i = 0; i < NB_ROWS; i++) {
        for (int j = 0; j < NB_COLUMNS; j++) {
            if (3*i+(j+1) <= _nbLevel)
                drawLevelProgressPicture(i, j);
        }
    }

    _window->updateScreen();
}

void ProgressWindowContent::drawLevelProgressPicture(int iLevelIndex, int jLevelIndex) {
    int noLevel = iLevelIndex * 3 + jLevelIndex + 1;
    const char progressOfLevel = _levelProgression[noLevel - 1];
    string folder;
    if (progressOfLevel == LevelProgress::DONE + '0') {
        folder = "done/";
    } else if (progressOfLevel == LevelProgress::PERFECTLY_DONE + '0') {
        folder = "best/";
    } else {
        folder = "empty/";
    }
    _window->drawPng((int) ((304 + 200 * jLevelIndex) * _window->getWidth() / 1200.0),
                     (int) ((54 + 200 * iLevelIndex) * _window->getHeight() / 700.0),
                     string(ASSET_DIRECTORY) + "/img/Progress/" + folder + to_string(noLevel) + ".png");
}



