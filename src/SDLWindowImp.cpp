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
 * @file SDLWindowImp.cpp
 *
 *
 */

#include "SDLWindowImp.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <sstream>

SDLWindowImp::SDLWindowImp(const string &windowName, unsigned int sizeX, unsigned int sizeY) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    _actualWindow = SDL_CreateWindow(windowName.c_str(),
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     (int) sizeX, (int) sizeY, 0);
    if (_actualWindow == nullptr) {
        std::cout << "SDLWindowImp::SDLWindowImp() :" << SDL_GetError()
                  << std::endl;
    }
    _renderer = SDL_CreateRenderer(_actualWindow, -1, SDL_RENDERER_SOFTWARE);
    _surface = SDL_GetWindowSurface(_actualWindow);
    _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
    SDL_SetRenderTarget(_renderer,_texture);
}

SDLWindowImp::~SDLWindowImp() {
    SDL_DestroyTexture(_texture);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_actualWindow);
    for (auto p : _cacheTextureMemory) {
        SDL_DestroyTexture(p.second._texture);
    }

    for (auto p : _cacheFontMemory) {
        TTF_CloseFont(p.second);
    }
    TTF_Quit();
}

void SDLWindowImp::setTitle(const std::string &windowTitle) {
    SDL_SetWindowTitle(_actualWindow, windowTitle.c_str());
}


SDLTextureWithSize SDLWindowImp::getPictureTexture(const string &pictureName) {
    SDLTextureWithSize textureToClip = {};
    auto pairPathAndTexture = _cacheTextureMemory.find(pictureName);
    if (pairPathAndTexture != _cacheTextureMemory.end()) {
        textureToClip = pairPathAndTexture->second;
    } else {
        textureToClip = loadTexture(pictureName);
        if (textureToClip._texture != nullptr) {
            _cacheTextureMemory.emplace(pictureName, textureToClip);
        }
    }
    return textureToClip;
}


SDLTextureWithSize SDLWindowImp::loadTexture(const string &pictureName) const {
    SDL_Surface *surface = IMG_Load(pictureName.c_str());
    if (surface == nullptr) {
        cout << "SDLWindowImp::loadTexture() :" << SDL_GetError()
             << endl;
        return {nullptr, 0, 0};
    }
    SDL_Texture *texture =  SDL_CreateTextureFromSurface( _renderer, surface ); ;
    if (texture == nullptr) {
        cout << "SDLWindowImp::loadTexture() :" << SDL_GetError()
             << endl;
        return {nullptr, 0, 0};
    }
    return {texture, surface->w, surface->h};
}


void SDLWindowImp::drawPNG(int x, int y, const std::string &pictureName) {

    SDLTextureWithSize texture = getPictureTexture(pictureName);
    texture.draw(_renderer, x, y);
}

void SDLWindowImp::drawPNGWithBoundChecking(Rectangle &rect, const std::string &pictureName) {
    SDLTextureWithSize texture = getPictureTexture(pictureName);
    unsigned int width = getWidth();
    unsigned int height = getHeight();
    if (rect.x < 0) {
        rect.x = 0;
    }
    if (rect.y < 0) {
        rect.y = 0;
    }
    if (rect.x + rect.width > width) {
        rect.x = (int) (width - rect.width);
    }
    if (rect.y + rect.height > height) {
        rect.y = (int) (height - rect.height);
    }
    texture.draw(_renderer, rect.x, rect.y);
}

void SDLWindowImp::clearScreen() {
    SDL_RenderClear(_renderer);
}

void SDLWindowImp::updateScreen() {
    SDL_RenderPresent(_renderer);
}

Event SDLWindowImp::getEvent() {
    SDL_Event e;
    Event result{EventType::UNKNOWN};
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_MOUSEBUTTONDOWN :
                return  {EventType::MOUSEDOWN, (unsigned int) e.button.x,
                        (unsigned int) e.button.y};
            case SDL_MOUSEBUTTONUP :
                return {EventType::MOUSEUP, (unsigned int) e.button.x, (unsigned int) e.button.y};
            case SDL_QUIT :
                return {EventType::QUIT};
            case SDL_KEYDOWN :
                return {EventType::KEYDOWN};
            case SDL_MOUSEMOTION :
                result =  {EventType::MOUSEMOTION, (unsigned int) e.motion.x, (unsigned int) e.motion.y};
                break;
        }
    }
    return result;
}


void SDLWindowImp::addWindowIcon(const string &iconPath) {
    SDL_Surface *img = IMG_Load(iconPath.c_str());
    SDL_SetWindowIcon(_actualWindow, img);
}

