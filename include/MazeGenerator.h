#include <vector>
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <Coin.h>

#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H


class MazeGenerator
{
    public:
        MazeGenerator(int,int,sf::RenderWindow&);
        void DrawConsole();
        void Init();
        void Generate();
        void DoPath(int,int);
        void DrawMaze(sf::RenderWindow&);
        std::vector<bool> getMaze();
        int GetSizeX();
        int GetSizeY();
        bool CollectCoin(int,int);
    protected:
    private:
        std::vector<bool> maze;
        std::vector<sf::RectangleShape> walls;
        unsigned int sizeX;
        unsigned int sizeY;
        float height;
        std::vector<Coin> coins;
};

#endif // MAZEGENERATOR_H
