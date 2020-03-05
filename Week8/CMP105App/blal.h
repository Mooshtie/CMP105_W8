#pragma once
#include "Framework/GameObject.h"
class blal :
	public GameObject
{
public:
	blal();
	~blal();

	void update(float dt) override;
	void handleInput(float dt) override;
	void collisionResponse(GameObject* collider) override;

	sf::RenderWindow* window;

	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
};

