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

	bool IsAtDestination();
	void UpdateTiles(int tilex, int tiley);
protected:

	int myCurrentTileX;
	int myCurrentTileY;

	int myNextTileX;
	int myNextTileY;

};

#endif // MOVABLEGAMEENTITY_H