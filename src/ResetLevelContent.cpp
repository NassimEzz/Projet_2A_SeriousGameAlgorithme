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
 * @file ResetLevelContent.cpp.cc
 *
 *
 */

#include "ResetLevelContent.h"

ResetLevelContent::ResetLevelContent(Level *receiver) {
    _receiver = receiver;
}

ResetLevelContent::~ResetLevelContent() = default;

void ResetLevelContent::execute() {
    _receiver->resetAndDrawWindowContent();
}