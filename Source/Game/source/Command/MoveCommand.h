#pragma once
#include <ostream>

#include "Physics/Body.h"

class MoveCommand
{
public:
    MoveCommand();
    ~MoveCommand();

    bool Execute(Body& outBody);
};