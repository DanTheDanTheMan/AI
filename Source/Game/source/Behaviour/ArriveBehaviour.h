#pragma once
#include <ostream>

class ArriveBehaviour
{
public:
    ArriveBehaviour();
    ~ArriveBehaviour();

    ArriveBehaviour(const ArriveBehaviour& aObject);
    ArriveBehaviour& operator=(const ArriveBehaviour& c);

    ArriveBehaviour(ArriveBehaviour&& aObject) noexcept;
    ArriveBehaviour& operator=(ArriveBehaviour&& c) noexcept;

    bool operator==(const ArriveBehaviour& aItem) const;
    bool operator<(const ArriveBehaviour& aItem) const;
    bool operator>(const ArriveBehaviour& aItem) const;

    friend std::ostream& operator<<(std::ostream& os, const ArriveBehaviour& aItem);
};