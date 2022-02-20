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
 * @file Level.h
 *
 *
 */

#ifndef LEVEL_H
#define LEVEL_H


#include <vector>
#include <fstream>
#include "WindowContent.h"
#include "DraggableRectangle.h"
#include "Receiver.h"
#include "GameLogic.h"
#include "LevelRuler.h"
#include "WinningScreen.h"
#include "ProgressModel.h"

class LevelRuler;

class Level : public WindowContent {
public :
    Level(int noLevel, Window *window, const std::string &pathToBackground,
          const std::string &pathToRuleFile, const std::string &pathToLogicFile,
          WindowContent *nextContent);

    ~Level() override;

    void addButton(std::unique_ptr<Button> &&button) override;

    void displayMeOnWindow() override;

    void receiveEvent(Event event) override;

    void createNewDraggableRectangle(const DraggableRectangle &draggableRectangle);

    void createNewReceiver(const Receiver &receiver);

    void resetAndDrawWindowContent();

    void resetLevel();

private :
    void mouseDownProcess(int x, int y);

    void putSelectedOnTop(long selected);
    void associateDraggableToReceivers(int x, int y, DraggableRectangle& draggable);
    void mouseUpProcess(int x, int y);
    void mouseMovingProcess(int x, int y);

    void handleAnswer();

    void launchWinningScreen(const string& pathToWinningScreen);

    std::vector<std::unique_ptr<Button>> _arrButton;
    std::vector<DraggableRectangle> _dragRectVect;
    std::vector<Receiver> _dropRectVect;

    std::unique_ptr<GameLogic> _gameLogic;
    std::unique_ptr<LevelRuler> _levelRuler;
    std::unique_ptr<WinningScreen> _winningScreen;
    WindowContent *_contentAfterWinning;

    ProgressModel _progress;
    int _noLevel;

    bool _isReceiverCorrect;
    bool _isFirstTimeDisplayed = true;
    std::string _pathToBackground;
};


#endif //LEVEL_H
