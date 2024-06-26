#include <SFML/Graphics.hpp>
#ifndef PENDULUM_HPP 
#define PENDULUM_HPP 

class Pendulum{
    private: 
        sf::CircleShape ball;
        sf::Vector2f pivot;
        float rodLength;
        sf::VertexArray lines; 
    public: 
        Pendulum(sf::Vector2f fixedPivot, float length, float radius); 
        ~Pendulum();
};

#endif 