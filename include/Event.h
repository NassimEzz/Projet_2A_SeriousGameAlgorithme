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

/**
 * @file EventType.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_EVENT_H
#define P2A_SERIOUS_GAME_EVENT_H


enum class EventType {
    QUIT, MOUSEDOWN, MOUSEUP, MOUSEMOTION, KEYDOWN, UNKNOWN
};

class Event {
public :
    Event(EventType type, unsigned int x = 0, unsigned int y = 0);

    inline EventType getType();

    inline unsigned int getX() const;

    inline unsigned int getY() const;

private :
    EventType _type;
    unsigned int _x = 0;
    unsigned int _y = 0;
};


EventType Event::getType() {
    return _type;
}

unsigned int Event::getX() const {
    return _x;
}

unsigned int Event::getY() const {
    return _y;
}

#endif //P2A_SERIOUS_GAME_EVENT_H
