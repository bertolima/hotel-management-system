#include "Screen.hpp"

//init controls variables
void Screen::initVariables(){
    this->window = nullptr;
    this->quit = false;
    this->start = false;
    this->menu = true;
    this->quadColor = false;
    this->write_state = WRITE_ZERO;
    this->hotel_print = HOTEL_ZERO;
    this->count = 0;
}

//init window
void Screen::initWindow(){
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Beauty Screen", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    this->clock = new sf::Clock;
    
    this->miniScreen.setSize(sf::Vector2f(650, 350));
    this->miniScreen.setPosition(sf::Vector2f((this->window->getSize().x - this->miniScreen.getGlobalBounds().width)/2.f, window->getSize().y - this->miniScreen.getGlobalBounds().height - 135.f));
    this->miniScreen.setFillColor(sf::Color(135, 135, 135));
    this->miniScreen2.setSize(sf::Vector2f(660, 360));
    this->miniScreen2.setPosition(sf::Vector2f((this->window->getSize().x - this->miniScreen.getGlobalBounds().width)/2.f -5, window->getSize().y - this->miniScreen.getGlobalBounds().height - 140.f));
    this->miniScreen2.setFillColor(sf::Color::White);

}

//init used fonts
void Screen::initFont(){
    this->font.loadFromFile("./fonts/MANDORS.otf");
}

//init all texts
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
    this->posMenuTexts["DAY"] = new sf::Text("Day: ", this->font, 25);
    this->posMenuTexts["DAYCOUNT"] = new sf::Text(this->dayCount, this->font, 25);

    this->posMenuTexts["HOTEL"]->setPosition(10, 15);
    this->posMenuTexts["HOTEL"]->setFillColor(sf::Color::Green);
    this->posMenuTexts["STARS"]->setPosition(220, 15);
    this->posMenuTexts["STARS"]->setFillColor(sf::Color::Green);
    this->posMenuTexts["ROOMS"]->setPosition(340, 15);
    this->posMenuTexts["ROOMS"]->setFillColor(sf::Color::Green);
    this->posMenuTexts["FLOORS"]->setPosition(460, 15);
    this->posMenuTexts["FLOORS"]->setFillColor(sf::Color::Green);
    this->posMenuTexts["DAY"]->setPosition(10, 70);
    this->posMenuTexts["DAY"]->setFillColor(sf::Color::Green);
    this->posMenuTexts["DAYCOUNT"]->setPosition(this->posMenuTexts["DAY"]->getPosition().x + this->posMenuTexts["DAY"]->getGlobalBounds().width, 70);
    this->posMenuTexts["DAYCOUNT"]->setFillColor(sf::Color::Red);

    }
}

