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
 * @version 0.0 - 05/04/2021
 */

/**
 * @file Platform.cpp
 *
 *
 */

#include "Platform.h"
#include "SDLWindowImp.h"
#include "EMSWindowImp.h"


std::unique_ptr<IWindowImp> Platform::instantiateWindowImp() {
  switch (getCurrentPlatform()) {
    case SDL:
      return std::make_unique<SDLWindowImp>("P2A - SeriousGame", 1200, 700);
#ifdef __EMSCRIPTEN__
    case EMS:
      return std::make_unique<EMSWindowImp>("P2A - SeriousGame", 1200, 700);
#endif
    default:
      throw "Error: invalid platform";
      
  }
}

Platform::target Platform::getCurrentPlatform() {
#ifdef __EMSCRIPTEN__
  return EMS;
#else
  return SDL;
#endif
}

