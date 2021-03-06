#include "Pacman.h"
#include "Drawer.h"
#include "SDL.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Avatar.h"
#include "World.h"
#include "Ghost.h"

Pacman* Pacman::Create(Drawer* aDrawer)
{
	Pacman* pacman = new Pacman(aDrawer);

	if (!pacman->Init())
	{
		delete pacman;
		pacman = NULL;
	}

	return pacman;
}

Pacman::Pacman(Drawer* aDrawer)
	: myDrawer(aDrawer)
	, myTimeToNextUpdate(0.f)
	, myNextMovement(-1.f, 0.f)
	, myScore(0)
	, myFps(0)
	, myLives(3)
	, myGhostGhostCounter(0.f)
{
	myAvatar = new Avatar(myDrawer->returnRenderer(), Vector2f(13 * 22, 22 * 22)); // retriving the renderer and positions for the newly made objects
	myGhost = new Ghost(myDrawer->returnRenderer(), Vector2f(13 * 22, 13 * 22));
	myWorld = new World();
}

Pacman::~Pacman(void)
{
	delete myAvatar; // deleting these for memory managment
	delete myGhost;
	delete myWorld;
}

bool Pacman::Init()
{
	myWorld->Init(myDrawer->returnRenderer());

	return true;
}

bool Pacman::Update(float aTime)
{
	if (!UpdateInput())
		return false;

	if (CheckEndGameCondition())
	{
		myDrawer->DrawText("You win!", "freefont-ttf\\sfd\\FreeMono.ttf", 20, 70);
		return true;
	}
	else if (myLives <= 0)
	{
		myDrawer->DrawText("You lose!", "freefont-ttf\\sfd\\FreeMono.ttf", 20, 70);
		return true;
	}

	MoveAvatar();
	myAvatar->Update(aTime, myDrawer->returnRenderer(), myWorld);
	myGhost->Update(aTime, myWorld, myDrawer->returnRenderer(), myAvatar);
	
	if (myWorld->HasIntersectedDot(myAvatar->GetPosition()))
		myScore += 10;

	if (myWorld->HasIntersectedCherry(myAvatar->GetPosition())) // if a cherry (RED GHOST) is intersected with increase the score by 100
	{
		myScore += 100;
	}

	myGhostGhostCounter -= aTime;

	if (myWorld->HasIntersectedBigDot(myAvatar->GetPosition()))
	{
		myScore += 20;
		myGhostGhostCounter = 20.f;
		myGhost->myIsClaimableFlag = true;
	}

	if (myGhostGhostCounter <= 0)
	{
		myGhost->myIsClaimableFlag = false;
	}

	if ((myGhost->GetPosition() - myAvatar->GetPosition()).Length() < 10.f)
	{
		if (myGhostGhostCounter <= 0.f)
		{
			myLives--;

			myAvatar->SetPosition(Vector2f(13 * 22, 22 * 22));
			
			myGhost->SetPosition(Vector2f(13 * 22, 13 * 22));
		}
		else if (myGhost->myIsClaimableFlag && !myGhost->myIsDeadFlag)
		{
			myScore += 50;
			myGhost->myIsDeadFlag = true;
			myGhost->Die(myWorld);
		}
	}

	
	
	if (aTime > 0)
		myFps = (int) (1 / aTime);

	return true;
}

bool Pacman::UpdateInput()
{
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_UP])
	{
		myNextMovement = Vector2f(0.f, -1.f);
		myAvatar->ChangeDir(myDrawer->returnRenderer()); // whenever a button is pressed to change the direction of the character, we call this function and switch the correlating booleans to true and/or false
		myAvatar->Up = true;
		myAvatar->Down = false;
		myAvatar->Right = false;
		myAvatar->Left = false;
		
	}

	else if (keystate[SDL_SCANCODE_DOWN])
	{
		myNextMovement = Vector2f(0.f, 1.f);
		myAvatar->ChangeDir(myDrawer->returnRenderer());
		myAvatar->Down = true;
		myAvatar->Up = false;
		myAvatar->Left = false;
		myAvatar->Right = false;
	}
	else if (keystate[SDL_SCANCODE_RIGHT])
	{
		myNextMovement = Vector2f(1.f, 0.f);
	myAvatar->ChangeDir(myDrawer->returnRenderer());
		myAvatar->Right = true;
		myAvatar->Down = false;
		myAvatar->Up = false;
		myAvatar->Left = false;
	}
	else if (keystate[SDL_SCANCODE_LEFT])
	{
		myNextMovement = Vector2f(-1.f, 0.f);
		myAvatar->ChangeDir(myDrawer->returnRenderer());
		myAvatar->Left = true;
		myAvatar->Down = false;
		myAvatar->Right = false;
		myAvatar->Up = false;
	}


	if (keystate[SDL_SCANCODE_ESCAPE])
		return false;

	return true;
}

void Pacman::MoveAvatar()
{
	int nextTileX = myAvatar->GetCurrentTileX() + myNextMovement.myX;
	int nextTileY = myAvatar->GetCurrentTileY() + myNextMovement.myY;

	if (myAvatar->IsAtDestination())
	{
		if (myWorld->TileIsValid(nextTileX, nextTileY))
		{
			myAvatar->SetNextTile(nextTileX, nextTileY);
			
		}
	}
	
}

bool Pacman::CheckEndGameCondition()
{
	if (myWorld->win) // if the win boolean is set to true end the game as a win
	{
		return true;
	}
	return false;
}


bool Pacman::Draw(Drawer* aDrawer)
{
	myWorld->Draw(aDrawer);
	myAvatar->Draw(aDrawer);
	myGhost->Draw(aDrawer);

	std::string scoreString;
	std::stringstream scoreStream;
	scoreStream << myScore;
	scoreString = scoreStream.str();
	aDrawer->DrawText("Score", "freefont-ttf\\sfd\\FreeMono.ttf", 20, 50);
	aDrawer->DrawText(scoreString.c_str(), "freefont-ttf\\sfd\\FreeMono.ttf", 90, 50);

	std::string livesString;
	std::stringstream liveStream;
	liveStream << myLives;
	livesString = liveStream.str();
	aDrawer->DrawText("Lives", "freefont-ttf\\sfd\\FreeMono.ttf", 20, 80);
	aDrawer->DrawText(livesString.c_str(), "freefont-ttf\\sfd\\FreeMono.ttf", 90, 80);

	aDrawer->DrawText("FPS", "freefont-ttf\\sfd\\FreeMono.ttf", 880, 50);
	std::string fpsString;
	std::stringstream fpsStream;
	fpsStream << myFps;
	fpsString = fpsStream.str();
	aDrawer->DrawText(fpsString.c_str(), "freefont-ttf\\sfd\\FreeMono.ttf", 930, 50);

	return true;
}
