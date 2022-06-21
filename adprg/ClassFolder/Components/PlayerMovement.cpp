#include "PlayerMovement.h"

#include <iostream>

#include "PlayerInputController.h"
#include "../AirplanePlayer.h"


PlayerMovement::PlayerMovement(std::string name) : AComponent(name, Script)
{
}

PlayerMovement::~PlayerMovement()
{
}

void PlayerMovement::perform()
{
	AirplanePlayer* airplanePlayer = (AirplanePlayer*)this->getOwner();
	PlayerInputController* inputController = (PlayerInputController*)(airplanePlayer->getComponentsOfType(ComponentType::Input)[0]);

	sf::Transformable* playerTransformable = this->getOwner()->getTransformable();
	if (playerTransformable == NULL || inputController == NULL) {
		std::cout << "One or more of the needed dependencies are missing!\n";
		return;
	}

	sf::Vector2f offset(0.0f, 0.0f);
	if (inputController->isUp()) {
		offset.y -= inputController->SPEED_MULT;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isDown()) {
		offset.y += inputController->SPEED_MULT;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}

	else if (inputController->isRight()) {
		offset.x -= inputController->SPEED_MULT;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}
	else if (inputController->isLeft()) {
		offset.x += inputController->SPEED_MULT;
		playerTransformable->move(offset * deltaTime.asSeconds());
	}
}
