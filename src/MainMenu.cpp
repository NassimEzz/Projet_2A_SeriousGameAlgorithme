//
// Created by navid on 05/01/2021.
//

#include <MainMenu.h>

void MainMenu::handleClickEvent(unsigned int x, unsigned int y) {
    for (auto &button : _arrButton) {
        if (button->overlap(x, y)) {
            button->onClick();
        }
    }
}

void MainMenu::receiveEvent(Event event) {
    if (event.getType() == EventType::MOUSEDOWN) {
        handleClickEvent(event.getX(), event.getY());
    }
}

void MainMenu::displayMeOnWindow() {
    _window->clearScreen();
    _window->setTitle(_title);
    _window->drawPng(0, 0, std::string(ASSET_DIRECTORY) + "/img/MainMenu/" + "principal_menu.png");
    for (auto &button : _arrButton) {
        button->drawMe(*_window);
    }
    _window->setCurrentContent(this);
    _window->updateScreen();
}

void MainMenu::activateMe() {
    WindowContent::activateMe();
}

void MainMenu::addButton(unique_ptr<Button> &&button) {
    _arrButton.push_back(std::move(button));
}
