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

	circleTexture.loadFromFile("gfx/Beach_ball.png");
	circle.setTexture(&circleTexture);
	circle.setSize(sf::Vector2f(50, 50));
	circle.setPosition(800, 100);
	circle.setWindow(window);


	player1.setSize(sf::Vector2f(50, 100));
	player1.setCollisionBox(sf::FloatRect(0, 0, 50, 100));
	player1.setPosition(10, 100);
	player1.setFillColor(sf::Color::Blue);
	player1.setWindow(window);
	player1.setInput(input);

	player2.setSize(sf::Vector2f(50, 100));
	player2.setCollisionBox(sf::FloatRect(0, 0, 50, 100));
	player2.setPosition(1010, 10);
	player2.setFillColor(sf::Color::Green);
	player2.setWindow(window);
	player2.setInput(input);

	square.setSize(sf::Vector2f(55, 55));
	square.setCollisionBox(sf::FloatRect(0, 0, 55, 55));
	square.setPosition(500, 500);
	square.setFillColor(sf::Color::White);
	square.setWindow(window);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//player1
	if (input->isKeyDown(sf::Keyboard::S))
	{
		player1.setVelocity(0, 200.f);
		player1.move(player1.getVelocity() * dt);
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		player1.setVelocity(0, -200.f);
		player1.move(player1.getVelocity() * dt);
	}

	//player2
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		player2.setVelocity(0, 200.f);
		player2.move(player2.getVelocity() * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		player2.setVelocity(0, -200.f);
		player2.move(player2.getVelocity() * dt);
	}
}

// Update game objects
void Level::update(float dt)
{
	//task1
	ball.update(dt);
	circle.update(dt);

	if (Collision::checkBoundingCircle(&circle, &ball))
	{
		ball.collisionResponse(NULL);
		circle.collisionResponse(NULL);
	}

	//pong
	player1.update(dt);
	player2.update(dt);
	square.update(dt);

	if (Collision::checkBoundingBox(&square, &player1))
	{
		square.collisionResponse(NULL);
	}
	if (Collision::checkBoundingBox(&square, &player2))
	{
		square.collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);
	window->draw(circle);
	window->draw(player1);
	window->draw(player2);
	window->draw(square);

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