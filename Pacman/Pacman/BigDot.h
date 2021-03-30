#ifndef BIGDOT_H
#define BIGDOT_H

#include "StaticGameEntity.h"
#include "Vector2f.h"

class BigDot : public StaticGameEntity
{
public:
	BigDot(SDL_Renderer* myrenderer, Vector2f aPosition);
	~BigDot(void);
};

#endif // BIGDOT_H