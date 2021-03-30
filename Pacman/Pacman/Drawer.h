#ifndef DRAWER_H
#define DRAWER_H
#include "SDL.h"
#include "SDL_image.h"
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;

class Drawer
{
public:
	static Drawer* Create(SDL_Window* aWindow, SDL_Renderer* aRenderer);
	~Drawer(void);

	void Draw(SDL_Texture* Texture, SDL_Rect SizeRect, SDL_Rect PosRect);
	void DrawText(const char* aText, const char* aFontFile, int aX, int aY);

	SDL_Renderer* returnRenderer();

private:
	Drawer(SDL_Window* aWindow, SDL_Renderer* aRenderer);
	bool Init();
	
	SDL_Window* myWindow;
	SDL_Renderer* myRenderer;
	SDL_Surface* world;
};

#endif // DRAWER_H