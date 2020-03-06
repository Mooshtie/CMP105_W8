#include "blal.h"
blal::blal()
{
	velocity = sf::Vector2f(100, 0);
}

blal::~blal()
{
}

void blal::update(float dt)
{
	move(velocity * dt);

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x + 55 >= window->getSize().x)
	{
		setPosition(window->getSize().x - 55, getPosition().y);
		velocity.x = -velocity.x;
	}
}

void blal::collisionResponse(GameObject* collider)
{
	velocity.x = -velocity.x;
}
