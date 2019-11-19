#include <iostream>
#include <state.h>
#include "string.h"
#include "render.h"
#include "engine.h"

using namespace std;
using namespace state;
using namespace render;
using namespace engine;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
    //display arena
    sf::Texture arena;
    sf::Sprite arenaSprite;
    int frame = 0;
    int row = 1;
    int frameCounter = 0;

    if (!arena.loadFromFile("/home/ensea/plt/res/Terrains/seku_terrain.png"))
    {
        std::cout << "Load Failed" << std::endl;
        system("Pause");
    }
    //arenaSprite.setScale(0.5,0.5);
    arenaSprite.setTexture(arena);

    //display fighter1
    sf::Texture spriteSheet;
    //sf:: IntRect rectSourceSprite(0,100,100,100);
    if (!spriteSheet.loadFromFile("/home/ensea/plt/res/Fighters/Kuro.png")) //,rectSourceSprite));
    {
        std::cout << "Load Failed" << std::endl;
        system("Pause");
    }
    sf::Sprite playerSprite;
    playerSprite.setTexture(spriteSheet);

    // put fighter on the right of the arena
    playerSprite.setPosition(sf::Vector2f(50.f, 250.f));

    //display fighter2
    sf::Texture spriteSheet2;
    sf::IntRect rectSourceSprite1(0, 0, 100, 100);
    if (!spriteSheet2.loadFromFile("/home/ensea/plt/res/Fighters/Flint.png", rectSourceSprite1))
    {
        std::cout << "Load Failed" << std::endl;
        system("Pause");
    }
    sf::Sprite playerSprite2;
    // playerSprite2.setOrigin(10.f, 20.f);
    playerSprite2.setTexture(spriteSheet2);
    // // put fighter on the left of the arena
    playerSprite2.setPosition(sf::Vector2f(500.f, 250.f));

    if (argc > 1)
    {
        if (strcmp(argv[1], "hello") == 0)
        {
            cout << "Bonjour " << ((argv[2]) ? argv[2] : "tout le monde") << endl;
        }
        if (strcmp(argv[1], "testSFML") == 0)
        {
            cout << "test sfml" << endl;

            //size of image as input of VideoMode
            sf::VideoMode resolution;

            sf::RenderWindow window(sf::VideoMode(640, 384), "SFML works!", sf::Style::Default);
            
            

            while (window.isOpen())
            {
                sf::Event event;
                sf::Font font;
				if(!font.loadFromFile("/home/ensea/plt/res/Fonts/FontFile.ttf"))
				{
				return false;
				}
				sf::Text text1;
				text1.setFont(font);
				text1.setString("Health Points");
				text1.setCharacterSize(40);
				
				sf::Text text2;
				text2.setFont(font);
				text2.setString("Health Points");
				text2.setCharacterSize(40);
				text2.setPosition(530.f,0.f);
				
				sf::Texture hpBarTexture;
				if(!hpBarTexture.loadFromFile("/home/ensea/plt/res/redBg.jpg",sf::IntRect(0,0,100,10)))
				{
					return false;
				}
				
				sf::Sprite hpBarP1;
				hpBarP1.setTexture(hpBarTexture);
				hpBarP1.setPosition(0.f,40.f);
				
				sf::Sprite hpBarP2;
				hpBarP2.setTexture(hpBarTexture);
				hpBarP2.setPosition(530.f,40.f);
				
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                playerSprite.setTextureRect(sf::IntRect(100 * frame, 100 * row, 100, 100));

                if (frameCounter == 100)
                {
                    frame = (frame + 1) % 3;
                    frameCounter = 0;
                }
                frameCounter++;
                // if(clock.getElapsedTime().asSeconds()>1.0f)
                // {
                //     if(rectSourceSpritel.left==300)
                //         rectSourceSprite.left=0;
                //     else
                //     {
                //         rectSourceSprite.left +=100;
                //     }
                // playerSprite.setTextureRect(rectSourceSprite);
                // clock.restart();

                //playerSprite.setTextureRect(sf::IntRect(32*frame, row, 32,48));
				
            

            sf::Clock clock;
					
                window.clear();
                
                window.draw(arenaSprite);
                window.draw(text1);
                window.draw(text2);
                window.draw(hpBarP1);
                window.draw(hpBarP2);
                window.draw(playerSprite);
                window.draw(playerSprite2);
                window.display();
                //}
            }

            // Fin test SFML
        }
        else if (strcmp(argv[1], "render") == 0)
        {
            cout << "affichage d'un etat" << endl;

            // //testSFML();
            
        
       
            State state;
			
            state.initPlayers();
            std::vector<std::shared_ptr<Player>> playerList = state.getPlayerList();

            Fighter fighter1;
            fighter1.setName(Flint);
            Fighter fighter2;
            fighter2.setName(Kuro);
            cout << "fighters name ok" << endl;
            // Fighter fighter1(Flint, DEAD, 100,100,300,10,2,COUPDEPOING,100);
            // Fighter fighter2(Seku, DEAD, 100,100,300,10,2,COUPDEPOING,100);
            //state.setFighter(fighter1);
            //state.setFighter(fighter2);
            //playerList[0]->setFighter(fighter1);

            state.setFighters(fighter1, fighter2);
            cout << "fighters ok" << endl;
            //state.setFighter(fighter2);
            state.setTerrain(SekuTerrain);
            cout << "etat cree" << endl;

            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");
            cout << " fenetre cree" << endl;

            TextureManager *textureManager = textureManager->getInstance();
            if (textureManager->load())
            {
                cout << "texuture manager ok!" << endl;
            }
            else
            {
                cout << "texuture manager loading failed!" << endl;
                return EXIT_FAILURE;
            }

            //textureManager->getTileBackground(SekuTerrain);
            //textureManager->getTileFighter(Flint);
            //textureManager->getTileFighter(Kuro);

            BackgroundManager backgroundManager;
            // backgroundManager.

            StateLayer stateLayer(window, state);
            state.registerObserver(&stateLayer);
            cout << "statelayer ok!" << endl;
            bool attackPress = false;
            stateLayer.draw();
            cout << "ok";
            
            while (window.isOpen())
            {
                // Close the window if the close button is pressed
                sf::Event event;
                while (window.pollEvent(event))
                {
                    switch (event.type)
                    {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        switch (event.key.code)
                        {
                        case sf::Keyboard::A:
                            cout << " touche A ENCLENCHE" << endl;
                            attackPress = true;
                            break;
                        default:
                            //state.notifyObservers({StateEventID::ALLCHANGED}, state);
                            break;
                        }
                        break;
                    case sf::Event::MouseMoved:
                        break;
                    default:
                        //state.notifyObservers({StateEventID::ALLCHANGED}, state);
                        break;
                    }
                }
                if (attackPress)
                {
                    playerSprite.setTextureRect(sf::IntRect(100 * frame, 100 * row, 100, 100));
                    if (frameCounter == 100)
                    {
                        frame = (frame + 1) % 3;
                        frameCounter = 0;
                    }
                    frameCounter++;
                }
                cout << "frame = " << frame << endl;
                cout << "frame counter = " << frameCounter << endl;

                //   window.clear();
                // window.draw(arenaSprite);
                // window.draw(playerSprite);
                // window.draw(playerSprite2);
                // window.display();
                window.clear();
                window.draw(arenaSprite);
                window.draw(playerSprite);

                window.display();
                //cout << " window opened" << endl;
            }
        }
    }
    else if (strcmp(argv[1], "engine") == 0)
    {
        cout << "engine is coming !!" << endl;

        // sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");

        // Engine engine;
        // engine.getState().initPlayers();

        // StateLayer stateLayer(window,engine.getState());
        // stateLayer.initTextureManagers(engine.getState());

        // StateLayer* ptr_stateLayer=&stateLayer;
        // engine.getState().registerObserver(ptr_stateLayer);

        // stateLayer.getTextureManagers()[0]->setPosition(sf::Vector2f(50.f, 250.f));
        // stateLayer.getTextureManagers()[1]->setPosition(sf::Vector2f(500.f, 250.f));

        // while (window.isOpen()){
        // 	sf::Event event;

        //     // Draw all the display on the screen
        //     stateLayer.draw();

        //     while (window.pollEvent(event)){
        // 		if (event.type == sf::Event::Closed){
        // 			window.close();
        //         }
        //         else if(event.type==sf::Event::KeyPressed && engine.getState().getRound()==1)
        //         {
        //             // cout<<"in loop if" << endl;
        //             // Attaq attaq(*engine.getState().getPlayerList()[0]->getFighter(),*engine.getState().getPlayerList()[1]->getFighter());
        //             // unique_ptr<Command> ptr_attack (new Attaq(attaq));
        //             // engine.addCommand(1, move(ptr_attack));

        //             // engine.getState().setRound(2);
        //             // engine.update();
        //         }
        //     }
        //     //window.close();
        // }

        //Attaq attaq(*engine.getState().getPlayerList()[0]->getFighter(), *engine.getState().getPlayerList()[1]->getFighter());
        // unique_ptr<Command> ptr_attack (new Attaq(attaq));
        // engine.addCommand(1, move(ptr_attack));

        // engine.update();

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
        //}
    }
}
// return 0;
