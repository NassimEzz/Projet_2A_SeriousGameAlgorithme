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
 * @file Window.cpp
 *
 *
 */

#include "Event.h"
#include "Window.h"
#include "WindowContent.h"
#include "IWindowImp.h"

Window::Window(unique_ptr<IWindowImp> &&windowImp) {
    _windowImp = unique_ptr<IWindowImp>(move(windowImp));
}

void Window::drawPng(int x, int y, const std::string &pictureName) {
    _windowImp->drawPNG(x, y, pictureName);

}

void Window::setTitle(const std::string &windowTitle) {
    _windowImp->setTitle(windowTitle);
}

void Window::clearScreen() {
    _windowImp->clearScreen();
}

void Window::updateScreen() {
    _windowImp->updateScreen();
}

void Window::setCurrentContent(WindowContent *content) {
    _content = content;
}


bool Window::renderFrame() {
    Event event = _windowImp->getEvent();
    if ((event.getType() == EventType::QUIT) || (_exitWindow)) {
        _windowImp->close();
        return false;
    } else {
        _content->receiveEvent(event);
    }
    _content->displayMeOnWindow();
    return true;
}

void Window::mainLoop() {
    bool keepDrawing = true;
    do {
        keepDrawing = renderFrame();
#ifdef __EMSCRIPTEN__
#else
        _windowImp->wait(1);
#endif
    } while (keepDrawing);
}

Window::~Window() = default;

void Window::exitWindow() {
    _exitWindow = true;
}

void Window::addWindowIcon(const string &iconPath) {
    _windowImp->addWindowIcon(iconPath);
}

void Window::writePixelText(const std::string &text, int size, unsigned int x, unsigned int y, const Color &color,
                            unsigned int length) {
    _windowImp->writePixelText(text, size, x, y, color, length);
}

void Window::writePixelText(ifstream &file, int size, unsigned int x, unsigned int y, const Color &color,
                            unsigned int length) {
    _windowImp->writePixelText(file, size, x, y, color, length);
}

int Window::getWidth() {
    return _windowImp->getWidth();
}

int Window::getHeight() {
    return _windowImp->getHeight();
}

unsigned int Window::getPictureHeight(const string &path) {
    return _windowImp->getPictureHeight(path);
}

unsigned int Window::getPictureWidth(const string &path) {
    return _windowImp->getPictureWidth(path);
}

void Window::drawPNGWithBoundChecking(Rectangle &rect, const string &pictureName) {
    _windowImp->drawPNGWithBoundChecking(rect, pictureName);
}


