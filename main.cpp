#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

int Y2, Y3;
float speed = 1, X1 = 0, Y1 = 1;

void Bollen(sf::CircleShape &shape, sf::RectangleShape &rectangle, sf::RectangleShape &rectangle2){

    int tiden = time(0);

    srand(tiden);

    if(rectangle2.getGlobalBounds().intersects(shape.getGlobalBounds())){
        for(int i = 0; i < 1;){
            X1 = rand()%7-3;
            if(X1 < 0){
                i++;
            }
        }

        if(Y1 < 0){
            for(int i = 0; i < 1;){
                Y1 = rand()%7-3;
                if(Y1 < 0){
                    i++;
                }
            }
        }
        if(Y1 > 0){
            for(int i = 0; i < 1;){
                Y1 = rand()%7-3;
                if(Y1 > 0){
                    i++;
                }
            }
        }
        if(Y1 == 0){
            Y1 = rand()%7-3;
        }
    }
    if(shape.getPosition().y > 860){
        for(int i = 0; i < 1;){
            Y1 = rand()%7-3;
            if(Y1 < 0){
                i++;
            }
        }

        if(X1 < 0){
            for(int i = 0; i < 1;){
                X1 = rand()%7-3;
                if(X1 < 0){
                    i++;
                }
            }
        }
        if(X1 > 0){
            for(int i = 0; i < 1;){
                X1 = rand()%7-3;
                if(X1 > 0){
                    i++;
                }
            }
        }
        if(X1 == 0){
            X1 = rand()%7-3;
        }
    }
    if(shape.getPosition().y < 0){
        for(int i = 0; i < 1;){
            Y1 = rand()%7-3;
            if(Y1 > 0){
                i++;
            }
        }

        if(X1 < 0){
            for(int i = 0; i < 1;){
                X1 = rand()%7-3;
                if(X1 < 0){
                    i++;
                }
            }
        }
        if(X1 > 0){
            for(int i = 0; i < 1;){
                X1 = rand()%7-3;
                if(X1 > 0){
                    i++;
                }
            }
        }
        if(X1 == 0){
            X1 = rand()%7-3;
        }
    }
    if(rectangle.getGlobalBounds().intersects(shape.getGlobalBounds())){
        for(int i = 0; i < 1;){
            X1 = rand()%7-3;
            if(X1 > 0){
                i++;
            }
        }

        if(Y1 < 0){
            for(int i = 0; i < 1;){
                Y1 = rand()%7-3;
                if(Y1 < 0){
                    i++;
                }
            }
        }
        if(Y1 > 0){
            for(int i = 0; i < 1;){
                Y1 = rand()%7-3;
                if(Y1 > 0){
                    i++;
                }
            }
        }
        if(Y1 == 0){
            Y1 = rand()%7-3;
        }
    }
    shape.move(X1,Y1);
}



void Player_one(sf::RectangleShape &rectangle, sf::Event &event){
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::PageUp){
            Y2 = -3;
        }
        if(event.key.code == sf::Keyboard::Left){
            Y2 = 3;
        }
    }
    if (event.type == sf::Event::KeyReleased){
        if(event.key.code == sf::Keyboard::Left or event.key.code == sf::Keyboard::PageUp){
            Y2 = 0;
        }
    }
    rectangle.move(0,Y2);
}



void Player_two(sf::RectangleShape &rectangle2, sf::Event &event){
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::PageDown){
            Y3 = -3;
        }
        if(event.key.code == sf::Keyboard::Right){
            Y3 = 3;
        }
    }
    if (event.type == sf::Event::KeyReleased){
        if(event.key.code == sf::Keyboard::PageDown or event.key.code == sf::Keyboard::Right){
            Y3 = 0;
        }
    }
    rectangle2.move(0,Y3);
}

void end_of_screen(sf::RectangleShape &rectangle, sf::RectangleShape &rectangle2){

    if(rectangle.getPosition().y < 0){
        rectangle.setPosition(5, 0);
    }
    if(rectangle.getPosition().y > 750){
        rectangle.setPosition(5, 750);
    }
    if(rectangle2.getPosition().y < 0){
        rectangle2.setPosition(1785, 0);
    }
    if(rectangle2.getPosition().y > 750){
        rectangle2.setPosition(1785, 750);
    }
}

void Ball_Speed(sf::Event &event){
    if(event.type == sf::Event::KeyPressed){
        if(speed > 0.00001){
            if(event.key.code == sf::Keyboard::Up){
                speed = speed * 0.1;
            }
        }
        if(speed < 10){
            if(event.key.code == sf::Keyboard::Down){
                speed = speed / 0.1;
            }
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1800, 900), "2018 CANCER PONG!!!");

    int score1 = 0, score2 = 0;
    int tiden = time(0);

    sf::CircleShape shape(18.f);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Green);
    shape.setOutlineThickness(2);
    shape.setPosition(880, 430);
    sf::Clock clock;
    sf::Clock clock2;

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(10, 150));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(5, 400);

    sf::RectangleShape rectangle2;
    rectangle2.setSize(sf::Vector2f(10, 150));
    rectangle2.setFillColor(sf::Color::Green);
    rectangle2.setPosition(1785, 400);

    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        Player_one(rectangle, event);
        Player_two(rectangle2, event);
        end_of_screen(rectangle, rectangle2);
        Ball_Speed(event);

        if(clock.getElapsedTime().asSeconds() > speed){
            Bollen(shape, rectangle, rectangle2);
            clock.restart();
        }
        window.clear();
        window.draw(shape);
        window.draw(rectangle);
        window.draw(rectangle2);
        window.display();

        if(shape.getPosition().x < -100 or shape.getPosition().x > 1900){

            if(shape.getPosition().x < -100){
                score2++;
            }
            if(shape.getPosition().x > 1900){
                score1++;
            }

            shape.setPosition(900, 450);
            X1 = 0;
            Y1 = 1;
        }
    }

    std::cout << "Scoreboard:" << std::endl << "Player One: " << score1 << std::endl << "Player Two: " << score2 << std::endl;
    if(score1 > score2){
        std::cout << "Player One WIN";
    }
    if(score1 < score2){
        std::cout << "Player Two WIN";
    }
    if(score1 == score2){
        std::cout << "It's A Tie";
    }

    return 0;
}
