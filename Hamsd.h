#ifndef ham_sd
#define _hamsd
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<Windows.h>
#include<iostream>
int MAU = 1;
int HIGHSCORE = 0;
using namespace std;
using namespace sf;
void ramdoming(Text& newgame, Text& highscore, Text& quicgame, Text& about)
{
    if (MAU >= 5)
    {
        MAU = 1;
    }
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
    
}
int initwinbackround(RenderWindow&window)
{
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
    hightscore.setString("HIGH SCORE");
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
    hightscore.move(410.f, 220.f);
    quickgame.move(400.f, 260.f);
    about.move(445.f, 300.f);
    sf::Image img;
    if (!img.loadFromFile("img.jpg"))
    {
        cout << "Can Not IMG";
    }
    sf::Texture textture;
    textture.loadFromImage(img);
    sf::Sprite spirte;
    spirte.setTexture(textture);
    int i = 0;
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        ramdoming(newgame, hightscore, quickgame, about);
        Sleep(250);
        window.clear();
        window.draw(spirte);
        window.draw(text);
        window.draw(newgame);
        window.draw(hightscore);
        window.draw(quickgame);
        window.draw(about);
        window.display();
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 3;
            }
            if (event.type == Event::MouseButtonPressed)
            {
                int x = event.mouseButton.x, y = event.mouseButton.y;
                if (x > 420 && x < 595 && y>180 && y < 205)
                {
                    return 1;
                }
                if (x > 400 && x < 615 && y>220 && y < 245)
                {
                    if (event.type == Event::MouseButtonPressed)
                    {
                        return 2;
                    }
                }
                if (x > 400 && x < 600 && y>260 && y < 285)
                {
                    if (event.type == Event::MouseButtonPressed)
                    {
                        return 3;
                    }
                }
                if (x > 445 && x < 555 && y>300 && y < 325)
                {
                    if (event.type == Event::MouseButtonPressed)
                    {
                        return 4;
                    }
                }

            }
            
        }
    }
}
void mauabout(Text&mon, Text&dack,Text&svthuchien, Text&sv1, Text&sv2, Text&sv3, Text&huongdan,Text&gv)
{
    if (MAU >= 8)MAU = 1;;
    int i = MAU-1;
    Color a[] = { Color::Black,Color::Blue,Color::Cyan,Color::Green,Color::Magenta,Color::Transparent,Color::White,Color::Yellow };
    mon.setFillColor(a[(i++)%7]);
    dack.setFillColor(a[(i++)%7]);
    svthuchien.setFillColor(a[(i++) % 7]);
    sv1.setFillColor(a[(i++) % 7]);
    sv2.setFillColor(a[(i++) % 7]);
    sv3.setFillColor(a[(i++) % 7]);
    huongdan.setFillColor(a[(i++) % 7]);
    gv.setFillColor(a[(i++) % 7]);
    MAU++;
}
int About(RenderWindow&window)
{
    sf::Image img;
    if (!img.loadFromFile("img.jpg"))
    {
        cout << "Can Not IMG";
    }
    sf::Texture textture;
    textture.loadFromImage(img);
    sf::Sprite spirte;
    spirte.setTexture(textture);
    sf::Style::Resize;
    sf::Style::Close;
    sf::Text about,mon,dack,svthuchien, sv1, sv2, sv3,huongdan,gv;
    sf::Font font;
    if (!font.loadFromFile("Metropolian-Display.ttf"))
    {
        throw("NOT FILE");
    }
    about.setFont(font);
    mon.setFont(font);
    dack.setFont(font);
    svthuchien.setFont(font);
    sv1.setFont(font);
    sv2.setFont(font);
    sv3.setFont(font);
    huongdan.setFont(font);
    gv.setFont(font);
    about.setString("ABOUT");
    mon.setString("KY NANG NGHE NGHIEP - SS004.M11");
    svthuchien.setString("SINH VIEN THUC HIEN");
    dack.setString("TRO CHOI 'CON RAN SAN MOI'");
    sv1.setString("NGUYEN KHAC THAI - 20521888");
    sv2.setString("PHAM DUC ANH - 20521076");
    sv3.setString("NGUYEN THE VINH - 20520862");
    huongdan.setString("GIANG VIEN HUONG DAN");
    gv.setString("NGUYEN VAN TOAN");
    about.setCharacterSize(30);
    mon.setCharacterSize(25);
    dack.setCharacterSize(25);
    svthuchien.setCharacterSize(25);
    sv1.setCharacterSize(20);
    sv2.setCharacterSize(20);
    sv3.setCharacterSize(20);
    huongdan.setCharacterSize(25);
    gv.setCharacterSize(20);
    about.setFillColor(sf::Color::Red);
    about.setStyle(sf::Text::Bold);
    about.move(450.f, 60.f);
    mon.move(270.f, 140.f);
    dack.move(306.f, 180.f);
    svthuchien.move(325.f, 220.f);
    sv1.move(318.f, 260.f);
    sv2.move(336.f, 300.f);
    sv3.move(325.f, 340.f);
    huongdan.move(300.f, 380.f);
    gv.move(355.f, 420.f);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                return 3;
            }
            if (event.type == Event::MouseButtonPressed)
            {
                return 0;
            }
        }
        mauabout(mon, dack,svthuchien, sv1, sv2, sv3, huongdan, gv);
        Sleep(250);
        window.clear();
        window.draw(spirte);
        window.draw(about);
        window.draw(mon);
        window.draw(dack);
        window.draw(svthuchien);
        window.draw(sv1);
        window.draw(sv2);
        window.draw(sv3);
        window.draw(huongdan);
        window.draw(gv);
        window.display();
    }
}
int highscore(RenderWindow& window)
{
    sf::Image img;
    if (!img.loadFromFile("img.jpg"))
    {
        cout << "Can Not IMG";
    }
    sf::Texture textture;
    textture.loadFromImage(img);
    sf::Sprite spirte;
    spirte.setTexture(textture);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                return 3;
            }
            if (event.type == Event::MouseButtonPressed)
            {
                return 0;
            }
        }
        window.clear();
        window.draw(spirte);
        window.display();
    }
}
int setleve(RenderWindow& window)
{
    sf::Image img;
    if (!img.loadFromFile("img.jpg"))
    {
        cout << "Can Not IMG";
    }
    sf::Texture textture;
    textture.loadFromImage(img);
    sf::Sprite spirte;
    spirte.setTexture(textture);
    sf::Font font;
    if (!font.loadFromFile("Metropolian-Display.ttf"))
    {
        throw("NOT FILE");
    }
    Text leve, youchoise;
    leve.setFont(font);
    youchoise.setFont(font);
    leve.setString("LEVE 1 - 5");
    youchoise.setString("YOU CHOICE:  1   2   3   4   5");
    leve.setCharacterSize(60);
    youchoise.setCharacterSize(40);
    leve.setFillColor(Color::Red);
    youchoise.setFillColor(Color::Yellow);
    leve.move(342.f, 100.f);
    youchoise.move(20.f, 180.f);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                return 0;
            }
            if (event.type == Event::MouseButtonPressed)
            {
                int x = event.mouseButton.x, y = event.mouseButton.y;
                if (y >= 188 && y <= 220)
                {
                    if (x >= 339 && x <= 355)return 1;
                    if (x >= 403 && x <= 425)return 2;
                    if (x >= 472 && x <= 490)return 3;
                    if (x >= 542 && x <= 563)return 4;
                    if (x >= 617 && x <= 632)return 4;
                }
            }
        }
        window.clear();
        window.draw(spirte);
        window.draw(leve);
        window.draw(youchoise);
        window.display();
    }
}
int newgame(RenderWindow&window)
{
    int leve = setleve(window);
    if (leve == 0)return 3;
    sf::Image img;
    if (!img.loadFromFile("img.jpg"))
    {
        cout << "Can Not IMG";
    }
    sf::Texture textture;
    textture.loadFromImage(img);
    sf::Sprite spirte;
    spirte.setTexture(textture);
    sf::RectangleShape line1(Vector2f(1024.f, 10.f)), line2(Vector2f(512.f, 10.f)), line3(Vector2f(1024.f, 10.f)), line4(Vector2f(512.f, 10.f));

    line1.rotate(0.f);
    line2.rotate(90.f);
    line3.rotate(0.f);
    line4.rotate(90.f);
    line1.setFillColor(Color::Color(200, 50, 50));
    line2.setFillColor(Color::Color(200, 50, 50));
    line3.setFillColor(Color::Color(200, 50, 50));
    line4.setFillColor(Color::Color(200, 50, 50));
    line2.move(10,10);
    line3.move(0, 502);
    line4.move(1024,10);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                return 3;
            }
            if (event.type == Event::MouseButtonPressed)
            {
                int x = event.mouseButton.x, y = event.mouseButton.y;
                cout << x << " " << y << endl;
            }
        }
        window.clear();
        window.draw(spirte);
        window.draw(line1);
        window.draw(line2);
        window.draw(line3);
        window.draw(line4);
        window.display();
    }
    return 0;
}
void game()
{
    sf::RenderWindow window(sf::VideoMode(1024, 512), "My window");
    window.setFramerateLimit(60);
    window.setTitle("Snake");
    sf::Style::Resize;
    sf::Style::Close;
    int chon = initwinbackround(window);
    while (chon != 3)
    {
        int a = 0;
        switch (chon)
        {
        case 1:
        {
            a = newgame(window);
        }break;
        case 2:
        {
           a=highscore(window);
        }break;
        case 3:
        {
            window.close();
            break;
        }break;
        case 4:
        {
            a=About(window);
        }break;
        }
        if (a == 3)
        {
            window.close();
            break;
        }
        chon = initwinbackround(window);
    }
}
#endif // !ham_du

