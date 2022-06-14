#include "TextureManager.h"
#include  <iostream>

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance()
{

	if(sharedInstance == NULL)
	{
		sharedInstance = new TextureManager();

	}
	return sharedInstance;
}

void TextureManager::testFunc()
{
	std::cout << "hello singleton" << std::endl; 
}

void TextureManager::loadAll()
{
	/*
	for (int i = 0; i < 8; i++)
	{
		std::string str_i = std::to_string(i);
		loadTexture("bed_" + str_i, "res/textures/bed000" + str_i + ".png");
	}*/

	loadTexture("desert_bg", "res/textures/Desert.png");
	loadTexture("eagle", "res/textures/Eagle.png");
	loadTexture("avenger", "res/textures/Avenger.png");
	loadTexture("ui_bg", "res/textures/f.png");
	loadTexture("btn_normal", "res/textures/b_4.png");
	sf::Texture* bgTex;
	bgTex = getTexture("desert_bg");
	bgTex->setRepeated(true);
}

sf::Texture* TextureManager::getTexture(std::string key)
{
	if (textureMap[key] != NULL)
	{
		return textureMap[key];
	}
	else {

		std::cerr << "error" << std::endl;
		return NULL;
	}
}

void TextureManager::loadTexture(std::string key, std::string path)
{
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile(path);
	textureMap[key] = texture;
}
