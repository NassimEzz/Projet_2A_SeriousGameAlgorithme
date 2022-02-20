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
 * @version 0.0 - 27/12/2020
 */

/**
 * @file LevelSelectorThemePixel.cpp.cc
 *
 *
 */

#include "RectButton.h"
#include "LevelSelectorThemePixel.h"

#include <utility>

LevelSelectorThemePixel::LevelSelectorThemePixel(unsigned int width, unsigned int height, std::string page,
                                                 Window *window)
        : _window(window), width(width), height(height), page(std::move(page)) {}


std::unique_ptr<Button> LevelSelectorThemePixel::makeLevelButton(unsigned int level,
                                                                 std::shared_ptr<ICommand> command) {
    std::string levelStr = std::to_string(level);
    std::string message = "Level" + levelStr;
    std::string imgPath =
            std::string(ASSET_DIRECTORY) + "/img/LevelSelector/" + page +
            "/l" + levelStr + ".png";
    unsigned int x, y;
    getLevelButtonPosition(level, x, y);
    auto levelButton = std::make_unique<RectButton>(command, Point{int(x), int(y)},
                                                    PictureInformer{imgPath, _window});
    return levelButton;
}

std::unique_ptr<Button> LevelSelectorThemePixel::makeNextPageButton(
        std::shared_ptr<ICommand> command) {
    auto nextButton = std::make_unique<RectButton>(command, Point{int(9 * width / 10), int(height / 2)},
                                                   PictureInformer{
                                                           std::string(ASSET_DIRECTORY) +
                                                           "/img/LevelSelector/" + page +
                                                           "/right_arrow.png", _window});
    return nextButton;
}

std::unique_ptr<Button> LevelSelectorThemePixel::makePrevPageButton(
        std::shared_ptr<ICommand> command) {
    auto nextButton = std::make_unique<RectButton>(command,
                                                   Point{int(width / 10), int(height / 2)},
                                                   PictureInformer{
                                                           std::string(ASSET_DIRECTORY) +
                                                           "/img/LevelSelector/" + page +
                                                           "/left_arrow.png", _window});
    return nextButton;
}

std::unique_ptr<Button> LevelSelectorThemePixel::makeQuitPageButton(
        std::shared_ptr<ICommand> command) {
    auto quitButton = std::make_unique<RectButton>(command,
                                                   Point{int(9 * width) / 10, int(9 * height / 10)},
                                                   PictureInformer{std::string(ASSET_DIRECTORY) +
                                                                   "/img/LevelSelector/" + "/quit_button.png",
                                                                   _window});
    return quitButton;
}

std::unique_ptr<Button> LevelSelectorThemePixel::makeMenuButton(
        std::shared_ptr<ICommand> command) {
    auto returnButton = std::make_unique<RectButton>(command,
                                                     Point{int(9 * width / 10), int(8 * height / 10)},
                                                     PictureInformer{
                                                             std::string(ASSET_DIRECTORY) + "/img/LevelSelector/"
                                                             + "/menu_boutton.png", _window});
    return returnButton;
}

void LevelSelectorThemePixel::getLevelButtonPosition(unsigned int level,
                                                     unsigned int &x,
                                                     unsigned int &y) const {
    x = level * width / 3;
    y = level * height / 4;
    if (level == 3) {
        x = width / 2;
    }
    if (level == 2) {
        y = height / 4;
    }
}
