#include <iostream>
#include <state.h>
#include "string.h"
#include "render.h"
#include "engine.h"
#include <unistd.h>
#include <ai.h>


using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

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
    if (!spriteSheet.loadFromFile("/home/ensea/plt/res/Fighters/Kuro.png", sf::IntRect(0, 0, 100, 100))) //,rectSourceSprite));
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
                if (!font.loadFromFile("/home/ensea/plt/res/Fonts/FontFile.ttf"))
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
                if (!hpBarTexture.loadFromFile("/home/ensea/plt/res/redBg.jpg", sf::IntRect(0, 0, 100, 10)))
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
                    playerSprite.setTextureRect(sf::IntRect(100 * frame, 100 * row, 100, 100));
                    playerSprite2.move(sf::Vector2f(50.f,250.f));
                    if (frameCounter == 100)
                    {
                        frame = (frame + 1) % 3;
                        frameCounter = 0;
                    }
                    frameCounter++;
                }
            
                cout << "frame = " << frame << endl;
                cout << "frame counter = " << frameCounter << endl;

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
                if (!font.loadFromFile("/home/ensea/plt/res/Fonts/FontFile.ttf"))
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
                if (!hpBarTexture.loadFromFile("/home/ensea/plt/res/redBg.jpg", sf::IntRect(0, 0, 100, 10)))
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
            cout << "------------------engine-----------------"<< endl;
            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");

            Engine engine;
            engine.getState().setTerrain(SekuTerrain);
            engine.getState().initPlayers(); //getting the state by using engine
            engine.getState().setRound(1);
           

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

            // //registering statelayer to observer
            StateLayer stateLayer(window, engine.getState());
            engine.getState().registerObserver(&stateLayer);

            stateLayer.draw();

            engine.checkRoundStart();
    
            //Kuro attacks 
            AttackCommand attackCommand(engine.getState().getPlayerList()[0]->getFighter(), 
                                        engine.getState().getPlayerList()[1]->getFighter());
            unique_ptr<Command> ptr_attack (new AttackCommand(attackCommand));
            engine.addCommand(0, move(ptr_attack));
            engine.checkRoundEnd();

            //Flint recharges
            RechargeCommand rechargeCommand(engine.getState().getPlayerList()[1]->getFighter());
            unique_ptr<Command> ptr_recharge (new RechargeCommand(rechargeCommand));
            engine.addCommand(1, move(ptr_recharge));
            engine.checkRoundEnd();

            AttackCommand attackCommand1(engine.getState().getPlayerList()[0]->getFighter(), 
                                        engine.getState().getPlayerList()[1]->getFighter());
            unique_ptr<Command> ptr_attack1 (new AttackCommand(attackCommand1));
            engine.addCommand(2, move(ptr_attack1));

            AttackCommand attackCommand2(engine.getState().getPlayerList()[0]->getFighter(), 
                                        engine.getState().getPlayerList()[1]->getFighter());
            unique_ptr<Command> ptr_attack2 (new AttackCommand(attackCommand2));
            engine.addCommand(3, move(ptr_attack2));

            AttackCommand attackCommand3(engine.getState().getPlayerList()[0]->getFighter(), 
                                        engine.getState().getPlayerList()[1]->getFighter());
            unique_ptr<Command> ptr_attack3 (new AttackCommand(attackCommand3));
            engine.addCommand(4, move(ptr_attack3));

            AttackCommand attackCommand4(engine.getState().getPlayerList()[0]->getFighter(), 
                                        engine.getState().getPlayerList()[1]->getFighter());
            unique_ptr<Command> ptr_attack4 (new AttackCommand(attackCommand4));
            engine.addCommand(5, move(ptr_attack4));


            
            // engine.checkGameEnd();
            // //Kuro recharges 
            // DefenseCommand defenseCommand(engine.getState().getPlayerList()[0].getFighter());
            // unique_ptr<Command> ptr_defense (new DefenseCommand(defenseCommand));
            // engine.addCommand(2, move(ptr_defense));

            // //Flint attacks
            // AttackCommand attackCommand1(engine.getState().getPlayerList()[1].getFighter(), 
            //                             engine.getState().getPlayerList()[0].getFighter());
            // unique_ptr<Command> ptr_attack1 (new AttackCommand(attackCommand1));
            // engine.addCommand(3, move(ptr_attack1));


            engine.update();
            engine.screenRefresh();
        
            
            while (window.isOpen())
            {
                sf::Event event;
                while(window.pollEvent(event)){
                    switch (event.type)
                    {                                
                        case sf::Event::Closed:
                            window.close();
                            break;
                        case sf::Event::KeyPressed :
                            switch (event.key.code)
                            {
                            case sf::Keyboard::A:
                                cout << " Attack is coming" << endl;
                                break;
                            default:
                            break;
                            }
                        default:
                        engine.getState().notifyObservers({StateEventID::ALLCHANGED}, engine.getState());
                        break;
                    }
                }
            }
        }else if (strcmp(argv[1], "random_ai") == 0)
        {
            
            cout << "--------------------random ai-------------------" << endl;
            sf::RenderWindow window(sf::VideoMode(640, 384), "Fighter Zone");

            Engine engine;
            engine.getState().initPlayers();
            engine.getState().setTerrain(SekuTerrain);

            //Client Side (Render)
            StateLayer stateLayer(window, engine.getState());
            engine.getState().registerObserver(&stateLayer);
            
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
            //randomAi.initAi(1,engine);

            // StateLayer* ptr_stateLayer= &stateLayer;
            // engine.getState().registerObserver(ptr_stateLayer);
            //cout <<"stateLayer ok!" <<endl;

            while (window.isOpen()){
                
               
                bool booting = true;
                //Initialize the scrren by drawing the default State
                if(booting){
                    // Draw all the display on the screen
                    stateLayer.draw();
                    
                    booting = false;
                }

                
                    engine.checkRoundStart();
                    
                    RandomAI randomAi(0);
                    randomAi.run(engine);

                    //Check if a fighter is dead or not
                    if(engine.checkGameEnd()==true){
                        window.close();
                        cout<<"Game END"<<endl;
                        break;
                    }

                    //Check if a fighter played
                    if(engine.checkRoundEnd()){
                        cout<<"round  change"<<endl;
                        engine.checkRoundStart();
                        StateEvent stateEvent(PLAYERCHANGED);
                        engine.getState().notifyObservers(stateEvent, engine.getState());
                    }

            
                sf::Event event;
                while(window.pollEvent(event)){
                    switch (event.type)
                    {                                
                        case sf::Event::Closed:
                            window.close();
                            break;
                        case sf::Event::KeyPressed :
                            switch (event.key.code)
                            {
                            case sf::Keyboard::A:
                                cout << " Attack is coming" << endl;
                                //engine.addCommand(0, move(ptr_attack));
                                break;
                            default:
                            break;
                            }
                        default:
                        engine.getState().notifyObservers({StateEventID::ALLCHANGED}, engine.getState());
                        break;
                    }
                }
        
                   // stateLayer.inputManager(event, engine.getState());
                    engine.screenRefresh();
                }   usleep(5);
                
        }


        
    }
}
           // stateLayer.draw();

            
           
            // // bool booting = true;

            // bool start = true;
            // while (window.isOpen())
            // {
            //     sf::Event event;
            //     while(window.pollEvent(event)){
            //         switch (event.type)
            //         {                                
            //             case sf::Event::Closed:
            //                 window.close();
            //                 break;
            //             case sf::Event::KeyPressed:
            //                 switch (event.key.code)
            //                 {
            //                 case sf::Keyboard::Q:
            //                     cout << " touche Q ENCLENCHE" << endl;
            //                     playerSprite.move(-200.f,0.0f);
            //                     break;
            //                 default:
            //                 break;
            //                 }
            //             default:
            //             break;
            //         }
            //     }
            //   // Draw all the display on the screen
            //         stateLayer.draw();

            
                
            
            

            

            //registering statelayer to observer
            // StateLayer stateLayer(window, engine.getState());
            // engine.getState().registerObserver(&stateLayer);
            // cout << "stateLayer ok!" << endl;
            // Engine* ptr_engine=&engine;
            // stateLayer.registerRenderObserver(ptr_engine);
