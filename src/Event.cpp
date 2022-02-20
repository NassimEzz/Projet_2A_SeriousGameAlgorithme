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
 * @version 0.0 - 28/11/2020
 */

#include <Event.h>

/**
 * @file Event.cpp
 *
 *
 */

Event::Event(EventType type, unsigned int x, unsigned int y) {
    _type = type;
    _x = x;
    _y = y;
}
