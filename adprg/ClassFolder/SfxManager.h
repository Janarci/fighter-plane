#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>

class SfxManager
{
public:

	static  SfxManager* getInstance();
	void loadAll();
	sf::SoundBuffer* getBuffer(std::string);


private:
	SfxManager() {};

	static SfxManager* sharedInstance;
	void loadBuffer(std::string, std::string);
	std::unordered_map<std::string, sf::SoundBuffer*> BufferMap;
};

