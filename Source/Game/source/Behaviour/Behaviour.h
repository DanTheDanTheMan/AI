#pragma once
#include <ostream>
#include <format>
#include <memory>

#include "Command/Command.h"

class Behaviour
{
public:
    Behaviour();
    virtual ~Behaviour();

    Behaviour(const Behaviour& aObject) = delete;
    Behaviour& operator=(const Behaviour& c) = delete;

    friend std::ostream& operator<<(std::ostream& os, const Behaviour& aItem);

    std::unique_ptr<Command> GetCommand();
};


std::ostream& operator<<(std::ostream& os, const Behaviour& aItem)
{
    const std::string log = std::format("{{ Type:{} }}", typeid(aItem).name());
    os << log << std::endl;
    return os;
}