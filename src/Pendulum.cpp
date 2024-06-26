#include "Pendulum.hpp"


Pendulum::Pendulum(sf::Vector2f fixedPivot, float length, float radius) : lines(sf::LineStrip, 2){
    pivot = fixedPivot; 
    rodLength = length; 
    ball.setRadius(radius);
    ball.setFillColor(sf::Color::White);
    // lines.setPrimitiveType(sf::LinesStrip);
}; 

Pendulum::~Pendulum(){};