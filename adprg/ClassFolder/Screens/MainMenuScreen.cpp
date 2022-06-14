#include "MainMenuScreen.h"

#include "Sidebar.h"
#include "../TextureManager.h"
#include "../../ApplicationManager.h"
#include "../Components/Renderer.h"
#include "../../game.h"
class Sidebar;

MainMenuScreen::MainMenuScreen(std::string name) : AGameObject(name), ButtonListener()
{
}

MainMenuScreen::~MainMenuScreen()
{
	delete this->button1;
	delete this->button1_text;
}

void MainMenuScreen::initialize()
{
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("ui_bg"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("MainMenuScreen");
	renderer->assignDrawable(sprite);
	this->attachComponents(renderer);

	float posX = game::WINDOW_WIDTH / 2;
	float posY = game::WINDOW_HEIGHT / 2;
	this->setPosition(posX, posY);

	this->quitText = new UIText("QuitText");
	this->attachChild(quitText);
	this->quitText->setText("Are you sure you want to quit the game?");
	this->quitText->setSize(35);
	this->quitText->setPosition(40, 0);

	this->button1 = new UIButton("button_1", TextureManager::getInstance()->getTexture("btn_normal"), TextureManager::getInstance()->getTexture("btn_normal"));
	this->attachChild(this->button1);
	button1->setPosition(-150, 150);
	button1->getTransformable()->setScale(.7f, .7f);

	this->button1_text = new UIText("button1_text");
	this->button1->attachChild(button1_text);
	this->button1_text->setPosition(0, -20);
	this->button1_text->setSize(64);
	button1_text->setText("Yes");
	this->button1->setButtonListener(this);

	this->button2 = new UIButton("button_2", TextureManager::getInstance()->getTexture("btn_normal"), TextureManager::getInstance()->getTexture("btn_normal"));
	this->attachChild(this->button2);
	button2->setPosition(150, 150);
	button2->getTransformable()->setScale(.7f, .7f);

	this->button2_text = new UIText("button2_text");
	this->button2->attachChild(button2_text);
	this->button2_text->setPosition(0, -20);
	this->button2_text->setSize(64);
	button2_text->setText("No");
	this->button2->setButtonListener(this);
}

void MainMenuScreen::onButtonClick(UIButton* button)
{
	
}

void MainMenuScreen::onButtonReleased(UIButton* button)
{
	if (button->getName() == "button_1")
	{
		ApplicationManager::getInstance()->applicationQuit();
	}

	if (button->getName() == "button_2")
	{
		GameObjectManager::getInstance()->deleteObjectByName("PauseScreen");
		ApplicationManager::getInstance()->resumeApplication();
	}

}
