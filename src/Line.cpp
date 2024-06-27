#include "Line.hpp"

Line::Line(sf::Vector2f point1, sf::Vector2f point2) : line(sf::LineStrip, 2){
    line[0].position = point1; 
    line[1].position = point2;    
}
Line::~Line(){}