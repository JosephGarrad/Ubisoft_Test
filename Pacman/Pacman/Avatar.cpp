#include "Avatar.h"
#include "Drawer.h"
#include <string>
#include <sstream>
Avatar::Avatar(SDL_Renderer* myrenderer, const Vector2f& aPosition)
	: MovableGameEntity(myrenderer, aPosition, "open_left_32.png")
{
	
	starttileX = myCurrentTileX;
	starttileY = myCurrentTileY;

	Left = true;
	Right = false;
	Down = false;
	Up = false;
	
}

Avatar::~Avatar(void)
{
}

void Avatar::Update(float aTime, SDL_Renderer* myrenderer, World* myworld)
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
	

	if (myPosition.myX <= myworld->sizeRect.x)
	{
		myPosition.myX = 575;
	}
	if (myPosition.myX >= myworld->sizeRect.x + 575)
	{
		myPosition.myX = 0;
	}

	
	
	animateSprite(aTime, myrenderer);
	moveSprite(myPosition.myX + 220, myPosition.myY + 60);
	UpdateTiles(myCurrentTileX, myCurrentTileY);
}

void Avatar::ChangeSprite(const char* anImage)
{
	myImage = anImage;
	
}

void Avatar::Restart()
{
	myPosition = Vector2f(13 * 22, 22 * 22);
	
}


void Avatar::animateSprite(float deltatime, SDL_Renderer* myrenderer)
{
	currentTime += deltatime;
	if (currentTime >= 0.25f)
	{
		UpdateSprite(myrenderer);
		currentTime = 0;
		
		
	}
}


void Avatar::UpdateSprite(SDL_Renderer* myrenderer)
{
	if (Up && open)
	{
	changeText(myrenderer, myPosition, "closed_up_32.png");
	closed = true;
	open = false;
	}
	else if (Up && closed)
	{
	changeText(myrenderer, myPosition, "open_up_32.png");
	closed = false;
	open = true;
	}
	else if (Down && open)
	{
		changeText(myrenderer, myPosition, "closed_down_32.png");
		closed = true;
		open = false;
	}
	else if (Down && closed)
	{
		changeText(myrenderer, myPosition, "open_down_32.png");
		closed = false;
		open = true;
	}
	else if (Left && open)
	{
		changeText(myrenderer, myPosition, "closed_left_32.png");
		closed = true;
		open = false;
	}
	else if (Left && closed)
	{
		changeText(myrenderer, myPosition, "open_left_32.png");
		closed = false;
		open = true;
	}
	else if (Right && open)
	{
		changeText(myrenderer, myPosition, "closed_right_32.png");
		closed = true;
		open = false;
	}
	else if (Right && closed)
	{
		changeText(myrenderer, myPosition, "open_right_32.png");
		closed = false;
		open = true;
	}

}

void Avatar::ChangeDir(SDL_Renderer* myrenderer) // used to change the facing direction of the player sprites
{
	if (Up )
	{
		changeText(myrenderer, myPosition, "open_up_32.png");
		
	}

	 if (Left)
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
