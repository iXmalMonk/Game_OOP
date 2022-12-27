#include "..\include\GameResources.h"

GameResources::GameResources()
{
	loadTexture(FILENAME_PNG_BRICKWALL, GameObject::GameObjectType::BRICKWALL);
	loadTexture(FILENAME_PNG_CONCRETEWALL, GameObject::GameObjectType::CONCRETEWALL);
	loadTexture(FILENAME_PNG_ENEMY, GameObject::GameObjectType::ENEMY);
	loadTexture(FILENAME_PNG_FLAG, GameObject::GameObjectType::FLAG);
	loadTexture(FILENAME_PNG_FOREST, GameObject::GameObjectType::FOREST);
	loadTexture(FILENAME_PNG_HEADQUARTERS, GameObject::GameObjectType::HEADQUARTERS);
	loadTexture(FILENAME_PNG_PLAYER, GameObject::GameObjectType::PLAYER);
	loadTexture(FILENAME_PNG_PROJECTILE, GameObject::GameObjectType::PROJECTILE);
	loadTexture(FILENAME_PNG_WATER, GameObject::GameObjectType::WATER);
}

GameResources::~GameResources()
{
	for (auto texture : textures)
		delete texture.second;
	textures.clear();
}

void GameResources::loadTexture(const char* _filename, GameObject::GameObjectType _gameObjectType)
{
	auto texture = new Texture;
	texture->loadFromFile(_filename);
	textures[_gameObjectType] = texture;
}

GameResources* GameResources::instance = nullptr;

GameResources* GameResources::getInstance()
{
	if (!instance)
		instance = new GameResources;
	return instance;
}

void GameResources::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

Texture* GameResources::getTexture(GameObject::GameObjectType _gameObjectType)
{
	return textures[_gameObjectType];
}