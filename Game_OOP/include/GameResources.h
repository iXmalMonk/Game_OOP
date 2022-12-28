#ifndef _GAMERESOURCES_H
#define _GAMERESOURCES_H

#include "GameObject.h"

class GameResources
{
private:
	static GameResources* instance;
	map<GameObject::GameObjectType,
		Texture*> textures;

	GameResources();
	~GameResources();
	void loadTexture(const char* _filename,
		GameObject::GameObjectType _gameObjectType);

public:
	void destroy();
	static GameResources* getInstance();
	Texture* getTexture(GameObject::GameObjectType _gameObjectType);
};

#endif // !_GAMERESOURCES_H