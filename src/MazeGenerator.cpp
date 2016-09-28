#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(int x, int y, sf::RenderWindow& b){
    sizeX = x; sizeY = y;
    maze.resize(sizeX*sizeY);
    height = b.getSize().x;
    srand (time(NULL));
}

void MazeGenerator::DrawConsole(){
    for (int i = 0; i < sizeY; i++){
        for (int j = 0; j < sizeX; j++){
            if (maze[i * sizeX + j])
                std::cout << "1 ";
        else std::cout << "0 ";
        }
        std::cout << std::endl;
    }
}

void MazeGenerator::Init(){
    std::fill(maze.begin(), maze.end(), false);

    //making boundaries
    for (int i = 0; i < sizeX; i++){
        maze[i] = true;
        maze[sizeX * (sizeY - 1) + i] = true;
    }

    for (int i = 0; i < sizeY; i++){
        maze[i * sizeX] = true;
        maze[i * (sizeX) + sizeX - 1] = true;
    }
}

void MazeGenerator::Generate(){
    maze.clear();
    walls.clear();
    maze.resize(sizeX*sizeY);
    Init();
    DoPath(2, 2);
    maze[sizeX + 2] = true;
    maze[(sizeY - 2) * sizeX + sizeX - 3] = true;
    maze[2] = false;
    maze[1] = false;

   /* for (int i = 0; i < sizeX; i++){
        maze[i] = false;
        maze[sizeX * (sizeY - 1) + i] = false;
    }

    for (int i = 0; i < sizeY; i++){
        maze[i * sizeX] = false;
        maze[i * (sizeX) + sizeX - 1] = false;
    }*/

    //Horizontal
    int offset = 60;
    for (int i = 1; i < sizeY; i++){
        for (int j = 1; j < sizeX; j++) {
            if (!maze[i * sizeX + j] && maze[(i+1) * sizeX + j] ){
                sf::RectangleShape a(sf::Vector2f(30 , 3));
                a.setPosition(j * 30 + offset, i * 30 + 30 + offset);
                walls.push_back(a);
            }

            if (!maze[i * sizeX + j] && maze[(i-1) * sizeX + j] ){
                sf::RectangleShape a(sf::Vector2f(30, 3));
                a.setPosition(j * 30 + offset, i * 30 + offset);
                walls.push_back(a);
            }


        }
    }


    // Vertical
    for (int i = 1; i < sizeX; i++){
        for (int j = 1; j < sizeY; j++) {
            if (!maze[j * sizeX + i] && maze[j*sizeX + i + 1]){
                sf::RectangleShape a(sf::Vector2f(30, 3));
                a.setPosition(i * 30 + 30 + offset, j * 30 + 30 + offset);
                a.rotate(270);
                walls.push_back(a);
            }

            if (!maze[j * sizeX + i] && maze[j*sizeX + i - 1]){
                sf::RectangleShape a(sf::Vector2f(30, 3));
                a.setPosition(i * 30 + offset, j * 30 + 30 + offset);
                a.rotate(270);
                walls.push_back(a);
            }
        }
    }
    sf::RectangleShape a(sf::Vector2f(60, 3));
    a.setPosition(90,90);
    walls.push_back(a);

}

void MazeGenerator::DoPath(int x, int y){
    maze[y * sizeX + x] = true;

    Coin coin(x * 30 + 60 + 13, y * 30 + 60 + 13);
    coins.push_back(coin);
    std::cout<<coin.GetPosX()<<"  "<<coin.GetPosY()<<std::endl;

    int r = rand();
    int dir[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++){
        int dx = dir[(i + r) % 4];
        int dy = dir[(i + r + 2) % 4];

        int x1 = x + dx;
        int y1 = y + dy;
        int x2 = x1 + dx;
        int y2 = y1 + dy;

        if (!maze[y1 * sizeX + x1] && !maze[y2 * sizeX + x2]){
            maze[y1 * sizeX + x1] = true;
            DoPath(x2, y2);
        }
    }
}

void MazeGenerator::DrawMaze(sf::RenderWindow& window){
    for (int i = 0; i < walls.size(); i++)
        window.draw(walls[i]);

    for (int i = 0; i < coins.size(); i++)
        coins[i].Render(window);
}

std::vector<bool> MazeGenerator::getMaze(){
    return maze;
}

int MazeGenerator::GetSizeX(){
    return sizeX;
}

int MazeGenerator::GetSizeY(){
    return sizeY;
}

bool MazeGenerator::CollectCoin(int x, int y){
    for (int i = 0; i < coins.size(); i++){
        if (x == (coins[i].GetPosX() - 90) / 30 + 1 && y == (coins[i].GetPosY() - 60) / 30 + 1){
            coins.erase(coins.begin()+i);
            //std::cout<<coins[i].GetPosX()<<"  "<<coins[i].GetPosY()<<std::endl;
            return true;
            //std::cout<<x<<"  "<<y<<std::endl;
        }
    }
    return false;
}


