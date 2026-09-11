#include "Actor.h"

#include <tge/texture/texture.h>
#include <tge/graphics/GraphicsEngine.h>
#include <tge/texture/TextureManager.h>
#include <tge/application.h>

void Actor::Init(ActorDescription aDescription)
{
    auto& graphicsEngine = *Tga::GraphicsEngine::GetInstance();

    const std::string filepath = aDescription.spritePath.string();
    mySharedData.texture = graphicsEngine.GetTextureManager().GetTexture(filepath.c_str());

    Tga::Application& application = *Tga::Application::GetInstance();
    Tga::Vector2ui intResolution = application.GetRenderSize();
    
    mySpriteInstance.position = Tga::Vector2f{ 500.f ,500.f };
    mySpriteInstance.pivot = Tga::Vector2f{ 0.5f,0.5f };
    Tga::Vector2f spriteSize = Tga::Vector2f{ 100.0f, 100.0f };
    mySpriteInstance.size = spriteSize;
}

void Actor::Update(const float /*aDeltaTime*/)
{
	
}

void Actor::Render(Tga::SpriteDrawer& aSpriteDrawer) const
{
	aSpriteDrawer.Draw(mySharedData, mySpriteInstance);
}
