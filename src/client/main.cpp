#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    
    sf::Texture texture;
    if (!texture.loadFromFile("/home/ensea/plt/res/5.png"))
    {
        std::cout<<"Load Failed" << std::endl;
        system("Pause");
    }
    
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!",sf::Style::Default);
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

// Fin test SFML

#include <state.h>

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    cout << "Bonjour " <<argv[1] << endl;
    testSFML();

    return 0;
}
