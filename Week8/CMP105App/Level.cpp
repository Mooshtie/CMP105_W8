#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTexture.loadFromFile("gfx/Beach_ball.png");
	ball.setTexture(&ballTexture);
	ball.setSize(sf::Vector2f(55, 55));
	ball.setPosition(100, 100);
	ball.setWindow(window);
	ball.setInput(input);

	circleTexture.loadFromFile("gfx/Beach_ball.png");
	circle.setTexture(&circleTexture);
	circle.setSize(sf::Vector2f(50, 50));
	circle.setPosition(800, 100);
	circle.setWindow(window);
	circle.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt);
	circle.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
	circle.update(dt);

	if (Collision::checkBoundingCircle(&circle, &ball))
	{
		ball.collisionResponse(NULL);
		circle.collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);
	window->draw(circle);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}