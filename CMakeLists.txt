cmake_minimum_required(VERSION 3.10)
project(P2A_Serious_Game)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
add_definitions(-Wall -Wextra -pedantic)

if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    add_definitions(-DASSET_DIRECTORY=\"\")
    set(USE_FLAGS "-s ASYNCIFY=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' --use-preload-plugins -s ALLOW_MEMORY_GROWTH=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS} --emrun --preload-file ${PROJECT_SOURCE_DIR}/assets@/")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
else()
    add_definitions(-DASSET_DIRECTORY=\"${PROJECT_SOURCE_DIR}/assets\")
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED >=2.0.0)
    find_package(SDL2_TTF REQUIRED >= 2.0.0)
    include_directories(${SDL2_INCLUDE_DIR})
    include_directories(${SDL2_IMAGE_INCLUDE_DIR})
endif()
include_directories(include)
add_executable(AurelieEtValentin
        src/main.cpp
        src/Platform.cpp include/Platform.h
        src/GameApplication.cpp include/GameApplication.h
        src/Window.cpp include/Window.h
        src/IWindowImp.cpp include/IWindowImp.h
        src/SDLWindowImp.cpp include/SDLWindowImp.h
        src/EMSWindowImp.cpp include/EMSWindowImp.h
        src/WindowContent.cpp include/WindowContent.h
        src/LevelSelectorPage.cpp include/LevelSelectorPage.h
        src/Level.cpp include/Level.h
        src/Button.cpp include/Button.h
        src/RectButton.cpp include/RectButton.h
        src/ICommand.cpp include/ICommand.h
        src/DisplayContentCommand.cpp include/DisplayContentCommand.h
        src/Event.cpp include/Event.h
        src/LevelSelectorThemeFactory.cpp include/LevelSelectorThemeFactory.h
        src/LevelSelectorThemePixel.cpp include/LevelSelectorThemePixel.h
        src/MainMenu.cpp include/MainMenu.h
        src/ExitCommand.cpp include/ExitCommand.h
        src/DraggableRectangle.cpp include/DraggableRectangle.h
        src/ResetLevelAndDisplayOtherContent.cpp include/ResetLevelAndDisplayOtherContent.h
        src/ResetLevelContent.cpp include/ResetLevelContent.h
        src/Receiver.cpp include/Receiver.h
        src/LevelRuler.cpp include/LevelRuler.h
        src/GameLogic.cpp include/GameLogic.h
        src/WinningScreen.cpp include/WinningScreen.h
        src/ProgressWindowContent.cpp include/ProgressWindowContent.h
        src/PictureInformer.cpp include/PictureInformer.h
        src/ProgressModel.cpp include/ProgressModel.h
        include/Utils.h
        )
if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
else()
    target_link_libraries(AurelieEtValentin ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
endif()
