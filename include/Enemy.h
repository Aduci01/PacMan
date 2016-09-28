#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy();
        void DrawObject(sf::RenderWindow&);
        void MoveObject(sf::Time);
        void SetDir(int);
        void GetMazePlace();
        virtual ~Enemy();
    protected:
    private:
        std::vector<bool> maze;
        bool win = false;
        int sizeX, sizeY;
        int moveDir = 0; // stand = 0, up = 1, down = 2, right = 3, left = 4 //
        float posX, posY;
        int mX, mY;
};

#endif // ENEMY_H
