#include "Player1.h"
Player1::Player1()
{
}

Player1::~Player1()
{
}

void Player1::handleInput(float dt)
{
	/*if (input->isKeyDown(sf::Keyboard::S))
	{
		setVelocity(0, 200.f);
		move(getVelocity() * dt);
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		setVelocity(0, -200.f);
		move(getVelocity() * dt);
	}*/
}

void Player1::update(float dt)
{
	move(velocity * dt);

	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
	}
	if (getPosition().y + 100 >= window->getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - 100);
	}
}