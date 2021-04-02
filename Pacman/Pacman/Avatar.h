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

	void Restart();



	

	

	//Vector2f GetPOS(const Vector2f& aPosition);
	
	void animateSprite(float deltatime, SDL_Renderer* myrenderer);
	
	void UpdateSprite(SDL_Renderer* myrenderer);
	void ChangeDir(SDL_Renderer* myrenderer);

	void Update(float aTime, SDL_Renderer* myrenderer, World* myworld);

	const char* avatar_sprite;
	bool Up;
	bool Left;
	bool Right;
	bool Down;

	int starttileX;
	int starttileY;


	bool restarted = false;
	float currentTime;


	bool closed = false;
	bool open = true;
	bool running = false;


	std::stringstream TimeToSwap;
	std::stringstream time;
	
	//void Draw(Drawer* aDrawer);
	
private:
	int tileSize; // moved from CPP
	float distanceToMove; // moved from CPP
};

#endif //AVATAR_H