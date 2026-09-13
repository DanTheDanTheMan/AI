#pragma once
#include <Behaviour/Behaviour.h>

class SeekBehaviour: public Behaviour
{
public:
    virtual bool Enter(Actor* outActor);
    virtual bool Mimic(Actor* outActor);
    virtual bool Exit(Actor* outActor);
private:

};
