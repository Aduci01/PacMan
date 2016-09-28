#include <vector>
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <MazeGenerator.h>
#include <Coin.h>

#ifndef COINMANAGER_H
#define COINMANAGER_H


class CoinManager
{
    public:
        CoinManager(int,int);
        ~CoinManager();
    protected:
    private:
        std::vector<Coin> coins;
        int row, column;
};

#endif // COINMANAGER_H
