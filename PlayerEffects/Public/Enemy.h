#pragma once
#include "Public/Character.h"

class Enemy : public Character {
public:
    Enemy();
    ~Enemy();
    void move() override;
    void attack() override;
    void defend() override;
    void runAi();
};
