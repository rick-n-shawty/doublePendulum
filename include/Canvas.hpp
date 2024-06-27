#include "Pendulum.hpp"
#include <SFML/Graphics.hpp> 
#include "Line.hpp"
#include <vector>
#ifndef CANVAS_HPP 
#define CANVAS_HPP 


class Canvas{
    private: 
        sf::RenderWindow window;
        sf::Clock clock; 
        sf::View view;
        std::vector<Pendulum*> pendulums; 

        void update(float dt); 
        void handleEvents(); 
        void render(); 


        const float G = 0.1;
        const float airDrag = 0.99; 
        float initialAngleOne = 0; 
        float initialAngleTwo = 0;
        float deltaAngle = 0;

    public: 
        Canvas(int width=1024, int height=1024, int pendulumsNum=1);
        ~Canvas(); 
        void run(); 
};
#endif 