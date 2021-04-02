#include "GameEntity.h"
#include "Drawer.h"

GameEntity::GameEntity(SDL_Renderer* myrenderer, const Vector2f& aPosition, const char* anImage)
:myPosition(aPosition)
,myImage(anImage)
,myIdMarkedForDeleteFlag(false)
{
	changeText(myrenderer, aPosition, anImage); // using this to pass through a texture whenever the sprite needs to be chnaged 
}

GameEntity::~GameEntity(void)
{
}

bool GameEntity::Intersect(GameEntity* aGameEntity)
{

	return false;	
}

void GameEntity::Draw(Drawer* aDrawer)
{
	aDrawer->Draw(optimizedSurface, sizeRect, posRect); // drawing the surface to the window
}

void GameEntity::moveSprite(int cellX, int cellY) // assigning the sprites position to its previous position to update movement
{
	posRect.x = cellX;
	posRect.y = cellY;
	posRect.w = sizeRect.w;
	posRect.h = sizeRect.h;
}





void GameEntity::changeText(SDL_Renderer* myrenderer, const Vector2f& aPosition, const char* anImage) // using this function to store a surface and texure.
{
	SDL_Surface* surface = IMG_Load(anImage); // stores an image that is used for sprites that inherite from this class

	if (!surface)
		return;

	optimizedSurface = SDL_CreateTextureFromSurface(myrenderer, surface);


	sizeRect.x = 0;
	sizeRect.y = 0;
	sizeRect.w = surface->w;
	sizeRect.h = surface->h;


	posRect.x = aPosition.myX + 220;
	posRect.y = aPosition.myY + 60;
	posRect.w = sizeRect.w;
	posRect.h = sizeRect.h;


	
	SDL_FreeSurface(surface); // freeing the surface before making it again to save space and stop duplicates
}

