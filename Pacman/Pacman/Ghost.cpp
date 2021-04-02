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
	//aWorld->GetPath(myCurrentTileX, myCurrentTileY, 13, 13, myPath);
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
	
	
	GhostStates(myrenderer);
	UpdateTiles(myCurrentTileX, myCurrentTileY);
	
	moveSprite(myPosition.myX + 220, myPosition.myY + 60);
	
	}

void Ghost::SetImage(const char* anImage)
{
	myImage = anImage;
}

void Ghost::MakePath(World* aWorld, Avatar* myavatar)
{
	aWorld->GetPath(myCurrentTileX, myCurrentTileY, myavatar->GetCurrentTileX(), myavatar->GetCurrentTileY(), myPath);
}

void Ghost::GhostStates(SDL_Renderer* myrenderer) // used to chnage the srpties of the ghost when there states change
{
	if (myIsClaimableFlag)
	{
		changeText(myrenderer, myPosition, "Ghost_Vulnerable_32.png");
	}
	if (myIsDeadFlag)
	{
		changeText(myrenderer, myPosition, "Ghost_Dead_32.png");
	}

}
//void Ghost::Draw(Drawer* aDrawer)
//{
//	if (myIsDeadFlag)
//		aDrawer->Draw("Ghost_Dead_32.png", (int)myPosition.myX + 220, (int)myPosition.myY + 60);
//	else if (myIsClaimableFlag)
//		aDrawer->Draw("Ghost_Vulnerable_32.png", (int)myPosition.myX + 220, (int)myPosition.myY + 60);
//	else
//		aDrawer->Draw(myImage, (int)myPosition.myX + 220, (int)myPosition.myY + 60);
//}
