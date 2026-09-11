#include "GameWorld_1.h"

#include <filesystem>
#include <tge/graphics/GraphicsEngine.h>
#include <tge/drawers/SpriteDrawer.h>
#include <tge/texture/TextureManager.h>
#include <tge/drawers/DebugDrawer.h>
#include <tge/application.h>

using namespace Tga;

GameWorld_1::GameWorld_1()
{
}

GameWorld_1::~GameWorld_1()
{
}

void GameWorld_1::Init()
{
	{
		std::unique_ptr<Actor> seekActor = std::make_unique<Actor>();
		Actor::ActorDescription description;
		description.spritePath = std::filesystem::path("textures/human.png");
		seekActor->Init(description);
		myActors.push_back(std::move(seekActor));
	}
}

void GameWorld_1::Update(float aTimeDelta)
{
	UNREFERENCED_PARAMETER(aTimeDelta);

	for (auto& actor: myActors)
	{
		actor->Update(aTimeDelta);
	}
}

void GameWorld_1::Render()
{
	auto& graphicsEngine = *Tga::GraphicsEngine::GetInstance();

	Tga::SpriteDrawer& spriteDrawer(graphicsEngine.GetSpriteDrawer());

	for (auto& actor : myActors)
	{
		actor->Render(spriteDrawer);
	}
}

//Tga::Application& application = *Tga::Application::GetInstance();

//Tga::Vector2ui intResolution = application.GetRenderSize();
//Tga::Vector2f resolution = { (float)intResolution.x, (float)intResolution.y };
//{
//	mySharedData.texture = GraphicsEngine::GetInstance()->GetTextureManager().GetTexture("Sprites/tge_logo_w.dds");
//	myTGELogoInstance.pivot = { 0.5f, 0.5f };
//	myTGELogoInstance.position = Tga::Vector2f{ 0.5f, 0.5f }*resolution;
//	myTGELogoInstance.size = Tga::Vector2f{ 0.75f, 0.75f }*resolution.y;
//	myTGELogoInstance.color = Tga::Color(1, 1, 1, 1);
//}

//	// Game update
//	{
//		spriteDrawer.Draw(mySharedData, myTGELogoInstance);
//	}
//	// Debug draw pivot
//#ifndef _RETAIL
//	{
//		Tga::DebugDrawer& dbg = graphicsEngine.GetDebugDrawer();
//		Tga::Color c1 = myTGELogoInstance.color;
//		dbg.DrawCircle(myTGELogoInstance.position, 5.f, (c1.myR + c1.myG + c1.myB) / 3 > 0.3f ? Tga::Color(0, 0, 0, 1) : Tga::Color(1, 1, 1, 1));
//	}
//#endif