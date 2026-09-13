#pragma once
#include <ostream>
#include <format>

class Actor;

class Command
{
public:
    Command();
    virtual ~Command();

    bool operator==(const Command& aItem) const;
    bool operator<(const Command& aItem) const = delete;
    bool operator>(const Command& aItem) const = delete;

    virtual bool Execute(Actor* outActor) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Command& aItem);

protected:
    static unsigned int myIdCounter;
    unsigned int myId;
};

bool Command::operator==(const Command& aItem) const
{
    return aItem.myId == this->myId;
}

std::ostream& operator<<(std::ostream& os, const Command& aItem)
{
    const std::string log = std::format("{{ Type:{} }}", typeid(aItem).name());
    os << log << std::endl;
    return os;
}