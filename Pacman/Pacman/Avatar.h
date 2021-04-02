#ifndef AVATAR_H
#define AVATAR_H

#include "MovableGameEntity.h"
#include "World.h"
#include "Vector2f.h"
#include <string>
#include <sstream>
#include <chrono>


class World;

class Avatar : public MovableGameEntity
{
public:
	Avatar(SDL_Renderer*,const Vector2f& aPosition);
	~Avatar(void);
	void ChangeSprite(const char* anImage); // chnaging the direcion of the sprite

	
	void animateSprite(float deltatime, SDL_Renderer* myrenderer); // use this to animate the sprite
	
	void UpdateSprite(SDL_Renderer* myrenderer);
	void ChangeDir(SDL_Renderer* myrenderer); // use this to change direction of the sprite 

	void Update(float aTime, SDL_Renderer* myrenderer, World* myworld);



	bool Up;
	bool Left;
	bool Right;
	bool Down;
	int starttileX;
	int starttileY;
	float currentTime;

private:
	int tileSize; // moved from CPP
	float distanceToMove; // moved from CPP
	bool closed = false;
	bool open = true;
};

#endif //AVATAR_H