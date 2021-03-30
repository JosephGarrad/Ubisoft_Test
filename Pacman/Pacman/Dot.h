#ifndef DOT_H
#define DOT_H

#include "StaticGameEntity.h"
#include "Vector2f.h"

class Dot : public StaticGameEntity
{
public:
	Dot(SDL_Renderer* myrenderer, Vector2f aPosition);
	~Dot(void);

	
};

#endif // DOT_H