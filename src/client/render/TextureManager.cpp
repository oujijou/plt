#include "TextureManager.h"

using namespace std;
using namespace render;
using namespace state;

#include <iostream>
#include "../render.h"
#include "state.h"
#include "string.h"


bool TextureManager::loadTerrain(int width, int height , string mapImageDirectory)
{
    texture.loadFromFile(mapImageDirectory);

	quads.setPrimitiveType(sf::Quads);
    quads.resize(4);//quads--> a vertex array with 4 vertex 

	sf::Vertex* quad = &quads[0]; //pointor to the first vertex element of quads
		
	//	Definition of the four corners of the vertex in the window
	quad[0].position = sf::Vector2f(0, 0);
	quad[1].position = sf::Vector2f(width, 0);
	quad[2].position = sf::Vector2f(width, height);
	quad[3].position = sf::Vector2f(0, height);
		
    //Definition of coordinates to retrieve the first texture
	quad[0].texCoords = sf::Vector2f(0, 0);
	quad[1].texCoords = sf::Vector2f(width, 0);
	quad[2].texCoords = sf::Vector2f(width, height);
	quad[3].texCoords = sf::Vector2f(0, height);
		
	return true;
}

bool TextureManager::loadFighter(state::State& currentState, TileSet& textureTileset)
{
	texture = textureTileset.getTexture(); //Recover the sf::Texture with TileSet image loaded initialised in render::TileSet Class

	quads.setPrimitiveType(sf::Quads);

	Player currentPlayer;//Initialise Player class object in order to have the list of units belonging to each player
	int vertexArrayIndex = 0;

	for(unsigned int i=0;i<currentState.getPlayerList().size();i++)
	{
        currentPlayer=*currentState.getPlayerList()[i];//take the value of one player pointor adn store it in Player type variable
        cout << "Player NAME: " << currentPlayer.getPlayerName() << endl; 
	}

	// for(unsigned int j=0;j<currentPlayer.getMobileEntityList().size();j++)
	// {
		quads.resize(quads.getVertexCount() + 4);
		sf::Vertex* quad = &quads[vertexArrayIndex * 4];  
		vertexArrayIndex += 1;

		// int tx = currentPlayer.getMobileEntityList()[j]->getEntityId();
		// int ty = currentPlayer.getMobileEntityList()[j]->getDirection();

		//Definition of the four corners of the vertex in the window
			//2 coordinate(x,y) for each vertx--> x = the unit X position in the map product the width of the unit tileSet
			//                                --> y = the unit Y position in the map product the height of the unit tileSet
		quad[0].position = sf::Vector2f(textureTileset.getCellWidth(),textureTileset.getCellHeight());
		quad[1].position = sf::Vector2f(textureTileset.getCellWidth(),textureTileset.getCellHeight());
		quad[2].position = sf::Vector2f(textureTileset.getCellWidth(), textureTileset.getCellHeight());
		quad[3].position = sf::Vector2f(textureTileset.getCellWidth(),textureTileset.getCellHeight());
	
		//Definition of coordinates to retrieve the first texture
			//same as quads position
		quad[0].texCoords = sf::Vector2f( textureTileset.getCellWidth(), textureTileset.getCellHeight());
		quad[1].texCoords = sf::Vector2f( textureTileset.getCellWidth(),  textureTileset.getCellHeight());
		quad[2].texCoords = sf::Vector2f( textureTileset.getCellWidth(), textureTileset.getCellHeight());
		quad[3].texCoords = sf::Vector2f(textureTileset.getCellWidth(), textureTileset.getCellHeight());
    //}
		return true;

}

void TextureManager:: draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // Apply a transformation
        states.transform *= getTransform();

        // Apply texture of the tileset
        states.texture = &texture;

        // Draw the table with the vertex
        target.draw(quads, states);
}

// bool TextureArea::loadFighter(state::State& currentState, TileSet& textureTileset){
//     texture = textureTileset.getTexture(); //Recover the sf::Texture with TileSet image loaded initialised in render::TileSet Class

//     quads.setPrimitiveType(sf::Quads);

//     Player currentPlayer;//Initialise Player class object in order to have the list of units belonging to each player
//     int vertexArrayIndex = 0;

//     //for each player initialized in the state object 
//     for(unsigned int i=0;i<currentState.getPlayerList().size();i++){
//         currentPlayer=*currentState.getPlayerList()[i];//take the value of one player pointor adn store it in Player type variable
//         cout << "Player id: " << currentPlayer.getId() << endl;
//         cout << "Number of units: " << currentPlayer.getMobileEntityList().size() << endl;

//         //for each units controlled by the player choose before 
//         for(unsigned int j=0;j<currentPlayer.getMobileEntityList().size();j++){
//             quads.resize(quads.getVertexCount() + 4);
//             sf::Vertex* quad = &quads[vertexArrayIndex * 4];  
//             vertexArrayIndex += 1;

//             int tx = currentPlayer.getMobileEntityList()[j]->getEntityId();
//             int ty = currentPlayer.getMobileEntityList()[j]->getDirection();

//             //Definition of the four corners of the vertex in the window
//                //2 coordinate(x,y) for each vertx--> x = the unit X position in the map product the width of the unit tileSet
//                //                                --> y = the unit Y position in the map product the height of the unit tileSet
//             quad[0].position = sf::Vector2f(textureTileset.getCellWidth(),textureTileset.getCellHeight());
//             quad[1].position = sf::Vector2f(textureTileset.getCellWidth(),textureTileset.getCellHeight());
//             quad[2].position = sf::Vector2f(textureTileset.getCellWidth(),( * textureTileset.getCellHeight());
//             quad[3].position = sf::Vector2f(textureTileset.getCellWidth(),( * textureTileset.getCellHeight());
            
//             //Definition of coordinates to retrieve the first texture
//                //same as quads position
//             quad[0].texCoords = sf::Vector2f(tx * textureTileset.getCellWidth(), ty * textureTileset.getCellHeight());
//             quad[1].texCoords = sf::Vector2f((tx+1) * textureTileset.getCellWidth(), ty * textureTileset.getCellHeight());
//             quad[2].texCoords = sf::Vector2f((tx+1) * textureTileset.getCellWidth(), (ty+1) * textureTileset.getCellHeight());
//             quad[3].texCoords = sf::Vector2f(tx * textureTileset.getCellWidth(), (ty+1) * textureTileset.getCellHeight());
//         }
//     }
    // return true;
// }
