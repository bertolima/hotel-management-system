#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef BUTTON_HPP
#define BUTTON_HPP

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button{
    private:
    short unsigned buttonState;


    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;



    public:
        //constructor and destructor
        Button(float x, float y, float width, float height,
        sf::Font* font, std::string text,
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
        ~Button();
        
        //acessors
        const bool isPressed() const;

        //functions
        void update(const sf::Vector2f mousePos);
        void render(sf::RenderTarget* target);
        void setPosition(float x, float y);
        float getLocalBounds();


};

#endif