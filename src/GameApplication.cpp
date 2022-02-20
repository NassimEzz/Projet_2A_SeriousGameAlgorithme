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
 * @version 0.0 - 15/03/2021
 */

/**
 * @file GameApplication.cpp
 *
 *
 */
#include <random>
#include <algorithm>
#include "GameApplication.h"
#include "ResetLevelContent.h"
#include "ResetLevelAndDisplayOtherContent.h"
#include "LevelSelectorThemePixel.h"
#include "DisplayContentCommand.h"
#include "ExitCommand.h"
#include "Platform.h"


GameApplication::GameApplication() : mainWindow(Platform::instantiateWindowImp()),
                                     mainMenu(&mainWindow, "Menu Principal"),
                                     progressWindowContent(&mainWindow, "Progression", 9, std::string(ASSET_DIRECTORY) +
                                                                                          "/img/Progress/background.png"),
                                     selector1(&mainWindow, "Sélecteur de Niveau - Page 1",
                                               std::string(ASSET_DIRECTORY) +
                                               "/img/LevelSelector/Page1/background.png"),
                                     selector2(&mainWindow, "Sélecteur de Niveau - Page 2",
                                               std::string(ASSET_DIRECTORY) +
                                               "/img/LevelSelector/Page2/background.png"),
                                     selector3(&mainWindow, "Sélecteur de Niveau - Page 3",
                                               std::string(ASSET_DIRECTORY) +
                                               "/img/LevelSelector/Page3/background.png"),
                                     l1(1, &mainWindow, std::string(ASSET_DIRECTORY) + "/img/Level/L1/background.png",
                                        std::string(ASSET_DIRECTORY) + "/rule/Lvl1_Rules.txt",
                                        std::string(ASSET_DIRECTORY) + "/logic/Lvl1_Logic.txt",
                                        &selector1),
                                     l2(2, &mainWindow, std::string(ASSET_DIRECTORY) + "/img/Level/L2/background.png",
                                        std::string(ASSET_DIRECTORY) + "/rule/Lvl2_Rules.txt",
                                        std::string(ASSET_DIRECTORY) + "/logic/Lvl2_Logic.txt",
                                        &selector1),
                                     l3(3, &mainWindow, std::string(ASSET_DIRECTORY) + "/img/Level/L3/background.png",
                                        std::string(ASSET_DIRECTORY) + "/rule/Lvl3_Rules.txt",
                                        std::string(ASSET_DIRECTORY) + "/logic/Lvl3_Logic.txt",
                                        &selector1)

{
    mainWindow.addWindowIcon(std::string(ASSET_DIRECTORY) + "/img/icon.png");
    build();
}

GameApplication::~GameApplication() = default;


void GameApplication::makeLevel1() {
    for (int i = 1; i < 7; i++) {
        l1.createNewReceiver({{760, int((0.5 + 9 / 6.0 * (i - 1)) * mainWindow.getHeight() / 20)},
                              {std::string(ASSET_DIRECTORY) + "/img/Level/L1/Receiver_390-50.png", &mainWindow},
                              std::string(ASSET_DIRECTORY) + "/img/Level/L1/Receiver_b_390-50.png",
                              std::string(ASSET_DIRECTORY) + "/img/Level/L1/Receiver_locked_390-50.png"});
    }
    std::vector<std::string> instructions = {"Prendre les chaussures", "Mettre la chaussure droite",
                                             "Faire le lacet droit",
                                             "Mettre la chassure gauche", "Faire le lacet gauche",
                                             "Sortir s'amuser avec Corneil"};
    std::vector<int> mixAnswers = {0, 1, 2, 3, 4, 5};
    std::random_device rng;
    std::mt19937 urng(rng()); //Uniform Random Number Generator
    std::shuffle(mixAnswers.begin(), mixAnswers.end(), urng);


    Color c = {14, 30, 150};
    for (int i = 1; i < 7; i++) {
        l1.createNewDraggableRectangle({mixAnswers[i - 1] + 1,
                                        {765, int((8 + i) * mainWindow.getHeight() / 17)},
                                        c, instructions[mixAnswers[i - 1]], 13, &mainWindow,
                                        {std::string(ASSET_DIRECTORY) + "/img/Level/L1/Draggable_380-40.png",
                                         &mainWindow}});
    }

    l1.addButton(
            make_unique<RectButton>(make_shared<ResetLevelContent>(&l1),
                                    Point{16 * mainWindow.getWidth() / 20, 16 * mainWindow.getHeight() / 17},
                                    PictureInformer{std::string(ASSET_DIRECTORY) + "/img/Level/reset_button.png",
                                                    &mainWindow}));

    l1.addButton(
            make_unique<RectButton>(make_shared<ResetLevelAndDisplayOtherContent>(&l1, &selector1),
                                    Point{mainWindow.getWidth() / 12, 16 * mainWindow.getHeight() / 17},
                                    PictureInformer{std::string(ASSET_DIRECTORY) + "/img/Level/" + "return_button.png",
                                                    &mainWindow}));
}

