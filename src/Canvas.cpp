#include <iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.hpp"
#include <cmath>
using std::cout; 

float ANGLE = -M_PI_2; 

Canvas::Canvas(int width, int height){
    pendulum = new Pendulum(ANGLE, M_PI_2, 200, 200, 5, 5);
    pendulum->setRodColor(sf::Color(0,128,128));
    pendulum->setBallColor(sf::Color(255,236,209));
    pendulum->setTraceColor(sf::Color(128,0,32));


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

    for(int i = 0; i < pendulums.size(); i++){
        if(pendulums[i] != nullptr){
            delete pendulums[i];
            pendulums[i] = nullptr;
        }
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
