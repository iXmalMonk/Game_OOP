#ifndef _HEADQUARTERS_H
#define _HEADQUARTERS_H

#include "StaticObject.h"

class Headquarters : public StaticObject
{
public:
	Headquarters(Vector2f _position);
	void message(Message* _message) override;
};

#endif // !_HEADQUARTERS_H