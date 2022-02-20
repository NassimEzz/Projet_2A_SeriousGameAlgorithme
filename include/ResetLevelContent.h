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
 * @version 0.0 - 07/02/2021
 */

/**
 * @file ResetLevelContent.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_RESETLEVELCONTENT_H
#define P2A_SERIOUS_GAME_RESETLEVELCONTENT_H


#include "ICommand.h"
#include "Level.h"

class ResetLevelContent : public ICommand {
public :
    explicit ResetLevelContent(Level *receiver);

    void execute() override;

    ~ResetLevelContent() override;

private :
    Level *_receiver;
};


#endif //P2A_SERIOUS_GAME_RESETLEVELCONTENT_H
