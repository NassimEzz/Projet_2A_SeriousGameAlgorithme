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
 * @file SDLWindowImp.h
 *
 *
 */

#ifndef SDLWINDOWIMP_H
#define SDLWINDOWIMP_H


#include "IWindowImp.h"
#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include <map>
#include <fstream>
#include <SDL_ttf.h>

struct SDLTextureWithSize {
    SDL_Texture *_texture;
    int w;
    int h;


    bool draw(SDL_Renderer *renderer, int x, int y) const {
        if (_texture == nullptr) {
            return false;
        }
        SDL_Rect p;
        p.x = x;
        p.y = y;
        p.w = w;
        p.h = h;
        SDL_RenderCopy(renderer, _texture, nullptr, &p);
        return true;
  }
}; 

class SDLWindowImp : public IWindowImp {
public :
    SDLWindowImp(const string &window_name, unsigned int sizeX, unsigned
    sizeY);

    void setTitle(const string &windowTitle) override;

    void drawPNG(int x, int y, const std::string &pictureName) override;

    void drawPNGWithBoundChecking(Rectangle &rect, const std::string &pictureName) override;

    void addWindowIcon(const string &iconPath) override;

    Event getEvent() override;

    int getHeightOfAnEmptyLine(const string &text, TTF_Font *font);

    void writePixelText(const string &text, int size, unsigned int x, unsigned int y, const Color &color,
                        unsigned int length) override;

    void writePixelText(ifstream &file, int size, unsigned int x, unsigned int y, const Color &color,
                        unsigned int length) override;

    void clearScreen() override;

    void updateScreen() override;

    int getWidth() override;

    int getHeight() override;

    virtual void wait(unsigned int ms) override;

    void close() override;

    unsigned int getPictureHeight(const string &path) override;

    unsigned int getPictureWidth(const string &path) override;

    ~SDLWindowImp() override;

private:
    SDL_Window *_actualWindow;
    SDL_Renderer *_renderer;
    SDL_Surface *_surface;
    SDL_Texture *_texture;
    std::unordered_map<string, SDLTextureWithSize> _cacheTextureMemory;
    std::map<pair<std::string, int>, TTF_Font *> _cacheFontMemory;

    TTF_Font *getFont(int size, const string &pathToFont);

    SDLTextureWithSize getPictureTexture(const string &pictureName);

    SDLTextureWithSize getTextAsTexture(const string &text, TTF_Font *font, SDL_Color &color, unsigned int length);

    SDLTextureWithSize loadTexture(const string &pictureName) const;
};
#endif //SDLWINDOWIMP_H
