#include "Ghost.h"
#include "World.h"
#include "PathmapTile.h"
#include "Drawer.h"

Ghost::Ghost(SDL_Renderer* myrenderer, const Vector2f& aPosition)
: MovableGameEntity(myrenderer,aPosition, "ghost_32.png")
{
	myIsClaimableFlag = false;
	myIsDeadFlag = false;

	myDesiredMovementX = 0;
	myDesiredMovementY = -1;

	
}

Ghost::~Ghost(void)
{
}

void Ghost::Die(World* aWorld)
{
	myPath.clear();
	aWorld->GetPath(myCurrentTileX, myCurrentTileY, 13, 13, myPath);

}

void Ghost::Update(float aTime, World* aWorld, SDL_Renderer* myrenderer, Avatar* myavatar)
{
	
	 speed = 30.f; //moved decleration into .h
	nextTileX = GetCurrentTileX() + myDesiredMovementX; // both now declared in .H // so if we need to go to the next tile on the x it sents the disired movement to that tile 
	nextTileY = GetCurrentTileY() + myDesiredMovementY;
	
	if (myIsDeadFlag)
		speed = 120.f;
	
	if (IsAtDestination())
	{
		
		if (!myPath.empty())
		{
			PathmapTile* nextTile = myPath.front();
			myPath.pop_front();
			SetNextTile(nextTile->myX, nextTile->myY);
		
		}
		else if (aWorld->TileIsValid(nextTileX, nextTileY))
		{
			SetNextTile(nextTileX, nextTileY);
		}
		else
		{
			if (myDesiredMovementX == 1)
			{
				myDesiredMovementX = 0;
				myDesiredMovementY = 1;
			}else if (myDesiredMovementY == 1)
			{
				myDesiredMovementX = -1;
				myDesiredMovementY = 0;			
			} else if (myDesiredMovementX == -1)
			{
				myDesiredMovementX = 0;
				myDesiredMovementY = -1;
			} 
			
			else
			{
				myDesiredMovementX = 1;
				myDesiredMovementY = 0;
			}

			myIsDeadFlag = false;
		}
	}

	
	tileSize = 22; // now declared in the .H

	Vector2f destination(myNextTileX * tileSize, myNextTileY * tileSize);
	Vector2f direction = destination - myPosition;

	distanceToMove = aTime * speed; // now declared in the .H

	if (distanceToMove > direction.Length())
	{
		myPosition = destination;
		myCurrentTileX = myNextTileX;
		myCurrentTileY = myNextTileY;
	}
	else
	{
		direction.Normalize();
		myPosition += direction * distanceToMove;
	}
	
	
	GhostStates(myrenderer); // calling the Ghosts states function
	//aWorld->GetPath(myCurrentTileX, myCurrentTileY, myavatar->GetCurrentTileX(), myavatar->GetCurrentTileY(), myPath); // was using this line to create a path between the Ghost and Avatar to allow for pathfinding, however i did not manage to complete implementation 
	moveSprite(myPosition.myX + 220, myPosition.myY + 60);
	
}

void Ghost::SetImage(const char* anImage)
{
	myImage = anImage;
}

void Ghost::MakePath(World* aWorld, Avatar* myavatar) // calling this function allows us to create a path between the Ghost and Avatar
{
	aWorld->GetPath(myCurrentTileX, myCurrentTileY, myavatar->GetCurrentTileX(), myavatar->GetCurrentTileY(), myPath);
}

void Ghost::GhostStates(SDL_Renderer* myrenderer) // used to chnage the srpties of the ghost when there states change
{
	if (myIsDeadFlag) // if the Ghost is dead
	{
		changeText(myrenderer, myPosition, "Ghost_Dead_32.png"); // set its sprite to the dead sprite 
	}
	else if (myIsClaimableFlag) // if the Ghost is killable 
	{
		changeText(myrenderer, myPosition, "Ghost_Vulnerable_32.png"); // set it sprite to be vunerable
	}
	else
	{
		changeText(myrenderer, myPosition, "ghost_32.png"); // otherwise make the sprite the default Ghost sprite 
	}

}
