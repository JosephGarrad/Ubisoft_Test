#ifndef MOVABLEGAMEENTITY_H
#define MOVABLEGAMEENTITY_H

#include "GameEntity.h"
#include "Vector2f.h"



class MovableGameEntity : public GameEntity
{
public:
	MovableGameEntity(SDL_Renderer*, const Vector2f& aPosition, const char* anImage);
	~MovableGameEntity(void);

	

	void SetNextTile(int anX, int anY);
	int GetCurrentTileX() const { return myCurrentTileX; }
	int GetCurrentTileY() const { return myCurrentTileY; }
	
	void UpdateTiles(int tileX, int TileY); // updating the tiles that the entity is on to help with the pathfinding (not working)
	bool IsAtDestination();
	
protected:

	int myCurrentTileX;
	int myCurrentTileY;

	int myNextTileX;
	int myNextTileY;

};

#endif // MOVABLEGAMEENTITY_H