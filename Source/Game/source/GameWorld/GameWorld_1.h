#pragma once

#include <tge/sprite/sprite.h>
#include <memory>

#include "Actor.h"

class GameWorld_1
{
public:
	GameWorld_1(); 
	~GameWorld_1();

	void Init();
	void Update(float aTimeDelta);
	void Render();
private:
	Tga::Sprite2DInstanceData myTGELogoInstance = {};
	Tga::SpriteSharedData mySharedData = {};

	std::vector<std::unique_ptr<Actor>> myActors;
};