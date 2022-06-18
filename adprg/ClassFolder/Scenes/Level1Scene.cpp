#include "Level1Scene.h"





Level1Scene::Level1Scene() : AScene("Level1")
{
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::onLoadResources()
{
}

void Level1Scene::onLoadObjects()
{

	EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
	this->registerObject(physicsManager);
	PhysicsManager::initialize("PhysicsManager", physicsManager);


	BGObject* bgObject = new BGObject("BGOjbect");
	GameObjectManager::getInstance()->addObject(bgObject);

	AirplanePlayer* playerObject = new AirplanePlayer("PlayerObject");
	GameObjectManager::getInstance()->addObject(playerObject);

	AirplaneSupport* support1 = new AirplaneSupport("AirSupport_1");
	playerObject->attachChild(support1);
	support1->setPosition(50, 100);

	AirplaneSupport* support2 = new AirplaneSupport("AirSupport_2");
	playerObject->attachChild(support2);
	support2->setPosition(-50, 100);

	EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
	EnemySwarmHandler* SwarmHandler = new EnemySwarmHandler(200, "SwarmHandler");
	enemiesManager->attachComponents(SwarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);

	
	EmptyGameObject* bulletSpawner = new EmptyGameObject("BulletSpawner");
	GameObjectManager::getInstance()->addObject(bulletSpawner);
	this->projectilePool = new GameObjectPool(
		ObjectPoolHolder::PROJECTILE_POOL_TAG,
		new ProjectileObject("projectile"),
		10,
		bulletSpawner);

	this->projectilePool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(projectilePool);
	
	
	Sidebar* sidebar = new Sidebar("Sidebar");
	GameObjectManager::getInstance()->addObject(sidebar);


}

void Level1Scene::onUnloadObjects()
{

	
	GameObjectPool* enemyPooltest = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	ObjectPoolHolder::getInstance()->unregisterObjectPool(enemyPooltest);

	AScene::onUnloadObjects();

	//
	//std::cout <<"Pool amaps: "<< ObjectPoolHolder::getInstance()->poolMap.size() << std::endl;


}
