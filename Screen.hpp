#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include "cHotel.hpp"
#include <string>


class Screen{
    private:
        //variables
        //window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;

        //hotel
        cHotel hotel;

        //game objects
        sf::Font font;
        sf::Text start;
        std::vector<sf::Text> texts;

        //mouse positions
        sf::Vector2i mousePosWindow;

        //logic
        float spawnTextTime;


        //private functions
        void initVariables();
        void initWindow();
        void initText();
    public:
        //constructor and destructor
        Screen(std::string, int, int, int);
        virtual ~Screen();

        //acess
        const bool running() const;

        //functions
        void spawText();
        void pollEvent();
        void updateMousePos();

        void updateText();
        void update();

        void renderText();
        void render();
};