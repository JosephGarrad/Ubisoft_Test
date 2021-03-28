#ifndef AVATAR_H
#define AVATAR_H

#include "MovableGameEntity.h"
#include "Vector2f.h"

class Avatar : public MovableGameEntity
{
public:
	Avatar(const Vector2f& aPosition);
	~Avatar(void);
	void ChangeSprite(const char* anImage); // chnaging the direcion of the sprite
	void Update(float aTime);

private:


};

#endif //AVATAR_H