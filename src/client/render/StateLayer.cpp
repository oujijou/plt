#include "StateLayer.h"

using namespace std;

namespace render
{
    StateLayer::StateLayer(state::State &state, sf::RenderWindow &window) : window(window)
    {
        std::unique_ptr<SpriteSet> spriteSetFighter(new SpriteSet(SpriteSetID::FLINT_SPRITE, SpriteSetID::SEKU_SPRITE, SpriteSetID::FLINT_TERRAIN));
        spritesets.push_back(move(spriteSetFighter));
    }
}