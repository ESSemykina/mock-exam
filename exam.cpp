#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "Winx.hpp"



using namespace std::chrono_literals;
int main()
{


    sf::RenderWindow window(sf::VideoMode(700, 400), "winx!");

    sf::Texture texture;
    if (!texture.loadFromFile("img/back 22.jpg"))
    {
        std::cout << "ERROR when loading back.jpg" << std::endl;
        return false;
    }

    sf::Sprite back;
    back.setTexture(texture);



    sf::Texture Winx;
    Winx.loadFromFile("img/winx.png");

    katya::wiinx wiinx(Winx);
    // sf::Sprite Bloom;
    // Bloom.setTexture(Winx);
    // Bloom.setPosition(10, 300);




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            // left key is pressed: move our character
           // Bloom.move(-1.f, 0.f);
            wiinx.Left();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            // left key is pressed: move our character
           // Bloom.move(1.f, 0.f);
            wiinx.Right();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // left key is pressed: move our character
            //Bloom.move(0.f, -1.f);
            wiinx.Up();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // left key is pressed: move our character
            //Bloom.move(0.f, 1.f);
            wiinx.Down();
        }


        window.clear();
        window.draw(back);
        window.draw(wiinx.GetBloom());


        window.display();



    }


    return 0;
}
