#ifndef GHOST_H
#define GHOST_H

#include <list>
#include "MovableGameEntity.h"

class World;
class PathmapTile;

class Ghost : public MovableGameEntity
{
public:
	Ghost(SDL_Renderer* myrenderer, const Vector2f& aPosition);
	~Ghost(void);

	void Update(float aTime, World* aWorld, SDL_Renderer* myrenderer);

	bool myIsClaimableFlag;
	bool myIsDeadFlag;
	
	Drawer* MyDrawer;
	void SetImage(const char* anImage);

	void GhostStates(SDL_Renderer* myrenderer);

	void Die(World* aWorld);

	//void Draw(Drawer* aDrawer);

protected:
	
	int myDesiredMovementX;
	int myDesiredMovementY;
	

	std::list<PathmapTile*> myPath;
private:
	float speed; // moved from CPP
	int nextTileY; //Moved from CPP
	int nextTileX; // moved from CPP
	int tileSize; // moved from CPP
	float distanceToMove; // moved from CPP

};

#endif // GHOST_H