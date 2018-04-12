#pragma once
#include "Component.h"

enum CollisionLayer {
	Default,
	Player,
	Shot,
	Astroid,
};

struct CollisonData
{
	CollisionLayer CollisionLayer;
	GameObject* Object;
};

class Collider :
	public Component
{
public:
	Collider(bool ControledByVelocity);
	~Collider();

	void virtual Update();

private:
	bool controledByVelocity;

};

