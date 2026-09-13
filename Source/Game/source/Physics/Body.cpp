#include "Body.h"

Body::Body(const float aWeight): myWeight(aWeight)
{
	// EMPTY
}

void Body::AddForce(const Force& /*aForce*/)
{

}

void Body::AddForce(const Force& /*aForce*/, const float /*aSpeedLimit*/)
{

}

Tga::Vector2f Body::GetCurrentVelocity()
{
	return Tga::Vector2f();
}
