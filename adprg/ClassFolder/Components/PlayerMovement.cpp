#include "PlayerMovement.h"

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
}
