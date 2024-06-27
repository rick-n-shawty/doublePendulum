#include <iostream>
#include <SFML/Graphics.hpp>
#include "Canvas.hpp"
#include <cmath>
#include <random>
using std::cout; 

float ANGLE = -M_PI_2; 


float randomFloat(float min, float max){
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribution(min, max);
    float randomFloat = distribution(gen);
    return randomFloat;
}


Canvas::Canvas(int width, int height, int pendulumsNum){
    initialAngleOne = randomFloat(-M_PI, M_PI); 
    initialAngleTwo = randomFloat(-M_PI, M_PI);
    deltaAngle = 0.01; 
    

    for(int i = 0; i < pendulumsNum; i++){
        pendulums.push_back(new Pendulum(initialAngleOne, initialAngleTwo, 200, 200, 5, 5));
        pendulums[i]->setBallColor(sf::Color::White);
        pendulums[i]->setRodColor(sf::Color::White);
        pendulums[i]->setTraceColor(sf::Color(0,71,171));

        initialAngleOne += deltaAngle; 
        initialAngleTwo += deltaAngle; 
    }


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
    for(int i = 0; i < pendulums.size(); i++){
        delete pendulums[i];
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
    for(int i = 0; i < pendulums.size(); i++){
        pendulums[i]->update(G, airDrag);
    }
}
void Canvas::render(){
    window.clear(sf::Color::Black); 
    for(int i = 0; i < pendulums.size(); i++){
        pendulums[i]->show(window);
    }
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
