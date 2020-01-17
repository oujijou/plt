#include <iostream>
#include <state.h>
#include "string.h"
#include "render.h"
#define _JSON_H_INCOMPLETE 
#include "engine.h"
#include <unistd.h>
#include <fstream>
#include <streambuf>
#include <ai.h>


using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void handleInputs(sf::RenderWindow &window,  std::shared_ptr<Engine> engine);
bool iaTurn = false;


int main(int argc, char *argv[])
{
    //display arena
    sf::Texture arena;
    sf::Sprite arenaSprite;
    int frame = 0;
    int row = 1;
    int frameCounter = 0;

    if (!arena.loadFromFile("../res/Terrains/seku_terrain.png"))
    {
        std::cout << "Load Failed" << std::endl;
        system("Pause");
    }
    //arenaSprite.setScale(0.5,0.5);
    arenaSprite.setTexture(arena);

    //display fighter1
    sf::Texture spriteSheet;
    //sf:: IntRect rectSourceSprite(0,100,100,100);
    if (!spriteSheet.loadFromFile("../res/Fighters/Kuro.png")) //,rectSourceSprite));
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
    if (!spriteSheet2.loadFromFile("../res/Fighters/Flint.png", rectSourceSprite1))
    {
        std::cout << "Load Failed" << std::endl;
        system("Pause");
    }
    sf::Sprite playerSprite2;
    // playerSprite2.setOrigin(10.f, 20.f);
    playerSprite2.setTexture(spriteSheet2);
    // // put fighter on the left of the arena
    playerSprite2.setPosition(sf::Vector2f(500.f, 250.f));

    Animation animation(&spriteSheet, sf::Vector2u(3,4), 0.3f);

    float deltaTime = 0.0f;
    sf::Clock clock;

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
                deltaTime = clock.restart().asSeconds();

                sf::Event event;
                sf::Font font;
                if (!font.loadFromFile("../res/Fonts/FontFile.ttf"))
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
                text2.setPosition(530.f, 0.f);

                sf::Texture hpBarTexture;
                if (!hpBarTexture.loadFromFile("../res/redBg.jpg", sf::IntRect(0, 0, 100, 10)))
                {
                    return false;
                }

                State state;
                sf::Sprite hpBarP1;
                hpBarP1.setTexture(hpBarTexture);
                hpBarP1.setPosition(0.f, 40.f);

                sf::Sprite hpBarP2;
                hpBarP2.setTexture(hpBarTexture);
                hpBarP2.setPosition(530.f, 40.f);
                bool attackPress = false;
                //playerSprite2.move(sf::Vector2f(200.f,250.f));
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
                            state.notifyObservers(StateEventID::ALLCHANGED, state);
                            break;
                        }
                        break;
                    case sf::Event::MouseMoved:
                        break;
                    default:
                        state.notifyObservers({StateEventID::ALLCHANGED}, state);
                        break;
                    }
                }

                if (attackPress)
                {
                    playerSprite.move(385,0);
                    animation.Update(2, deltaTime);
                    playerSprite.setTextureRect(animation.uvRect);
                    
                    // playerSprite.setTextureRect(sf::IntRect(100 * frame, 100 * row, 100, 100));
                    // playerSprite2.move(sf::Vector2f(50.f,250.f));
                    // if (frameCounter == 100)
                    // {
                    //     frame = (frame + 1) % 3;
                    //     frameCounter = 0;
                    // }
                    // frameCounter++;
                }
            
                //cout << "frame = " << frame << endl;
                //cout << "frame counter = " << frameCounter << endl;

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
            cout << "---------------render ---------------------" << endl;
            State state;
            
            state.initPlayers();
            // auto playerList = state.getPlayerList();
            // cout << playerList.size() <<endl;
            // cout << &playerList[0] <<endl;
            // cout << &playerList[1] <<endl;
            

            //initiate Terrain
            state.setTerrain(FlintTerrain); // ThorkTerrain, FlintTerrain, KuroTerrain
            cout << "etat cree" << endl;
            cout << "setting fighters on the state ok" << endl;

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

            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");
            cout << " fenetre cree" << endl;

            //registering statelayer to observer
            StateLayer stateLayer(window, state);
            state.registerObserver(&stateLayer);
            cout << "statelayer ok!" << endl;
            bool attackPress = false;

            stateLayer.draw();
            cout << "drawing ok!" << endl;

            while (window.isOpen())
            {
                // Close the window if the close button is pressed
                sf::Event event;
                sf::Font font;
                if (!font.loadFromFile("../res/Fonts/FontFile.ttf"))
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
                text2.setPosition(530.f, 0.f);

                sf::Texture hpBarTexture;
                if (!hpBarTexture.loadFromFile("../res/redBg.jpg", sf::IntRect(0, 0, 100, 10)))
                {
                    return false;
                }

                sf::Sprite hpBarP1;
                hpBarP1.setTexture(hpBarTexture);
                hpBarP1.setPosition(0.f, 40.f);

                sf::Sprite hpBarP2;
                hpBarP2.setTexture(hpBarTexture);
                hpBarP2.setPosition(530.f, 40.f);

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
                        state.notifyObservers({StateEventID::ALLCHANGED}, state);
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

               
            }
        }
    
        else if (strcmp(argv[1], "engine") == 0)
        {
            cout<<"--- Moteur du jeu ---"<<endl;
            
            
            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");
			
            std::shared_ptr<Engine> engine = make_shared<Engine>();
            engine->getState().setTerrain(SekuTerrain);
            engine->getState().initPlayers(); //getting the state by using engine
            engine->getState().setRound(1);
           

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

            //registering statelayer to observer
            StateLayer stateLayer(window, engine->getState());
            engine->getState().registerObserver(&stateLayer);

            stateLayer.draw();
            while (window.isOpen()) {
                handleInputs(window,engine);
            }
            
        }else if (strcmp(argv[1], "random_ai") == 0 || strcmp(argv[1], "heuristic_ai") == 0 || strcmp(argv[1], "deep_ai") == 0)
        {    
            cout << "--------------------random / heuristic / deep ai-------------------" << endl;
            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");


            std::shared_ptr<Engine> engine = make_shared<Engine>();

            engine->getState().setTerrain(SekuTerrain);
            engine->getState().initPlayers(); //getting the state by using engine
            engine->getState().setRound(1);

            
            //Client Side (Render)
            StateLayer stateLayer(window, engine->getState());
            engine->getState().registerObserver(&stateLayer);
            
            TextureManager *textureManager = textureManager->getInstance();
            if (textureManager->load())
            {
                cout << "texuture manager ok!\n" << endl;
            }
            else
            {
                cout << "texuture manager loading failed!" << endl;
                return EXIT_FAILURE;
            }
            stateLayer.draw();

            cout << " User plays first" << endl;
            cout << "Use the following rules to play." << endl;
            cout << "A : Attack, R: Recharge mana, D: Defend" << endl;
            cout << "Press T : Turn Over, IA plays" << endl;
           
           
            while (window.isOpen()) {
                if (engine->turnOperation >= 3)
                {
                    // If the player / IA already made 3 operations, switch turns.
                    engine->turnOperation = 0;
                    iaTurn = !iaTurn;
                    std::cout << "END OF TURN" << std::endl;
                }
                if(!iaTurn)
                {
                    // Manage user inputs
                    handleInputs(window,engine); 
                } else {
                    if (strcmp(argv[1], "random_ai") == 0)
                    {
                        RandomAI randomAi(0); //AiID == 0
                        randomAi.aiID = 0;
                        randomAi.plID = 1;
                        randomAi.run(engine);
                        engine->turnOperation ++;
                    }
                    else if (strcmp(argv[1], "heuristic_ai") == 0)
                    {
                        HeuristicAI heuristicAi(0); //AiID == 0
                        heuristicAi.aiID = 0;
                        heuristicAi.plID = 1;
                        heuristicAi.run(engine);
                        engine->turnOperation ++;
                    }
                    else if (strcmp(argv[1], "deep_ai") == 0)
                    {
                        DeepAI deepAI(0); //AiID == 0
                        deepAI.aiID = 0;
                        deepAI.plID = 1;
                        deepAI.run(engine);
                        engine->turnOperation += 3;
                    }
                    sf::sleep(sf::milliseconds(1000 / 60));
                }
                engine->update();
            }
                
        }else if(strcmp(argv[1], "threads") == 0)
        {
            bool engineInit = false;
            bool engineWaiting = false;
            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");
            std::shared_ptr<Engine> engine = make_shared<Engine>();
            auto engineThreadFunction = [&]()
            {
                engine->getState().setTerrain(SekuTerrain);
                engine->getState().initPlayers(); //getting the state by using engine
                engine->getState().setRound(1);
                
                cout << "Engine OK" << endl;
                engineInit = true;
                
                while (window.isOpen())
                {
                    while (engineWaiting)
                    {

                    }
                    engine->update();
                }
            };

            sf::Thread  engineThread(engineThreadFunction);
            engineThread.launch();

            while (!engineInit)
            {
                cout << "Waiting for engine initialization..." << endl;
            }

            cout << "Thread OK" << endl;

            //Client Side (Render)
            StateLayer stateLayer(window, engine->getState());
            engine->getState().registerObserver(&stateLayer);
            
            TextureManager *textureManager = textureManager->getInstance();
            if (textureManager->load())
            {
                cout << "texture manager ok!\n" << endl;
            }
            else
            {
                cout << "texuture manager loading failed!" << endl;
                return EXIT_FAILURE;
            }
            
            stateLayer.draw();

            engineWaiting = true;
            while (window.isOpen())
            {
                if (engine->turnOperation >= 3)
                {
                    // If the player / IA already made 3 operations, switch turns.
                    engine->turnOperation = 0;
                    iaTurn = !iaTurn;
                    std::cout << "END OF TURN" << std::endl;
                }
                if(!iaTurn)
                {
                    DeepAI deepAI(1);
                    deepAI.aiID = 1;
                    deepAI.plID = 0;
                    deepAI.run(engine);
                    engine->turnOperation += 3;
                    engineWaiting = false;
                    sf::sleep(sf::milliseconds(1000));
                    engineWaiting = true;
                } else {
                    DeepAI deepAI(0);
                    deepAI.aiID = 0;
                    deepAI.plID = 1;
                    deepAI.run(engine);
                    engine->turnOperation += 3;
                    engineWaiting = false;
                    sf::sleep(sf::milliseconds(1000));
                    engineWaiting = true;
                }
            }
        }
        else if(strcmp(argv[1], "record") == 0)
        {
            bool engineInit = false;
            bool engineWaiting = false;
            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");
            std::shared_ptr<Engine> engine = make_shared<Engine>();
            auto engineThreadFunction = [&]()
            {
                engine->getState().setTerrain(SekuTerrain);
                engine->getState().initPlayers(); //getting the state by using engine
                engine->getState().setRound(1);
                engine->dumpJSONCommands = true;
                
                cout << "Engine OK" << endl;
                engineInit = true;
                
                while (window.isOpen())
                {
                    while (engineWaiting)
                    {

                    }
                    engine->update();
                }
            };

            sf::Thread  engineThread(engineThreadFunction);
            engineThread.launch();

            while (!engineInit)
            {
                cout << "Waiting for engine initialization..." << endl;
            }

            cout << "Thread OK" << endl;

            //Client Side (Render)
            StateLayer stateLayer(window, engine->getState());
            engine->getState().registerObserver(&stateLayer);
            
            TextureManager *textureManager = textureManager->getInstance();
            if (textureManager->load())
            {
                cout << "texture manager ok!\n" << endl;
            }
            else
            {
                cout << "texuture manager loading failed!" << endl;
                return EXIT_FAILURE;
            }
            
            stateLayer.draw();

            engineWaiting = true;
            while (window.isOpen())
            {
                if (engine->turnOperation >= 3)
                {
                    // If the player / IA already made 3 operations, switch turns.
                    engine->turnOperation = 0;
                    iaTurn = !iaTurn;
                    std::cout << "END OF TURN" << std::endl;
                }
                if(!iaTurn)
                {
                    DeepAI deepAI(1);
                    deepAI.aiID = 1;
                    deepAI.plID = 0;
                    deepAI.run(engine);
                    engine->turnOperation += 3;
                    engineWaiting = false;
                    sf::sleep(sf::milliseconds(1000));
                    engineWaiting = true;
                } else {
                    DeepAI deepAI(0);
                    deepAI.aiID = 0;
                    deepAI.plID = 1;
                    deepAI.run(engine);
                    engine->turnOperation += 3;
                    engineWaiting = false;
                    sf::sleep(sf::milliseconds(1000));
                    engineWaiting = true;
                }
            }
        }
        else if(strcmp(argv[1], "play") == 0)
        {
            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");
            std::shared_ptr<Engine> engine = make_shared<Engine>();
            engine->getState().setTerrain(SekuTerrain);
            engine->getState().initPlayers(); //getting the state by using engine
            engine->getState().setRound(1);

            //Client Side (Render)
            StateLayer stateLayer(window, engine->getState());
            engine->getState().registerObserver(&stateLayer);
            
            TextureManager *textureManager = textureManager->getInstance();
            if (textureManager->load())
            {
                cout << "texture manager ok!\n" << endl;
            }
            else
            {
                cout << "texuture manager loading failed!" << endl;
                return EXIT_FAILURE;
            }
            
            stateLayer.draw();

            std::ifstream t("replay.txt");
            std::string str((std::istreambuf_iterator<char>(t)),
                std::istreambuf_iterator<char>());
            std::vector<std::shared_ptr<Command>> commands = engine->jsonCommands->toCommands(str, engine);
            
            int i = 0;
            while (window.isOpen())
            {
                engine->addCommand(0, commands[i]);
                engine->update();
                sf::sleep(sf::seconds(1));
                i++;
            }
        }
    }
}

