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
 * @file WindowContent.cpp
 *
 *
 */

#include "WindowContent.h"

WindowContent::WindowContent(Window *window, const std::string &title)
        : _window(window), _title(title) {}

WindowContent::~WindowContent() = default;

void WindowContent::activateMe() {
    _window->setCurrentContent(this);
}

