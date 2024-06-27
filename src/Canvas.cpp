#include <iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.hpp"
#include <cmath>
using std::cout; 

float ANGLE = -M_PI_2 / 2; 

Canvas::Canvas(int width, int height){
    pendulum = new Pendulum(ANGLE, 0, 200, 200, 10, 10);
    pendulum->setAngle(ANGLE);
    pendulum->load(G);

    sf::ContextSettings settings; 
    settings.antialiasingLevel = 15; 
    window.create(sf::VideoMode(width, height), "Pendulum", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize(); 

    view.setSize(sf::Vector2f(windowSize.x, windowSize.y));
    view.setCenter(sf::Vector2f(0,300));
    window.setView(view);
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
    pendulum->update(G, dt);
}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    pendulum->show(window);    
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
