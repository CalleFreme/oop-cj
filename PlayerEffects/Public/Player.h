#pragma once
#include "Public/Character.h"

class Player : public Character {
public:
    Player();
    ~Player();
    void move() override;
    void attack() override;
    void defend() override;

};
