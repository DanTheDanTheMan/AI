#pragma once
#include <ostream>
#include <format>
#include <tge/math/vector2.h>

#include "Force.h"

class Body
{
public:
    Body(const float aWeight);

    bool operator==(const Body& aItem) const = delete;
    bool operator<(const Body& aItem) const = delete;
    bool operator>(const Body& aItem) const = delete;

    void AddForce(const Force& aForce);
    void AddForce(const Force& aForce, const float aSpeedLimit);
    
    Tga::Vector2f GetCurrentVelocity();

    friend std::ostream& operator<<(std::ostream& os, const Body& aItem);
private:
    const float myWeight;
    float myCurrentSpeed;
    Tga::Vector2f myCurrentDirection;
};

inline std::ostream& operator<<(std::ostream& os, const Body& aItem)
{
    const std::string log = std::format("{{ type: Body, myWeight: {}, myCurrentSpeed: {}, myCurrentDirection }}", aItem.myWeight, aItem.myCurrentSpeed, 0, aItem.myCurrentDirection);
    os << log << std::endl;
    return os;
}