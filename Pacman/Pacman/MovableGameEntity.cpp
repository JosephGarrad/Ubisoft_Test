#include "MovableGameEntity.h"

MovableGameEntity::MovableGameEntity(SDL_Renderer* renderer, const Vector2f& aPosition, const char* anImage)
: GameEntity(renderer,aPosition, anImage)
{
	myCurrentTileX = myNextTileX =  myPosition.myX / 22;
	myCurrentTileY = myNextTileY =  myPosition.myY / 22;
}

MovableGameEntity::~MovableGameEntity(void)
{
}


void MovableGameEntity::UpdateTiles(int tileX, int TileY)
{
	myCurrentTileX = tileX;
	myCurrentTileY = TileY;
}

bool MovableGameEntity::IsAtDestination()
{
	if (myCurrentTileX == myNextTileX && myCurrentTileY == myNextTileY)
	{


		return true;
	}

	return false;
}

void MovableGameEntity::SetNextTile(int anX, int anY)
{
	myNextTileX = anX;
	myNextTileY = anY;
}

