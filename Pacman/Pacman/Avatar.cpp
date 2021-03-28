#include "Avatar.h"
#include "Drawer.h"
Avatar::Avatar(const Vector2f& aPosition)
: MovableGameEntity(aPosition, "open_32.png")
{
	Left = true;
	Right = false;
	Down = false;
	Up = false;
	
}

Avatar::~Avatar(void)
{
}

void Avatar::Update(float aTime)
{
	int tileSize = 22;

	Vector2f destination(myNextTileX * tileSize, myNextTileY * tileSize);
	Vector2f direction = destination - myPosition;

	float distanceToMove = aTime * 30.f;

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
}

void Avatar::ChangeSprite(const char* anImage)
{
	myImage = anImage;
}
void Avatar::Draw(Drawer* aDrawer)
{
	if (Up)
	{
		aDrawer->Draw("open_up_32.png", (int)myPosition.myX + 220, (int)myPosition.myY + 60);
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
	}
}