//init all buttons
void Screen::initButtons(){
    this->buttons["SIMULATION_STATE"] = new Button(320, 100, 150, 50,
    &this->font, "Start Simulation",
     sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

    this->buttons["EXIT_STATE"] = new Button(320, 300, 150, 50,
    &this->font, "Quit",
     sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));


    this->nav_buttons["PREVIOUS_BNT"]= new Button(150, 480, 150, 50,
    &this->font, "Previous",
     sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
     
    this->nav_buttons["NEXT_BNT"]= new Button(460, 480, 150, 50,
    &this->font, "Next",
     sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

    
}

//init quad shapes
void Screen::initQuad(){
    if (start==true){

        this->quad.setSize({20.f, 20.f});
        this->quad.setPosition(texts["WRITE_HOTEL_NAME"]->getGlobalBounds().left - this->quad.getSize().x - 5, texts["WRITE_HOTEL_NAME"]->getPosition().y + 10);
    }
}

//init main TAD
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

//on screen events
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

//get mouse positions on screen
void Screen::updateMousePos(){
    this->mousePosWindow = sf::Mouse::getPosition();
    mousePositionFloat = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

//update variables and methods
void Screen::update(){
    this->pollEvent();
    this->updateMousePos();
    this->updateButtons();
    this->updateText();
    this->updateQuad();
    this->updateDay();


    if (quit == true) this->window->close();
    
}

//update button states 
void Screen::updateButtons(){

    for (auto &it : this->buttons){
        it.second->update(this->mousePositionFloat);
    }

    for (auto &it : this->nav_buttons){
        it.second->update(this->mousePositionFloat);
    }

    if (this->buttons["EXIT_STATE"]->isPressed()){
        this->quit = true;
    }

    if (this->buttons["SIMULATION_STATE"]->isPressed()){
        this->start = true;
        this->initText();
        this->initQuad();
    }
    if(this->clock->getElapsedTime().asMilliseconds() >= 500.f){
        if (this->nav_buttons["PREVIOUS_BNT"]->isPressed()){
            if (this->count > 1){
                this->count--;
                this->hotel_print = HOTEL_FIRST;
                
                this->posMenuTexts["DAYCOUNT"]->setString(std::to_string(this->count));
                this->clock->restart();
            }
        }
    }

    if(this->clock->getElapsedTime().asMilliseconds() >= 500.f){
        if(this->nav_buttons["NEXT_BNT"]->isPressed()){
            this->count++;
            if(this->count-1 == hotel_days.size())
                this->updateHotel();
            if (this->hotel_days.size() > 0){
                this->hotel_print = HOTEL_FIRST;
                
            }
            this->posMenuTexts["DAYCOUNT"]->setString(std::to_string(this->count));
            this->clock->restart();
        }
    }
}

//update input user text
void Screen::updateTextPollEvent(){
    if (start == true){
            if (this->ev.type == sf::Event::TextEntered){
                if (this->ev.text.unicode == 13){
                    switch(write_state){
                        case WRITE_ZERO:
                            write_state = WRITE_FIRST;
                            break;
                        case WRITE_FIRST:
                            write_state = WRITE_SECOND;
                            break;
                        case WRITE_SECOND:
                            write_state = WRITE_THIRD;
                            break;
                        case WRITE_THIRD:
                            this->menu = false;
                            this->clock->restart();
                            this->initHotel();
                            this->buttons["EXIT_STATE"]->setPosition(this->window->getSize().x - 10 -this->buttons["EXIT_STATE"]->getLocalBounds(), 10);
                            this->write_state = -1;
                            break;
                        default:
                            break;   
                    }
                }
                switch(write_state){
                    case WRITE_ZERO:
                        if (((this->ev.text.unicode > 64 && this->ev.text.unicode < 91) || (this->ev.text.unicode > 96 && this->ev.text.unicode < 123) || this->ev.text.unicode == 32) && hotel_name.size() < 10)
                            this->hotel_name.push_back(static_cast<char>(this->ev.text.unicode));
                        else if ((!(this->hotel_name.empty())) && this->ev.text.unicode == 8)
                            this->hotel_name.pop_back();
                        break;
                    case WRITE_FIRST:
                        if((this->ev.text.unicode > 47 && this->ev.text.unicode < 54) && hotel_star.size() < 1)
                            this->hotel_star.push_back(static_cast<char>(this->ev.text.unicode));
                        else if (!(this->hotel_star.empty()) && this->ev.text.unicode == 8)
                            this->hotel_star.pop_back();
                        break;
                    case WRITE_SECOND:
                        if ((this->ev.text.unicode > 47 && this->ev.text.unicode < 58) && hotel_room.size() < 2)
                            this->hotel_room.push_back(static_cast<char>(this->ev.text.unicode));
                        else if (!(this->hotel_room.empty()) && this->ev.text.unicode == 8)
                            this->hotel_room.pop_back();
                        break;
                    case WRITE_THIRD:
                        if ((this->ev.text.unicode > 47 && this->ev.text.unicode < 58) && hotel_floor.size() < 2) 
                            this->hotel_floor.push_back(static_cast<char>(this->ev.text.unicode));
                        else if (!(this->hotel_floor.empty()) && this->ev.text.unicode == 8)
                            this->hotel_floor.pop_back();
                        break;
                    default:
                        break;
                }         
                
            }       

        }
        if(!( this->boxTexts.empty())){
            this->boxTexts["HOTEL_NAME"]->setString(hotel_name);
            this->boxTexts["HOTEL_STAR"]->setString(hotel_star);
            this->boxTexts["HOTEL_ROOM"]->setString(hotel_room);
            this->boxTexts["HOTEL_FLOOR"]->setString(hotel_floor);
        }


}

//update text location etc
void Screen::updateText(){

        if (menu == false){
            this->boxTexts["HOTEL_NAME"]->setPosition(this->posMenuTexts["HOTEL"]->getPosition().x + this->posMenuTexts["HOTEL"]->getGlobalBounds().width,this->posMenuTexts["HOTEL"]->getPosition().y);
            this->boxTexts["HOTEL_STAR"]->setPosition(this->posMenuTexts["STARS"]->getPosition().x + this->posMenuTexts["STARS"]->getGlobalBounds().width,this->posMenuTexts["STARS"]->getPosition().y);
            this->boxTexts["HOTEL_ROOM"]->setPosition(this->posMenuTexts["ROOMS"]->getPosition().x + this->posMenuTexts["ROOMS"]->getGlobalBounds().width,this->posMenuTexts["ROOMS"]->getPosition().y);
            this->boxTexts["HOTEL_FLOOR"]->setPosition(this->posMenuTexts["FLOORS"]->getPosition().x + this->posMenuTexts["FLOORS"]->getGlobalBounds().width,this->posMenuTexts["FLOORS"]->getPosition().y);
        }



}

//update quad shape locations
void Screen::updateQuad(){
    if (menu == true){
        switch(write_state){
            case WRITE_ZERO:
                break;
            case WRITE_FIRST:
                this->quad.setPosition(texts["WRITE_HOTEL_STAR"]->getGlobalBounds().left - this->quad.getSize().x - 5, texts["WRITE_HOTEL_STAR"]->getPosition().y + 10);
                break;
            case WRITE_SECOND:
                this->quad.setPosition(texts["WRITE_HOTEL_ROOMS"]->getGlobalBounds().left - this->quad.getSize().x - 5, texts["WRITE_HOTEL_ROOMS"]->getPosition().y + 10);
                break; 
            case WRITE_THIRD:
                this->quad.setPosition(texts["WRITE_HOTEL_FLOORS"]->getGlobalBounds().left - this->quad.getSize().x - 5, texts["WRITE_HOTEL_FLOORS"]->getPosition().y + 10);
                break;
            default:
                this->quad.setPosition(texts["WRITE_HOTEL_NAME"]->getGlobalBounds().left - this->quad.getSize().x - 5, texts["WRITE_HOTEL_NAME"]->getPosition().y + 10);
                break;


        }

        if(this->clock->getElapsedTime().asSeconds() >= 1.f){
                if (this->quadColor == false){
                    this->quad.setFillColor(sf::Color::Black);
                    this->quadColor = true;
                }
                else{
                    this->quad.setFillColor(sf::Color::White);
                    this->quadColor = !this->quadColor;
                    
                }
                this->clock->restart();
        }
    }
}

//update hotel infos
void Screen::updateHotel(){
    if (menu == false){
        this->hotel->queueFill(10);
        this->hotel->allocate();
        this->hotel_days.push_back(std::make_pair(this->count, this->hotel));
    }
}

//update days
void Screen::updateDay(){


}

//render all buttons
void Screen::renderButtons(){
    if (start == false){
        for (auto &it : this->buttons){
            it.second->render(this->window);
        }
    }
    else if(menu == false){
        this->buttons["EXIT_STATE"]->render(this->window);
        for (auto &it : this->nav_buttons){
            it.second->render(this->window);
        } 
    }
}

//render all texts
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

//render quad shapes
void Screen::renderQuad(){
    if (menu == true) this->window->draw(this->quad);
        
}

//render hotel infos
void Screen::renderHotel(){
    if (this->hotel_print == HOTEL_FIRST){
            this->hotel_days[count-1].second->print(this->count-1);
            this->hotel_print = HOTEL_ZERO;
    }
}
//render MiniScreen
void Screen::renderMScreen(){
    if(menu == false){
        this->window->draw(this->miniScreen2);
        this->window->draw(this->miniScreen);
    } 
    
}
//main render function
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
    this->renderQuad();
    this->renderMScreen();
    this->renderHotel();

    
    this->window->display();
}





