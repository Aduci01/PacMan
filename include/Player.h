#include <vector>
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <MazeGenerator.h>

#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(MazeGenerator);
        void SetMaze(MazeGenerator);
        void DrawPlayer(sf::RenderWindow&);
        void MovePlayer(sf::Time);
        void SetDir(int);
        void GetMazePlace();
        void CheckWin();
        virtual ~Player();
        int GetMX();
        int GetMY();
        bool GetWin();
        void SetWin(bool);
        void SetBasic();

        int moveDir = 0; // stand = 0, up = 1, down = 2, right = 3, left = 4 //
    protected:
    private:
        std::vector<bool> maze;
        bool win = false;
        float speed = 120;
        int sizeX, sizeY;
        float posX = 124, posY = 90;
        int mX = 2, mY = 2;
};

#endif // PLAYER_H