void GameApplication::makeLevel2() {
    for (int i = 1; i < 7; i++) {
        int stepRight = ((i + 1) % 2);
        l2.createNewReceiver({{880 + stepRight * 20, int((0.65 + 9 / 6.0 * (i - 1)) * mainWindow.getHeight() / 20)},
                              {std::string(ASSET_DIRECTORY) + "/img/Level/L2/Receiver_280-50.png", &mainWindow},
                              std::string(ASSET_DIRECTORY) + "/img/Level/L2/Receiver_b_280-50.png",
                              std::string(ASSET_DIRECTORY) + "/img/Level/L2/Receiver_locked_280-50.png"});
    }
    std::vector<std::string> instructions = {"Valentin joue pierre", "Valentin joue ciseaux",
                                             "Valentin joue feuille", "Jouer pierre", "Jouer ciseaux",
                                             "Jouer feuille"};
    std::vector<int> mixAnswers = {0, 1, 2, 3, 4, 5};
    std::random_device rng;
    std::mt19937 urng(rng()); //Uniform Random Number Generator
    std::shuffle(mixAnswers.begin(), mixAnswers.end(), urng);

    Color c = {14, 30, 150};
    for (int i = 1; i < 7; i++) {
        l2.createNewDraggableRectangle({mixAnswers[i - 1] + 1,
                                        {790, int((8 + i) * mainWindow.getHeight() / 17)},
                                        c, instructions[mixAnswers[i - 1]], 12, &mainWindow,
                                        {std::string(ASSET_DIRECTORY) + "/img/Level/L2/Draggable_270_40.png",
                                         &mainWindow}});
    }

    l2.addButton(
            make_unique<RectButton>(make_shared<ResetLevelContent>(&l2),
                                    Point{14 * mainWindow.getWidth() / 18, 16 * mainWindow.getHeight() / 17},
                                    PictureInformer{std::string(ASSET_DIRECTORY) + "/img/Level/reset_button.png",
                                                    &mainWindow}));

    l2.addButton(
            make_unique<RectButton>(make_shared<ResetLevelAndDisplayOtherContent>(&l2, &selector1),
                                    Point{mainWindow.getWidth() / 12, 16 * mainWindow.getHeight() / 17},
                                    PictureInformer{std::string(ASSET_DIRECTORY) + "/img/Level/" + "return_button.png",
                                                    &mainWindow}));
}