void SDLWindowImp::close() {
    SDL_Quit();
}

TTF_Font *SDLWindowImp::getFont(int size, const string &pathToFont) {
    TTF_Font *font;
    auto pairPathAndFont = _cacheFontMemory.find(make_pair(pathToFont, size));
    if (pairPathAndFont != _cacheFontMemory.end()) {
        font = pairPathAndFont->second;
    } else {
        font = TTF_OpenFont(pathToFont.c_str(), size);
        if (font == nullptr) {
            cout << "SDLWindowImp::writePixelText() :" << SDL_GetError()
                 << endl;
        } else {
            _cacheFontMemory.emplace(make_pair(pathToFont, size), font);
        }
    }
    return font;
}


SDLTextureWithSize SDLWindowImp::getTextAsTexture(const string &text, TTF_Font *font, SDL_Color &color, unsigned int length) {
    SDLTextureWithSize texture = {};
    auto pairPathAndSurface = _cacheTextureMemory.find(text);
    if (pairPathAndSurface != _cacheTextureMemory.end()) {
        texture = pairPathAndSurface->second;
    } else {
        SDL_Surface* surface = TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), color, length);
        if (surface == nullptr) {
            std::cout << "SDLWindowImp::writePixelText() :" << SDL_GetError()
                      << std::endl;
        } else {
            texture._texture = SDL_CreateTextureFromSurface(_renderer, surface);
            texture.w = surface->w;
            texture.h = surface->h;
            if (texture._texture == nullptr) {
                std::cout << "SDLWindowImp::writePixelText() :" << SDL_GetError()
                          << std::endl;
            }
            else {
                _cacheTextureMemory.emplace(text, texture);
            }
        }
    }
    return texture;
}

int SDLWindowImp::getHeightOfAnEmptyLine(const string &text, TTF_Font *font) {
    SDL_Color colorSDL = {1, 1, 1, 1};
    SDLTextureWithSize texture = getTextAsTexture(text, font, colorSDL, 10);
    if (texture._texture == nullptr) {
        return 10;
    }
    return texture.h;
}


void SDLWindowImp::writePixelText(const string &text, int size, unsigned int x, unsigned int y, const Color &color,
                                  unsigned int length) {
    TTF_Font *font;
    SDL_Color colorSDL;

    colorSDL.r = color.r;
    colorSDL.g = color.g;
    colorSDL.b = color.b;
    colorSDL.a = 255;

    font = getFont(size, string(ASSET_DIRECTORY) + "/font/utf-font/utf-font.ttf");
    if (font == nullptr) {
        return;
    }

    std::istringstream streamToWrite(text);
    string line;
    while (std::getline(streamToWrite, line, '\n')) {
        if (line.empty() || line == "\n") {
            y += getHeightOfAnEmptyLine("T", font);
        } else {
            SDLTextureWithSize  texture = getTextAsTexture(line, font, colorSDL, length - x);
            if (texture.draw(_renderer, int(x), int(y))) {
                y += texture.h;
            } else { cout << "problem: " << line << endl; }
        }
    }
}

void SDLWindowImp::writePixelText(ifstream &file, int size, unsigned int x, unsigned int y, const Color &color,
                                  unsigned int length) {
    if (!file.good()) {
        std::cout << "SDLWindowImp::writePixelText() : can't open file" << std::endl;
    } else {
        std::streamoff posInFileAtBeginning = file.tellg();
        string line;
        string textToWrite;
        while (getline(file, line)) {
            if (line == "\n") {
                textToWrite += " \n";
            } else {
                textToWrite += line + '\n';
            }
        }
        writePixelText(textToWrite, size, x, y, color, length - x);

        file.clear();
        file.seekg(posInFileAtBeginning, std::ios_base::beg);
    }
}

int SDLWindowImp::getWidth() {
    int h;
    int w;
    SDL_GetWindowSize(_actualWindow, &w, &h);
    return w;
}

int SDLWindowImp::getHeight() {
    int h;
    int w;
    SDL_GetWindowSize(_actualWindow, &w, &h);
    return h;
}

unsigned int SDLWindowImp::getPictureHeight(const string &path) {
    SDLTextureWithSize temp = getPictureTexture(path);
    if (temp._texture != nullptr) {
        return temp.h;
    }
    return -1;
}

unsigned int SDLWindowImp::getPictureWidth(const string &path) {
    SDLTextureWithSize temp = getPictureTexture(path);
    if (temp._texture != nullptr) {
        return temp.w;
    }
    return -1;
}

void SDLWindowImp::wait(unsigned int ms) {
    SDL_Delay(ms);
}


