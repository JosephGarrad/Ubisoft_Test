#include "StaticGameEntity.h"

StaticGameEntity::StaticGameEntity(SDL_Renderer* myrenderer, Vector2f aPosition, const char* anImage)
: GameEntity(myrenderer, aPosition, anImage)
{
}

StaticGameEntity::~StaticGameEntity(void)
{
}
