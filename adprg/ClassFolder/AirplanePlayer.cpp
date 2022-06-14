#include "AirplanePlayer.h"
#include "TextureManager.h"
#include "../game.h"
#include <iostream>

#include "Components/PlayerInputController.h"
#include "Components/PlayerMovement.h"
#include "Components/Renderer.h"

AirplanePlayer::AirplanePlayer(std::string name): AGameObject(name)
{

}

void AirplanePlayer::initialize()
{
	/*this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("eagle"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(game::WINDOW_WIDTH / 2, game::WINDOW_WIDTH / 2);*/

	sf::Sprite* sprite = new sf::Sprite;
	sprite->setTexture(*TextureManager::getInstance()->getTexture("eagle"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->transformable.setPosition(game::WINDOW_WIDTH / 2, game::WINDOW_WIDTH / 2);

	Renderer* renderer = new Renderer("PlayerSprite");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);

	PlayerInputController* inputController = new PlayerInputController("MyPlayerInput");
	this->attachComponents(inputController);

	PlayerMovement* movement = new PlayerMovement("MyMovement");
	this->attachComponents(movement);


}
