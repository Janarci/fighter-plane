#include "PhysicsManager.h"

PhysicsManager* PhysicsManager::sharedInstance = NULL;

void PhysicsManager::initialize(std::string name, AGameObject* parent)
{

	sharedInstance = new PhysicsManager(name);
	parent->attachComponents(sharedInstance);

}

void PhysicsManager::destroy()
{
	delete sharedInstance;

}

PhysicsManager* PhysicsManager::getInstance()
{

	return sharedInstance;
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::trackObject(Collider* object)
{
	object->setAlreadyCollided(false);
	this->trackedObjects.push_back(object);
}

void PhysicsManager::untrackObject(Collider* object)
{
	this->forCleaningObjects.push_back(object);

}

void PhysicsManager::perform()
{
	for (int i = 0; i < this->trackedObjects.size(); ++i)//compare all game objects to each other
	{
		for (int j = i; j < this->trackedObjects.size(); ++j)
		{
			Collider* firstObject = this->trackedObjects[i];
			Collider* secondObject = this->trackedObjects[j];

			if (firstObject != secondObject &&
				firstObject->getOwner()->getName() != secondObject->getOwner()->getName() &&// check if comparing to itself
				firstObject->getOwner()->isEnabled() &&
				secondObject->getOwner()->isEnabled()
				)
			{
				if (firstObject->willCollide(secondObject )&& 
					!firstObject->alreadyCollided() &&
					!secondObject->alreadyCollided()
					)
				{
					firstObject->collisionEnter(secondObject->getOwner());
					secondObject->collisionEnter(firstObject->getOwner());
					firstObject->setAlreadyCollided(true);
					secondObject->setAlreadyCollided(true);

				}
				else if (!firstObject->willCollide(secondObject) &&
					firstObject->alreadyCollided() &&
					secondObject->alreadyCollided())
				{
					firstObject->collisionExit(secondObject->getOwner());
					secondObject->collisionExit(firstObject->getOwner());
					firstObject->setAlreadyCollided(false);
					secondObject->setAlreadyCollided(false);
				}
			}
		}
	}
	this->cleanUpObjects();
	/*
	for (int i = 0; i < this->trackedObjects.size(); ++i)
	{
		this->trackedObjects[i]->setChecked(false);

	}*/
}

void PhysicsManager::cleanUpObjects()
{
	for (int i = 0; i < this->forCleaningObjects.size(); ++i)
	{
		this->trackedObjects.erase(this->trackedObjects.begin() + i);
	}
	this->forCleaningObjects.clear();
}
