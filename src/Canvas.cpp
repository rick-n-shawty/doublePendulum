#include <iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.hpp"
using std::cout; 

Canvas::Canvas(int width, int height){


    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10; 
    window.create(sf::VideoMode(width, height), "Pendulum", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);
    sf::Vector2u windowSize = window.getSize(); 

    view.setSize(sf::Vector2f(windowSize.x, windowSize.y));
    view.setCenter(sf::Vector2f(0,0));
    window.setView(view);




    circle.setRadius(10); 
    circle.setOrigin(sf::Vector2f(10,10));
    circle.setFillColor(sf::Color::White); 
    circle.setPosition(sf::Vector2f(-200,0));

};

Canvas::~Canvas(){};

void Canvas::handleEvents(){
    sf::Event event; 
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
    }
}
void Canvas::update(float dt){



}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    window.draw(circle);
    window.display();
}

void Canvas::run(){
    while(window.isOpen()){
        handleEvents();
        update(1); 
        render();
    }
}
