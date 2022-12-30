#ifndef _GAMERESOURCES_H
#define _GAMERESOURCES_H

#include "..\abstract\GameObject.h"

class GameResources
{
public:
	enum class TextType {
		EXIT,
		MENU,
		PLAY
	};

private:
	static GameResources* instance;

	Font font;
	map<TextType,
		Text*> texts;
	map<GameObject::GameObjectType,
		Texture*> textures;

	GameResources();
	~GameResources();
	void loadText(Font& _font,
		int _y,
		String _text,
		TextType _textType,
		unsigned int _size);
	void loadTexture(const char* _filename,
		GameObject::GameObjectType _gameObjectType);

public:
	void destroy();
	static GameResources* getInstance();
	Text* getText(TextType _textType);
	Texture* getTexture(GameObject::GameObjectType _gameObjectType);
};

#endif // !_GAMERESOURCES_H