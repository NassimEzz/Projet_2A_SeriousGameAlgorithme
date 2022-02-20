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
 * @version 0.0 - 03/02/2021
 */

/**
 * @file DraggableRectangle.cpp.cc
 *
 *
 */

#include "PictureInformer.h"
#include "DraggableRectangle.h"

DraggableRectangle::DraggableRectangle(int uniqueID, const Point &position, const Color &color, const std::string &text,
                                       int fontSize, Window *window, const PictureInformer &pictureInformer) {
    _logicID = uniqueID;
    _uniqueID = uniqueID;
    _picturePath = pictureInformer.picturePath;
    _rect = {position.x, position.y, pictureInformer.getPictureWidth(), pictureInformer.getPictureHeight()};
    _x0 = position.x;
    _y0 = position.y;
    _color = color;
    _text = text;
    _window = window;
    _fontSize = fontSize;
}

DraggableRectangle::DraggableRectangle(int uniqueID, int logicID, const Point &position, const Color &color,
                                       const std::string &text,
                                       int fontSize, Window *window, const PictureInformer &pictureInformer) {
    _logicID = logicID;
    _uniqueID = uniqueID;
    _picturePath = pictureInformer.picturePath;
    _rect = {position.x, position.y, pictureInformer.getPictureWidth(), pictureInformer.getPictureHeight()};
    _x0 = position.x;
    _y0 = position.y;
    _color = color;
    _text = text;
    _fontSize = fontSize;
    _window = window;
}

void DraggableRectangle::drawMe() {
    _window->drawPNGWithBoundChecking(_rect, _picturePath);
    _window->writePixelText(_text, _fontSize, _rect.x + 15, _rect.y + _rect.height / 3, _color, _window->getWidth());
}

bool DraggableRectangle::overlap(unsigned int x, unsigned int y) const {
    return _rect.isInRectangle((int) x, (int) y);
}

void DraggableRectangle::onDragClicked(int x, int y) {
    if (!_isDragRectClicked) {
        _isDragRectClicked = true;
        _xClickOffset = x - _rect.x;
        _yClickOffset = y - _rect.y;
    }
}

void DraggableRectangle::onDragReleased(int x, int y) {
    _rect.x = x - _xClickOffset;
    _rect.y = y - _yClickOffset;
    _isDragRectClicked = false;
}

void DraggableRectangle::onDragMoved(int x, int y) {
    if (_isDragRectClicked) {
        _rect.x = x - _xClickOffset;
        _rect.y = y - _yClickOffset;
    }
}

bool DraggableRectangle::isCurrentlyClicked() const {
    return _isDragRectClicked;
}

void DraggableRectangle::resetPosition() {
    _rect.x = _x0;
    _rect.y = _y0;
    _isDragRectClicked = false;
}

int DraggableRectangle::getLogicID() const {
    return _logicID;
}

long DraggableRectangle::getUniqueID() const {
    return _uniqueID;
}

int DraggableRectangle::getX() const {
    return _rect.x;
}

int DraggableRectangle::getY() const {
    return _rect.y;
}

void DraggableRectangle::setMeInReceiver(int x, int y) {
    _rect.x = x;
    _rect.y = y;
}
