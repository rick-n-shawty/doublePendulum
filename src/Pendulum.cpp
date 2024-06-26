#include "Pendulum.hpp"


Pendulum::Pendulum(float ballRadius, float length) : lines(sf::LineStrip, 2){
    pivot = sf::Vector2f(0,0);
    rodLength = length;


    float x = rodLength * sin(angle); 
    float y = rodLength * cos(angle);
    ball.setRadius(ballRadius);
    ball.setOrigin(sf::Vector2f(ballRadius, ballRadius));
    ball.setFillColor(sf::Color::White);
    ball.setPosition(sf::Vector2f(x, y));




    lines[0].position = pivot; 
    lines[0].color = sf::Color::Red;
    lines[1].position = ball.getPosition();
    lines[1].color = sf::Color::Red;
}; 

Pendulum::~Pendulum(){};