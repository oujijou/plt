#include <iostream>
#include <state.h>
#include "string.h"
#include "render.h"

using namespace std;
using namespace state;
using namespace render;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

int main(int argc,char* argv[])
{
    if (argc >1)
    {
        if(strcmp(argv[1], "hello")==0)
        {
            cout << "Bonjour " <<((argv[2])?argv[2]:"tout le monde") << endl;
        }
        if(strcmp(argv[1], "testSFML")==0)
        {
            cout << "test sfml"  << endl;
            
            //display arena
            sf::Texture arena;
            sf::Sprite arenaSprite;
                        
            if (!arena.loadFromFile("/home/ensea/plt/res/Terrains/seku_terrain.png"))
            {
                std::cout<<"Load Failed" << std::endl;
                system("Pause");
            }
            //arenaSprite.setScale(0.5,0.5);
            arenaSprite.setTexture(arena);
                
            //display fighter1
            sf::Texture spriteSheet;
            sf:: IntRect rectSourceSprite(0,0,100,100);
            if (!spriteSheet.loadFromFile("/home/ensea/plt/res/Fighters/Kuro.png",rectSourceSprite));
            {
                std::cout<<"Load Failed" << std::endl;
                system("Pause");
            }
            sf::Sprite playerSprite;
            playerSprite.setTexture(spriteSheet);
            // put fighter on the right of the arena
            playerSprite.setPosition(sf::Vector2f(50.f, 250.f)); 
                

            //display fighter2
            sf::Texture spriteSheet2;
            sf:: IntRect rectSourceSprite1(0,0,100,100);
            if (!spriteSheet2.loadFromFile("/home/ensea/plt/res/Fighters/Flint.png",rectSourceSprite1))
            {
                std::cout<<"Load Failed" << std::endl;
                system("Pause");
            }
            sf::Sprite playerSprite2;
            // playerSprite2.setOrigin(10.f, 20.f);
            playerSprite2.setTexture(spriteSheet2);
            // // put fighter on the left of the arena
            playerSprite2.setPosition(sf::Vector2f(500.f, 250.f)); 

            //size of image as input of VideoMode
            sf::VideoMode resolution;

            sf::RenderWindow window(sf::VideoMode(640, 384), "SFML works!",sf::Style::Default);
            
            sf::Clock clock;

            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                // if(clock.getElapsedTime().asSeconds()>1.0f)
                // {
                //     if(rectSourceSprite.left==300)
                //         rectSourceSprite.left=0;
                //     else
                //     {
                //         rectSourceSprite.left +=100;
                //     }
                    // playerSprite.setTextureRect(rectSourceSprite);
                    // clock.restart();
                        
                    
                    //playerSprite.setTextureRect(sf::IntRect(32*frame, row, 32,48));

                    window.clear();
                    window.draw(arenaSprite);
                    window.draw(playerSprite);
                    window.draw(playerSprite2);
                    window.display();
                //}
            }

            // Fin test SFML
        }
        else if (strcmp(argv[1],"render")==0)
        {
            cout << "affichage d'un etat" << endl;

            //testSFML();
            State state;
            cout << " etat cree" << endl;
            state.initPlayers();
            
            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");
            cout << " fenetre cree" << endl;

            //les differentes couches de textures
            StateLayer stateLayer(window,state); // on cree une couche pour l'etat  et y associant une fenetre
            cout << " window et state ok cree" << endl;
            stateLayer.initTextureManagers(state); //
            cout << " texture Managers init ok cree" << endl;

            // Positionnement des texture sur le terrain
            stateLayer.getTextureManagers()[0]->setPosition(sf::Vector2f(50.f, 250.f));
            stateLayer.getTextureManagers()[1]->setPosition(sf::Vector2f(500.f, 250.f));
        
            while (window.isOpen()){
            // Close the window if the close button is pressed
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                    }
                }
               // cout << " window opened" << endl;
                stateLayer.draw(window); //on utilise la methode draw de StateLayer pour afficher l etat
                //window.clear();
                // window.draw(*stateLayer.getTextureManagers()[0]);	// Draw fighter1			
                // window.draw(*stateLayer.getTextureManagers()[1]);	// Draw fighter2
                // window.draw(*stateLayer.getTextureManagers()[2]);	// Draw the terrain
                window.display();
		    }  
        }else if( strcmp(argv[1],"engine")==0 ){
            cout << "render" << endl;

            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");
        }
    }
    return 0;
}
