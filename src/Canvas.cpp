#include <iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.hpp"
#include <cmath>
using std::cout; 

float ANGLE = -M_PI_2; 

Canvas::Canvas(int width, int height){
    pendulum = new Pendulum(10, 200);

    pendulum->setAngle(ANGLE);
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 15; 
    window.create(sf::VideoMode(width, height), "Pendulum", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize(); 

    view.setSize(sf::Vector2f(windowSize.x, windowSize.y));
    view.setCenter(sf::Vector2f(0,300));
    window.setView(view);




    circle.setRadius(10); 
    circle.setOrigin(sf::Vector2f(10,10));
    circle.setFillColor(sf::Color::White); 
    circle.setPosition(sf::Vector2f(-200,0));

};

Canvas::~Canvas(){
    if(pendulum != nullptr){
        delete pendulum; 
        pendulum = nullptr;
    }
};

void Canvas::handleEvents(){
    sf::Event event; 
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
    }
}
void Canvas::update(float dt){
    // float omega = sqrt(G / pendulum->getLength());
    // float dtheta_dt = - ANGLE * omega * sin(omega * dt);
    // float theta = pendulum->getAngle() + dtheta_dt; 
    // pendulum->setAngle(theta);
}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    window.draw(pendulum->getBallShape());
    window.draw(pendulum->getLines());
    window.display();
}

void Canvas::run(){
    while(window.isOpen()){
        float dt = clock.restart().asSeconds(); 
        handleEvents();
        update(dt); 
        render();
    }
}
