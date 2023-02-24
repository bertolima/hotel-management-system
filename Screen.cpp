#include "Screen.hpp"


//init 
void Screen::initVariables(){
    this->window = nullptr;
    this->spawnTextTime = 2.f;
}

void Screen::initWindow(){
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Beauty Screen", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Screen::initText(){
    this->font.loadFromFile("./Atmosphier Notes.otf");
    this->start.setCharacterSize(40);
    this->start.setFillColor(sf::Color::Red);
    this->start.setFont(font);
    this->start.setString(hotel.getName());
}
//constructor and destructor
Screen::Screen(std::string m, int s, int r, int f){
    this->hotel.setName(m);
    this->hotel.setStars(s);
    this->hotel.setRoooms(r);
    this->hotel.setFloors(f);


    this->initVariables();
    this->initWindow();
    this->initText();

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

void Screen::updateMousePos(){
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Screen::updateText(){

}

void Screen::update(){
    this->pollEvent();
    this->updateMousePos();
    this->updateText();
}


void Screen::renderText(){

}
void Screen::render(){
    //clear old frames
    //render objects
    //display frames in window
    //render game objects

    this->window->clear();

    //draw game objects
    this->window->draw(this->start);


    this->window->display();
}





