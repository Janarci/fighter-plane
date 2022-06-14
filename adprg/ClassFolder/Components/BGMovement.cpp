#include "BGMovement.h"

#include "../BGObject.h"


BGMovement::BGMovement(std::string name) : AComponent(name, Script)
{
}

BGMovement::~BGMovement()
{
}



void BGMovement::perform()
{
	BGObject* BgObject = (BGObject*)this->getOwner();
	this->sprite = BgObject->getSprite();


	sf::Vector2f offset(0.0f, 0.0f);

	offset.y += SPEED_MULTIPLIER;
	sprite->move(offset * deltaTime.asSeconds());

	sf::Vector2f localPos = sprite->getPosition();
	if (localPos.y*deltaTime.asSeconds() > 0)
	{
		sprite->setPosition(0, -game::WINDOW_HEIGHT * 7);
		
	}

}
