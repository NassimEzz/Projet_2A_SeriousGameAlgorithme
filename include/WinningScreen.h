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
 * @author Navid Kavian
 * @version 1.0
 */

#ifndef P2A_SERIOUS_GAME_WINNINGSCREEN_H
#define P2A_SERIOUS_GAME_WINNINGSCREEN_H

#include "WindowContent.h"

class WinningScreen : public WindowContent {
public :
    WinningScreen(Window *window, const std::string &backgroundPath,
                  WindowContent *nextContent);

    ~WinningScreen() override;

    void addButton(std::unique_ptr<Button> &&/*button*/) override {};

    void displayMeOnWindow() override;

    void receiveEvent(Event event) override;


private :
    WindowContent *_nextContent = nullptr;
    std::string _backgroundPath;

};

#endif //P2A_SERIOUS_GAME_WINNINGSCREEN_H
