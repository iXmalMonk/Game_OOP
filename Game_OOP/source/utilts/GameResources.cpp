#include "..\..\include\utilts\GameResources.h"

GameResources* GameResources::instance = nullptr;

GameResources::GameResources()
{
	font.loadFromFile(FILENAME_FONT_SAMSON);
	loadText(font,
		200,
		Side::RIGHT,
		"ENEMY:",
		TextType::ENEMY,
		TEXT_SMALL_SIZE);
	loadText(font,
		600,
		Side::LEFT,
		"EXIT",
		TextType::EXIT,
		TEXT_BIG_SIZE);
	loadText(font,
		400,
		Side::LEFT,
		"MENU",
		TextType::MENU,
		TEXT_BIG_SIZE);
	loadText(font,
		200,
		Side::LEFT,
		"PLAY",
		TextType::PLAY,
		TEXT_BIG_SIZE);
	loadText(font,
		600,
		Side::RIGHT,
		"PLAYER:",
		TextType::PLAYER,
		TEXT_SMALL_SIZE);
	loadEmptyText(font,
		TextTypeForCounters::ENEMY,
		TEXT_SMALL_SIZE);
	loadEmptyText(font,
		TextTypeForCounters::PLAYER,
		TEXT_SMALL_SIZE);
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

void GameResources::loadEmptyText(Font& _font, TextTypeForCounters _textTypeForCounters, unsigned int _size)
{
	auto text = new Text;
	text->setFont(_font);
	text->setCharacterSize(_size);
	text->setFillColor(Color::White);
	switch (_textTypeForCounters)
	{
	case TextTypeForCounters::ENEMY:
		text->setPosition(texts[TextType::ENEMY]->getPosition().x + texts[TextType::ENEMY]->getLocalBounds().width + TEXT_SPACING_BEETWEEN_TEXT_AND_TEXT_FOR_COUNTER,
			texts[TextType::ENEMY]->getPosition().y);
		break;
	case TextTypeForCounters::PLAYER:
		text->setPosition(texts[TextType::PLAYER]->getPosition().x + texts[TextType::PLAYER]->getLocalBounds().width + TEXT_SPACING_BEETWEEN_TEXT_AND_TEXT_FOR_COUNTER,
			texts[TextType::PLAYER]->getPosition().y);
		break;
	}
	textsForCounters[_textTypeForCounters] = text;
}

void GameResources::loadText(Font& _font, int _y, Side _side, String _text, TextType _textType, unsigned int _size)
{
	auto text = new Text(_text,
		_font,
		_size);
	text->setFillColor(Color::White);
	switch (_side)
	{
	case Side::LEFT:
		text->setPosition(Vector2f((MAP_BLOCK * MAP_SIZE / 2 - text->getLocalBounds().width) / 2,
			float(_y)));
		break;
	case Side::RIGHT:
		text->setPosition(Vector2f(MAP_BLOCK * MAP_SIZE + MAP_BLOCK * MAP_SIZE / 2 + (MAP_BLOCK * MAP_SIZE / 2 - text->getLocalBounds().width) / 2,
			float(_y)));
		break;
	}
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

Text* GameResources::getTextForCounters(TextTypeForCounters _textTypeForCounters)
{
	return textsForCounters[_textTypeForCounters];
}

Texture* GameResources::getTexture(GameObject::GameObjectType _gameObjectType)
{
	return textures[_gameObjectType];
}

void GameResources::setCounterForText(int _number, TextTypeForCounters _textTypeForCounters)
{
	stringstream stringStream;
	stringStream << _number;
	textsForCounters[_textTypeForCounters]->setString(stringStream.str().c_str());
}
