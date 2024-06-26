#include "Pendulum.hpp"
#include <SFML/Graphics.hpp> 
#ifndef CANVAS_HPP 
#define CANVAS_HPP 


class Canvas{
    private: 
        sf::RenderWindow window;
        sf::Clock clock; 
        sf::View view;
        sf::CircleShape circle; 
        Pendulum* pendulum;         

        void update(float dt); 
        void handleEvents(); 
        void render(); 


        const int timeSteps = 100; 
        const float G = 20;

    public: 
        Canvas(int width, int height);
        ~Canvas(); 
        void run(); 
};


#endif 