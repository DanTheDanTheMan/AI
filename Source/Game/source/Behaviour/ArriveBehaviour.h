#pragma once
#include <Behaviour/Behaviour.h>

class ArriveBehaviour: public Behaviour
{
public:
	bool Mimic(Actor* outActor) override;
};