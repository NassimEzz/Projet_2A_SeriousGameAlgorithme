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
 * @file LevelSelectorPage.h
 *
 *
 */

#ifndef LEVELSELECTORPAGE_H
#define LEVELSELECTORPAGE_H


#include <vector>
#include "WindowContent.h"
#include <memory>

class LevelSelectorPage : public WindowContent {
public :
    LevelSelectorPage(Window *window, const std::string &title, const std::string &backgroundPath);

    ~LevelSelectorPage() override;

    void addButton(std::unique_ptr<Button> &&button) override;

    void displayMeOnWindow() override;

    void receiveEvent(Event event) override;

private :
    std::vector<std::unique_ptr<Button>> _arrButton;
    std::string _backgroundPath;

    void handleClickEvent(unsigned int x, unsigned int y);
};


#endif //LEVELSELECTORPAGE_H
