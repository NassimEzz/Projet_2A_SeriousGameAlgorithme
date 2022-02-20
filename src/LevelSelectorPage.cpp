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
 * @version 0.0 - 27/11/2020
 */

/**
 * @file LevelSelectorPage.cpp
 *
 *
 */

#include "LevelSelectorPage.h"

#include <utility>

LevelSelectorPage::LevelSelectorPage(Window *window, const std::string &title, const std::string &backgroundPath)
        : WindowContent(window, title), _backgroundPath(std::move(backgroundPath)) {

}

void LevelSelectorPage::addButton(std::unique_ptr<Button> &&button) {
    _arrButton.push_back(std::move(button));
}

void LevelSelectorPage::displayMeOnWindow() {
    _window->clearScreen();
    _window->setTitle(_title);
    _window->drawPng(0, 0, _backgroundPath);
    for (auto &button : _arrButton) {
        button->drawMe(*_window);
    }
    _window->updateScreen();
}

void LevelSelectorPage::handleClickEvent(unsigned int x, unsigned int y) {
    for (auto &button : _arrButton) {
        if (button->overlap(x, y)) {
            button->onClick();
        }
    }
}

void LevelSelectorPage::receiveEvent(Event event) {
    if (event.getType() == EventType::MOUSEDOWN) {
        handleClickEvent(event.getX(), event.getY());
    }
}

LevelSelectorPage::~LevelSelectorPage() = default;