void GameApplication::makeLevel3() {
    for (int i = 1; i < 13; i++) {
        int stepLeft = ((i - 1) % 4 == 0) ? 1 : 0;
        l3.createNewReceiver({{820 - 40 * stepLeft, int((0.6 + (i - 1)) * mainWindow.getHeight() / 26)},
                              {std::string(ASSET_DIRECTORY) + "/img/Level/L3/Receiver_334-24.png", &mainWindow},
                              std::string(ASSET_DIRECTORY) + "/img/Level/L3/Receiver_b_334-24.png",
                              std::string(ASSET_DIRECTORY) + "/img/Level/L3/Receiver_locked_334-24.png"});
    }

    std::vector<std::string> instructions = {"Valentin va à la plage",
                                             "Valentin prend son short", "Valentin prend sa coupe",
                                             "Valentin prend son maillot de bain",
                                             "Valentin va à la montagne",
                                             "Valentin prend son pantalon de ski",
                                             "Valentin prend sa coupe", "Valentin prend sa veste polaire",
                                             "Valentin va à la campagne",
                                             "Valentin prend son pantalon", "Valentin prend sa coupe",
                                             "Valentin prend sa veste légère"};
    std::vector<std::pair<int, int>> mixAnswers = {{1, 0},
                                                   {2, 1},
                                                   {3, 2},
                                                   {2, 3},
                                                   {4, 4},
                                                   {5, 5},
                                                   {3, 6},
                                                   {5, 7},
                                                   {6, 8},
                                                   {7, 9},
                                                   {3, 10},
                                                   {7, 11}};
    std::random_device rng;
    std::mt19937 urng(rng()); //Uniform Random Number Generator
    std::shuffle(mixAnswers.begin(), mixAnswers.end(), urng);

    Color c = {14, 30, 150};
    for (int i = 1; i < 13; i++) {
        l3.createNewDraggableRectangle({mixAnswers[i - 1].second + 1, mixAnswers[i - 1].first,
                                        {750, int((13 + 0.7 + (i - 1)) * mainWindow.getHeight() / 26)},
                                        c, instructions[mixAnswers[i - 1].second], 9, &mainWindow,
                                        {std::string(ASSET_DIRECTORY) + "/img/Level/L3/Dragabble_330-20.png",
                                         &mainWindow}});
    }


    l3.addButton(
            make_unique<RectButton>(make_shared<ResetLevelContent>(&l3),
                                    Point{7 * mainWindow.getWidth() / 17, 16 * mainWindow.getHeight() / 17},
                                    PictureInformer{std::string(ASSET_DIRECTORY) + "/img/Level/reset_button.png",
                                                    &mainWindow}));

    l3.addButton(
            make_unique<RectButton>(make_shared<ResetLevelAndDisplayOtherContent>(&l3, &selector1),
                                    Point{mainWindow.getWidth() / 12, 16 * mainWindow.getHeight() / 17},
                                    PictureInformer{std::string(ASSET_DIRECTORY) + "/img/Level/" + "return_button.png",
                                                    &mainWindow}));
}

struct SelectorCommands {
    std::shared_ptr<ICommand> launchLevel1;
    std::shared_ptr<ICommand> launchLevel2;
    std::shared_ptr<ICommand> launchLevel3;
    std::shared_ptr<ICommand> launchPrevPage = nullptr;
    std::shared_ptr<ICommand> launchNextPage = nullptr;
    std::shared_ptr<ICommand> backToMenu;
    std::shared_ptr<ICommand> exit;
};


void populateLevelSelector(LevelSelectorPage& selector, SelectorCommands& commands, LevelSelectorThemeFactory& theme) {
    // Level  :
    selector.addButton(theme.makeLevelButton(1, commands.launchLevel1));
    selector.addButton(theme.makeLevelButton(2, commands.launchLevel2));
    selector.addButton(theme.makeLevelButton(3, commands.launchLevel3));
    if(commands.launchPrevPage != nullptr) {
        selector.addButton(theme.makePrevPageButton(commands.launchPrevPage));
    }
    if(commands.launchNextPage != nullptr) {
        selector.addButton(theme.makeNextPageButton(commands.launchNextPage));
    }
    selector.addButton(theme.makeMenuButton(commands.backToMenu));
    selector.addButton(theme.makeQuitPageButton(commands.exit));
}


