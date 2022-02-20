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
 * @author Navid Kavian
 * @version 1.0
 */

#include <LevelRuler.h>

LevelRuler::LevelRuler(const std::string &pathToRules, const std::string &levelBackground, Level *level, Window *window,
                       const std::string &title) :
        WindowContent(window, title), _levelBackground(levelBackground), _ruleFile(pathToRules), _level(level) {
}

LevelRuler::~LevelRuler() = default;

void LevelRuler::displayMeOnWindow() {
    _window->clearScreen();
    _window->setTitle(_title);
    _window->drawPng(0, 0, _levelBackground);
    _window->drawPng(60, 35, string(ASSET_DIRECTORY) + "/img/Level/Rules_Background.png");
    _window->writePixelText(_ruleFile, 24, 210, 185, {10, 140, 78}, _window->getWidth());
    _window->updateScreen();
}

void LevelRuler::receiveEvent(Event event) {
    if ((event.getType() == EventType::KEYDOWN)||(event.getType() == EventType::MOUSEDOWN)){
        _window->setCurrentContent(_level);
    }
}
