#pragma once
#include "AGameObject.h"
class AirplanePlayer :
    public AGameObject
{
public:

    AirplanePlayer(std::string name);
    void initialize() override;
    //void processInput(sf::Event event) override;
    //void update(sf::Time deltaTime) override;

private:
    const float SPEED_MULT = 300.0f;
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
};

