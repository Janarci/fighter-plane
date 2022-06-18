#include "EnemyAirplane.h"

#include "ObjectPoolHolder.h"
#include "Physics/PhysicsManager.h"


EnemyAirplane::EnemyAirplane(std::string name) : APoolable(name), CollisionListener()
{
}

EnemyAirplane::~EnemyAirplane()
{
	delete this->sprite;
}

void EnemyAirplane::initialize()
{
	this->sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("avenger"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	this->setPosition(game::WINDOW_WIDTH / 2, -30);
	this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
	this->getTransformable()->setRotation(180);

	Renderer* renderer = new Renderer("EnemySprite");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);

	EnemyBehavior* behavior = new EnemyBehavior("EnemyBehavior");
	this->attachComponents(behavior);
	behavior->configure(1.0f);

	this->collider = new Collider("EnemyCollider");

	collider->setLocalBounds(sprite->getGlobalBounds());
	collider->setCollisionListener(this);
	this->attachComponents(collider);

}

void EnemyAirplane::onRelease()
{
	PhysicsManager::getInstance()->untrackObject(this->collider);

}

void EnemyAirplane::onActivate()
{
	EnemyBehavior* behavior = (EnemyBehavior*)this->findComponentByName("EnemyBehavior");
	behavior->reset();
	this->setPosition(game::WINDOW_WIDTH / 2, -0);
	this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
	PhysicsManager::getInstance()->trackObject(this->collider);

}

void EnemyAirplane::onCollisionEnter(AGameObject* contact)
{
	
	if (contact->getName().find("projectile") != std::string::npos)
	{
		GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
		enemyPool->releasePoolable(this);

	}

}

void EnemyAirplane::onCollisionExit(AGameObject* contact)
{
	std::cout << "releasing" << std::endl;

}

APoolable* EnemyAirplane::clone()
{
	APoolable* copyObject = new EnemyAirplane(this->name);

	return copyObject;

}

