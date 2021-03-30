#ifndef STATICGAMEENTITY_H
#define STATICGAMEENTITY_H

#include "GameEntity.h"
#include "Vector2f.h"

class StaticGameEntity : public GameEntity
{
public:
	StaticGameEntity(SDL_Renderer* myrenderer, Vector2f aPosition, const char* anImage);
	~StaticGameEntity(void);
};

#endif // STATICGAMEENTITY_H