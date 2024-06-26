#include <SFML/Graphics.hpp> 
#ifndef CANVAS_HPP 
#define CANVAS_HPP 


class Canvas{
    private: 
        sf::RenderWindow window; 
        sf::View view;
        sf::CircleShape circle; 
        void update(float dt); 
        void handleEvents(); 
        void render(); 


    public: 
        Canvas(int width, int height);
        ~Canvas(); 
        void run(); 
};


#endif 