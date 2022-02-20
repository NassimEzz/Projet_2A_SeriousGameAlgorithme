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
 * @author Loic Simon <loic.simon@ensicaen.fr>
 * @version 0.0 - 15/03/2021
 */

/**
 * @file GameApplication.h
 *
 *
 */

#ifndef GAME_APPLICATION_H
#define GAME_APPLICATION_H


#include "ICommand.h"
#include "Window.h"
#include "MainMenu.h"
#include "ProgressWindowContent.h"
#include "LevelSelectorPage.h"
#include "Level.h"
#include "PictureInformer.h"
#include <memory>

class GameApplication {
public :
    GameApplication();

    ~GameApplication();

    void run();


private:
    void build();

    void makeLevel1();

    void makeLevel2();

    void makeLevel3();

private:
    Window mainWindow;
    MainMenu mainMenu;
    ProgressWindowContent progressWindowContent;
    LevelSelectorPage selector1;
    LevelSelectorPage selector2;
    LevelSelectorPage selector3;
    Level l1;
    Level l2;
    Level l3;
};


#endif //GAME_APPLICATION_H

