#include <iostream>
#include "Game.h"


//using namespace sf;

int main()
{
	//Init Game Engine
	Game game;
	/*Window(!!!its already in Game.cpp)
	sf::RenderWindow window(sf::VideoMode(800,600), "Game", sf::Style::Titlebar | sf::Style::Close);
	sf::Event ev;*/

	//Game Loop
	while (game.running())
	{
		//Update
		game.update();

		//Render
		game.render();

		/*/Move

		game.move();
	*/
	//End of the app
	}
	return 0;
}