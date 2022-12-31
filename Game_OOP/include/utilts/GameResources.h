#ifndef _GAMERESOURCES_H
#define _GAMERESOURCES_H

#include "..\abstract\GameObject.h"

class GameResources
{
public:
	enum class TextType {
		ENEMY,
		EXIT,
		MENU,
		PLAY,
		PLAYER
	};
	enum class TextTypeForCounters {
		ENEMY,
		PLAYER,
	};

private:
	enum class Side {
		LEFT,
		RIGHT
	};

	static GameResources* instance;

	Font font;
	map<TextType,
		Text*> texts;
	map<TextTypeForCounters,
		Text*> textsForCounters;
	map<GameObject::GameObjectType,
		Texture*> textures;

	GameResources();
	~GameResources();
	void loadEmptyText(Font& _font,
		TextTypeForCounters _textTypeForCounters,
		unsigned int _size);
	void loadText(Font& _font,
		int _y,
		Side _side,
		String _text,
		TextType _textType,
		unsigned int _size);
	void loadTexture(const char* _filename,
		GameObject::GameObjectType _gameObjectType);

public:
	void destroy();
	static GameResources* getInstance();
	Text* getText(TextType _textType);
	Text* getTextForCounters(TextTypeForCounters _textTypeForCounters);
	Texture* getTexture(GameObject::GameObjectType _gameObjectType);
	void setCounterForText(int _number, TextTypeForCounters _textTypeForCounters);
};

#endif // !_GAMERESOURCES_H