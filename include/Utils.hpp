#include <iostream>
#include <cmath> 
#include <SFML/Graphics.hpp>
#ifndef UTILS_HPP 
#define UTILS_HPP 

inline float getDist(const sf::Vector2f& A, const sf::Vector2f& B){
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
inline float getAngle(const sf::Vector2f& A, const sf::Vector2f& B){
    float dotProduct = (A.x * B.x) + (A.y * B.y); 
    float mag = sqrt( (pow(A.x, 2) + pow(A.y, 2)) * (pow(B.x, 2) + pow(B.y, 2)) );
    return (acos(dotProduct / mag));   
}

inline sf::Vector2f getMidPoint(const sf::Vector2f& A, const sf::Vector2f& B){
    return sf::Vector2f((A.x + B.x) / 2.0f, (A.y + B.y) / 2.0f);
}


#endif