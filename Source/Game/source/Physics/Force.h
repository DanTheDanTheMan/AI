#pragma once
#include <ostream>

class Force
{
public:
    Force();
    ~Force();

    Force(const Force& aObject);
    Force& operator=(const Force& c);

    Force(Force&& aObject) noexcept;
    Force& operator=(Force&& c) noexcept;

    bool operator==(const Force& aItem) const;
    bool operator<(const Force& aItem) const;
    bool operator>(const Force& aItem) const;

    friend std::ostream& operator<<(std::ostream& os, const Force& aItem);
};