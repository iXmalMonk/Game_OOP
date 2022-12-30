#include "..\..\include\utilts\GameResources.h"

GameResources* GameResources::instance = nullptr;

GameResources::GameResources()
{
	font.loadFromFile(FILENAME_FONT_SAMSON);
	loadText(font,
		600,
		"EXIT",
		TextType::EXIT,
		TEXT_SIZE);
	loadText(font,
		400,
		"MENU",
		TextType::MENU,
		TEXT_SIZE);
	loadText(font,
		200,
		"PLAY",
		TextType::PLAY,
		TEXT_SIZE);
	loadTexture(FILENAME_TEXTURE_BRICKWALL,
		GameObject::GameObjectType::BRICKWALL);
	loadTexture(FILENAME_TEXTURE_CONCRETEWALL,
		GameObject::GameObjectType::CONCRETEWALL);
	loadTexture(FILENAME_TEXTURE_ENEMY,
		GameObject::GameObjectType::ENEMY);
	loadTexture(FILENAME_TEXTURE_FLAG,
		GameObject::GameObjectType::FLAG);
	loadTexture(FILENAME_TEXTURE_FOREST,
		GameObject::GameObjectType::FOREST);
	loadTexture(FILENAME_TEXTURE_HEADQUARTERS,
		GameObject::GameObjectType::HEADQUARTERS);
	loadTexture(FILENAME_TEXTURE_PLAYER,
		GameObject::GameObjectType::PLAYER);
	loadTexture(FILENAME_TEXTURE_PROJECTILE,
		GameObject::GameObjectType::PROJECTILE);
	loadTexture(FILENAME_TEXTURE_WATER,
		GameObject::GameObjectType::WATER);
}

GameResources::~GameResources()
{
	for (auto text : texts)
		delete text.second;
	texts.clear();
	for (auto texture : textures)
		delete texture.second;
	textures.clear();
}

void GameResources::loadText(Font& _font, int _y, String _text, TextType _textType, unsigned int _size)
{
	auto text = new Text(_text,
		_font,
		_size);
	text->setFillColor(Color::White);
	text->setPosition(Vector2f((MAP_BLOCK * MAP_SIZE / 2 - text->getLocalBounds().width) / 2,
		float(_y)));
	texts[_textType] = text;
}

void GameResources::loadTexture(const char* _filename, GameObject::GameObjectType _gameObjectType)
{
	auto texture = new Texture;
	texture->loadFromFile(_filename);
	textures[_gameObjectType] = texture;
}

void GameResources::destroy()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

GameResources* GameResources::getInstance()
{
	if (!instance)
		instance = new GameResources;
	return instance;
}

Text* GameResources::getText(TextType _textType)
{
	return texts[_textType];
}

Texture* GameResources::getTexture(GameObject::GameObjectType _gameObjectType)
{
	return textures[_gameObjectType];
}