//             bool booting = true;


//             while (window.isOpen())
//             {
//                 sf::Event event;

//                 // if (booting)
//                 // {
//                 //     // Draw all the display on the screen
//                 //     stateLayer.draw();
//                 //     cout << "Start of the game.\n"
//                 //         << endl;
//                 //     booting = false;
//                 // }
//                 // Close the window if the close button is pressed
//                 /*move fighter*/
//                 while(window.pollEvent(event)){
                    
//                     // else  if(event.type==sf::Event::KeyPressed && engine.getState().getRound()==1){
//                     //     cout << "\t\t--- Round 1 ---\n" << endl;
                    
                        
//                             switch (event.type)
//                             {                                
//                                 case sf::Event::Closed:
//                                     window.close();
//                                     break;
//                                 case sf::Event::KeyPressed:
//                                     switch (event.key.code)
//                                     {
//                                     case sf::Keyboard::Q:
//                                         cout << " touche Q ENCLENCHE" << endl;
//                                         playerSprite.move(-200.f,0.0f);
//                                         break;
//                                     case sf::Keyboard::D:
//                                         cout << " touche D ENCLENCHE" << endl;
//                                         //playerSprite.move(10.0f,0.0f);
//                                         playerSprite.move(200.f,0.0f);
//                                         break;
//                                     case sf::Keyboard::Left:
//                                         cout << " touche Left ENCLENCHE" << endl;
//                                         //playerSprite.move(10.0f,0.0f);
//                                         playerSprite2.move(-200.f,0.0f);
//                                         break;
//                                     case sf::Keyboard::Right:
//                                         cout << " touche right ENCLENCHE" << endl;
//                                         //playerSprite.move(10.0f,0.0f);
//                                         playerSprite2.move(200.f,0.0f);
//                                         break;
//                                     default:
//                                         engine.getState().notifyObservers({StateEventID::ALLCHANGED}, engine.getState());
//                                         break;
//                                     }
//                                     break;
//                                 case sf::Event::MouseMoved:
//                                     break;
//                                 default:
//                                     //state.notifyObservers({StateEventID::ALLCHANGED}, state);
//                                     break;
//                             }//fin switch
                        
