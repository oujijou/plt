#include <iostream>
using namespace std;



// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    
    int frame = 0;
    int row = 0;   
    int frameCounter = 0;

    sf::Texture texture;
    sf::Sprite texSprite;
    if (!texture.loadFromFile("/home/ensea/plt/res/arena1.jpg"))
    {
        std::cout<<"Load Failed" << std::endl;
        system("Pause");
    }
    texSprite.setTexture(texture);

    sf::Texture spriteSheet;
    if (!spriteSheet.loadFromFile("/home/ensea/plt/res/ken.png",sf::IntRect(7,7,100,120)))
    {
        std::cout<<"Load Failed" << std::endl;
        system("Pause");
    }
    sf::Sprite playerSprite;
    playerSprite.setTexture(spriteSheet,true);
    //playerSprite.setScale(0.5,0.5);
    

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

        //playerSprite.setTextureRect(sf::IntRect(32*frame, row, 32,48));

        window.clear();
        window.draw(texSprite);
        window.draw(playerSprite);
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
