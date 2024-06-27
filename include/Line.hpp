#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef LINE_HPP 
#define LINE_HPP 

class Line{
    private:
        // line[0] is a pivot point 
        // line[1] is a loose point
        sf::VertexArray line; 
    public: 
        Line(sf::Vector2f point1, sf::Vector2f point2); 
        ~Line();
        void show(sf::RenderWindow& window){
            window.draw(line); 
        }
        void setColor(sf::Color color){
            line[0].color = color; 
            line[1].color = color;
        }
        void setPivotPoint(sf::Vector2f point){
            line[0].position = point;
        }
        void setLoosePoint(sf::Vector2f point){
            line[1].position = point;
        }
};


#endif