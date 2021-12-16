#ifndef ham_sd
#define _hamsd
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<Windows.h>;
#include<iostream>
int MAU = 1;
using namespace std;
using namespace sf;
void check(int&a)
{
    if (a >= 12)a = a % 12;
}
void ramdoming(Text& newgame, Text& highscore, Text& quicgame, Text& about)
{
    int a = rand()%12;
    switch (MAU)
    {
    case 1:
    {
        newgame.setFillColor(Color::Blue);
        highscore.setFillColor(Color::Green);
        quicgame.setFillColor(Color::White);
        about.setFillColor(Color::Yellow);
    }break;
    case 2:
    {
        newgame.setFillColor(Color::Yellow);
        highscore.setFillColor(Color::Blue);
        quicgame.setFillColor(Color::Green);
        about.setFillColor(Color::White);
    }break;
    case 3:
    {
        newgame.setFillColor(Color::White);
        highscore.setFillColor(Color::Yellow);
        quicgame.setFillColor(Color::Blue);
        about.setFillColor(Color::Green);
    }break;
    case 4:
    {
        newgame.setFillColor(Color::Green);
        highscore.setFillColor(Color::White);
        quicgame.setFillColor(Color::Yellow);
        about.setFillColor(Color::Blue);

    }break;
    }
    MAU = MAU + 1;
    if (MAU == 5)
    {
        MAU = 1;
    }
    
}
void initwinbackround()
{
    sf::RenderWindow window(sf::VideoMode(1024, 512), "My window");
    window.setFramerateLimit(60);
	window.setTitle("Snake");
    sf::Style::Resize;
    sf::Style::Close;
    sf::Text text, newgame, quickgame, hightscore, about;
    sf::Font font;
    if (!font.loadFromFile("Metropolian-Display.ttf"))
    {
        throw("NOT FILE");
    }
    newgame.setFont(font);
    quickgame.setFont(font);
    hightscore.setFont(font);
    text.setFont(font);
    about.setFont(font);
    text.setString("MENU");
    newgame.setString("NEW GAME");
    quickgame.setString("QUICK GAME");
    hightscore.setString("HIGHT SCORE");
    about.setString("ABOUT");
    text.setCharacterSize(30);
    newgame.setCharacterSize(25);
    hightscore.setCharacterSize(25);
    quickgame.setCharacterSize(25);
    about.setCharacterSize(25);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.move(450.f, 100.f);
    newgame.move(420.f, 180.f);
    hightscore.move(400.f, 220.f);
    quickgame.move(400.f, 260.f);
    about.move(445.f, 300.f);
    sf::Image img;
    if (!img.loadFromFile("img.jpg"))
    {
        cout<<"Can Not IMG";
    }
    sf::Texture textture;
    textture.loadFromImage(img);
    sf::Sprite spirte;
    spirte.setTexture(textture);
    int i = 0;
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        i++;
        if (i==10)
        {
            i =9;
            ramdoming(newgame, hightscore, quickgame, about);
            Sleep(250);
           
        }
        window.clear();
        window.draw(spirte);
        window.draw(text);
        window.draw(newgame);
        window.draw(hightscore);
        window.draw(quickgame);
        window.draw(about);
        window.display();
    }
}
#endif // !ham_du

