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
 * @file PictureInformer.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_PICTUREINFORMER_H
#define P2A_SERIOUS_GAME_PICTUREINFORMER_H


#include "Window.h"

struct PictureInformer {
public :
    PictureInformer();

    PictureInformer(const std::string &picture, Window *window);

    unsigned int getPictureWidth() const;

    unsigned int getPictureHeight() const;

    std::string picturePath;
private :
    Window *_window;
};


#endif //P2A_SERIOUS_GAME_PICTUREINFORMER_H
