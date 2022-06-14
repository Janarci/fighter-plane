#pragma once
#include "AComponent.h"
#include "../ObjectPooling/GameObjectPool.h"
#include "../ObjectPoolHolder.h"
#include "../EnemyAirplane.h"

class EnemySwarmHandler :
    public AComponent
{

public:
    EnemySwarmHandler(int numEnemies, std::string name);

    ~EnemySwarmHandler();
	void perform() override;



private:
    GameObjectPool* enemyPool;
    const float SPAWN_INTERVAL = 0.01f;
    float ticks = 0.0f;
};

