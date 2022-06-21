#include "PlayerInputController.h"

#include <iostream>

PlayerInputController::PlayerInputController(std::string name): GenericInputController(name)
{
}

PlayerInputController::~PlayerInputController()
{
}

void PlayerInputController::perform()
{

	bool keyFlag = false;
	if (event.type == sf::Event::KeyPressed)
	{
		keyFlag = true;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		keyFlag = false;
	}

	sf::Keyboard::Key key = event.key.code;
	if (key == (sf::Keyboard::W))
	{
		this->moveUp = keyFlag;
		this->moving = keyFlag;
	}
	if (key == (sf::Keyboard::A))
	{
		this->moveRight = keyFlag;
		this->moving = keyFlag;

		std::cout << "a" << std::endl;
	}
	if (key == (sf::Keyboard::S))
	{
		this->moveDown = keyFlag;
		this->moving = keyFlag;

		std::cout << "s" << std::endl;
	}
	if (key == (sf::Keyboard::D))
	{
		this->moveLeft = keyFlag;
		this->moving = keyFlag;

		std::cout << "d" << std::endl;
	}
}

bool PlayerInputController::isUp()
{
	return this->moveUp;
}

bool PlayerInputController::isDown()
{
	return this->moveDown;
}

bool PlayerInputController::isLeft()
{
	return this->moveLeft;
}

bool PlayerInputController::isRight()
{
	return this->moveRight;
}

bool PlayerInputController::isMoving()
{
	return this->moving;
}