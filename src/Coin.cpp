#include "Coin.h"

Coin::Coin(int x, int y)
{
    posX = x; posY = y;
}

Coin::~Coin()
{
    //dtor
}


void Coin::Render(sf::RenderWindow& window){
    sf::CircleShape a;
    a.setRadius(4);
    a.setFillColor(sf::Color::Yellow);
    a.setPosition(posX, posY);
    window.draw(a);
}

int Coin::GetPosX(){
    return posX;
}

int Coin::GetPosY(){
    return posY;
}
