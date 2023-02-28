#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "cHotel.hpp"
#include "Button.hpp"
#include <string>
#include <map>

enum write_states{WRITE_ZERO = 0, WRITE_FIRST,  WRITE_SECOND, WRITE_THIRD};



class Screen{
    private:
        //variables
        std::map<std::string, Button*> buttons;
        std::map<std::string, sf::Text*> texts;
        std::map<std::string, sf::Text*> boxTexts;
        std::map<std::string, sf::Text*> posMenuTexts;
        std::string hotel_name, hotel_star, hotel_room, hotel_floor;
        sf::RectangleShape quad;
        bool quadColor;
        int cont;
        bool quit;
        bool start;
        bool menu;
        short unsigned write_state;

        //window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;
        sf::Clock* clock;
        
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
        void initQuad();
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
        void updateQuad();
        void updateButtons();
        void update();

        void renderButtons();
        void renderText();
        void renderQuad();
        void render();
};