//                    // }
// /*fin move fighter */          }//while(window.pollEvent(event))
                    
//                     // else if (engine.checkGameEnd() == true)
//                     // {
//                     //     window.close();
//                     //     cout << "Game END" << endl;
//                     //     break;
//                     // }

//                     // else if (!engine.getState().getEndFight() && engine.checkRoundEnd())
//                     // {
//                     //     engine.checkRoundStart();
//                     //     StateEvent stateEvent(FIGHTERCHANGED);
//                     //     engine.getState().notifyObservers(stateEvent, engine.getState());
//                     // }
                   
//                         //Kuro attacks
                    
//                     // AttackCommand attackCommand(*engine.getState().getPlayerList()[0]->getFighterList()[1], *engine.getState().getPlayerList()[1]->getFighterList()[0]);
//                     // cout << engine.getState().getPlayerList()[0]->getFighterList()[1]->getName() << endl;
//                     // unique_ptr<Command> ptr_attack (new AttackCommand(attackCommand));
//                     // engine.addCommand(1, move(ptr_attack));



//                         //Seku attacks


//                 window.clear();
//                 window.draw(arenaSprite);
//                 window.draw(playerSprite);
//                 window.draw(playerSprite2);
//                 window.display();  
                    
//             }

                
        
                
                // stateLayer.inputManager(event, engine.getState());
                // engine.screenRefresh();
                // usleep(5);
                //stateLayer.initTextureAreas(engine.getState());

                // StateLayer* ptr_stateLayer= &stateLayer;
                // engine.getState().registerObserver(ptr_stateLayer);

                // Engine* ptr_engine=&engine;
                // stateLayer.registerRenderObserver(ptr_engine);

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
            
        
    //}

    // return 0;
