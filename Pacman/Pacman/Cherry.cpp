#include "Cherry.h"

Cherry::Cherry(SDL_Renderer* myrenderer, Vector2f aPosition)
: StaticGameEntity(myrenderer ,aPosition, "dot.png")
{
}

Cherry::~Cherry(void)
{
}
