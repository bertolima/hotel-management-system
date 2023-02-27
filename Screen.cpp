#include "Screen.hpp"

//init 
void Screen::initVariables(){
    this->window = nullptr;
    this->spawnTextTime = 2.f;
    this->quit = false;
    this->start = false;
    this->menu = true;
    this->att_hotel_infos = false;
    this->cont = 0;
 
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
    if (this->start == true){
    this->texts["WRITE_HOTEL_NAME"] = new sf::Text("Write Hotel Name: ", this->font, 25);
    this->texts["WRITE_HOTEL_STAR"] = new sf::Text("How many stars have?: ", this->font, 25);
    this->texts["WRITE_HOTEL_ROOMS"] = new sf::Text("How many rooms per floor? ", this->font, 25);
    this->texts["WRITE_HOTEL_FLOORS"] = new sf::Text("How many floors? ", this->font, 25);

    this->texts["WRITE_HOTEL_NAME"]->setPosition(100, 100);
    this->texts["WRITE_HOTEL_NAME"]->setFillColor(sf::Color::Green);
    this->texts["WRITE_HOTEL_STAR"]->setPosition(100, 200);
    this->texts["WRITE_HOTEL_STAR"]->setFillColor(sf::Color::Green);
    this->texts["WRITE_HOTEL_ROOMS"]->setPosition(100, 300);
    this->texts["WRITE_HOTEL_ROOMS"]->setFillColor(sf::Color::Green);
    this->texts["WRITE_HOTEL_FLOORS"]->setPosition(100, 400);
    this->texts["WRITE_HOTEL_FLOORS"]->setFillColor(sf::Color::Green);

    this->boxTexts["HOTEL_NAME"] = new sf::Text(this->hotel_name, this->font, 25);
    this->boxTexts["HOTEL_NAME"]->setPosition(texts["WRITE_HOTEL_NAME"]->getPosition().x + texts["WRITE_HOTEL_NAME"]->getGlobalBounds().width,texts["WRITE_HOTEL_NAME"]->getPosition().y);
    this->boxTexts["HOTEL_NAME"]->setFillColor(sf::Color::Red);

    this->boxTexts["HOTEL_STAR"] = new sf::Text(this->hotel_star, this->font, 25);
    this->boxTexts["HOTEL_STAR"]->setPosition(texts["WRITE_HOTEL_STAR"]->getPosition().x + texts["WRITE_HOTEL_STAR"]->getGlobalBounds().width,texts["WRITE_HOTEL_STAR"]->getPosition().y);
    this->boxTexts["HOTEL_STAR"]->setFillColor(sf::Color::Red);

    this->boxTexts["HOTEL_ROOM"] = new sf::Text(this->hotel_room, this->font, 25);
    this->boxTexts["HOTEL_ROOM"]->setPosition(texts["WRITE_HOTEL_ROOMS"]->getPosition().x + texts["WRITE_HOTEL_ROOMS"]->getGlobalBounds().width,texts["WRITE_HOTEL_ROOMS"]->getPosition().y);
    this->boxTexts["HOTEL_ROOM"]->setFillColor(sf::Color::Red);

    this->boxTexts["HOTEL_FLOOR"] = new sf::Text(this->hotel_floor, this->font, 25);
    this->boxTexts["HOTEL_FLOOR"]->setPosition(texts["WRITE_HOTEL_FLOORS"]->getPosition().x + texts["WRITE_HOTEL_FLOORS"]->getGlobalBounds().width,texts["WRITE_HOTEL_FLOORS"]->getPosition().y);
    this->boxTexts["HOTEL_FLOOR"]->setFillColor(sf::Color::Red);

    this->posMenuTexts["HOTEL"] = new sf::Text("Hotel: ", this->font, 25);
    this->posMenuTexts["STARS"] = new sf::Text("Stars: ", this->font, 25);
    this->posMenuTexts["ROOMS"] = new sf::Text("Rooms: ", this->font, 25);
    this->posMenuTexts["FLOORS"] = new sf::Text("Flooors: ", this->font, 25);

    this->posMenuTexts["HOTEL"]->setPosition(10, 15);
    this->posMenuTexts["HOTEL"]->setFillColor(sf::Color::Green);
    this->posMenuTexts["STARS"]->setPosition(220, 15);
    this->posMenuTexts["STARS"]->setFillColor(sf::Color::Green);
    this->posMenuTexts["ROOMS"]->setPosition(340, 15);
    this->posMenuTexts["ROOMS"]->setFillColor(sf::Color::Green);
    this->posMenuTexts["FLOORS"]->setPosition(460, 15);
    this->posMenuTexts["FLOORS"]->setFillColor(sf::Color::Green);
    }
}

