#include <iostream>
#include <unistd.h>

#include "Game.h"

using std::cout;
using std::cin;
using std::endl;

Game::Game(/* args */)
{
}

Game::~Game()
{
}

void Game::loop() {
    while (!quit)
    {
        display();
        cout << "Turn player " << turn << endl;

        int trayNumber;
        cout << "Add the number of tray (1-6)" << endl;

        do {
            cin >> trayNumber;

            if (trayNumber < 1 || trayNumber > 6)
                cout << "Wrong number of tray" << endl;
            else if (players[0].getTray(trayNumber) == 0)
                cout << "This tray is empty" << endl;
        }
        while (trayNumber < 1 || trayNumber > 6 || players[0].getTray(trayNumber-1) == 0);

        step(trayNumber-1);

        if (isEnd()) {
            if (players[0].getTray(6) > players[1].getTray(6))
                cout << "Player 1 wins" << endl;
            else if (players[0].getTray(6) < players[1].getTray(6))
                cout << "Player 2 wins" << endl;
            else
                cout << "Draw game" << endl;
            sleep(5);
            quit = true;
        }
        
    }
    
}

void Game::step(const int trayIndex) {
    int stepRemaining = players[turn].pickFromTray(trayIndex);
    int trayArea = turn;
    int currentTray = trayIndex;

    while (stepRemaining > 0)
    {
        currentTray++;
        if (currentTray == 7) {
            trayArea == 0 ? trayArea = 1 : trayArea = 0;
            currentTray = 0;
        }

        players[trayArea].addToTray(currentTray, 1);
        stepRemaining--;

    }

    if (currentTray < 6 && players[trayArea].getTray(currentTray) == 1) {
        players[turn].addToTray(6, players[trayArea].pickFromTray(currentTray));
        int enemy = trayArea == (0 ? 1 : 0);
        players[turn].addToTray(6, players[enemy].pickFromTray(5 - currentTray));
    }
    
    if (currentTray != 6 && trayArea != turn) {
        turn == 0 ? turn = 1 : turn = 0;
    }
    else {
        cout << "Turn again" << endl;
    }
    
}

void Game::display() {
    cout << "|" << players[1].getTray(6) << "| ";
    for (int i = 5; i >= 0; i--)
        cout << players[1].getTray(i) << " ";
    cout << endl;

    for (int i = 0; i < 6; i++)
        cout << players[0].getTray(i) << " ";
    cout << "|" << players[0].getTray(6) << "| ";
    cout << endl;

}

bool Game::isEnd() {
    for (int i = 0; i < 6; i++)
        if (players[turn].getTray(i) > 0)
            return false;
    return true;
}