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
 * @file WindowContent.h
 *
 *
 */

#ifndef WINDOWCONTENT_H
#define WINDOWCONTENT_H


#include <string>
#include <memory>
#include "Window.h"
#include "Button.h"
#include "Event.h"

class WindowContent {
public:
    WindowContent(Window *window,
                  const std::string &title);

    WindowContent() {};

    virtual ~WindowContent();

    virtual void addButton(std::unique_ptr<Button> &&button) = 0;

    virtual void receiveEvent(Event event) = 0;

    virtual void displayMeOnWindow() = 0;

    virtual void activateMe();

protected :
    Window *_window = nullptr;
    std::string _title;
};


#endif //WINDOWCONTENT_H
