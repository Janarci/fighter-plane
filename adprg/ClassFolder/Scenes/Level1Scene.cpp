#include "Level1Scene.h"

#include "../GameObjectManager.h"
#include "../AirplanePlayer.h"
#include "../EmptyGameObject.h"
#include "../BGObject.h"
#include "../Components/EnemySwarmHandler.h"
#include "../Screens/Sidebar.h"
#include "../Screens/MainMenuScreen.h"


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
	BGObject* bgObject = new BGObject("BGOjbect");
	GameObjectManager::getInstance()->addObject(bgObject);

	AirplanePlayer* playerObject = new AirplanePlayer("PlayerObject");
	GameObjectManager::getInstance()->addObject(playerObject);

	EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
	EnemySwarmHandler* SwarmHandler = new EnemySwarmHandler(200, "SwarmHandler");

	enemiesManager->attachComponents(SwarmHandler);
	GameObjectManager::getInstance()->addObject(enemiesManager);
/*	*/
	Sidebar* sidebar = new Sidebar("Sidebar");
	GameObjectManager::getInstance()->addObject(sidebar);


}
