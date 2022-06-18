#pragma once
#include "AComponent.h"
class PlayerMovement :
    public AComponent
{
public:

    PlayerMovement(std::string name);
    ~PlayerMovement();

    void perform() override;

private:
    float ticks = 0;
    float bulletSpawnInterval = 0.3f;


};

