#pragma once
#include "GenericInputController.h"
class PlayerInputController :
    public GenericInputController
{
public:
    PlayerInputController(std::string name);
    ~PlayerInputController();
    const float SPEED_MULT = 300.0f;
    void perform() override;

    bool isUp();
    bool isDown();
    bool isLeft();
    bool isRight();
    bool isMoving();


private:
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool moving = false;
};

