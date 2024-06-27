#include <SFML/Graphics.hpp>
#include "Line.hpp"
#ifndef PENDULUM_HPP 
#define PENDULUM_HPP 

class Pendulum{
    private: 
        sf::Vector2f pivot;

        // ballOne 
        sf::CircleShape ballOne; 
        sf::Vector2f ballOnePos; 
        float angleOne = 0;
        float lengthOne = 100;
        float radiusOne = 10;
        float massOne = 10; 
        Line* lineOne; 
        float velocityOne = 0; // angular
        float accelerationOne = 0; // angular
        // 

        // ballTwo
        sf::CircleShape ballTwo;  
        sf::Vector2f ballTwoPos;
        float angleTwo = 0;
        float lengthTwo = 100;
        float radiusTwo = 10; 
        float massTwo = 10; 
        Line* lineTwo;
        float velocityTwo = 0; // angular
        float accelerationTwo = 0; // angular
        //


    public: 
        Pendulum(float angle1, float angle2, float L1, float L2, float r1, float r2); 
        ~Pendulum();
        void update(const float& G, const float& dt){
            // float force = sin(angle) * G;
            // angleAccelaration = (-1 * force); 
            // angleVelocity += angleAccelaration; 
            // angle += angleVelocity; 

            // float x = sin(angle) * rodLength; 
            // float y = cos(angle) * rodLength; 
            // ball.setPosition(sf::Vector2f(x, y)); 
            // line->setLoosePoint(ball.getPosition());

        }
        void show(sf::RenderWindow& window){
            lineOne->show(window);
            lineTwo->show(window); 
            window.draw(ballOne); 
            window.draw(ballTwo);
        }
        void load(const float& G){
            // angleAccelaration = -1 * sin(angle) * G; 
            // angleVelocity += angleAccelaration;
        }

};

#endif 