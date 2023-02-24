#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Screen{
    private:
        //variables
        //window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;

        //private functions
        void initVariables();
        void initWindow();
    public:
        //constructor and destructor
        Screen();
        virtual ~Screen();

        //acess
        const bool running() const;

        //functions
        void pollEvent();
        void update();
        void render();
};