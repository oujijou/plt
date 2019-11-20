#include "TextureManager.h"

using namespace std;
using namespace render;
using namespace state;

#include <iostream>
#include "../render.h"
#include "state.h"
#include "string.h"

/*
TextureManager *t = TextureManager::getInstance();
auto *tile = TextureManager::getInstance()->getTileFighter(...);
*/

TextureManager* TextureManager::instance = nullptr;

TextureManager::TextureManager(){
	tiles_fighter.insert({Kuro, make_shared<TileSet>("./res/Fighters/Kuro.png")});
	tiles_fighter.insert({Flint, make_shared<TileSet>("./res/Fighters/Flint.png")});
	tiles_fighter.insert({Thork, make_shared<TileSet>("./res/Fighters/Thork.png")});
	tiles_fighter.insert({Seku, make_shared<TileSet>("./res/Fighters/Seku.png")});

	tiles_background.insert({SekuTerrain, make_shared<TileSet>("./res/Terrains/seku_terrain.png")});
	tiles_background.insert({FlintTerrain, make_shared<TileSet>("./res/Terrains/flint_terrain.png")});
	tiles_background.insert({KuroTerrain, make_shared<TileSet>("./res/Terrains/kuro_terrain.png")});
	tiles_background.insert({ThorkTerrain, make_shared<TileSet>("./res/Terrains/thork_terrain.png")});
}

TextureManager* TextureManager::getInstance(){
	if (!instance) {
		instance = new TextureManager();
	}
	return instance;
}

TileSet* TextureManager::getTileFighter (state::FighterName fighter)
{	
	
	return tiles_fighter.at(fighter).get();
}

TileSet* TextureManager::getTileBackground (state::Terrain bg)
{	
	return tiles_background.at(bg).get();
}


bool TextureManager::load(){
	// TODO: Check if Textures loaded? Prevent double call to "load"
	
	for (auto &it : tiles_fighter) {
		if (!it.second->loadTexture()) {
			return false;
		}
	}

	for (auto &it : tiles_background) {
		if (!it.second->loadTexture()) {
			return false;
		}
	}
	
	return true;
}

// bool TextureManager::loadTerrain(int width, int height , string mapImageDirectory)
// {
//     texture.loadFromFile(mapImageDirectory);

// 	quads.setPrimitiveType(sf::Quads);
//     quads.resize(4);

// 	sf::Vertex* quad = &quads[0]; 
		
// 	//	Definition of the four corners of the vertex in the window
// 	quad[0].position = sf::Vector2f(0, 0);
// 	quad[1].position = sf::Vector2f(width, 0);
// 	quad[2].position = sf::Vector2f(width, height);
// 	quad[3].position = sf::Vector2f(0, height);
		
//     //Definition of coordinates to retrieve the first texture
// 	quad[0].texCoords = sf::Vector2f(0, 0);
// 	quad[1].texCoords = sf::Vector2f(width, 0);
// 	quad[2].texCoords = sf::Vector2f(width, height);
// 	quad[3].texCoords = sf::Vector2f(0, height);
		
// 	return true;
// }

// bool TextureManager::loadFighter(int width, int height, string ImageDirectory)
// {
// 	texture.loadFromFile(ImageDirectory);

// 	quads.setPrimitiveType(sf::Quads);
//     quads.resize(4);//quads--> a vertex array with 4 vertex 

// 	sf::Vertex* quad = &quads[0]; //pointer to the first vertex element of quads
		
// 	//	Definition of the four corners of the vertex in the window
// 	quad[0].position = sf::Vector2f(0, 0);
// 	quad[1].position = sf::Vector2f(width, 0);
// 	quad[2].position = sf::Vector2f(width, height);
// 	quad[3].position = sf::Vector2f(0, height);
		
//     //Definition of coordinates to retrieve the first texture
// 	quad[0].texCoords = sf::Vector2f(0, 0);
// 	quad[1].texCoords = sf::Vector2f(width, 0);
// 	quad[2].texCoords = sf::Vector2f(width, height);
// 	quad[3].texCoords = sf::Vector2f(0, height);
	
// 	return true;
// }

// bool TextureManager::loadFighter1(state::State& currentState, TileSet& textureTileset){
// 	texture = textureTileset.getTexture(); 
// 	sf::VertexArray quads(sf::Quads , 4);

// // on le définit comme un rectangle, placé en (50, 250) et de taille 100x100
// 	quads[0].position = sf::Vector2f(50.f, 250.f);
// 	quads[1].position = sf::Vector2f(150.f, 250.f);
// 	quads[2].position = sf::Vector2f(150.f, 350.f);
// 	quads[3].position = sf::Vector2f(150.f, 250.f);

// // on applique la texture commencant en 0,0 de dimension 100,100
// 	quads[0].texCoords = sf::Vector2f(0.f, 0.f);
// 	quads[1].texCoords = sf::Vector2f(100.f, 0.f);
// 	quads[2].texCoords = sf::Vector2f(100.f, 100.f);
// 	quads[3].texCoords = sf::Vector2f(0.f, 100.f);

// 	return true;
// }

// bool TextureManager::loadFighter2(state::State& currentState, TileSet& textureTileset){
// 	texture = textureTileset.getTexture(); 
// 	sf::VertexArray quads(sf::Quads , 4);
// 	//sf::Vertex* quad = &quads;

// // on le définit comme un rectangle, placé en (10, 10) et de taille 100x100
// 	quads[0].position = sf::Vector2f(60.f, 250.f);
// 	quads[1].position = sf::Vector2f(160.f, 250.f);
// 	quads[2].position = sf::Vector2f(160.f, 350.f);
// 	quads[3].position = sf::Vector2f(60.f, 350.f);

// 	quads[0].texCoords = sf::Vector2f(0.f, 0.f);
// 	quads[1].texCoords = sf::Vector2f(100.f, 0.f);
// 	quads[2].texCoords = sf::Vector2f(100.f, 100.f);
// 	quads[3].texCoords = sf::Vector2f(0.f, 100.f);

// 	return true;
// }

// void TextureManager:: draw(sf::RenderTarget& target, sf::RenderStates states) const {
//         // Apply a transformation
//         states.transform *= getTransform();

//         // Apply texture of the tileset
//         states.texture = &texture;

//         // Draw the table with the vertex
//         target.draw(quads, states);
// }

