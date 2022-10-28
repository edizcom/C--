#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
	Class that acts as the game engine.
	Wrapper class.
*/

class Game
{
private:
//Vars
//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	
	//Game objects
	sf::RectangleShape enemy;
	sf::RectangleShape player;

	//Private Functions
	void initVariables();
	void initWindow();
	void initEnemy(); 
	void initPlayer();
public:
//Constructors/Destructors
	Game();
	//~Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	//Functions
	void pollEvents();
	void update();
	void render();
	void move();

};