void GameApplication::build() {

    // All useful commands
    auto backToMenuCommand = std::make_shared<DisplayContentCommand>((&mainMenu));
    auto exitCommand = std::make_shared<ExitCommand>((&mainWindow));
    auto goToSelector1Command =  std::make_shared<DisplayContentCommand>(&selector1);
    auto goToSelector2Command =  std::make_shared<DisplayContentCommand>(&selector2);
    auto goToSelector3Command =  std::make_shared<DisplayContentCommand>(&selector3);
    auto goToProgressCommand = std::make_shared<DisplayContentCommand>(&progressWindowContent);


    // Progress Menu Buttons
    progressWindowContent.addButton(
            std::make_unique<RectButton>(backToMenuCommand,
                                         Point{43 * mainWindow.getWidth() / 48, 37 * mainWindow.getHeight() / 40},
                                         PictureInformer{std::string(ASSET_DIRECTORY) + "/img/Progress/menu_button.png",
                                                         &mainWindow}));

    // Level Selectors common commands
    SelectorCommands commands;
    commands.exit = exitCommand;
    commands.backToMenu = backToMenuCommand;

    // LevelSelector - Page 1
    makeLevel1();
    makeLevel2();
    makeLevel3();

    LevelSelectorThemePixel theme1(mainWindow.getWidth(), mainWindow.getHeight(), "Page1", &mainWindow);
    commands.launchPrevPage = nullptr;
    commands.launchNextPage = goToSelector2Command,
            commands.launchLevel1 = std::make_shared<DisplayContentCommand>(&l1);
    commands.launchLevel2 = std::make_shared<DisplayContentCommand>(&l2);
    commands.launchLevel3 = std::make_shared<DisplayContentCommand>(&l3);
    populateLevelSelector(selector1, commands, theme1);

    // LevelSelector - Page 2
    LevelSelectorThemePixel theme2(mainWindow.getWidth(), mainWindow.getHeight(), "Page2", &mainWindow);
    commands.launchPrevPage = goToSelector1Command,
    commands.launchNextPage = goToSelector3Command,
    commands.launchLevel1 = nullptr, //Disabled button
    commands.launchLevel2 = nullptr, // Disabled button
    commands.launchLevel3 = nullptr, // Disabled button
            populateLevelSelector(selector2, commands, theme2);


    // LevelSelector - Page 3
    LevelSelectorThemePixel theme3(mainWindow.getWidth(), mainWindow.getHeight(), "Page3", &mainWindow);
    commands.launchPrevPage = goToSelector2Command;
    commands.launchNextPage = nullptr;
    commands.launchLevel1 = nullptr, //Disabled button
    commands.launchLevel2 = nullptr, // Disabled button
    commands.launchLevel3 = nullptr, // Disabled button
    populateLevelSelector(selector3, commands, theme3);


    // Main Menu
    mainMenu.addButton(std::make_unique<RectButton>(goToSelector1Command,
                                                    Point{mainWindow.getWidth() / 2, 5 * mainWindow.getHeight() / 8},
                                                    PictureInformer{std::string(ASSET_DIRECTORY) +
                                                                    "/img/MainMenu/play_button.png", &mainWindow}));
    mainMenu.addButton(std::make_unique<RectButton>(goToProgressCommand,
                                                    Point{mainWindow.getWidth() / 2, 6 * mainWindow.getHeight() / 8},
                                                    PictureInformer{std::string(ASSET_DIRECTORY) +
                                                                    "/img/MainMenu/progress_button.png", &mainWindow}));
    mainMenu.addButton(std::make_unique<RectButton>(exitCommand,
                                                    Point{mainWindow.getWidth() / 2, 7 * mainWindow.getHeight() / 8},
                                                    PictureInformer{std::string(ASSET_DIRECTORY) +
                                                                    "/img/MainMenu/quit_button.png", &mainWindow}));


    // Launching the window
    mainWindow.setCurrentContent(&mainMenu);
}

void GameApplication::run() {
    mainWindow.mainLoop();
}
