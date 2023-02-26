#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "cHotel.hpp"
#include "Button.hpp"
#include <string>
#include <map>


class Screen{
    private:
        //variables
        //window
        bool quit;
        bool start;
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;
        std::map<std::string, Button*> buttons;
        std::map<std::string, sf::Text*> texts;

        //hotel
        cHotel *hotel;

        //game objects
        
        sf::Font font;

        //mouse positions
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePositionFloat;

        //logic
        float spawnTextTime;


        //private functions
        void initVariables();
        void initWindow();
        void initFont();
        void initText();
        void initButtons();
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
        void updateButtons();
        void update();

        void renderButtons();
        void renderText();
        void render();
};