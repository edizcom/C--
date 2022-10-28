#include "Game.h"


//Private Functions
void Game::initVariables()
{
	this->window = nullptr;
}
void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initEnemy()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f)); /*You need to use Vector2 to declare size of object*/
	/* this->enemy.setScale(sf::Vector2f(0.5f, 0.5f)); //overall sizescale */
	this->enemy.setFillColor(sf::Color::Red);
	this->enemy.setOutlineColor(sf::Color::White);
	this->enemy.setOutlineThickness(2.f);
}

void Game::initPlayer()
{
	this->player.setPosition(10.f, 50.f);
	this->player.setSize(sf::Vector2f(50.f, 50.f)); /*You need to use Vector2 to declare size of object*/
	/* this->player.setScale(sf::Vector2f(0.5f, 0.5f)); //overall sizescale */
	this->player.setFillColor(sf::Color::Yellow);
	this->player.setOutlineColor(sf::Color::White);
	this->player.setOutlineThickness(2.f);
}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemy();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}
//Funtions
void Game::pollEvents()
{
	//Event Polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

		}
	}
}

void Game::update()
{
	this->pollEvents();

	//Update mouse position
	std::cout << "Mouse Pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";
}
 /* void Game::move()
{
	this->pollEvents();
	
	time = clock.restart();
	float deltaTime = time.asSeconds();

	float playerSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player.move(0.f, -playerSpeed * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player.move(0.f, playerSpeed * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player.move(-playerSpeed * deltaTime, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player.move(playerSpeed * deltaTime, 0.f);
	}

}
*/
void Game::render()
{
	/*
	@return void

	-clear old frame
	-render objects
	-display frame in window

	Renders the game objects
	*/
	this->window->clear();

	//Draw game object
	this->window->draw(this->enemy);
	this->window->draw(this->player);
	this->window->display();
}
