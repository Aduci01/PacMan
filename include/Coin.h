
#include <vector>
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#ifndef COIN_H
#define COIN_H


class Coin
{
    public:
        Coin(int, int);
        void Render(sf::RenderWindow&);
        int GetPosX();
        int GetPosY();
        ~Coin();
    protected:
    private:
        int posX, posY;
};

#endif // COIN_H
