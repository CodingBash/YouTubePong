#ifndef GUARD_PADDLE_H
#define GUARD_PADDLE_H
#include <SFML\Graphics.hpp>
class Paddle{
	public:
	sf::RectangleShape body;
	int height;
	int width;
	int x;
	int y;
	int player;
	Paddle::Paddle(int height, int width, int x, int y, int player);
	void input();

};


#endif GUARD_PADDLE_H