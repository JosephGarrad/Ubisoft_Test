#include "BigDot.h"

BigDot::BigDot(SDL_Renderer* myrenderer, Vector2f aPosition)
: StaticGameEntity(myrenderer, aPosition, "Big_Dot_32.png")
{
}

BigDot::~BigDot(void)
{
}
