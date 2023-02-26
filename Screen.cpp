#include "Screen.hpp"

//init 
void Screen::initVariables(){
    this->window = nullptr;
    this->spawnTextTime = 2.f;
    this->quit = false;
    this->start = false;
 
}

void Screen::initWindow(){
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Beauty Screen", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Screen::initFont(){
    this->font.loadFromFile("./fonts/MANDORS.otf");
}

void Screen::initText(){
    this->texts["HOTEL_NAME"] = new sf::Text("Hotel name: ", this->font, 15);
    this->texts["HOTEL_NAME"]->setPosition(0,0);
    this->texts["HOTEL_NAME"]->setFillColor(sf::Color::Red);
}

void Screen::initButtons(){
    this->buttons["SIMULATION_STATE"] = new Button(320, 100, 150, 50,
    &this->font, "Start Simulation",
     sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

    this->buttons["EXIT_STATE"] = new Button(320, 300, 150, 50,
    &this->font, "Quit",
     sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
}


//constructor and destructor
Screen::Screen(std::string m, int s, int r, int f){
    // this->hotel->setName(m);
    // this->hotel->setStars(s);
    // this->hotel->setRoooms(r);
    // this->hotel->setFloors(f);


    this->initVariables();
    this->initWindow();
    this->initFont();
    this->initButtons();

}
Screen::~Screen(){
    delete this->window;
}

//access
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
    this->mousePosWindow = sf::Mouse::getPosition();
    mousePositionFloat = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}



void Screen::update(){
    this->pollEvent();
    this->updateMousePos();
    this->updateText();
    this->updateButtons();

    if (quit == true) this->window->close();
    if (start == true) this->initText();
}



void Screen::updateButtons(){

    for (auto &it : this->buttons){
        it.second->update(this->mousePositionFloat);
    }

    if (this->buttons["EXIT_STATE"]->isPressed()){
        this->quit = true;
    }

    if (this->buttons["SIMULATION_STATE"]->isPressed()){
        this->start = true;
    }

}

void Screen::updateText(){
    

}

void Screen::renderButtons(){

    for (auto &it : this->buttons){
        it.second->render(this->window);
    }
}
void Screen::renderText(){
    for (auto &it : this->texts){
        this->window->draw(*it.second);
    }

}
void Screen::render(){
    //clear old frames
    //render objects
    //display frames in window
    //render game objects

    this->window->clear();

    //draw game objects
    // this->window->draw(this->start);
    this->renderButtons();
    this->renderText();
    
    this->window->display();
}





