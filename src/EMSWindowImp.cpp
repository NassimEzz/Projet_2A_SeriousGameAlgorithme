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
 * @file EMSWindowImp.cpp
 *
 *
 */


#include "EMSWindowImp.h"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
EMSWindowImp::EMSWindowImp(const string &window_name, unsigned int sizeX, unsigned
sizeY) : SDLWindowImp( window_name, sizeX, sizeY) {
}

void EMSWindowImp::wait(unsigned int ms) {
  emscripten_sleep(ms);
}
#endif




