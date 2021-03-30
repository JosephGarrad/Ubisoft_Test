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


	bool Up;
	bool Left;
	bool Right;
	bool Down;
	
	void Draw(Drawer* aDrawer);
	
private:
	int tileSize; // moved from CPP
	float distanceToMove; // moved from CPP
};

#endif //AVATAR_H