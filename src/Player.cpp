#include "Player.h"

Player::Player(/* args */)
{
    for (int i=0; i<6; i++)
        trays[i] = 6;
    trays[6] = 0;
}

Player::~Player()
{
}

void Player::addToTray(const int index, const int value) {
    trays[index] += value;
}
    
const int Player::getTray(const int index) const {
    return trays[index];
}

const int Player::pickFromTray(const int index) {
    const int ret = trays[index];
    trays[index] = 0;
    return  ret;
}