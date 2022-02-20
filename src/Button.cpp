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
 * @file Button.cpp
 *
 *
 */

#include "Button.h"

Button::Button(shared_ptr<ICommand> command) : _command(command) {}

Button::~Button() = default;

void Button::onClick() {
    if(_command != nullptr) {
        _command->execute();
    }
}



