#include <stdlib.h>
#include <SFML/Graphics.hpp>

class Matrix
{
public:
	int no,side;
	bool *grid;


	Matrix(int no,sf::RenderWindow &window)
	{
		int i,j,t;
		this->no = no;
		this->side = window.getSize().x/this->no;
		grid = new bool[no*no]{};

		for(i = 0 ; i < this->no ; i++)
		{
			for(j = 0 ; j < this->no ; j++)
			{
				if(rand()%100 < 50)
				{
					this->grid[i*no + j] = true;
				}
				else
				{
					this->grid[i*no + j] = false;
				}
			}
		}

	}

	void draw(sf::RenderWindow &window)
	{
		int i,j;
		sf::RectangleShape rect(sf::Vector2f((float)side,(float)side));
		for(i = 0 ; i < this->no ; i++)
		{
			for(j = 0 ; j < this->no ; j++ )
			{
				rect.setPosition(i*side,j*side);
				if(grid[i*no + j] == true)
				{
					rect.setFillColor(sf::Color(0,200,0));
				}
				else
				{
					rect.setFillColor(sf::Color(0,0,200));	
				}
				window.draw(rect);
			}
		}
	}

	void setGrid(int x,int y)
	{
		int i = (int) x / this->side;
		int j = (int) y / this->side;
		grid[i*no + j] = !grid[i*no + j];	
	}

	void makeCellAlive(int i,int j)
	{
		grid[i*no + j] = true;
	}

	int getNbrs(int p,int q)
	{
		int i,j;
		int ans = 0;
		int ti,tj;
		for(i = -1 ; i <= 1 ; i++)
		{
			for(j = -1 ; j <= 1 ; j++)
			{
				ti = p + i;
				tj = q + j;
				if(ti == -1)
					ti = this->no - 1;
				if(ti == this->no)
					ti = 0;
				if(tj == -1)
					tj = this->no - 1;
				if(tj == this->no)
					tj = 0;

				if(i == 0 && j == 0)
					continue;				

				if(this->grid[ti*no + tj] == true)
				{
					ans = ans + 1;
				}
			}
		}
		return ans;

	}

	void update()
	{
		bool *tempGrid;
		int i,j;
		int nbrs;
		tempGrid = new bool[this->no*this->no]{};

		for(i = 0 ; i < this->no ; i++)
		{
			for(j = 0 ; j < this->no ; j++)
			{
				tempGrid[i*no + j] = this->grid[i*no + j]; 
			}
		}

		for(i = 0 ; i < this->no ; i++)
		{
			for(j = 0 ; j < this->no ; j++)
			{
				nbrs = getNbrs(i,j);
				if(nbrs < 2 || nbrs >3)
				{
					tempGrid[i*no + j] = false;
				}
				else if(nbrs == 3)
				{
					tempGrid[i*no + j] = true;
				}
			}
		}

		for(i = 0 ; i < this->no ; i++)
		{
			for(j = 0 ; j < this->no ; j++)
			{
				this->grid[i*no + j] = tempGrid[i*no + j]; 
			}
		}
	}

};
