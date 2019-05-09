#include "functions.h"



void drawPoints(sf::RenderWindow &window,double step,int radius)
{
	int radiusOfPoint = 1;
	double i;
	int t1;
	int p;
	for(i = 0 ; i <= 2*M_PI ; i = i + step)
	{
		sf::CircleShape circle((float)radiusOfPoint);
		circle.setFillColor(sf::Color::Black);
		circle.setPosition(window.getSize().x/2 + radius*cos(i),window.getSize().y/2 + radius*sin(i));
		window.draw(circle);	
		t1 = t1 + 1;
	}
}

void drawLine(sf::RenderWindow &window,int p,sf::Color c,double step,int noOfPoints,int radius,int no)
{
	sf::Vertex line[2];
	line[0] = sf::Vertex(sf::Vector2f(window.getSize().x/2 + radius*cos(p*step),window.getSize().y/2 + radius*sin(p*step)) ,c); 
	line[1] = sf::Vertex(sf::Vector2f(window.getSize().x/2 + radius*cos(((p*no)%noOfPoints)*step),window.getSize().y/2 + radius*sin(((p*no)%noOfPoints)*step)),c);
	window.draw(line,2,sf::Lines);
}