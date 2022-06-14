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
	if(event.type == sf::Event::KeyPressed)
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
		//std::cout << "w" << std::endl;
	}
	if (key == (sf::Keyboard::A))
	{
		//std::cout << "a" << std::endl;
	}
	if (key == (sf::Keyboard::S))
	{
		//std::cout << "s" << std::endl;
	}
	if (key == (sf::Keyboard::D))
	{
		//std::cout << "d" << std::endl;
	}
}

void PlayerInputController::isUp()
{
}

void PlayerInputController::isDown()
{
}

void PlayerInputController::isLeft()
{
}

void PlayerInputController::isRight()
{
}
