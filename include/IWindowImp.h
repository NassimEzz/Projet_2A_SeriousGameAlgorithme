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
 * @file IWindowImp.h
 *
 *
 */

#ifndef IWINDOWIMP_H
#define IWINDOWIMP_H

#include <string>
#include "Utils.h"
#include "Event.h"

using namespace std;

class IWindowImp {

public:
    virtual ~IWindowImp();

    virtual void setTitle(const string &windowTitle) = 0;

    virtual void drawPNG(int x, int y, const std::string &pictureName) = 0;

    virtual void drawPNGWithBoundChecking(Rectangle &rect, const std::string &pictureName) = 0;

    virtual void addWindowIcon(const string &iconPath) = 0;

    virtual void writePixelText(const string &text, int size, unsigned int x, unsigned int y, const Color &color,
                                unsigned int length) = 0;

    virtual void writePixelText(ifstream &file, int size, unsigned int x, unsigned int y, const Color &color,
                                unsigned int length) = 0;

    virtual int getWidth() = 0;

    virtual int getHeight() = 0;

    virtual unsigned int getPictureHeight(const string &path) = 0;

    virtual unsigned int getPictureWidth(const string &path) = 0;

    virtual void clearScreen() = 0;

    virtual void updateScreen() = 0;

    virtual Event getEvent() = 0;

    virtual void wait(unsigned int ms) = 0;

    virtual void close() = 0;
};


#endif //IWINDOWIMP_H
