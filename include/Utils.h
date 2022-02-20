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
 * @version 0.0 - 18/02/2021
 */

/**
 * @file Utils.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_UTILS_H
#define P2A_SERIOUS_GAME_UTILS_H

struct Rectangle {
public :
    int x;
    int y;
    unsigned int width;
    unsigned int height;

    bool isInRectangle(int xPos, int yPos) const {
        return ((xPos >= x)
                && (xPos <= int(x + width))
                && (yPos >= y)
                && (yPos <= int(y + height)));
    }
};

struct Point {
    int x;
    int y;
};

struct Color {
    unsigned int r;
    unsigned int g;
    unsigned int b;
};

enum LevelProgress : int {
    NOT_DONE = 0,
    DONE = 1,
    PERFECTLY_DONE = 2,
    WRONGLY_DONE = 3
};

#endif //P2A_SERIOUS_GAME_UTILS_H
