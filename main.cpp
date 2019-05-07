#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Matrix.cpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(600,600), "My windows");
	
	bool updating = false;
	bool SpacePressed = true;

	window.setFramerateLimit(0);

	Matrix mat = Matrix(100,window);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				mat.setGrid(pos.x,pos.y);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && SpacePressed)
			{
				updating = !updating;
				SpacePressed = false;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				mat.getNbrs((int)(pos.x/mat.side),(int)(pos.y/mat.side));
			}
		}

		if(updating)
		{
			mat.update();
		}


		SpacePressed = true;

		window.clear(sf::Color::Black);
		mat.draw(window);
		window.display();
	}
}
