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
 * @file LevelSelectorThemePixel.h
 *
 *
 */

#ifndef P2A_SERIOUS_GAME_LEVELSELECTORTHEMEPIXEL_H
#define P2A_SERIOUS_GAME_LEVELSELECTORTHEMEPIXEL_H


#include "LevelSelectorThemeFactory.h"

#ifndef ASSET_DIRECTORY            // In the case ASSET_DIRECTORY
#define ASSET_DIRECTORY "./assets" // wouldn't be defined before compilation.
#endif // ASSET_DIRECTORY          //


class LevelSelectorThemePixel : public LevelSelectorThemeFactory {
public:
    LevelSelectorThemePixel(unsigned int width, unsigned int height, std::string page, Window *window);

    std::unique_ptr<Button> makeLevelButton(unsigned int level,
                                            std::shared_ptr<ICommand> command) override;

    std::unique_ptr<Button> makeNextPageButton(std::shared_ptr<ICommand> command) override;

    std::unique_ptr<Button> makePrevPageButton(std::shared_ptr<ICommand> command) override;

    std::unique_ptr<Button> makeQuitPageButton(std::shared_ptr<ICommand> command) override;

    std::unique_ptr<Button> makeMenuButton(std::shared_ptr<ICommand> command) override;

private:
    void getLevelButtonPosition(unsigned int level, unsigned int &x, unsigned int &y) const;

private:
    Window *_window;
    unsigned int width;
    unsigned int height;
    std::string page;
};


#endif //P2A_SERIOUS_GAME_LEVELSELECTORTHEMEPIXEL_H
