#include "Pendulum.hpp"


Pendulum::Pendulum(float angle1, float angle2, float L1 ,float L2, float r1, float r2){
    pivot = sf::Vector2f(0,0);
    lengthOne = L1; 
    lengthTwo = L2; 

    
    angleOne = angle1; 
    angleTwo = angle2; 


    radiusOne = r1; 
    radiusTwo = r2; 


    ballOne.setRadius(radiusOne);
    ballOne.setOrigin(sf::Vector2f(radiusOne, radiusOne));
    ballOne.setFillColor(sf::Color::White); 
    ballOne.setPosition(sf::Vector2f(lengthOne * sin(angleOne), lengthOne * cos(angleOne)));


    ballTwo.setRadius(radiusTwo);
    ballTwo.setOrigin(sf::Vector2f(radiusTwo, radiusTwo));
    ballTwo.setFillColor(sf::Color::White); 
    ballTwo.setPosition(sf::Vector2f(ballOne.getPosition().x + lengthTwo * sin(angleTwo), ballOne.getPosition().y + lengthTwo * cos(angleTwo)));


    lineOne = new Line(pivot, ballOne.getPosition());
    lineTwo = new Line(ballOne.getPosition(), ballTwo.getPosition());
}; 

Pendulum::~Pendulum(){
    if(lineOne != nullptr){
        delete lineOne; 
        lineOne = nullptr; 
    }
    if(lineTwo != nullptr){
        delete lineTwo; 
        lineTwo = nullptr;
    }
};