void Screen::initButtons(){
    this->buttons["SIMULATION_STATE"] = new Button(320, 100, 150, 50,
    &this->font, "Start Simulation",
     sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

    this->buttons["EXIT_STATE"] = new Button(320, 300, 150, 50,
    &this->font, "Quit",
     sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
}

void Screen::initHotel(){
    if (this->menu == false){
        int star = std::stoi(this->hotel_star);
        int room = std::stoi(this->hotel_room);
        int floor = std::stoi(this->hotel_floor);
        this->hotel = new cHotel(hotel_name, star, room, floor);
    }


}

//constructor and destructor
Screen::Screen(){

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

        this->updateTextPollEvent();
        
    }    
}

void Screen::updateMousePos(){
    this->mousePosWindow = sf::Mouse::getPosition();
    mousePositionFloat = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}



void Screen::update(){
    this->pollEvent();
    this->updateMousePos();
    this->updateButtons();
    this->initText();
    this->updateText();
    this->initHotel();

    if (quit == true) this->window->close();
    
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

    if (this->menu == false){
        this->buttons["EXIT_STATE"]->setPosition(this->window->getSize().x - 10 -this->buttons["EXIT_STATE"]->getLocalBounds(), 10);
    }

}

void Screen::updateTextPollEvent(){
    if (start == true){
            if (this->ev.type == sf::Event::TextEntered){
                if (this->ev.text.unicode == 13){
                    this->cont++;
                    if (this->cont == 4) this->menu = false;
                    
                } 

                if (((this->ev.text.unicode > 64 && this->ev.text.unicode < 91) || (this->ev.text.unicode > 96 && this->ev.text.unicode < 123) || this->ev.text.unicode == 32) && this->cont == 0 && hotel_name.size() < 10)
                    {this->hotel_name.push_back(static_cast<char>(this->ev.text.unicode));
                    }
                else if ((!(this->hotel_name.empty())) && this->ev.text.unicode == 8 && this->cont == 0){
                    this->hotel_name.pop_back();
                    std::cout << this->hotel_name;
                }
        


                if((this->ev.text.unicode > 47 && this->ev.text.unicode < 54) && this->cont == 1 && hotel_star.size() < 1)
                    this->hotel_star.push_back(static_cast<char>(this->ev.text.unicode));
                else if (!(this->hotel_star.empty()) && this->ev.text.unicode == 8 && this->cont == 1)
                    this->hotel_star.pop_back();


                if ((this->ev.text.unicode > 47 && this->ev.text.unicode < 58) && this->cont == 2 && hotel_room.size() < 2)
                    this->hotel_room.push_back(static_cast<char>(this->ev.text.unicode));
                else if (!(this->hotel_room.empty()) && this->ev.text.unicode == 8 && this->cont == 2)
                    this->hotel_room.pop_back();

                        
                if ((this->ev.text.unicode > 47 && this->ev.text.unicode < 58) && this->cont == 3)
                    this->hotel_floor.push_back(static_cast<char>(this->ev.text.unicode));
                else if (!(this->hotel_floor.empty()) && this->ev.text.unicode == 8 && this->cont == 3 && hotel_floor.size() < 2)
                    this->hotel_floor.pop_back();
            }       

        }

}

void Screen::updateText(){

        if (menu == false){
            this->boxTexts["HOTEL_NAME"]->setPosition(this->posMenuTexts["HOTEL"]->getPosition().x + this->posMenuTexts["HOTEL"]->getGlobalBounds().width,this->posMenuTexts["HOTEL"]->getPosition().y);
            this->boxTexts["HOTEL_STAR"]->setPosition(this->posMenuTexts["STARS"]->getPosition().x + this->posMenuTexts["STARS"]->getGlobalBounds().width,this->posMenuTexts["STARS"]->getPosition().y);
            this->boxTexts["HOTEL_ROOM"]->setPosition(this->posMenuTexts["ROOMS"]->getPosition().x + this->posMenuTexts["ROOMS"]->getGlobalBounds().width,this->posMenuTexts["ROOMS"]->getPosition().y);
            this->boxTexts["HOTEL_FLOOR"]->setPosition(this->posMenuTexts["FLOORS"]->getPosition().x + this->posMenuTexts["FLOORS"]->getGlobalBounds().width,this->posMenuTexts["FLOORS"]->getPosition().y);
        }



}

void Screen::renderButtons(){
    if (start == false){
        for (auto &it : this->buttons){
            it.second->render(this->window);
        }
    }
    else if(menu == false){
        this->buttons["EXIT_STATE"]->render(this->window);
        
    }
}
void Screen::renderText(){
        if(menu == true){
            for (auto &it : this->texts){
                this->window->draw(*it.second);
            }

            for (auto &it : this->boxTexts){
                this->window->draw(*it.second);
            }
        }

        if(menu == false){
            for (auto &it : this->posMenuTexts){
                this->window->draw(*it.second);
            }
            for (auto &it : this->boxTexts){
                this->window->draw(*it.second);
            }

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





