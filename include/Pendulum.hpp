#include <SFML/Graphics.hpp>
#ifndef PENDULUM_HPP 
#define PENDULUM_HPP 

class Pendulum{
    private: 
        sf::CircleShape ball;
        sf::Vector2f pivot;
        sf::VertexArray lines;

        float rodLength = 100;
        float angle = 20;
    public: 
        Pendulum(float ballRadius, float length); 
        ~Pendulum();

        sf::CircleShape getBallShape(){
            return ball;
        }
        sf::VertexArray getLines(){
            return lines;
        }

};

#endif 