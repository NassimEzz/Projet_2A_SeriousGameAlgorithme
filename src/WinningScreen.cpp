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
#include "WinningScreen.h"


WinningScreen::WinningScreen(Window *window, const std::string &backgroundPath, WindowContent *nextContent) :
        WindowContent(window, "Victoire !"),
        _nextContent(nextContent), _backgroundPath(backgroundPath) {
}

WinningScreen::~WinningScreen() = default;

void WinningScreen::displayMeOnWindow() {
    _window->clearScreen();
    _window->setTitle(_title);
    _window->drawPng(0, 0, _backgroundPath);
    _window->writePixelText("Niveau terminé. Appuie quelque part ou sur une touche.", 18, _window->getWidth() / 9,
                            10 * _window->getHeight() / 11,
                            {0, 0, 0}, _window->getWidth());
    _window->updateScreen();
}

void WinningScreen::receiveEvent(Event event) {
    if ((event.getType() == EventType::KEYDOWN)||(event.getType() == EventType::MOUSEDOWN)){
        _window->setCurrentContent(_nextContent);
    }
}
