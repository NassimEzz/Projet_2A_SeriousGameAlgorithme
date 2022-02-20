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
 * @file Platform.h
 *
 *
 */

#ifndef PLATFORM_APPLICATION_H
#define PLATFORM_APPLICATION_H
#include <memory>
class IWindowImp;

class Platform
{
public:
    static std::unique_ptr<IWindowImp> instantiateWindowImp();
    enum target { SDL, EMS };
private:
    static target getCurrentPlatform();
};
#endif //PLATFORM_APPLICATION_H


