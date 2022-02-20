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
 * @file Level.cpp
 *
 *
 */

#include <utility>
#include "PictureInformer.h"
#include "Level.h"
#include "LevelRuler.h"
#include "RectButton.h"
#include "DisplayContentCommand.h"


Level::Level(int noLevel, Window *window, const std::string &pathToBackground,
             const std::string &pathToRuleFile, const std::string &pathToLogicFile,
             WindowContent *nextContent) :
        WindowContent(window, "Niveau " + to_string(noLevel)) {
    _pathToBackground = pathToBackground;
    _noLevel = noLevel;
    _levelRuler = make_unique<LevelRuler>(pathToRuleFile, pathToBackground, this, _window,
                                          "Niveau " + to_string(noLevel) + " - Règles");
    _gameLogic = make_unique<GameLogic>(pathToLogicFile);
    _contentAfterWinning = nextContent;
    _isReceiverCorrect = true;
    addButton(
            std::make_unique<RectButton>(std::unique_ptr<ICommand>(
                    new DisplayContentCommand(_levelRuler.get())),
                                         Point{_window->getWidth() / 12, _window->getHeight() / 17},
                                         PictureInformer{std::string(ASSET_DIRECTORY) + "/img/Level/rules_button.png",
                                                         _window}));
}

void Level::addButton(std::unique_ptr<Button> &&button) {
    _arrButton.push_back(std::move(button));
}


void Level::displayMeOnWindow() {
    if (_isFirstTimeDisplayed) {
        _isFirstTimeDisplayed = false;
        _window->clearScreen();
        _window->setCurrentContent(_levelRuler.get());
        return;
    }
    _window->clearScreen();
    _window->setTitle(_title);
    _window->drawPng(0, 0, _pathToBackground);

    for (auto &button : _arrButton) {
        button->drawMe(*_window);
    }

    for (auto &dropRect : _dropRectVect) {
        dropRect.drawMe(_window, _isReceiverCorrect);
    }

    for (auto &dragRect : _dragRectVect) {
        dragRect.drawMe();
    }
    _window->updateScreen();
}

void Level::mouseDownProcess(int x, int y) {
    for (auto &button : _arrButton) {
        if (button->overlap(x, y)) {
            button->onClick();
            return;
        }
    }
    for (long i = long(_dragRectVect.size() - 1); i >= 0; i--) {
        if (_dragRectVect[i].overlap(x, y)) {
            _dragRectVect[i].onDragClicked(x, y);
            putSelectedOnTop(i);
            return;
        }
    }
}

void Level::putSelectedOnTop(long selected) {
    _dragRectVect.push_back(_dragRectVect[selected]);
    _dragRectVect.erase(_dragRectVect.begin() + selected);
}

void Level::associateDraggableToReceivers(int x, int y, DraggableRectangle& draggable) {
    for (auto &dropRect : _dropRectVect) {
        if (dropRect.isAvailable(draggable.getUniqueID(), x, y)) {
            dropRect.setReceiverContent(&draggable, x, y);
        } else if (dropRect.isOutOfReceiver(draggable.getUniqueID(), x, y)) {
            dropRect.resetDrag();
        }
    }
}

void Level::mouseUpProcess(int x, int y) {
    for ( auto & draggable : _dragRectVect) {
        if (draggable.isCurrentlyClicked()) {
            draggable.onDragReleased(x, y);
            associateDraggableToReceivers(x, y, draggable);
            break;
        }
    }
}

void Level::mouseMovingProcess(int x, int y) {
    for ( auto & draggable : _dragRectVect) {
        if (draggable.isCurrentlyClicked()) {
            draggable.onDragMoved(x,y);
            associateDraggableToReceivers(x, y, draggable);
            break;
        }
    }
}

void Level::launchWinningScreen(const string& pathToWinningScreen) {
    _winningScreen = nullptr;
    _winningScreen = make_unique<WinningScreen>(_window, pathToWinningScreen,_contentAfterWinning);
    _window->setCurrentContent(_winningScreen.get());
}

void Level::handleAnswer() {
    string list;
    unsigned int typeOfAnswer;

    for (auto &dropRect : _dropRectVect) {
        list += std::to_string(dropRect.getCurrentDragLogicID());
    }
    typeOfAnswer = _gameLogic->checkAnswer(list);
    _isReceiverCorrect=true;
    if (typeOfAnswer == LevelProgress::PERFECTLY_DONE) {
        _progress.setPerfectlyDone(_noLevel);
        launchWinningScreen(std::string(ASSET_DIRECTORY) + "/img/Level/" + "Perfect_Winning_Screen.png");
        resetLevel();
    } else if (typeOfAnswer == LevelProgress::DONE) {
        _progress.setDone(_noLevel);
        launchWinningScreen(std::string(ASSET_DIRECTORY) + "/img/Level/" + "Correct_Winning_Screen.png");
        resetLevel();
    } else if(typeOfAnswer == LevelProgress::WRONGLY_DONE){
        _isReceiverCorrect = false;
    }
}

void Level::receiveEvent(Event event) {
    switch (event.getType()) {
        case EventType::MOUSEDOWN :
            mouseDownProcess((int) event.getX(), (int) event.getY());
            break;
        case EventType::MOUSEUP:
            mouseUpProcess((int) event.getX(), (int) event.getY());
            handleAnswer();
            break;
        case EventType::MOUSEMOTION:
            mouseMovingProcess((int) event.getX(), (int) event.getY());
            break;
        default :
            break;
    }
}

void Level::resetAndDrawWindowContent() {
    _window->clearScreen();
    _window->setTitle(_title);
    _window->drawPng(0, 0, _pathToBackground);
    for (auto &dropRect : _dropRectVect) {
        dropRect.drawMe(_window,_isReceiverCorrect);
        dropRect.resetDrag();
    }
    for (auto &dragRect : _dragRectVect) {
        dragRect.resetPosition();
        dragRect.drawMe();
    }
    for (auto &button : _arrButton) {
        button->drawMe(*_window);
    }
    _window->updateScreen();
}

void Level::resetLevel() {
    _isFirstTimeDisplayed = true;
    for (auto &dragRect : _dragRectVect) {
        dragRect.resetPosition();
    }
    for (auto &dropRect : _dropRectVect) {
        dropRect.resetDrag();
    }
}

void Level::createNewReceiver(const Receiver &receiver) {
    _dropRectVect.push_back(receiver);
}

void Level::createNewDraggableRectangle(const DraggableRectangle &draggableRectangle) {
    _dragRectVect.push_back(draggableRectangle);
}

Level::~Level() = default;


