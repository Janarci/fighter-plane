#include "EnemySwarmHandler.h"

EnemySwarmHandler::EnemySwarmHandler(int numEnemies, std::string name) : AComponent(name, Script)
{
	this->enemyPool = new GameObjectPool(
		ObjectPoolHolder::ENEMY_POOL_TAG,
		new EnemyAirplane("enemy"),
		numEnemies,
		NULL
	);
	enemyPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);

}

EnemySwarmHandler::~EnemySwarmHandler()
{
	delete this->enemyPool;
}

void EnemySwarmHandler::perform()
{
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	this->ticks += this->deltaTime.asSeconds();
	ObjectList usedEnemyPlanes = enemyPool->getUsedObjects();
	
	if (this->ticks > SPAWN_INTERVAL)
	{
		this->ticks = 0.0f;
		enemyPool->requestPoolable();
		
	}
	
	for (int i = 0; i < usedEnemyPlanes.size(); ++i)
	{
		if (usedEnemyPlanes[i]->isEnabled())
		{
			sf::Transformable* transformable = usedEnemyPlanes[i]->getTransformable();

			if (transformable->getPosition().x > game::WINDOW_WIDTH || transformable->getPosition().x < 0)
			{
				enemyPool->releasePoolable(usedEnemyPlanes[i]);
			}
		}
		
		//enemyPool->releasePoolable(usedEnemyPlanes[i]);
		//std::cout << usedEnemyPlanes.size() << std::endl;

	}
	

	//perform checks for isactive here to release
}
