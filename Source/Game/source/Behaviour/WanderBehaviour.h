#pragma once
#include <Behaviour/Behaviour.h>

class WanderBehaviour: public Behaviour
{
public:
	bool Mimic(Actor* outActor) override;
};
