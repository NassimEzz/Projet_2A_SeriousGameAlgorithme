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
 * @author Loic Simon <loic.simon@ensicaen.fr>
 * @version 0.0 - 05/04/2021
 */

/**
 * @file SDLWindowImp.cpp
 *
 *
 */

#ifndef EMSWINDOWIMP_H
#define EMSWINDOWIMP_H


#include "SDLWindowImp.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
class EMSWindowImp : public SDLWindowImp {
public :
    EMSWindowImp(const string &window_name, unsigned int sizeX, unsigned
    sizeY);
    void wait(unsigned int ms) override;
};
#endif

#endif //EMSWINDOWIMP_H
