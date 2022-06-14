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



};

