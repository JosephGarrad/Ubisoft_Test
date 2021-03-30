#include "Dot.h"

Dot::Dot(SDL_Renderer* myrenderer, Vector2f aPosition)
: StaticGameEntity(myrenderer, aPosition, "Small_Dot_32.png")
{

}

Dot::~Dot(void)
{
}
