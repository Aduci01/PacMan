#include "Player.h"

Player::Player(MazeGenerator mg){
    maze = mg.getMaze();
    sizeX = mg.GetSizeX();
    sizeY = mg.GetSizeY();
}


Player::~Player()
{
    //dtor
}

void Player::DrawPlayer(sf::RenderWindow& window){
    sf::CircleShape a;
    a.setRadius(12);
    a.setPosition(posX, posY);
    window.draw(a);
}

void Player::SetDir(int d){
    moveDir = d;
}

void Player::MovePlayer(sf::Time dt){

    if (!win){
    switch (moveDir){
        case 1: if(maze[(int)((posY - 60 - 35) / 30 + 1) * sizeX + mX]) {
            posY -= speed * dt.asSeconds();
            posX = mX * 30 + 60 + 4;
        }
        break;
        case 2: if(maze[(int)((posY - 60 - 4) / 30 + 1) * sizeX + mX]){
             posY += speed * dt.asSeconds();
             posX = mX * 30 + 60 + 4;
        }
        break;
        case 3: if (maze[(mY-1) * sizeX + (int) (posX - 90 + 26) / 30 + 1]){
             posX += speed * dt.asSeconds();
             posY = mY * 30 + 30 + 4;
        }
        break;
        case 4: if (maze[(mY-1) * sizeX + (int) (posX - 90 - 5) / 30 + 1]){
             posX -= speed * dt.asSeconds();
             posY = mY * 30 + 30 + 4;

        }
        break;
    }
    GetMazePlace();
    CheckWin();
    }
}

void Player::GetMazePlace(){
    mY = (posY - 60) / 30 + 1;
    mX = (posX - 90) / 30 + 1;
    /*std::cout<<mX<<std::endl;
    std::cout<<mY<<std::endl;*/
}

void Player::CheckWin(){
    if (mY == sizeY)
        win = true;
}

int Player::GetMX(){
    return mX;
}

int Player::GetMY(){
    return mY;
}

bool Player::GetWin(){
    return win;
}

void Player::SetWin(bool b){
    win = b;
}

void Player::SetMaze(MazeGenerator mg){
    maze = mg.getMaze();
    sizeX = mg.GetSizeX();
    sizeY = mg.GetSizeY();
}

void Player::SetBasic(){
        win = false;
        speed = 120;
        posX = 124; posY = 90;
        mX = 2; mY = 2;
        moveDir = 0;
}
