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
 * @file RectButton.cpp
 *
 *
 */

#include "PictureInformer.h"
#include "RectButton.h"

RectButton::RectButton(std::shared_ptr<ICommand> command,
                       const Point &barycenter,
                       const PictureInformer &buttonInformer)
        : Button(move(command)) {
    _rect = {(int) (barycenter.x - buttonInformer.getPictureWidth() / 2),
             (int) (barycenter.y - buttonInformer.getPictureHeight() / 2),
             buttonInformer.getPictureWidth(), buttonInformer.getPictureHeight()};
    _pictureName = buttonInformer.picturePath;
}


bool RectButton::overlap(unsigned int x, unsigned int y) {
    return _rect.isInRectangle((int) x, (int) y);
}

RectButton::~RectButton() = default;

void RectButton::drawMe(Window &window) {
    window.drawPng(_rect.x, _rect.y, _pictureName);
}
