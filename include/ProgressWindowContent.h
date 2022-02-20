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
 * @version 0.0 - 06/03/2021
 */

/**
 * @file ProgressWindowContent.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_PROGRESSWINDOWCONTENT_H
#define P2A_SERIOUS_GAME_PROGRESSWINDOWCONTENT_H


#include "WindowContent.h"
#include "ProgressModel.h"
#include <vector>

class ProgressWindowContent : public WindowContent {
public :
    ProgressWindowContent(Window *window, const std::string &title, int nbLevel, const std::string &backgroundPath);

    void addButton(std::unique_ptr<Button> &&button) override;

    void receiveEvent(Event event) override;

    void displayMeOnWindow() override;

private :
    void drawLevelProgressPicture(int iLevelIndex, int jLevelIndex);

    void handleClickEvent(unsigned int x, unsigned int y);

    int NB_COLUMNS = 3;
    int NB_ROWS = 3;

    int _nbLevel;
    ProgressModel _progress;
    std::string _levelProgression;
    std::string _backgroundPath;
    std::vector<std::unique_ptr<Button>> _arrButton;
};


#endif //P2A_SERIOUS_GAME_PROGRESSWINDOWCONTENT_H
