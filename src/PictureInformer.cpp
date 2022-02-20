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
 * @version 0.0 - 23/03/2021
 */

/**
 * @file PictureInformer.cpp.cc
 *
 *
 */

#include "PictureInformer.h"

PictureInformer::PictureInformer(const std::string &picture, Window *window) {
    _window = window;
    picturePath = picture;
}

PictureInformer::PictureInformer() {
    picturePath = "";
    _window = nullptr;
}

unsigned int PictureInformer::getPictureWidth() const {
    if (_window) {
        return _window->getPictureWidth(picturePath);
    }
    return -1;
}

unsigned int PictureInformer::getPictureHeight() const {
    if (_window) {
        return _window->getPictureHeight(picturePath);
    }
    return -1;
}


