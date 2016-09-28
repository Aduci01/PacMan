#include <SFML/Graphics.hpp>
#include <iostream>
#include <MazeGenerator.h>
#include <Player.h>
#include <sstream>
#include <CoinManager.h>

std::string FloatToString(float d)
{
   std::stringstream ss;
   ss << d;
   std::string s = ss.str();
   std::string r = "";

   int db = 0;
   while (s[db] != '.'){
        db++;
   }
   int i = 0;
   while (i < db + 2){
        r += s[i];
        i++;
   }
   return r;
}

std::string IntToString(int d)
{
   std::stringstream ss;
   ss << d;
   std::string s = ss.str();
   return s;
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 720), "Pac-Man");
    MazeGenerator mazeGenerator(25,19,window);
    CoinManager coinManager(25,19);

    Player player(mazeGenerator);

    sf::Clock clock;
    sf::Time dt;
    sf::Time time;

    sf::Text displayTime, displayCoin, menuText;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
    //"Font error"
    }


    menuText.setFont(font);
    menuText.setCharacterSize(40);

    enum State {Menu, Game, Score};
    State state = Menu;


    int frameC = 0;

    int score = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                player.SetDir(4);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                player.SetDir(3);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                player.SetDir(1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                player.SetDir(2);
            }
            /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                player.SetDir(0);
            }*/
           /* if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                std::cout<<sf::Mouse::getPosition(window).x<<std::endl;
                std::cout<<sf::Mouse::getPosition(window).y<<std::endl;

            }
*/

        }
        window.clear();

        //GAMESTATE
        if (state == Game){

        frameC++;
        dt = clock.getElapsedTime();
        time += clock.getElapsedTime();
        clock.restart();
        if (frameC > 10){
        frameC = 0;
        displayTime.setString("Time: " + FloatToString(time.asSeconds()));
        }
        displayCoin.setString("Coins: " + IntToString(score));
        window.draw(displayCoin);
        window.draw(displayTime);
        player.MovePlayer(dt);
        if (mazeGenerator.CollectCoin(player.GetMX(), player.GetMY())){
            score++;
        }
        mazeGenerator.DrawMaze(window);
        player.DrawPlayer(window);

        if (player.GetWin()){
            state = Score;
        }
        }
        //GAMESTATE END



        //MENUSTATE
        if (state == Menu){
            menuText.setString("Play");
            menuText.setPosition(1024/2 - 40, 768/2 - 80);
            window.draw(menuText);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x > 1024 / 2 - 40 && sf::Mouse::getPosition(window).x < 1024 / 2 + 50 &&
                sf::Mouse::getPosition(window).y > 768 / 2 - 80 && sf::Mouse::getPosition(window).y < 768 / 2){
                state = Game;
                mazeGenerator.Generate();
                mazeGenerator.DrawConsole();
                player.SetMaze(mazeGenerator);
                player.SetBasic();

                score = 0;
                time = time.Zero;

                displayTime.setFont(font);
                displayTime.setCharacterSize(20);
                displayTime.setColor(sf::Color::White);
                displayTime.setPosition(300, 20);

                displayCoin.setFont(font);
                displayCoin.setCharacterSize(20);
                displayCoin.setColor(sf::Color::White);
                displayCoin.setPosition(100, 20);

                clock.restart();
            }
        }

        //SCORESTATE
        if (state == Score){
            displayTime.setString("Your score: " + IntToString(score * 5 - (int)(time.asSeconds() * 2)));
            displayTime.setPosition(1024/2 - 80, 768/2 - 80);

            displayCoin.setString("Press Space to return to the Main menu or ESC to exit the game");
            displayCoin.setPosition(1024/2 - 280, 768/2 - 200);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) state = Menu;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

            window.draw(displayCoin);
            window.draw(displayTime);
        }


        window.display();
    }
}
