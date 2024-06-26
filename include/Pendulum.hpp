#include <SFML/Graphics.hpp>
#ifndef PENDULUM_HPP 
#define PENDULUM_HPP 

class Pendulum{
    private: 
        sf::CircleShape ball;
        sf::Vector2f pivot;
        sf::VertexArray lines;

        float rodLength = 100;
        float angle = 0;
    public: 
        Pendulum(float ballRadius, float length); 
        ~Pendulum();
        void setAngle(float a){
            angle = a; 
            float x = rodLength * sin(angle); 
            float y = rodLength * cos(angle); 
            ball.setPosition(sf::Vector2f(x, y));
            lines[1].position = ball.getPosition();
        }
        float getAngle(){
            return angle; 
        }
        float getLength(){
            return rodLength;
        }
        sf::CircleShape getBallShape(){
            return ball;
        }
        sf::VertexArray getLines(){
            return lines;
        }

};

#endif 