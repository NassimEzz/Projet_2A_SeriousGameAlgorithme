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

#include <ExitCommand.h>

ExitCommand::ExitCommand(Window *mainWindow) : _window(mainWindow) {

}

void ExitCommand::execute() {
    _window->exitWindow();
}
