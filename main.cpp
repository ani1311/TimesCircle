#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "functions.h"
#include <cmath>



int main()
{
	int p;
	int radius = 300;
	int noOfPoints = 500;
	double step = M_PI*2 / noOfPoints;
	int no = 3;

	sf::RenderWindow window(sf::VideoMode(800,800),"TimesCricle");
	sf::Color lineColor = sf::Color(0,0,255,10);
	drawPoints(window,step,radius);
	window.setFramerateLimit(100);
	while(window.isOpen())
	{
		sf::Event event;
		
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		// window.clear(sf::Color::White);
		drawLine(window,p,lineColor,step,noOfPoints,radius,no);
		if(p == noOfPoints)
		{
			p = 0;
			no = no + 1;
			lineColor.r = (lineColor.r + 100 )% 255;
			lineColor.g = (lineColor.g + 50 )% 255;
			lineColor.b = (lineColor.b + 200 )% 255;
			lineColor.a = (lineColor.a + 3 ) % 50; 
		}
		// p = (p + 1)%100
		p = p + 1;
		window.display();
	
	
	}
}