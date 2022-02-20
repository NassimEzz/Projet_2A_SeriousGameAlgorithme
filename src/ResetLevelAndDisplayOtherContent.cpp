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
 * @file ResetContentBeforeQuittingItCommand.cpp.cc
 *
 *
 */

#include "ResetLevelAndDisplayOtherContent.h"

ResetLevelAndDisplayOtherContent::ResetLevelAndDisplayOtherContent(Level *level, WindowContent *receiver) {
    _currentLevelOnWindow = level;
    _receiver = receiver;
}

ResetLevelAndDisplayOtherContent::~ResetLevelAndDisplayOtherContent() = default;

void ResetLevelAndDisplayOtherContent::execute() {
    _currentLevelOnWindow->resetLevel();
    _receiver->activateMe();
}