void handleInputs(sf::RenderWindow &window, std::shared_ptr<Engine> engine){
    sf::Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (iaTurn)
                    break;
                if (event.key.code == sf::Keyboard::T)
                {
                    engine->turnOperation = 3;
                }
                if(event.key.code == sf::Keyboard::A )
                {
                    engine->turnOperation ++;
                    if (engine->realEngine)
                    std::cout << "Attack is coming for player 0" << std::endl;
                    AttackCommand attackCommand(engine->getState().getPlayerList()[1]->getFighter(), 
                                                engine->getState().getPlayerList()[0]->getFighter());
                    unique_ptr<Command> ptr_attack (new AttackCommand(attackCommand));
                    engine->addCommand(0, move(ptr_attack));
                    engine->update();
                }
                if(event.key.code == sf::Keyboard::R)
                {
                    engine->turnOperation ++;
                    if (engine->realEngine)
                    std::cout << "recharging is coming for player 1" << std::endl;
                    RechargeCommand rechargeCommand(engine->getState().getPlayerList()[1]
                                                        ->getFighter());
                    unique_ptr<Command> ptr_recharge (new RechargeCommand(rechargeCommand));
                    engine->addCommand(0, move(ptr_recharge));

                    engine->update();
                }
                if(event.key.code == sf::Keyboard::D)
                {
                    engine->turnOperation ++;
                    if (engine->realEngine)
                    std::cout << "Defense is coming for player 1 " << std::endl;
                    DefenseCommand defenseCommand(engine->getState().getPlayerList()[1]
                                                        ->getFighter());
                    unique_ptr<Command> ptr_defense (new DefenseCommand(defenseCommand));
                    engine->addCommand(0, move(ptr_defense));

                    engine->update();
                }
            default:
            break;
            
        }
    }
}
