#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef LINE_HPP 
#define LINE_HPP 

class Line{
    private:
        float thickness = 2; 
        float length; 
        sf::RectangleShape line; 
    public: 
        Line(sf::Vector2f point1, sf::Vector2f point2); 
        ~Line();
        void show(sf::RenderWindow& window){
            window.draw(line); 
        }
};


#endif