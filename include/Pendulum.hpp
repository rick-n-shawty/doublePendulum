#include <SFML/Graphics.hpp>
#include "Line.hpp"
#ifndef PENDULUM_HPP 
#define PENDULUM_HPP 

class Pendulum{
    private: 
        sf::Vector2f pivot;
        sf::VertexArray trace;
        sf::Color traceColor;

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

            float num1, num2, num3, num4, denom; 

            num1 = -G * (2 * massOne + massTwo) * sin(angleOne);
            num2 = - massTwo * G * sin(angleOne -2 * angleTwo); 
            num3 = -2 * sin(angleOne - angleTwo) * massTwo; 
            num4 = pow(velocityTwo, 2) * lengthTwo + pow(velocityOne, 2) * lengthOne * cos(angleOne - angleTwo); 
            denom = lengthOne * (2 * massOne + massTwo - massTwo * cos(2 * angleOne - 2 * angleTwo));
            accelerationOne = (num1 + num2 + num3 * num4) / denom;


            num1 = 2 * sin(angleOne - angleTwo); 
            num2 = pow(velocityOne, 2) * lengthOne * (massOne + massTwo); 
            num3 = G * (massOne + massTwo) * cos(angleOne); 
            num4 = pow(velocityTwo, 2) * lengthTwo * massTwo * cos(angleOne - angleTwo);
            denom = lengthTwo * (2 * massOne + massTwo - massTwo * cos(2 * angleOne - 2 * angleTwo));
            accelerationTwo = num1 * (num2 + num3 + num4) / denom;


            velocityOne += accelerationOne; 
            velocityTwo += accelerationTwo; 


            angleOne += velocityOne; 
            angleTwo += velocityTwo; 


            ballOne.setPosition(sf::Vector2f(lengthOne * sin(angleOne), lengthOne * cos(angleOne)));
            lineOne->setLoosePoint(ballOne.getPosition());

            ballTwo.setPosition(sf::Vector2f(ballOne.getPosition().x + sin(angleTwo) * lengthTwo, ballOne.getPosition().y + cos(angleTwo) * lengthTwo));
            lineTwo->setPivotPoint(ballOne.getPosition());
            lineTwo->setLoosePoint(ballTwo.getPosition());

            trace.append(sf::Vertex(ballTwo.getPosition(), traceColor));
        }
        void show(sf::RenderWindow& window){
            lineOne->show(window);
            lineTwo->show(window); 
            window.draw(ballOne); 
            window.draw(ballTwo);
            window.draw(trace);
        }

};

#endif 