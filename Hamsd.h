#ifndef ham_sd
#define _hamsd
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<Windows.h>
#include<iostream>
#define TUONG_TREN 10;
#define TUONG_DUOI 496
#define TUONG_TRAI 11
#define TUONG_PHAI 1012
int MAU = 1;
int HIGHSCORE = 0;
using namespace std;
using namespace sf;
struct node
{
    CircleShape x;
    node* next;
};
struct linklist
{
    node* head;
    node* tail;
};
void khoitaotree(linklist&l)
{
    l.head = l.tail = NULL;
}
node* khoitaonode(int x, int y)
{
    node *p = new node;
    p->x.setRadius(10.f);
    p->x.move(x, y);
    p->x.setFillColor(Color::Black);
    p->next = NULL;
    return p;
}
void themdau(linklist&l,node*p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}
void themcuoi(linklist& l, node* p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}
Vector2f getnode(node* p)
{
    return p->x.getPosition();
}
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
    sf::Font font;
    if (!font.loadFromFile("Metropolian-Display.ttf"))
    {
        throw("NOT FILE");
    }
    Text diem,diemcuaban, diemcao;
    diem.setFont(font);
    diemcao.setFont(font);
    diemcuaban.setFont(font);
    diemcao.setString("HIGH SCORE");
    diemcuaban.setString("DIEM CAO NHAT CUA BAN LA: ");
    diem.setString(to_string(HIGHSCORE));
    diemcao.setFillColor(Color::Red);
    diem.setFillColor(Color::Color(0,0,51));
    diemcuaban.setFillColor(Color::Color(0, 0, 51));
    diem.move(596, 171);
    diemcao.move(310, 66);
    diemcuaban.move(15, 171);
    diem.setCharacterSize(30);
    diemcuaban.setCharacterSize(30);
    diemcao.setCharacterSize(50);
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
                int  x = event.mouseButton.x, y = event.mouseButton.y;
                cout << x << " " << y;
                return 0;
            }
        }
        window.clear();
        window.draw(spirte);
        window.draw(diemcao);
        window.draw(diemcuaban);
        window.draw(diem);
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
                    if (x >= 617 && x <= 632)return 5;
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
Vector2f getran(linklist l)
{
    return l.tail->x.getPosition();
}
class conran
{
private:
    linklist ran;
    int n;
    CircleShape moi;
    int score;
public:
    int getscore()
    {
        int a = score;
        return a;
    }
    conran()
    {
        n = 3;
        score = 30;
        khoitaotree(ran);
        moi.setRadius(10.f);
        moi.setFillColor(Color(255, 0, 255));
        this->randommoi();
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                themdau(ran, khoitaonode(512, 256));
            }
            else
            {
                Vector2f k=getran(ran);
                themdau(ran, khoitaonode(k.x - 20, k.y));
            }
        }
    }
    void randommoi()
    {
        int x, y, nguyen;
        x = 12 + rand() % (992 - 12 + 1);
        y= 16+ rand() % (496 - 16 + 1);
        nguyen = x / 20;
        x = nguyen * 20 + 12;
        nguyen = y / 20;
        y = nguyen* 20 + 16;
        moi.setPosition(x, y);
    }
    void themran(int huong)
    {
        n = n + 1;
        score = score + 10;
        HIGHSCORE = score > HIGHSCORE ? score : HIGHSCORE;
        Vector2f k = getran(ran);
        if (huong == 3 || huong == 72)k.x = k.x + 20.f;
        else
        {
            if (huong == 71 || huong == int(0))k.x = k.x - 20.f;
            else
            {
                if (huong == 22 || huong == 73)k.y = k.y - 20.f;
                else
                {
                    if (huong == 18 || huong == 74)k.y = k.y + 20.f;
                }
            }
        }
        themcuoi(ran, khoitaonode(k.x, k.y));
    }
    int dichuyen(int huong)
    {
        
        for (node* p = ran.head; p->next != NULL; p = p->next)
        {
            Vector2f k = p->next->x.getPosition();
            p->x.setPosition(k.x,k.y);
        }
        Vector2f k = getran(ran);
        if (k.x == moi.getPosition().x && k.y == moi.getPosition().y)
        {
            this->randommoi();
            themran(huong);
        }
        if (huong == 3 || huong == 72)k.x = k.x + 20.f;
        else
        {
            if (huong == 71||huong==int(0))k.x = k.x - 20.f;
            else
            {
                if (huong == 22 || huong == 73)k.y = k.y - 20.f;
                else
                {
                    if (huong == 18 || huong == 74)k.y = k.y + 20.f;
                }
            }
        }
        ran.tail->x.setPosition(k);
        if (k.x <= 10)return 0;
        if (k.x >= TUONG_PHAI)return 0;
        if (k.y <= 10)return 0;
        if (k.y >= TUONG_DUOI)return 0;
        return -1;
    }
    void inran(RenderWindow& window)
    {
        for (node* p = ran.head; p != NULL; p = p->next)
        {
            window.draw(p->x);
        }
        window.draw(moi);
    }
};
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
    conran ran;
    int huong = 3, huongcu = 3;
    int flag = 1;
    sf::Font font;
    if (!font.loadFromFile("Metropolian-Display.ttf"))
    {
        throw("NOT FILE");
    }
    Text Diem, score;
    Diem.setFont(font);
    score.setFont(font);
    Diem.setString("Diem: ");
    Diem.setCharacterSize(20);
    Diem.move(800, 15);
    Diem.setFillColor(Color::White);
    score.setCharacterSize(20);
    score.move(885, 15);
    score.setFillColor(Color::White);
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
                return 0;
            }
            if (event.type == Event::KeyPressed)
            {
                huongcu = huong;
                huong= event.key.code;
            }

        }
        score.setString(to_string(ran.getscore()));
        if ((huongcu == 0 || huongcu == 71) && (huong == 3 || huong == 72))huong = huongcu;
        if ((huongcu == 3 || huongcu == 72) && (huong == 0 || huong == 71))huong = huongcu;
        if ((huongcu == 22 || huongcu == 73) && (huong == 18 || huong == 74))huong = huongcu;
        if ((huongcu == 18 || huongcu == 74) && (huong == 22 || huong == 73))huong = huongcu;
        window.clear();
        window.draw(spirte);
        ran.inran(window);
        /*window.draw(shape);*/
        window.draw(line1);
        window.draw(Diem);
        window.draw(score);
        window.draw(line2);
        window.draw(line3);
        window.draw(line4);
        window.display();
        switch (leve)
        {
        case 1:Sleep(450);
        case 2:Sleep(350);
        case 3:Sleep(250);
        case 4:Sleep(150);
        case 5:Sleep(50);
        }
        flag=ran.dichuyen(huong);
        if (flag == 0)
        {
            /*Sleep(5000);*/
            return 0;
        }
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

