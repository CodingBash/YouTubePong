#include <SFML/Graphics.hpp>
#include "Variables.h"
#include "Paddle.h"
#include "Ball.h"
#include <iostream>
#include <string>

void collision(Paddle&, Ball&);
bool score(Ball&);
void reset(Ball&, sf::Text&);
void start(Ball&);
int main()
{
	int score1=0;
	int score2=0;
	sf::Text windowScore;
	sf::Font font;
	if (!(font.loadFromFile("arial.ttf")))
		if(DEBUG)
			std::cout<< "Error loading font" <<std::endl;
	windowScore.setFont(font);
	windowScore.setString(std::to_string(score1) + " | " + std::to_string(score2));
	windowScore.setColor(sf::Color::White);
	windowScore.setCharacterSize(20);
	windowScore.setPosition(WIDTH/2 - (windowScore.getString().getSize()*(windowScore.getCharacterSize() / 5)), windowScore.getCharacterSize() - 5);
	windowScore.setStyle(sf::Text::Bold);
	Paddle paddle = Paddle(100, 10, 20 ,HEIGHT/2, 1 );
	Paddle paddle2 = Paddle(100, 10, WIDTH-20, HEIGHT/2,2);
	Ball puck = Ball(5, WIDTH/2 + 5, HEIGHT/2 + 5);
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong");
	window.setFramerateLimit(FRAMERATE);
    while (window.isOpen())
    {
		start(puck);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		window.clear();
		paddle.input();
		paddle2.input();
		puck.collides();
		collision(paddle, puck);
		collision(paddle2, puck);
		puck.move();
		if(score(puck))
			reset(puck, windowScore);
        window.draw(paddle.body);
		window.draw(paddle2.body);
		window.draw(puck.ball);
		window.draw(windowScore);
        window.display();
    }

    return 0;
}

void collision(Paddle& pad, Ball& puck){
	if(puck.ball.getPosition().x <= pad.body.getPosition().x+  pad.body.getSize().x &&
		puck.ball.getPosition().x >= pad.body.getPosition().x && puck.ball.getPosition().y <= pad.body.getPosition().y +  pad.body.getSize().y &&
		puck.ball.getPosition().y >= pad.body.getPosition().y){
		puck.velocity.x*=-1;
		
		if(puck.ball.getPosition().y<pad.body.getPosition().y+pad.body.getSize().y/3)
			puck.velocity.y = -10;
		else if(puck.ball.getPosition().y>pad.body.getPosition().y+pad.body.getSize().y-pad.body.getSize().y/3)
			puck.velocity.y = 10;
		else if(puck.velocity.y<0)
			puck.velocity.y = -5;
		else if(puck.velocity.y>0)
			puck.velocity.y=5;

	if(DEBUG)
		std::cout<<"HIT"<<std::endl;
	}
}
bool score(Ball& puck){
	if(puck.ball.getPosition().x>WIDTH){
		score1 +=1;
		return true;
	}
	if(puck.ball.getPosition().x<0){
		score2+=1;
		return true;
	}
	return false;
}

void reset(Ball& puck, sf::Text& text){
	puck.ball.setPosition(WIDTH/2 + 5, HEIGHT/2 + 5);
	puck.velocity.x = 0;
	puck.velocity.y = 0;
	text.setString(std::to_string(score1) + " | " + std::to_string(score2));
}

void start(Ball& puck){
	if(puck.velocity.x == 0 && puck.velocity.y == 0)
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
			puck.velocity.x = 10;
			if(score2 >score1)
				puck.velocity.x*=-1;
			puck.velocity.y= -5;
		}
}
