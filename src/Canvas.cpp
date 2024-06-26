#include <iostream>
#include "Canvas.hpp"
using std::cout; 

Canvas::Canvas(int width, int height){
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10; 
    sf::View view(sf::Vector2f(width / 2.0f, height / 2.0f), sf::Vector2f(width, height));
    window.create(sf::VideoMode(width, height), "Pendulum", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setView(view);

    window.setFramerateLimit(60);
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

    window.display();
}

void Canvas::run(){
    while(window.isOpen()){
        handleEvents();
        update(1); 
        render();
    }
}
