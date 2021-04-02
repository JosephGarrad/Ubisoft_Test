#include "Avatar.h"
#include "Drawer.h"
#include <string>
#include <sstream>
Avatar::Avatar(SDL_Renderer* myrenderer, const Vector2f& aPosition)
	: MovableGameEntity(myrenderer, aPosition, "open_left_32.png")
{
	
	starttileX = myCurrentTileX;
	starttileY = myCurrentTileY; // storing the Avatars first tiles;

	Left = true; // created four booleans each one represents a different direction for the Avatar
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
	

	if (myPosition.myX <= myworld->sizeRect.x) // if the Avatar has reached the left side of the map
	{
		myPosition.myX = 575; // teleport the Avatar to the right side of the map 
	}
	if (myPosition.myX >= myworld->sizeRect.x + 575) // if the Avatar reaches the Right side of the map
	{
		myPosition.myX = 0; // teleport them to the left side
	}

	
	
	animateSprite(aTime, myrenderer); // calling the animate sprite function
	moveSprite(myPosition.myX + 220, myPosition.myY + 60); // calling the move sprite function and update the sprites position
	UpdateTiles(myCurrentTileX, myCurrentTileY); // calling the updatetiles function and passing through the Avatars current Tiles 
}

void Avatar::ChangeSprite(const char* anImage)
{
	myImage = anImage;
}



void Avatar::animateSprite(float deltatime, SDL_Renderer* myrenderer) // use this function to animate the Avatar sprite 
{
	currentTime += deltatime; // using a stopwatch 
	if (currentTime >= 0.25f) // if the stop watch his a quater of a second 
	{
		UpdateSprite(myrenderer); // update the sprite 
		currentTime = 0; // set the stopwatch back to 0
		
		
	}
}


void Avatar::UpdateSprite(SDL_Renderer* myrenderer) // use this to change the sprites image
{
	if (Up && open) // if the sprite is facing up and is open
	{
	changeText(myrenderer, myPosition, "closed_up_32.png"); // change the sprite to be up and closed 
	closed = true; // set closed to true
	open = false; // set open to false
	}
	else if (Up && closed) // if the sprite is facing up and is closed
	{
	changeText(myrenderer, myPosition, "open_up_32.png"); // set the sprite to the up and open sprite 
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
	if (Up) // if the up boolean is set in Pacman.CPP 
	{
		changeText(myrenderer, myPosition, "open_up_32.png"); // change the sprite to face upwards
		
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
