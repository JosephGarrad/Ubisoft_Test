#include "GameEntity.h"
#include "Drawer.h"

GameEntity::GameEntity(SDL_Renderer* myrenderer, const Vector2f& aPosition, const char* anImage)
:myPosition(aPosition)
,myImage(anImage)
,myIdMarkedForDeleteFlag(false)
{
	changeText(myrenderer, aPosition, anImage);
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
	aDrawer->Draw(optimizedSurface, sizeRect, posRect);
}

void GameEntity::moveSprite(int cellX, int cellY)
{
	posRect.x = cellX;
	posRect.y = cellY;
	posRect.w = sizeRect.w;
	posRect.h = sizeRect.h;
}





void GameEntity::changeText(SDL_Renderer* myrenderer, const Vector2f& aPosition, const char* anImage)
{
	SDL_Surface* surface = IMG_Load(anImage);

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


	//SDL_DestroyTexture(optimizedSurface); // destroyed this surface as the program was creating a new texture but never destroying or freeing the previous one
	SDL_FreeSurface(surface); // freeing the surface before making it again to save space and stop duplicates
}

