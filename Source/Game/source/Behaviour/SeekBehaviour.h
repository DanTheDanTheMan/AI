#pragma once
#include <ostream>

class SeekBehaviour
{
public:
    SeekBehaviour();
    ~SeekBehaviour();

    SeekBehaviour(const SeekBehaviour& aObject);
    SeekBehaviour& operator=(const SeekBehaviour& c);

    SeekBehaviour(SeekBehaviour&& aObject) noexcept;
    SeekBehaviour& operator=(SeekBehaviour&& c) noexcept;

    bool operator==(const SeekBehaviour& aItem) const;
    bool operator<(const SeekBehaviour& aItem) const;
    bool operator>(const SeekBehaviour& aItem) const;

    friend std::ostream& operator<<(std::ostream& os, const SeekBehaviour& aItem);
};