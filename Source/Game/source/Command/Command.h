#pragma once
#include <ostream>

class Command
{
public:
    Command();
    virtual ~Command();

    bool operator==(const Command& aItem) const;
    bool operator<(const Command& aItem) const;
    bool operator>(const Command& aItem) const;

    bool Execute(Body& outBody);

    friend std::ostream& operator<<(std::ostream& os, const Command& aItem);

protected:
    static unsigned int myIdCounter;
    unsigned int myId;
};

bool Command::operator==(const Command& aItem) const
{
    return aItem.myId == this->myId;
}

std::ostream& operator<<(std::ostream& os, const Behaviour& aItem)
{
    const std::string log = std::format("{{ Type:{} }}", typeid(aItem).name());
    os << log << std::endl;
    return os;
}