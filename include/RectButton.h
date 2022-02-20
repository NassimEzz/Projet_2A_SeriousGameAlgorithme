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
 * @file RectButton.h
 *
 *
 */

#ifndef RECTBUTTON_H
#define RECTBUTTON_H


#include <string>
#include "Button.h"
#include "Utils.h"
#include "PictureInformer.h"

class RectButton : public Button {
public :
    RectButton(std::shared_ptr<ICommand> command,
               const Point &barycenter,
               const PictureInformer &buttonInformer);

    ~RectButton() override;

    bool overlap(unsigned int x, unsigned int y) override;

    void drawMe(Window &window) override;

private :
    Rectangle _rect = {};
    std::string _pictureName;
};


#endif //RECTBUTTON_H
