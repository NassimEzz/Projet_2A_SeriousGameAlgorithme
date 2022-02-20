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
 * @version 0.0 - 10/02/2021
 */

/**
 * @file ResetContentBeforeQuittingItCommand.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_RESETLEVELANDDISPLAYOTHERCONTENT_H
#define P2A_SERIOUS_GAME_RESETLEVELANDDISPLAYOTHERCONTENT_H


#include "WindowContent.h"
#include "Level.h"

class ResetLevelAndDisplayOtherContent : public ICommand {
public:
    explicit ResetLevelAndDisplayOtherContent(Level *level, WindowContent *receiver);

    ~ResetLevelAndDisplayOtherContent() override;

    void execute() override;

private :
    WindowContent *_receiver;
    Level *_currentLevelOnWindow;

};


#endif //P2A_SERIOUS_GAME_RESETLEVELANDDISPLAYOTHERCONTENT_H
