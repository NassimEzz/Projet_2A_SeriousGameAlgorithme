//
// Created by navid on 05/01/2021.
//

#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H

#include <ICommand.h>
#include <WindowContent.h>
#include <Window.h>


class ExitCommand : public ICommand {
public :
    explicit ExitCommand(Window *mainWindow);

    void execute() override;

private :
    Window *_window;
};

#endif // EXIT_COMMAND_H
