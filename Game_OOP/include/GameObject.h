#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Main.h"

using namespace sf;

class Game;

class GameObject
{
public:
	enum class MessageType {Create, Death};

	struct Message
	{
		MessageType messageType;

		union
		{
			struct 
			{
				GameObject* object;
			} create;

			struct
			{
				GameObject* object;
			} death;
		};
	};
protected:
	Vector2f position;
	Texture texture;
	Sprite sprite;
	int w, h;

	static Game* instance;
public:
	GameObject();
	virtual void update(float time) = 0;
	Sprite getSprite();

	void sendMessage(Message* message);
};

#endif // !_GAMEOBJECT_H
