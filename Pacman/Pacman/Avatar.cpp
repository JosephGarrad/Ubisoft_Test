#include "Avatar.h"
#include "Drawer.h"
Avatar::Avatar(SDL_Renderer* myrenderer, const Vector2f& aPosition)
	: MovableGameEntity(myrenderer, aPosition, "open_left_32.png")
{
	
	
	Left = true;
	Right = false;
	Down = false;
	Up = false;
	
}

Avatar::~Avatar(void)
{
}

void Avatar::Update(float aTime, SDL_Renderer* myrenderer)
{
	tileSize = 22; // now declared in the .H

	Vector2f destination(myNextTileX * tileSize, myNextTileY * tileSize);
	Vector2f direction = destination - myPosition;

	distanceToMove = aTime * 30.f; // now declared in the .H

	if (distanceToMove > direction.Length())
	{
		myPosition = destination;
		myCurrentTileX = myNextTileX;
		myCurrentTileY = myNextTileY;
	}
	else
	{
		direction.Normalize();
		myPosition += direction * distanceToMove;
	}
	
	ChangeDir(myrenderer);
	moveSprite(myPosition.myX + 220, myPosition.myY + 60);
}

void Avatar::ChangeSprite(const char* anImage)
{
	myImage = anImage;
	
}
void Avatar::ChangeDir(SDL_Renderer* myrenderer) // used to change the facing direction of the player sprites
{
	if (Up)
	{
		changeText(myrenderer, myPosition, "open_up_32.png");
	}
	else if (Left)
	{
		changeText(myrenderer, myPosition, "open_left_32.png");
	}
	else if (Right)
	{
		changeText(myrenderer, myPosition, "open_right_32.png");
	}
	else if (Down)
	{
		changeText(myrenderer, myPosition, "open_down_32.png");
	}
}


//void Avatar::Draw(Drawer* aDrawer)
//{
	/*if (Up)
	{
		aDrawer->Draw("open_up_32.png",posRect.my + 220, (int)myPosition.myY + 60);
	}
	else if (Left)
	{
		aDrawer->Draw("open_left_32.png", (int)myPosition.myX + 220, (int)myPosition.myY + 60);
	}
	else if (Right)
	{
		aDrawer->Draw("open_32.png", (int)myPosition.myX + 220, (int)myPosition.myY + 60);
	}
	else if (Down)
	{
		aDrawer->Draw("open_down_32.png", (int)myPosition.myX + 220, (int)myPosition.myY + 60);
	}*/
//}
