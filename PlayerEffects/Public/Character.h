#pragma once

#include <vector>
#include "Public/Effect.h"

class Character {
protected:
    int health;
    float speed;
    std::vector<Effect> activeEffects;
public:
    Character();
    virtual ~Character();
    virtual void move() = 0;
    virtual void attack() = 0;
    virtual void defend() = 0;

};
