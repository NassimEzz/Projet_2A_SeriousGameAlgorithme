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
 * @file Button.h
 *
 *
 */

#ifndef BUTTON_H
#define BUTTON_H


#include "ICommand.h"
#include "Window.h"
#include <memory>

class Button {
public :
    explicit Button(std::shared_ptr<ICommand> command);

    virtual ~Button();

    virtual bool overlap(unsigned int x, unsigned int y) = 0;

    void onClick();

    virtual void drawMe(Window &window) = 0;

private:
    std::shared_ptr<ICommand> _command;
};


#endif //BUTTON_H
