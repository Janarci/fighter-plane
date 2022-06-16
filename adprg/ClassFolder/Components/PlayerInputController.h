#pragma once
#include "GenericInputController.h"
class PlayerInputController :
    public GenericInputController
{
public:
    PlayerInputController(std::string name);
    ~PlayerInputController();
    void perform() override;
    const float SPEED_MULT = 300.0f;

    bool isUp();
    bool isDown();
    bool isLeft();
    bool isRight();
    bool isMoving();;
    

private:
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool moving = false;
};

