#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "Vector2f.h"
#include "SDL.h"
#include "SDL_image.h"

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
class Drawer;

class GameEntity
{
public:
	GameEntity(SDL_Renderer* myrenderer,const Vector2f& aPosition, const char* anImage);
	~GameEntity(void);

	Vector2f GetPosition() const { return myPosition; }
	void SetPosition(const Vector2f& aPosition){ myPosition = aPosition; }

	bool Intersect(GameEntity* aGameEntity);
	virtual void Draw(Drawer* aDrawer);

	void moveSprite(int cellX, int cellY);





	void changeText(SDL_Renderer* myrenderer, const Vector2f& aPosition, const char* anImage);



	
	void MarkForDelete() { myIdMarkedForDeleteFlag = true; }
	bool IsMarkedForDelete() const { return myIdMarkedForDeleteFlag; }
	SDL_Texture* optimizedSurface;
	SDL_Surface* surface;
	SDL_Rect sizeRect;
	SDL_Rect posRect;
protected:

	bool myIdMarkedForDeleteFlag;
	Vector2f myPosition;
	const char* myImage;
};

#endif // GAMEENTITY_H