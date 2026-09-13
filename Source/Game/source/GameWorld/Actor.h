#pragma once

#include "Physics/Body.h"

#include <ostream>
#include <format>
#include <filesystem>
#include <tge/sprite/sprite.h>
#include <tge/drawers/SpriteDrawer.h>

class Behaviour;

class Actor
{

public:
    struct ActorDescription
    {
        std::filesystem::path spritePath = "";
        Behaviour* behaviour;
    };

    Actor() = default;

    bool operator==(const Actor& aItem) const;
    bool operator<(const Actor& aItem) const = delete;
    bool operator>(const Actor& aItem) const = delete;

    void Init(ActorDescription aDescription);
    void Update(const float aDeltaTime);
    void Render(Tga::SpriteDrawer& aSpriteDrawer) const;

    friend std::ostream& operator<<(std::ostream& os, const Actor& aItem);

private:
    int static myIdCounter;
    int myId;

    Tga::Sprite2DInstanceData mySpriteInstance = {};
    Tga::SpriteSharedData mySharedData = {};

    float myMaxSpeed;
    Tga::Vector2f myPosition;
    Body myBody;

    Behaviour* myBehaviour;
};

inline bool Actor::operator==(const Actor& aItem) const
{
    return myId == aItem.myId;
}

inline std::ostream& operator<<(std::ostream& os, const Actor& aItem)
{
    const std::string log = std::format("{{ Type: Actor, id: {}, myMaxSpeed: {}, myBody: {} }}", aItem.myId, aItem.myMaxSpeed, aItem.myBody);
    os << log << std::endl;
    return os;
}
