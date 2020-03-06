#pragma once
#include "Framework/GameObject.h"
class Square :
	public GameObject
{
public:
	Square();
	~Square();

	void update(float dt) override;
	void collisionResponse(GameObject* collider) override;

	sf::RenderWindow* window;

	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
};

