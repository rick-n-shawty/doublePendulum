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
        float mass = 10; 
        float angleVelocity = 0; 
        float angleAccelaration = 0; 
    public: 
        Pendulum(float ballMass, float length); 
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
        float getAngularVel(){
            return angleVelocity; 
        }
        float getAngularAcc(){
            return angleAccelaration; 
        }
        void setAngularAcc(float num){
            angleAccelaration = num; 
        }
        void setAngularVel(float num){
            angleVelocity = num;
        }
        void update(const float& G, const float& dt){
            float force = sin(angle) * G;
            angleAccelaration = (-1 * force); 
            angleVelocity += angleAccelaration; 
            angle += angleVelocity; 

            float x = sin(angle) * rodLength; 
            float y = cos(angle) * rodLength; 
            ball.setPosition(sf::Vector2f(x, y)); 
            lines[1].position = ball.getPosition();

        }
        sf::CircleShape getBallShape(){
            return ball;
        }
        sf::VertexArray getLines(){
            return lines;
        }

        void load(const float& G){
            angleAccelaration = -1 * sin(angle) * G; 
            angleVelocity += angleAccelaration;
        }

};

#endif 