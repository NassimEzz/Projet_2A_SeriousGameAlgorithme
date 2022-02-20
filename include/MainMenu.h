//
// Created by navid on 05/01/2021.
//
#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED

#ifndef ASSET_DIRECTORY            // In the case ASSET_DIRECTORY
#define ASSET_DIRECTORY "./assets" // wouldn't be defined before compilation.
#endif // ASSET_DIRECTORY          //

#include <vector>
#include <WindowContent.h>
#include <Event.h>
#include <RectButton.h>

class MainMenu : public WindowContent {
public :
    MainMenu(Window *window, const std::string &title) : WindowContent(window, title) {};

    void addButton(std::unique_ptr<Button> &&button) override;

    void receiveEvent(Event event) override;

    void displayMeOnWindow() override;

    void activateMe() override;

private :
    std::vector<std::unique_ptr<Button>> _arrButton;

    void handleClickEvent(unsigned int x, unsigned int y);
};

#endif // MAINMENU_H_INCLUDED
