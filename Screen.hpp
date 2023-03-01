#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "cHotel.hpp"
#include "Button.hpp"
#include <string>
#include <map>
#include <utility>

enum write_states{WRITE_ZERO = 0, WRITE_FIRST,  WRITE_SECOND, WRITE_THIRD};
enum hotel_navigation{NAVIGATION_ZERO = 0, NAVIGATION_FIRST, NAVIGATION_SECOND, NAVIGATION_THIRD};
enum hotel_state{HOTEL_ZERO=0, HOTEL_FIRST, HOTEL_SECOND};



class Screen{
    private:
        //on screen variables
        std::map<std::string, Button*> buttons;
        std::map<std::string, Button*> nav_buttons;
        std::map<std::string, sf::Text*> texts;
        std::map<std::string, sf::Text*> boxTexts;
        std::map<std::string, sf::Text*> posMenuTexts;
        std::map<std::string, sf::Text*> hotel_infos;
        std::vector<std::pair<int, cHotel*>> hotel_days;
        sf::RectangleShape miniScreen;
        sf::RectangleShape miniScreen2;
        std::string hotel_name, hotel_star, hotel_room, hotel_floor;
        sf::RectangleShape quad;
        std::string dayCount;
        int count;

        //control variables
        bool quadColor;
        bool quit;
        bool start;
        bool menu;
        short unsigned write_state;

        //window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;
        sf::Clock* clock;
        
        //main TAD
        cHotel *hotel;
        
        //used fonts
        sf::Font font;

        //mouse positions variables
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePositionFloat;


        //private functions
        void initVariables();
        void initWindow();
        void initFont();
        void initText();
        void initButtons();
        void initQuad();
        void initHotel();


    public:
        //constructor and destructor
        Screen();
        virtual ~Screen();

        //acess
        const bool running() const;

        //functions
        void pollEvent();
        void updateMousePos();

        void updateTextPollEvent();
        void updateText();
        void updateQuad();
        void updateButtons();
        void updateHotel();
        void updateDay();
        void update();

        void renderButtons();
        void renderText();
        void renderQuad();
        void renderHotel();
        void renderMScreen();
        void render();
};