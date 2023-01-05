#ifndef _GAMERESOURCES_H
#define _GAMERESOURCES_H

#include "..\abstract\GameObject.h"

class GameResources
{
public:
	enum class TextType {
		CONTINUE,
		ENEMY,
		EXIT,
		LEVEL,
		LOSE,
		MENU,
		NEW_GAME,
		PLAYER,
		WIN
	};
	enum class TextTypeForCounters {
		ENEMY,
		LEVEL,
		PLAYER
	};

private:
	enum class Side {
		LEFT,
		MIDDLE,
		RIGHT
	};

	static GameResources* instance;

	Font font;
	map<GameObject::GameObjectType,
		Texture*> textures;
	map<TextType,
		Text*> texts;
	map<TextTypeForCounters,
		Text*> textsForCounters;

	GameResources();
	~GameResources();
	void loadEmptyText(Color _color,
		Font& _font,
		TextTypeForCounters _textTypeForCounters,
		unsigned int _size);
	void loadText(Color _color,
		Font& _font,
		int _y,
		Side _side,
		String _text,
		TextType _textType,
		unsigned int _size);
	void loadTexture(const char* _filename,
		GameObject::GameObjectType _gameObjectType);

public:
	static GameResources* getInstance();
	Text* getText(TextType _textType);
	Text* getTextForCounters(TextTypeForCounters _textTypeForCounters);
	Texture* getTexture(GameObject::GameObjectType _gameObjectType);
	void destroy();
	void setCounterForText(int _number, TextTypeForCounters _textTypeForCounters);
};

#endif // !_GAMERESOURCES_H