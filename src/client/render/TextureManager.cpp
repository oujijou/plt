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

	tiles_healthbar.insert({100, make_shared<TileSet>("./res/healthBar/100.png")});
	tiles_healthbar.insert({90, make_shared<TileSet>("./res/healthBar/90.png")});
	tiles_healthbar.insert({80, make_shared<TileSet>("./res/healthBar/80.png")});
	tiles_healthbar.insert({70, make_shared<TileSet>("./res/healthBar/70.png")});
	tiles_healthbar.insert({60, make_shared<TileSet>("./res/healthBar/60.png")});
	tiles_healthbar.insert({50, make_shared<TileSet>("./res/healthBar/50.png")});
	tiles_healthbar.insert({40, make_shared<TileSet>("./res/healthBar/40.png")});
	tiles_healthbar.insert({30, make_shared<TileSet>("./res/healthBar/30.png")});
	tiles_healthbar.insert({20, make_shared<TileSet>("./res/healthBar/20.png")});
	tiles_healthbar.insert({10, make_shared<TileSet>("./res/healthBar/10.png")});
	tiles_healthbar.insert({5, make_shared<TileSet>("./res/healthBar/5.png")});
	tiles_healthbar.insert({0, make_shared<TileSet>("./res/healthBar/0.png")});
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

TileSet* TextureManager::getTileHealthBar(int healthPoints)
{
	return tiles_healthbar.at(healthPoints).get();
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

	for (auto &it : tiles_healthbar) {
		if (!it.second->loadTexture()) {
			return false;
		}
	}
	
	return true;
}

