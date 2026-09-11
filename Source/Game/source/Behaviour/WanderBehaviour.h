#pragma once
#include <ostream>
#include <format>

#include "Command/MoveCommand.h"

class WanderBehaviour
{
public:
    WanderBehaviour();

    WanderBehaviour(const WanderBehaviour& aObject) = delete;
    WanderBehaviour& operator=(const WanderBehaviour& c) = delete;

    bool operator==(const WanderBehaviour& aItem) const = delete;
    bool operator<(const WanderBehaviour& aItem) const = delete;
    bool operator>(const WanderBehaviour& aItem) const = delete;

    friend std::ostream& operator<<(std::ostream& os, const WanderBehaviour& aItem);
};

inline std::ostream& operator<<(std::ostream& os, const WanderBehaviour& aItem)
{
    const std::string log = "{{ type: WanderBehaviour }}";
    os << log << std::endl;
    return os;
}