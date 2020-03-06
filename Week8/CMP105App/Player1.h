#pragma once
#include "Framework/GameObject.h"
class Player1 :
	public GameObject
{
public:
	Player1();
	~Player1();

	void handleInput(float dt) override;
	void update(float dt) override;

	sf::RenderWindow* window;

	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; }
};