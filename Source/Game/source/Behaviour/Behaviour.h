#pragma once
#include <ostream>
#include <format>
#include <memory>


class Actor;

class Behaviour
{
public:
    Behaviour();
    virtual ~Behaviour();

    Behaviour(const Behaviour& aObject) = delete;
    Behaviour& operator=(const Behaviour& c) = delete;

    friend std::ostream& operator<<(std::ostream& os, const Behaviour& aItem);

    virtual bool Enter(Actor* outActor) = 0;
    virtual bool Mimic(Actor* outActor) = 0;
    virtual bool Exit(Actor* outActor) = 0;
};


std::ostream& operator<<(std::ostream& os, const Behaviour& aItem)
{
    const std::string log = std::format("{{ Type:{} }}", typeid(aItem).name());
    os << log << std::endl;
    return os;
}