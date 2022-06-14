#include "SfxManager.h"

#include <iostream>

SfxManager* SfxManager::sharedInstance = NULL;

SfxManager* SfxManager::getInstance()
{
	if (sharedInstance == NULL)
	{
		sharedInstance = new SfxManager();

	}
	return sharedInstance;
}

void SfxManager::loadAll()
{
	loadBuffer("gunfire", "res/audio/EnemyGunfire.wav");
	loadBuffer("explode1", "res/audio/Explosion1.wav");
	loadBuffer("explode2", "res/audio/Explosion2.wav");
	loadBuffer("launchMissile", "res/audio/LaunchMissile.wav");
	
}

sf::SoundBuffer* SfxManager::getBuffer(std::string key)
{
	if (BufferMap[key] != NULL)
	{
		return BufferMap[key];
	}
	else {

		std::cerr << "error" << std::endl;
		return NULL;
	}
}

void SfxManager::loadBuffer(std::string key, std::string path)
{
	sf::SoundBuffer* texture = new sf::SoundBuffer;
	texture->loadFromFile(path);
	BufferMap[key] = texture;
}
