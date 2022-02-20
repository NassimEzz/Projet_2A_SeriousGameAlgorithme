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
 * @file Window.h
 *
 *
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <memory>
#include "Utils.h"
#include "IWindowImp.h"

class WindowContent;


class Window {
public :
    explicit Window(std::unique_ptr<IWindowImp> &&windowImp);

    ~Window();

    void addWindowIcon(const std::string &iconPath);

    void drawPng(int x, int y, const std::string &pictureName);

    void drawPNGWithBoundChecking(Rectangle &rect, const std::string &pictureName);

    void setTitle(const std::string &windowTitle);

    void setCurrentContent(WindowContent *content);

    void writePixelText(const std::string &text, int size, unsigned int x, unsigned int y, const Color &color,
                        unsigned int length);

    void
    writePixelText(ifstream &file, int size, unsigned int x, unsigned int y, const Color &color, unsigned int length);

    bool renderFrame();

    void mainLoop();

    void clearScreen();

    void updateScreen();

    int getWidth();

    int getHeight();

    unsigned int getPictureHeight(const string &path);

    unsigned int getPictureWidth(const string &path);

    void exitWindow();

private:
    bool _exitWindow = false;
    WindowContent *_content = nullptr;
    std::unique_ptr<IWindowImp> _windowImp = nullptr;
};


#endif //WINDOW_H
