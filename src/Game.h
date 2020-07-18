#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
private:
    Player players[2];
    bool quit = false;
    int turn = 0;
public:
    Game(/* args */);
    ~Game();
    void step(const int trayIndex);
    void loop();
    void display();
    bool isEnd();
};

#endif //GAME_H