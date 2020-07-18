#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    /* data */
    int trays[7];
    bool npc;
public:
    Player(/* args */);
    ~Player();
    void addToTray(const int index, const int value);
    const int getTray(const int index) const;
    const int pickFromTray(const int index);
};

#endif //PLAYER_H