#pragma once
#include "ObjectPooling/APoolable.h"
#include "../game.h"
#include "AGameObject.h"

#include "TextureManager.h"
#include "Components/EnemyBehavior.h"
class EnemyAirplane :
    public APoolable
{

public:
    EnemyAirplane(std::string name);
    ~EnemyAirplane();

    void initialize() override;/**/
    void onRelease() override;
    void onActivate() override;
 
	APoolable* clone();
   

private:
    sf::Sprite* sprite = new sf::Sprite();
    int SPAWN_RANGE = 300;
    int counter = 0;
};

