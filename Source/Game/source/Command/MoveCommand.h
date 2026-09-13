#pragma once

#include "Command.h"

class Actor;

struct MoveCommandDescription
{

};

class MoveCommand: public Command
{
public:
    MoveCommand() = delete;
    MoveCommand(MoveCommandDescription aDescription);

    bool Execute(Actor* outBody);
private:

};