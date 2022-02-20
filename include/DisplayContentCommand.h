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
 * @file DisplayContentCommand.h
 *
 *
 */

#ifndef DISPLAYWINDOWCONTENT_H
#define DISPLAYWINDOWCONTENT_H


#include "ICommand.h"
#include "WindowContent.h"
#include <memory>

class DisplayContentCommand : public ICommand {
public:
    explicit DisplayContentCommand(WindowContent *receiver);

    ~DisplayContentCommand() override;

    void execute() override;

private :
    WindowContent *_receiver;
};


#endif //DISPLAYWINDOWCONTENT_H
