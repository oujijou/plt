#include "SpriteSet.h"

using namespace std;
namespace render
{
    SpriteSet:: SpriteSet(SpriteSetID id1,SpriteSetID id2, SpriteSetID id3 )
    {
        //Arena
        if (id3 == SpriteSetID::FLINT_TERRAIN)
        {
            imageFile = "res/Terrains/flint_terrain.png";
        }
        if (id3 == SpriteSetID::THORK_TERRAIN)
        {
            imageFile = "res/Terrains/thork_terrain.png";
        }
        if (id3 == SpriteSetID::SEKU_TERRAIN)
        {
            imageFile = "res/Terrains/seku_terrain.png";
        }
        if (id3 == SpriteSetID::KURO_TERRAIN)
        {
            imageFile = "res/Terrains/kuro_terrain.png";
        }
        //Fighter1
        if (id1 == SpriteSetID::FLINT_SPRITE)
        {
            imageFile = "res/Fighters/flint.png";
        }

        if (id1 == SpriteSetID::SEKU_SPRITE)
        {
            imageFile = "res/Fighters/seku.png";
        }
        
        if (id1 == SpriteSetID::KURO_SPRITE)
        {
            imageFile = "res/Fighters/kuro.png";
        }

        if (id1 == SpriteSetID::SEKU_SPRITE)
        {
            imageFile = "res/Fighters/thork.png";
        }

               
        //Fighter2
        if (id2 == SpriteSetID::FLINT_SPRITE)
        {
            imageFile = "res/Fighters/flint.png";
        }

        if (id2 == SpriteSetID::SEKU_SPRITE)
        {
            imageFile = "res/Fighters/seku.png";
        }
        
        if (id2 == SpriteSetID::KURO_SPRITE)
        {
            imageFile = "res/Fighters/kuro.png";
        }

        if (id2 == SpriteSetID::SEKU_SPRITE)
        {
            imageFile = "res/Fighters/thork.png";
        }

        terrainTexture.loadFromFile(imageFile);
        //terrainSprite.setTexture(terrainTexture);

        sheetSprite1.loadFromFile(imageFile);
        fighter1Sprite.setTexture(sheetSprite1);

        sheetSprite2.loadFromFile(imageFile);
        fighter2Sprite.setTexture(sheetSprite2);

       // fighterSprite.setPosition(sf::Vector2f(10.f, 210.f));
    }

    SpriteSetID SpriteSet::getFighter1SpriteSetID()
    {
        return id1;
    }

    SpriteSetID SpriteSet::getFighter2SpriteSetID()
    {
        return id2;
    }

    SpriteSetID SpriteSet::getTerrainSpriteSetID()
    {
        return id3;
    }

    const std::string SpriteSet::getImageFile ()
    {
        return imageFile;
    }

   
}
