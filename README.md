# Serious Game on Algorithmic Principles

## Description

This C++ game consists in teaching algorithmic principles (loops, instructions, etc.) to children. 

This project was made during our second year in Computer Sciences at ENSICAEN and was tutored by Loïc Simon.

The game is divided in themes, each theme composed of three levels. For now, only the first theme "home" is available. The three developed levels are linked with the everyday life of an elementary school / young middle school child. The artwork of the game have been designed in pixelart.

## Gameplay

This game has a classic interface, starting with a main menu leading to a level selector and an achievements screen. 
Each level is composed of a rule screen explaining the goal and context in which the player will evolve. 

During the level, the only mechanic consists in a left click drag and drop (the instructions must be placed in the receivers in the right order to complete the level). When every instructions are placed, if the order is false the player will see red looking receivers, otherwise a correct or perfect screen appears.

The progress can be accessed at any time in the achievements screen and remains as it is while the game is closed.   

Here a quick display of the game :

![Demonstration of the game](./assets/demo/gameDemo.mp4)

## Requirements

- cmake
- SDL2.0-image
- SDL2.0-TTF
- SDL2.0

## Installation

### Build it with emscripten :

- Download emscripten (`brew install emscripten` under MacOs or from the [official website](https://emscripten.org) )

```shell
mkdir htmlBuild
cd htmlBuild
emcmake make ..
emmake make -j4
```

- Run it with ; `emrun AurelieEtValentin.html`

### Build it with cmake :

````shell
mkdir build
cd build
cmake ..
make -j4
````

- Run it with : `./AurelieEtValentin`

## Uninstallation 
Just remove the build folders : 
```shell
rm -rf build
rm -rf htmlBuild
```

# Web Game 
The game is also available here : [http://www.ecole.ensicaen.fr/~zaidi/aurelie_valentin_web_app/AurelieEtValentin.html](http://www.ecole.ensicaen.fr/~zaidi/aurelie_valentin_web_app/AurelieEtValentin.html)

## Authors

[p2a\_info\_seriousgamealgo@ensicaen.fr](mailto:p2a\_info\_seriousgamealgo@ensicaen.fr)

- Nassim EZZAYANI
- Navid KAVIAN
- Landry MARQUIS
- Julien ZAÏDI

# License
The code is published under the MIT License (MIT)

Copyright (c) 2021 Landry MARQUIS, Navid KAVIAN, Julien ZAÏDI and Nassim EZZAYANI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
