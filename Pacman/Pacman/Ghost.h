#ifndef GHOST_H
#define GHOST_H

#include <list>
#include "MovableGameEntity.h"

class World;
class PathmapTile;

class Ghost : public MovableGameEntity
{
public:
	Ghost(const Vector2f& aPosition);
	~Ghost(void);

	void Update(float aTime, World* aWorld);

	bool myIsClaimableFlag;
	bool myIsDeadFlag;

	void SetImage(const char* anImage);

	void Die(World* aWorld);

	void Draw(Drawer* aDrawer);

protected:
	float speed; // moved from CPP
	int myDesiredMovementX;
	int myDesiredMovementY;
	int nextTileY; //Moved from CPP
	int nextTileX; // moved from CPP
	int tileSize; // moved from CPP
	float distanceToMove; // moved from CPP

	std::list<PathmapTile*> myPath;

};

#endif // GHOST_H