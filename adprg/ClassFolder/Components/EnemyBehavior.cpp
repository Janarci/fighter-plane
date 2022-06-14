#include "EnemyBehavior.h"
#include "../../game.h"

EnemyBehavior::EnemyBehavior(std::string name) : AComponent(name, Script)
{
	this->reset();

}

void EnemyBehavior::perform()
{
	this->ticks += this->deltaTime.asSeconds();
	sf::Transformable* transformable = this->getOwner()->getTransformable();

	if (this->ticks > this->forwardDuration && this->movementType != Side)
	{
		int counter = (this->movementType + 1) % EnemyMovementType::Side + 1;
		this->movementType = (EnemyMovementType)counter;

	}
	if (this->movementType == Forward)
	{

		transformable->move(0, this->deltaTime.asSeconds() * (SPEED_MULT));
	}
	if (this->movementType == SlowForward)
	{
		transformable->move(0, this->deltaTime.asSeconds() * (SPEED_MULT / 2.0f));
	}
	if (this->movementType == Side)
	{
		if(transformable->getPosition().x  > game::WINDOW_WIDTH/2)
		{
			transformable->move( this->deltaTime.asSeconds() * (SPEED_MULT * 1.5f), 0);
		}
		else
		{
			transformable->move(-this->deltaTime.asSeconds() * SPEED_MULT * 1.5f, 0);
		}

	}

}

void EnemyBehavior::configure(float delay)
{
	this->delay = delay;

}

void EnemyBehavior::reset()
{
	ticks = 0;
	this->movementType = Forward;
	this->forwardDuration = (rand() % 3) + 1.0f;

}
