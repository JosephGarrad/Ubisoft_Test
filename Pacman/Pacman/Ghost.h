#ifndef GHOST_H
#define GHOST_H

#include <list>
#include "MovableGameEntity.h"
#include "Avatar.h";
class Avatar;
class World;
class PathmapTile;

class Ghost : public MovableGameEntity
{
public:
	Ghost(SDL_Renderer* myrenderer, const Vector2f& aPosition);
	~Ghost(void);

	void Update(float aTime, World* aWorld, SDL_Renderer* myrenderer, Avatar* myavatar);

	void SetImage(const char* anImage);

	void MakePath(World* aWorld, Avatar* myavatar); // this function allows for us to use the "Get path" function 

	void GhostStates(SDL_Renderer* myrenderer); // this controls the ghosts states and changes thier sprites acordingly

	void Die(World* aWorld);

	Drawer* MyDrawer;
	Avatar* MyAvatar; // getting a pointer to the avatar class to allow me to access variables and functions.

	std::list<PathmapTile*> myPath;
	bool myIsClaimableFlag;
	bool myIsDeadFlag;

protected:
	
	int myDesiredMovementX;
	int myDesiredMovementY;
	

	
private:
	float speed; // moved from CPP
	int nextTileY; //Moved from CPP
	int nextTileX; // moved from CPP
	int tileSize; // moved from CPP
	float distanceToMove; // moved from CPP

};

#endif // GHOST_H