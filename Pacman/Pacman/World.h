#ifndef WORLD_H
#define WORLD_H

#include <list>
#include "Vector2f.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Avatar.h"

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
class Drawer;
class PathmapTile;
class Dot;
class BigDot;
class Cherry;

class World
{
public:
	World(void);
	~World(void);

	void Init(SDL_Renderer* myrenderer);
	void Draw(Drawer* aDrawer);
	bool TileIsValid(int anX, int anY);
	bool HasIntersectedDot(const Vector2f& aPosition);
	bool HasIntersectedBigDot(const Vector2f& aPosition);
	bool HasIntersectedCherry(const Vector2f& aPosition);
	void Update();
	void GetPath(int aFromX, int aFromY, int aToX, int aToY, std::list<PathmapTile*>& aList);

	SDL_Texture* optimizedSurface; // moved into here from the CPP to allow for easier control of the textures and rect in memory and for coding usage
	SDL_Rect sizeRect;
	SDL_Rect posRect;

	PathmapTile* fromTile;
	PathmapTile* toTile;

	bool win = false; // set to true once all dots have been destroyed
private:

	PathmapTile* GetTile(int aFromX, int aFromY);
	bool Pathfind(PathmapTile* aFromTile, PathmapTile* aToTile, std::list<PathmapTile*>& aList);
	bool ListDoesNotContain(PathmapTile* aFromTile, std::list<PathmapTile*>& aList);

	bool InitPathmap(SDL_Renderer* myrenderer);
	bool InitDots(SDL_Renderer* myrenderer);
	bool InitCherry(SDL_Renderer* myrenderer);
	bool InitBigDots(SDL_Renderer* myrenderer);
	
	std::list<PathmapTile*> myPathmapTiles;
	std::list<Dot*> myDots;
	std::list<BigDot*> myBigDots;
	std::list<Cherry*> myCherry;

};

#endif // WORLD_H