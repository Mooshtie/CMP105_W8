#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Framework/Collision.h"
#include "blal.h"
#include "Player1.h"
#include "Square.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	blal ball;
	sf::Texture ballTexture;
	blal circle;
	sf::Texture circleTexture;
	Player1 player1;
	Player1 player2;
	Square square;
};