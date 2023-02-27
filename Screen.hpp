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
        std::map<std::string, Button*> buttons;
        std::map<std::string, sf::Text*> texts;
        std::map<std::string, sf::Text*> boxTexts;
        std::map<std::string, sf::Text*> posMenuTexts;
        std::string hotel_name, hotel_star, hotel_room, hotel_floor;
        int cont;
        bool quit;
        bool start;
        bool menu;
        bool att_hotel_infos;

        //window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;
        
        //hotel
        cHotel *hotel;
        
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
        void initHotel();
    public:
        //constructor and destructor
        Screen();
        virtual ~Screen();

        //acess
        const bool running() const;

        //functions
        void spawText();
        void pollEvent();
        void updateMousePos();

        void updateTextPollEvent();
        void updateText();
        void updateButtons();
        void update();

        void renderButtons();
        void renderText();
        void render();
};