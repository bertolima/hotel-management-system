#include "Screen.hpp"


//init 
void Screen::initVariables(){
    this->window = nullptr;
}

void Screen::initWindow(){
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Beauty Screen", sf::Style::Titlebar | sf::Style::Close);
}

//constructor and destructor
Screen::Screen(){
    this->initVariables();
    this->initWindow();

}
Screen::~Screen(){
    delete this->window;
}

//acess
const bool Screen::running() const{
    return this->window->isOpen();
}

void Screen::pollEvent(){
    //event polling
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape)
                    window->close();
                break;
        }
    }    
}

void Screen::update(){
    this->pollEvent();
}

void Screen::render(){
    //clear old frames
    //render objects
    //display frames in window
    //render game objects

    this->window->clear(sf::Color::White);

    //draw game objects

    this->window->display();
}





