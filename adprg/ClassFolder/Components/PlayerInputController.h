#pragma once
#include "GenericInputController.h"
class PlayerInputController :
    public GenericInputController
{
public:
    PlayerInputController(std::string name);
    ~PlayerInputController();

    void perform() override;

    void isUp();
    void isDown();
    void isLeft();
    void isRight();
    

private:
    const float SPEED_MULT = 300.0f;
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
};

