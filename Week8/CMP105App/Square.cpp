#include "Square.h"
Square::Square()
{
	velocity = sf::Vector2f(100, 100);
}

Square::~Square()
{
}

void Square::update(float dt)
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
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		velocity.y = -velocity.y;
	}
	if (getPosition().y + 55 >= window->getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - 55);
		velocity.y = -velocity.y;
	}
}

void Square::collisionResponse(GameObject* collider)
{
	velocity.x = -velocity.x;
}