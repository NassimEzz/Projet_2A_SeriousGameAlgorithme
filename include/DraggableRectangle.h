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
 * @file DraggableRectangle.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_DRAGGABLERECTANGLE_H
#define P2A_SERIOUS_GAME_DRAGGABLERECTANGLE_H

#include "PictureInformer.h"
#include "Window.h"
#include "Utils.h"

class DraggableRectangle {
public :
    DraggableRectangle(int uniqueID, const Point &position, const Color &color, const std::string &text,
                       int fontSize, Window *window, const PictureInformer &pictureInformer);

    DraggableRectangle(int uniqueID, int logicID, const Point &position, const Color &color, const std::string &text,
                       int fontSize, Window *window, const PictureInformer &pictureInformer);

    void drawMe();

    bool overlap(unsigned int x, unsigned int y) const;

    void onDragClicked(int x, int y);

    void onDragReleased(int x, int y);

    void onDragMoved(int x, int y);

    bool isCurrentlyClicked() const;

    void resetPosition();

    void setMeInReceiver(int x, int y);

    int getLogicID() const;

    long getUniqueID() const;

    int getX() const;

    int getY() const;


private :
    int _logicID;
    int _uniqueID;
    Rectangle _rect{};
    Color _color{};
    std::string _picturePath;
    int _x0;
    int _y0;
    bool _isDragRectClicked = false;
    int _xClickOffset = 0;
    int _yClickOffset = 0;
    std::string _text;
    int _fontSize;
    Window *_window;
};


#endif //P2A_SERIOUS_GAME_DRAGGABLERECTANGLE_H
