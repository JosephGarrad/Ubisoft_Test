#ifndef CHERRY_H
#define CHERRY_H

#include "StaticGameEntity.h"
#include "Vector2f.h"

class Cherry : public StaticGameEntity
{
public:
	Cherry(SDL_Renderer* myrenderer, Vector2f aPosition);
	~Cherry(void);
};

#endif // CHERRY_H