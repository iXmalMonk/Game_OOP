#include "..\include\Tank.h"

void Tank::shoot()
{
	sendMessage(new Message(MessageType::SHOOT, this));
}
