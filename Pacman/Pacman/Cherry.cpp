#include "Cherry.h"

Cherry::Cherry(SDL_Renderer* myrenderer, Vector2f aPosition)
: StaticGameEntity(myrenderer ,aPosition, "ghost_32_red.png")
{
}

Cherry::~Cherry(void)
{
}
